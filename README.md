Implementation of a priority queue scheduler for minix3 and a syscall, *quantum()*,
that allows to increment/decrement a process time quantum  at run time.

It's an old toy project that I hacked together during my BSc (~2006), but it still does its job. Kernel space is fun.

This patchset targets Minix 3.1.1, the operating system version
shipped with the [Minix book](http://vig.prenhall.com/catalog/academic/product/0,1144,0131429388,00.html).

# Project structure

 new/ - new files
 patchset/ - patch to Minix3 sources.
 doc/ - project documentation (in Italian)

# Setup

This code targets Minix3 3.1.1;

Copy new code into a fresh Minix3 /usr path with
```{bash}
# cd new
# ./copy.sh
```

Patch Minix3 system sources with

```{bash}
# cd patchset
# ./apply.sh
```

# Build

We need gmake to build kernel and user space code
```{bash}
# easypack make-3.80
# ln /usr/bin/gmake /usr/gnu/bin/gmake
```

Now we can recompile the system (libraries, kernel and servers ) with

```{bash}
# cd /usr/src/tools
# make fresh
# make hdboot

# cd /usr/src/commands/simple
# make
# make install
```

Upon sucessful compilation a kernel image should be generated under
/boot/image/3.1.1r1 the new *qnt*, a frontend for *quantum()* command should be available under /usr/bin/qnt.

#Run

Reboot the system to load the patched kernel and modified IS and PM services.

## Scheduler

To test the new scheduling mechanism, execute  the minix3 test suite (/usr/src/test). Press F9 to display the queue status on tty0.

## qnt

qnt takes two parameters: the pid of a process (-p) and a new time quantum size (-q).

For instance, to increment the time quantum of cron (pid 65), use
```{bash}
# qnt -p 65 -q 23
```

Press F1 to visualize a dump of the process  table, where the *quant* field will display the change.

Note that qnt affects only user space processes (including services).

# Documentation
Comments and implementation doc are in Italian. Sorry about that.