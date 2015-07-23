/* The kernel call implemented in this file:
 *   m_type:	SYS_QUANTUM
 *
 * The parameters for this kernel call are:
 *    m1_i1:	PR_PROC_NR	process number to change quantum 
 *    m1_i2:	PR_QUANTUM	the new quantum size
 */

#include "../system.h"
#include <minix/type.h>
#include <sys/resource.h>

#if USE_QUANTUM
/*===========================================================================*
 *				  do_quantum				     *
 *===========================================================================*/
PUBLIC int do_quantum(message *m_ptr)
{
  int proc_nr, quantum;
  register struct proc *rp;

  /* Individuo il numero del processo da modificare */
  proc_nr = m_ptr->PR_PROC_NR ;
  
  /* Il numero del processo non e` valido */
  if (! isokprocn(proc_nr)) return(EINVAL);

  /* Consento di modificare la dimensione del quanto solo nei processi utente */
  if (iskerneln(proc_nr)) return(EPERM);
  
  /* Nuova dimensione del quanto */
  quantum = m_ptr->PR_QUANTUM;
  
  /* Controllo che la sua dimensione rispetti i limiti consentiti */
  if (quantum < MIN_QUANTUM_SIZE) {
	  kprintf("WARNING: quantum size exceeds MIN_QUANTUM_SIZE, it will be raised to %d ticks\n",MIN_QUANTUM_SIZE);
	  quantum = MIN_QUANTUM_SIZE;
  }
  else if (quantum > MAX_QUANTUM_SIZE) {
	  kprintf("WARNING: quantum size exceeds MAX_QUANTUM_SIZE, it will be lowered to %d ticks\n",MAX_QUANTUM_SIZE);
	  quantum = MAX_QUANTUM_SIZE;
  }
 
  /* Seleziono il processo da aggiornare */ 
  rp = proc_addr(proc_nr);
 
  /* Lo rimuovo dalla coda */
  lock_dequeue(rp);

  /* Aggiorno la dimensione del quanto */
  rp->p_quantum_size = quantum;

  /* Reinserisco il processo in coda */
  if (! rp->p_rts_flags) lock_enqueue(rp);
  
  return(OK);
}

#endif
