# include "../includes/twilightwriter.h"


char *open_file(t_c *c, char *filename)
{
	int fd = open(filename, O_RDWR | O_CREAT, 0644);
	if (fd == -1) {
		perror("open");
		return NULL;
	}


	off_t size = lseek(fd, 0, SEEK_END);
	if (size == -1) {
		perror("lseek");
		close(fd);
		return NULL;
	}


	char *buffer = malloc(size + 1);
	if (!buffer) {
		perror("malloc");
		close(fd);
		return NULL;
    }


	lseek(fd, 0, SEEK_SET);
	ssize_t bytes = read(fd, buffer, size);
	if (bytes < 0) {
		perror("read");
		free(buffer);
		close(fd);
		return NULL;
	}

	buffer[bytes] = '\0';
	close(fd);

	return buffer;
}