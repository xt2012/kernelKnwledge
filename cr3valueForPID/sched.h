struct mm_struct {
        struct vm_area_struct  *mmap;               /* list of memory areas */
        struct rb_root         mm_rb;               /* red-black tree of VMAs */
        struct vm_area_struct  *mmap_cache;         /* last used memory area */
        unsigned long          free_area_cache;     /* 1st address space hole */
        pgd_t                  *pgd;                /* page global directory */
        atomic_t               mm_users;            /* address space users */
        atomic_t               mm_count;            /* primary usage counter */
        int                    map_count;           /* number of memory areas */
        struct rw_semaphore    mmap_sem;            /* memory area semaphore */
        spinlock_t             page_table_lock;     /* page table lock */
        struct list_head       mmlist;              /* list of all mm_structs */
        unsigned long          start_code;          /* start address of code */
        unsigned long          end_code;            /* final address of code */
        unsigned long          start_data;          /* start address of data */
        unsigned long          end_data;            /* final address of data */
        unsigned long          start_brk;           /* start address of heap */
        unsigned long          brk;                 /* final address of heap */
        unsigned long          start_stack;         /* start address of stack */
        unsigned long          arg_start;           /* start of arguments */
        unsigned long          arg_end;             /* end of arguments */
        unsigned long          env_start;           /* start of environment */
        unsigned long          env_end;             /* end of environment */
        unsigned long          rss;                 /* pages allocated */
        unsigned long          total_vm;            /* total number of pages */
        unsigned long          locked_vm;           /* number of locked pages */
        unsigned long          def_flags;           /* default access flags */
        unsigned long          cpu_vm_mask;         /* lazy TLB switch mask */
        unsigned long          swap_address;        /* last scanned address */
        unsigned               dumpable:1;          /* can this mm core dump? */
        int                    used_hugetlb;        /* used hugetlb pages? */
        mm_context_t           context;             /* arch-specific data */
        int                    core_waiters;        /* thread core dump waiters */
        struct completion      *core_startup_done;  /* core start completion */
        struct completion      core_done;           /* core end completion */
        rwlock_t               ioctx_list_lock;     /* AIO I/O list lock */
        struct kioctx          *ioctx_list;         /* AIO I/O list */
        struct kioctx          default_kioctx;      /* AIO default I/O context */
};

