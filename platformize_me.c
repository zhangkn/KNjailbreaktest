/* Set platform binary flag */
#define FLAG_PLATFORMIZE (1 << 1)

void platformize_me() {
    void* handle = dlopen(/usr/lib/libjailbreak.dylib, RTLD_LAZY);
    
    // Reset errors
    dlerror();
    typedef void (*fix_entitle_prt_t)(pid_t pid, uint32_t what);
    fix_entitle_prt_t ptr = (fix_entitle_prt_t)dlsym(handle, jb_oneshot_entitle_now);
    
    const char *dlsym_error = dlerror();
    if (dlsym_error) return;
    
    ptr(getpid(), FLAG_PLATFORMIZE);
}
