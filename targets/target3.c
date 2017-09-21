#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(char *arg)
{
	char buf[236];
	char temp;
	unsigned int i;
	snprintf(buf, sizeof buf, arg);
/*	
	for(i=1;i<100;i++){
		 if((&arg+4*i) == "%08x")break;
	}

	if(i==100)printf("Failed to find the value");
*/
	
//	printf(buf);
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s STRING\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	foo(argv[1]);

	return 0;
}
