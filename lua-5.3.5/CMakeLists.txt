
add_library(lua SHARED
        src/lapi.c     src/lbaselib.c  src/lcorolib.c  src/ldebug.c  src/ldump.c  src/lgc.h     src/llex.h      src/lmem.h     src/lopcodes.c  src/lparser.h  src/lstring.c  src/ltable.h   src/lutf8lib.c  src/lzio.h
        src/lapi.h     src/lbitlib.c   src/lctype.c    src/ldebug.h  src/lfunc.c  src/linit.c   src/llimits.h   src/loadlib.c  src/lopcodes.h  src/lprefix.h  src/lstring.h  src/ltablib.c  src/lualib.h   src/lvm.c
        src/lauxlib.c  src/lcode.c     src/lctype.h    src/ldo.c     src/lfunc.h  src/liolib.c  src/lmathlib.c  src/lobject.c  src/loslib.c    src/lstate.c   src/lstrlib.c  src/ltm.c      src/luaconf.h  src/lundump.c  src/lvm.h
        src/lauxlib.h  src/lcode.h     src/ldblib.c    src/ldo.h     src/lgc.c    src/llex.c    src/lmem.c      src/lobject.h  src/lparser.c   src/lstate.h   src/ltable.c   src/ltm.h      src/lua.h      src/lundump.h  src/lzio.c)

set_target_properties(lua
        PROPERTIES
        IMPORTED_LINK_INTERFACE_LANGUAGES C)

