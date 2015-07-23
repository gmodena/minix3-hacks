484,497c484,575
< 
<   /* Now add the process to the queue. */
<   if (rdy_head[q] == NIL_PROC) {		/* add to empty queue */
<       rdy_head[q] = rdy_tail[q] = rp; 		/* create a new queue */
<       rp->p_nextready = NIL_PROC;		/* mark new end */
<   } 
<   else if (front) {				/* add to head of queue */
<       rp->p_nextready = rdy_head[q];		/* chain head of queue */
<       rdy_head[q] = rp;				/* set new queue head */
<   } 
<   else {					/* add to tail of queue */
<       rdy_tail[q]->p_nextready = rp;		/* chain tail of queue */	
<       rdy_tail[q] = rp;				/* set new queue tail */
<       rp->p_nextready = NIL_PROC;		/* mark new end */
---
>   
>   if (q != USER_Q){
>    /* Now add the process to the queue. */
>    if (rdy_head[q] == NIL_PROC) {		/* add to empty queue */
>        rdy_head[q] = rdy_tail[q] = rp; 		/* create a new queue */
>        rp->p_nextready = NIL_PROC;		/* mark new end */
>    } 
>    else if (front) {				/* add to head of queue */
>        rp->p_nextready = rdy_head[q];		/* chain head of queue */
>        rdy_head[q] = rp;				/* set new queue head */
>    } 
>    else {					/* add to tail of queue */
>        rdy_tail[q]->p_nextready = rp;		/* chain tail of queue */	
>        rdy_tail[q] = rp;				/* set new queue tail */
>        rp->p_nextready = NIL_PROC;		/* mark new end */
>    }
>   }
>   else {
> 	 /* 
> 	  * Decommentando questa riga e commentando le successive
> 	  * e' possibile avere un esempio di starvation dei processi in coda.
> 	  * 
> 	  * usyslog (19) rimarra` costantemente in fondo alla coda 7 senza venir
> 	  * mai eseguito, cosa che non succede quando viene effettuato 
> 	  * l'invecchiamento.
> 	  * */
> 
> 	  /* prio_estimate = rp->p_user_time + rp->p_sys_time */
> 	  
> 	 /* Aggiorno la priorita` del processo che sta per essere inserita */
> 	 prio_estimate[rp->p_nr-1] += procs_lifetime[rp->p_nr-1];
> 	 
> 	 /* Aging dei processi in coda ogni 256 cicli di clock */
> 	 /* if ((get_uptime() % 16) == 0) */
> 	 if (time_elapsed <= 0)
> 	 {
> 		  int i;
> 		  for (i = 0; i < NR_PROCS; i++) {
> 		  	prio_estimate[i] = prio_estimate[i] / 4;
> 			procs_lifetime[i] = 0;
> 		  }
> 		  time_elapsed = AGE_TH;
> 	  }
> 	  /* Fine invecchiamento */
> 	  if (rdy_head[q] == NIL_PROC) { 
> 		  rdy_head[q] = rdy_tail[q] = rp; 
> 		  rp->p_nextready = NIL_PROC;
>   	  }
> 	  
> 	  else {
> 		  struct proc *cur;
> 
> 		  cur = rdy_head[q];
> 		  while (cur->p_nextready != NIL_PROC
> 		       && prio_estimate[cur->p_nextready->p_nr -1] <=
> 		   	prio_estimate[rp->p_nr-1]
> 		       ) {
> 		           cur = cur->p_nextready;
> 		  
> 		    }
> 		    /* sono arrivato in fondo alla coda */
> 		    if (cur->p_nextready == NIL_PROC &&
> 			 prio_estimate[cur->p_nr-1] <
> 					prio_estimate[rp->p_nr-1])  {
> 				cur->p_nextready = rp;
> 				rdy_tail[q] = rp;
> 				rp->p_nextready = NIL_PROC;
> 			
> 		    }
> 		    /* sono in cima alla coda */
> 	  	    else if (cur == rdy_head[q]) {
> 			    /* metto rp in testa */
> 			    if (prio_estimate[cur->p_nr -1] >
> 					    prio_estimate[rp->p_nr-1]) {
> 			    
> 			    	rp->p_nextready = rdy_head[q];
> 				rdy_head[q] = rp;
> 			    }
> 			    /* metto rp in seconda posizione */
> 			    else {
> 			    	rp->p_nextready = cur->p_nextready;
> 				cur->p_nextready = rp;
> 			    }
> 		    }
> 		    
> 		    else {
>                  	/* rp segue cur */
> 			rp->p_nextready = cur->p_nextready;
> 			cur->p_nextready = rp;
> 		    }
> 		  }
> 	  
522c600
< 
---
>  
624c702
<           next_ptr = rp;			/* run process 'rp' next */
---
> 	  next_ptr = rp;			/* run process 'rp' next */
627c705
<           return;				 
---
>           return;
