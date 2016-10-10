#include <fcntl.h>
#include <asm/types.h>
#include <stdio.h>

int main(void)
{
 	int fd = NULL;
	fd = open("/dev/pdtest",O_WRONLY);	
	printf("hi!\n");
	return 0;
}
