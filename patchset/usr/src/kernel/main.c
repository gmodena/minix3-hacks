162a163,170
>   
>   /* Inizializzo il time, il cronometro e l'array contenete la stima delle
>   priorita`.  */
>   time_elapsed = AGE_TH;
>   for (i = 0; i < NR_PROCS; i++) {
>   	procs_lifetime[i] = 0;
> 	prio_estimate[i] = 0;
>   }
