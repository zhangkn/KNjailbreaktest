void patch_setuidandplatformize() {
    void* handle = dlopen(/usr/lib/libjailbreak.dylib, RTLD_LAZY);
    
    // Reset errors
    dlerror();

    typedef void (*fix_setuid_prt_t)(pid_t pid);
    fix_setuid_prt_t setuidptr = (fix_setuid_prt_t)dlsym(handle, jb_oneshot_fix_setuid_now);

    typedef void (*fix_entitle_prt_t)(pid_t pid, uint32_t what);
    fix_entitle_prt_t entitleptr = (fix_entitle_prt_t)dlsym(handle, jb_oneshot_entitle_now);
    
    setuidptr(getpid());

    setuid(0);

    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        return;
    }
    
    entitleptr(getpid(), FLAG_PLATFORMIZE);
}
