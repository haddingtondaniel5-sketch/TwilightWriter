# include "../includes/twilightwriter.h"

size_t check_line_length(t_c *c)
{
	size_t line = 0;
	size_t i = 0;
	size_t length = 0;

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