213a214
>   unsigned int prio[NR_PROCS];
229a231,235
>   if ( (r = sys_getprioinfo(prio)) != OK) {
>   	report ("IR", "warning: couldn't get prio info", r);
>   	return;
>   }
> 
249,250c255,259
<           printf("%3d ", rp->p_nr);
<           rp = rp->p_nextready;
---
> 	  if (r == USER_Q) 
>            printf("Name: %s - Num: %d - Prio: %d || ", rp->p_name, rp->p_nr,  prio[rp->p_nr-1]);
> 	  else
> 	    printf("%3d, ", rp->p_nr);
> 	  rp = rp->p_nextready;
