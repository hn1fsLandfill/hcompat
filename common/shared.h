#ifndef __SHARED_H
#define __SHARED_H

// wtf x86 msvc
#ifndef _M_X64
#define export(a) comment(linker, "/export:" a "=_e_" a)
#else
#define export(a) comment(linker, "/export:" a "=e_" a)
#endif

#endif