#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |S_IROTH | S_IWOTH)

int main(int argc, char *argv[])
{
	umask(0);
	if (creat("foo", RWRWRW) < 0)
		perror(argv[0]);	

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (creat("bar", RWRWRW) < 0)
		perror(argv[0]);

	return 0;
}
