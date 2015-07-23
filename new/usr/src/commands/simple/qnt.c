#include <minix/type.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void help(void){
	printf("\nUsage: qnt -p PID -q SIZE\n");
	printf("Help: qnt -h\n");
}

int main(int argc, char *argv[]) {

	int c;
	int qnt;
	pid_t proc;
	
	if (argc < 2) {
	  fprintf(stderr, "To few arguments provided: ");
	  fflush(stdout);
          help();
	  exit(1);
	}
	while ((c = getopt (argc, argv, "hp:q:")) != EOF)
	  switch (c) {
	  	case 'h':
			help();
			break;

		case 'p':
			proc = atoi(optarg);
			break;
		
		case 'q':
			qnt = atoi(optarg);
			break;
			
		default:
			help();
			break;
	  }
	
	if (argc > 2)
	   quantum(proc, qnt);
	
	return 0;
}
