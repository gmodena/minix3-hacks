#include <lib.h>
#include <unistd.h>

/* Parametri:
 * proc - pid del processo target.
 * size - nuova dimensione del campo p_quantum_size
 * */

PUBLIC int quantum(int proc, int size)
{
  message m;

  /* Creo un messaggio contente i parametri passati dall'utente 
     e lo invio al server PM.
     PR_PID e PR_QUANTUM sono definiti in minix/com.h
  */

  m.PR_PID = proc;
  m.PR_QUANTUM = size;

  /* Notifico la chiamata al server PM */
  if (_syscall(PM_PROC_NR, QUANTUM, &m) < 0) return(-1);
  return 0;		/* return own process number */
}

