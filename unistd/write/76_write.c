#include <unistd.h> // write and datatype ssize_t  things.
#include <stdio.h> // perror
#include <sys/stat.h> 
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h> // error constant variable
int main (void)
{
	unsigned long word; /* 8 byte */
	size_t count; // unsigned, measure size by byte.
	ssize_t nr; // signed, measure size by byte, to capture err like -1
	extern int errno;
	int fd;
	/*
	 * size_t maximum value is SIZE_MAX
	 * ssize_t maximum value is SSIZE_MAX(usually LONG_MAX, 0x7ffffffff in 32bit system)
	 */

	word = 1720;
	count = sizeof (word);
	fd = open("/Users/jihhan/projects/repos/my_origin/c_pracs/unistd/write/writeable.txt", O_WRONLY);
	char fd_val;
	fd_val = fd+48;
	write(1, &fd_val, 1);
	while ((nr = write(fd, &word, count)) < 0)
	{
		const int err = errno;
		switch (err)
		{
			case EBADF:
				perror("fd not valid or no priviledges to write.");
				break;
			case EFAULT:
				perror("buf pointer not valid in process.");
				break;
			case EFBIG:
				perror("write size is restricted by os.");
				break;
			case EINVAL:
				perror("fd not unwritable object.");
				break;
			case EIO:
				perror("lowlevel IO error.");
				break;
			case ENOSPC:
				perror("FS in fd has no space.");
				break;
			case EPIPE:
				perror("fd piped with socket");
				break;
		}
		break;
	}
	if (close(fd) == -1)
		perror("close error!");
}
