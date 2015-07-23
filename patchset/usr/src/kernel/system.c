132a133,140
>   /* Associo la kernel call do_quantum() al segnale SYS_QUANTUM generato 
>      dalla funzione di libreria sys_quantum(). 
>      Quando il task SYSTEM riceve
>      un messaggio con richiesta SYS_QUANTUM, esegue la funzione do_quantum() 
>      passandole il messaggio che l'ha originata.
>   */
>   map(SYS_QUANTUM, do_quantum);
>   
137c145
<   map(SYS_NICE, do_nice);		/* set scheduling priority */
---
>   map(SYS_NICE, do_nice); 		/* set scheduling priority */
174a183
> 
