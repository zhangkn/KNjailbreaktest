#include <stdio.h>
int main()


{

	// void* handle = dlopen("/usr/lib/libjailbreak.dylib", RTLD_LAZY);
 //    if (!handle) return;
    
 //    // Reset errors
 //    dlerror();

 //    typedef void (*fix_setuid_prt_t)(pid_t pid);
 //    fix_setuid_prt_t setuidptr = (fix_setuid_prt_t)dlsym(handle, "jb_oneshot_fix_setuid_now");

 //    typedef void (*fix_entitle_prt_t)(pid_t pid, uint32_t what);
 //    fix_entitle_prt_t entitleptr = (fix_entitle_prt_t)dlsym(handle, "jb_oneshot_entitle_now");
    
 //    setuidptr(getpid());

 //    setuid(0);

    printf("Hello, world!\n");
    return 0;
}