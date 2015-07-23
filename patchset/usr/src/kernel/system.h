37a38,51
> /* 
>   Dichiarazione del prototipo della kernel call. L'implementazione si trova
>   nel file ./system/do_quantum.c
>   Se la label USE_QUANTUM non e` definta (./config.h), il kernel e` stato 
>   compilato senza il supporto alla chiamata. In questo caso, se dovesse arrivare
>   una richiesta SYS_QUANTUM, notifico l'assenza della kernel call tramite 
>   la funzione do_unused.
> */
> 
> _PROTOTYPE( int do_quantum, (message *m_ptr) );
> #if ! USE_QUANTUM
> #define do_quantum do_unused
> #endif
> 
