21a22
> #include <stdio.h>
99a101,121
> int do_quantum() {
> 	int pnr, qnt;
> 	
> 	/* Solo root puo' cambiare la dimensione del quanto */
> 	if (mp->mp_effuid != SUPER_USER)
> 		return(EACCES);
> 
> 	/* ricavo il numero del processo a partire dal suo PID */
> 	pnr = proc_from_pid(m_in.PR_PID);
> 
> 	/* Dimensione del quanto */
> 	qnt = m_in.PR_QUANTUM;
> 	
> 	printf("Do quantum (PM) on process %d with q size %d\n ", pnr, qnt);	
> 	
> 	sys_quantum(pnr, qnt);
> 
> 
> 	return (OK);
> }
> 
