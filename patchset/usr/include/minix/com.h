226c226,228
< #define NR_SYS_CALLS	29	/* number of system calls */ 
---
> #  define SYS_QUANTUM	 (KERNEL_CALL + 29)     /* sys_quantum */
> 
> #define NR_SYS_CALLS	30	/* number of system calls */ 
325a328
> #   define GET_PRIOINFO	  15	/* Preleva le informazioni dalla tabella prio_estimate */
371a375,376
> #define PR_QUANTUM     m1_i2 	/* dimensione del quanto temporale assegnato al processo */
> 
435a441,447
> /***************************************
>   * Limiti sulla dimensione del quanto *
>   **************************************/
> 
> #define MAX_QUANTUM_SIZE      25
> #define MIN_QUANTUM_SIZE      4
> 
