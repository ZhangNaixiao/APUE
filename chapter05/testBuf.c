#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE 1024

int main()
{
	struct timeval t_start, t_end;

	gettimeofday(&t_start, NULL);

	char buf[MAX_LINE] = "goodbyte not good bye";	
	if (fwrite(buf, sizeof(char), strlen(buf), stdout) < 0) {
		perror("this");	
	}
	
	sleep(10);	
	printf("Now:%ld us", t_start.tv_usec);

	if (fread(buf, sizeof(buf), 10, stdin) < 0) {
		perror("this");
	}
	
	gettimeofday(&t_end, NULL);

	printf("Now:%ld us", t_end.tv_usec);
}