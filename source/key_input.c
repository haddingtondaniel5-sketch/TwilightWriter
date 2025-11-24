#include "../includes/twilightwriter.h"



void handle_up_key(t_c *c)
{
	if (c->vis_y == YOFFSET && c->scroll_yoffset != 0)
		c->scroll_yoffset -= 1;
	if (c->vis_y > YOFFSET)
		c->vis_y -= 1;
	if (c->current_line != 0)
	{
		c->current_line -= 1;
		c->current_line_length =  check_line_length(c);
	}
		
	

}
void handle_down_key(t_c *c)
{
	if (c->current_line < c->line_count)
	{
		c->current_line += 1;
		c->current_line_length = check_line_length(c);
		if (c->vis_x > c->current_line_length && c->vis_x < c->max_x - 1)
		{
			c->vis_x = c->current_line_length;
		} 
	} else return ;
		
	if (c->vis_y == c->max_y - 1)
		c->scroll_yoffset += 1;
	if (c->vis_y < c->max_y - 1)
		c->vis_y += 1;
}



void handle_right_key(t_c *c)
{
	
	if (c->vis_x < c->current_line_length)
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