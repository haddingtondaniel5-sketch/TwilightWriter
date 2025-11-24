# include "../includes/twilightwriter.h"

unsigned long check_line_length(t_c *c)
{
	unsigned long line = 0;
	unsigned long i = 0;
	unsigned long length = 0;

	while (c->buffer[i] && line < c->current_line)
	{
		if (c->buffer[i] == '\n')
			line += 1;
		i += 1;
	}
	while (c->buffer[i] && c->buffer[i] != '\n')
	{
		length += 1;
		i += 1;
	}
	return (length);
}