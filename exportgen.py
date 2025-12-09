import pefile, sys, os

def help():
    print("hcompat-exportgen")
    print(f"{sys.argv[0]} <dll>")
    exit(1)

if len(sys.argv) < 2:
    help()

dllname = os.path.basename(sys.argv[1])
pe = pefile.PE(sys.argv[1])

for export in pe.DIRECTORY_ENTRY_EXPORT.symbols:
    # TODO: Account for exports without names
    if export.name != None:
        name = export.name.decode('utf-8')
        print(f"#pragma comment(linker, \"/export:{name}={dllname.strip(".dll")}.{name},@{export.ordinal}\")")