#include <winternl.h>

#ifndef NtCurrentPeb
#define NtCurrentPeb() (NtCurrentTeb()->ProcessEnvironmentBlock)
#endif

// fancy macros
#define REDIRECT_DLL(name, prefix) { \
    if(_stricmp(dllName, name) == 0) { \
        DbgPrint("hpatcher: " name " detected, replacing first letter\r\n"); \
        dllName[0] = prefix; \
    } \
}

void patchCurrentProcess() {
    PEB *currentPeb = NtCurrentPeb();
    LIST_ENTRY *ldrHead = &currentPeb->Ldr->InMemoryOrderModuleList;
    DbgPrint("hpatcher: Patching process..\n\r");
    DbgPrint("hpatcher: ldr field is 0x%lx\n\r", currentPeb->Ldr);

    //currentPeb->BeingDebugged = 0x00;
    //DbgPrint("hpatcher: Hid debugger in PEB\n\r");

    // Maybe clean up this mess later?

    LIST_ENTRY *currentLdrEntry = ldrHead->Flink;
    LDR_DATA_TABLE_ENTRY* ldr = (LDR_DATA_TABLE_ENTRY*) ((char*)currentLdrEntry-sizeof(LIST_ENTRY));
    DWORD dllSize = (DWORD)(ldr->Reserved3[1]);
    void *dllBase = ldr->DllBase;

    IMAGE_DOS_HEADER* dos_header  = (IMAGE_DOS_HEADER*)dllBase;
    IMAGE_NT_HEADERS* pe_header = (IMAGE_NT_HEADERS*) (((char*) dos_header) + dos_header->e_lfanew);
    IMAGE_IMPORT_DESCRIPTOR *import =
        (IMAGE_IMPORT_DESCRIPTOR *)( ((char *) dllBase) + pe_header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress );

    DbgPrint("hpatcher: exe's name is %ls (base: 0x%lx size: 0x%x)\r\n", ldr->FullDllName.Buffer, ldr->DllBase, dllSize);

    while(import->Name != 0) {
        DbgPrint("hpatcher: import at %lx\n\r", import );
        DbgPrint("hpatcher: removing protections from import name\r\n");
        DWORD name = import->Name;
        char *dllName = (char *)(((char *) dllBase) + name);

        DWORD oldProtections = 0;

        // for some reason VirtualProtect demands a place to put the old protection info
        BOOL result = VirtualProtect(
            dllName,
            strlen(dllName),
            PAGE_READWRITE,
            &oldProtections
        );

        if(!result) {
            DbgPrint("hpatcher: failed to remove protections, skipping patch :(\n");
            DebugBreak();
            goto fail;
        }

        REDIRECT_DLL("kernel32.dll", 'h');
        REDIRECT_DLL("user32.dll", 'h');

        DbgPrint("hpatcher: reverting protections back\r\n");
        result = VirtualProtect(
            dllName,
            strlen(dllName),
            PAGE_READONLY,
            &oldProtections
        );
        if(!result) {
            DbgPrint("hpatcher: oops can't revert protections from dll :(\r\n");
            DebugBreak();
        }


        fail:
        DbgPrint("hpatcher: exe imports %s\n\r", dllName);
        import++;
    }
}