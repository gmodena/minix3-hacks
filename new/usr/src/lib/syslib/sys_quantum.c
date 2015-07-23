#include "syslib.h"
#include <stdio.h>

/*===========================================================================*
 *                                sys_quantum			     	     *
 *===========================================================================*/
PUBLIC int sys_quantum(int proc, int quantum)
{
  message m;
  
  /* Creo un messaggio contente i parametri passati dal chiamante 
     e lo invio al task SYSTEM.
     La definizione di PR_PROC_NR e PR_QUANTUM si trova in minix/com.h
  */

  m.PR_PROC_NR = proc;
  m.PR_QUANTUM = quantum;
  
  /* Notifico a SYSTEM la richiesta SYS_QUANTUM */
  return(_taskcall(SYSTASK, SYS_QUANTUM, &m));
}
