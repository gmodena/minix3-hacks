107a108,126
>     /* do_getinfo e` stata richiamata con il parametro GET_PRIOINFO */
>     case GET_PRIOINFO: {
>  
> 	/* Calcolo la dimensione dell'array */
> 	length = sizeof(unsigned int) * NR_PROCS;
> 	
> 	/* Copio in userpace l'array prio_estimate. vir2phys restiuisce
> 	 una copia dell'address space (fisico) della struttura lato kernel. 
> 	 Successivamente do_getinfo copiera` questa informazione nell'address 
> 	 space del processo chiamate salvando le informazioni nella variabile
> 	 dst_phys e da li mappandole nel campo I_VAL_PTR del messaggio ricevuto
> 	 da do_getinfo (argomento passato alla funzione
> 	 sys_getprioinfo() ).  
> 	*/
> 	
> 	src_phys = vir2phys(prio_estimate);
> 	break;
>     }
> 
