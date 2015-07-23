81,84c81,85
< #define MAX_USER_Q  	   0    /* highest priority for user processes */   
< #define USER_Q  	   7    /* default (should correspond to nice 0) */   
< #define MIN_USER_Q	  14	/* minimum priority for user processes */
< #define IDLE_Q		  15    /* lowest, only IDLE process goes here */
---
> #define MAX_USER_Q  	   7    /* highest priority for user processes */   
> #define USER_Q  	   7    /* default (should correspond to nice 0) */   
> #define MIN_USER_Q	   7	/* minimum priority for user processes */
> #define IDLE_Q		  15    /* lowest, only IDLE process goes here */
> /* I processi utente sono limitati alla sola coda 7, ordinata per priorita` */
