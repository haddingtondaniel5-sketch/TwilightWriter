#include "../includes/twilightwriter.h"



void handle_up_key(t_c *c)
{
	if (c->current_line != 0)
	{
		c->current_line -= 1;
		c->current_line_length =  check_line_length(c);
		if (c->vis_x > c->current_line_length && c->vis_x > XOFFSET)
		{
			c->vis_x = c->current_line_length + XOFFSET;
		} 
	} else return ;

	if (c->vis_y == YOFFSET && c->scroll_yoffset != 0)
		c->scroll_yoffset -= 1;
	if (c->vis_y > YOFFSET)
		c->vis_y -= 1;

}

void handle_down_key(t_c *c)
{
	if (c->current_line < c->line_count)
	{
		c->current_line += 1;
		c->current_line_length = check_line_length(c);
		if (c->vis_x > c->current_line_length && c->vis_x < c->max_x - 1)
		{
			c->vis_x = c->current_line_length + XOFFSET;
		} 
	} else return ;
		
	if (c->vis_y == c->max_y - 1)
		c->scroll_yoffset += 1;
	if (c->vis_y < c->max_y - 1)
		c->vis_y += 1;
}



void handle_right_key(t_c *c)
{
	
	if (c->vis_x < c->current_line_length + 2)
	{
		if (c->vis_x == c->max_x - 1)
			c->scroll_xoffset += 1;
		if (c->vis_x < c->max_x - 1)
			c->vis_x += 1;	
		
	} 

}
		
void handle_left_key(t_c *c)
{
	if (c->vis_x == XOFFSET && c->scroll_xoffset != 0)
		c->scroll_xoffset -= 1;
	if (c->vis_x > XOFFSET)
		c->vis_x -= 1;	
}

void handle_character_key(t_c *c, int key)
{
	unsigned long position = c->vis_x - c->scroll_xoffset - XOFFSET;
	unsigned long line = 0;
	unsigned long i = 0;

	c->buffer = realloc(c->buffer, c->buffer_length + 2);

	while (c->buffer[i] && line != c->current_line)
	{
		if (c->buffer[i] == '\n')
			line += 1;
		i += 1;
	}
	position += i;
	unsigned long buffer_length = c->buffer_length;
	while (buffer_length > position)
	{
		c->buffer[buffer_length] = c->buffer[buffer_length - 1];
		buffer_length -= 1;
	}
	c->buffer[position] = key;
	c->buffer_length += 1;
	c->buffer[c->buffer_length] = '\0';
	handle_right_key(c);

}

void handle_return_key(t_c *c)
{
	unsigned long position = c->vis_x - c->scroll_xoffset - XOFFSET;
	unsigned long line = 0;
	unsigned long i = 0;

	c->buffer = realloc(c->buffer, c->buffer_length + 2);

	while (c->buffer[i] && line != c->current_line)
	{
		if (c->buffer[i] == '\n')
			line += 1;
		i += 1;
	}
	position += i;
	unsigned long buffer_length = c->buffer_length;
	while (buffer_length > position)
	{
		c->buffer[buffer_length] = c->buffer[buffer_length - 1];
		buffer_length -= 1;
	}
	c->buffer[position] = '\n';
	c->buffer_length += 1;
	c->buffer[c->buffer_length] = '\0';

	c->line_count += 1;
	handle_down_key(c);
}