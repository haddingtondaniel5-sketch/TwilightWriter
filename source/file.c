# include "../includes/twilightwriter.h"


char *open_file(char *filename)
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

int save_file(t_c *c, const char *filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    ssize_t bytes = write(fd, c->buffer, c->buffer_length);
    if (bytes < 0) {
        perror("write");
        close(fd);
        return -1;
    }

    // Optional: ensure full write
    if ((size_t)bytes != c->buffer_length) {
        fprintf(stderr, "Partial write\n");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}