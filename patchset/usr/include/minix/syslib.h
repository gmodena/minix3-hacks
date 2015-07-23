116a117,125
> 
> 
> /* Creo un alias delle funziona sys_getinfo per la richiesta GET_PRIOINFO.
>    La tabella delle priorita` verra` salvata in dst. 
>    Si vedano i commenti /usr/src/kernel/system/do_getinfo.c per i dettagli
>    sul funzionamento a basso livello della richiesta GET_PRIOINFO.
> */
> #define sys_getprioinfo(dst)	sys_getinfo(GET_PRIOINFO, dst, 0,0,0)
> 
150,151c159,163
< #endif /* _SYSLIB_H */
< 
---
> /* La funzione e' implementata in /usr/src/lib/syslib/sys_quantum.c */
> _PROTOTYPE(int sys_quantum, (int proc, int quantum) );
> 
> #endif /* _SYSLIB_H */
> 
