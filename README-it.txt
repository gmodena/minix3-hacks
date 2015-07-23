Gabriele Modena, mat. 108742, gabriele.modena@gmail.com

Struttura del pacchetto
=======================

new/ - contiene i file creati ex novo.

patchset/ - contiene le modifiche ai file orginari.

doc/ - contiene una relazione in formato pdf (e sorgente tex) sul lavoro svolto.

Installazione
=============

La procedura e` stata testata usando la versione di minix presente
in laboratorio (minix3 3.1.1).

Installazione dei nuovi file
----------------------------

# cd new
# ./copy.sh


Applicazione delle patch
------------------------

# cd patchset
# ./apply.sh


Compilazione
------------

Minix richiede il tool gmake per compilare le librerie fornite con il
sistema.
Pertanto, prima di procedere e` necessario installarlo con il comando

# easypack make-3.80
# ln /usr/bin/gmake /usr/gnu/bin/gmake

A questo punto e` possibile ricompilare il sistema.

# cd /usr/src/tools
# make fresh
# make hdboot

# cd /usr/src/commands/simple
# make
# make install

Con questi comandi verra' ricompilato l'intero sistema operativo (librerie,
comandi, server e kernel).

Al termine della fase di compilazione verra` creata l'immagine del kernel
/boot/image/3.1.1r1 e installato il comando /usr/bin/qnt.

A questo punto e` possibile riavviare il sistema e testare le modifiche.

Nel caso in cui minix3 non partisse con il kernel corretto e` possbile
specificare l'immagine al bootloader premendo ESC all'avvio del sistema
e, una volta avuto accesso alla shell, digitando:

# image=/boot/image/3.1.1r1
# boot

Esecuzione e test
=================

Al riavvio del sistema verranno caricati il nuovo kernel e i servizi IS e PM
modificati.

Scheduler
---------

Per fare un test sul nuovo meccanismo di scheduling e` possibili avviare
la suite di test di minix3 (/usr/src/test) e premendo il tasto F9 
si potra` visualizzare lo stato delle code sul terminale tty0. 

qnt
---

E' possibile richiamare l'help del programma digitando:
# qnt -h

qnt richiede due parametri, il pid del processo (-p) e la nuova dimensione del
quanto (-q).

Ad esempio, per incrementare il quanto del processo cron, occorre digitare:
# qnt -p 65 -q 23

Verra` stampato un messaggio di debug sul terminale tty0, con riportato il
numero di processo associato al PID inserito.

Premendo F1 e` possibile visualizzare un dump della tabella dei processi, dove
e` possibile notare il cambiamento del campo "quant" secondo il valore
specificato.

qnt ha effetto solo sui processi che girano in user space (server inclusi).
