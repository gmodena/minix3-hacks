16a17,19
> /* Lasso di tempo dopo il quale il cronometro procs_lifetime[] verra` azzerato */
> #define AGE_TH 16
> 
53a57,63
> EXTERN unsigned int prio_estimate[NR_PROCS]; /* Contiene la stima della 
> priorita` di un processo, 
> determinata dal suo tempo di vita */
> 
> EXTERN clock_t	procs_lifetime[NR_PROCS]; /* Cronometro che registra il tempo di vita di un processo. */
> EXTERN int time_elapsed;
> 
