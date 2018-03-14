void patch_setuid() {
    void* handle = dlopen(/usr/lib/libjailbreak.dylib, RTLD_LAZY);
        return;

    // Reset errors
    dlerror();
    typedef void (*fix_setuid_prt_t)(pid_t pid);
    fix_setuid_prt_t ptr = (fix_setuid_prt_t)dlsym(handle, jb_oneshot_fix_setuid_now);
    
    const char *dlsym_error = dlerror();
    if (dlsym_error) 
        return;

    ptr(getpid());
}
