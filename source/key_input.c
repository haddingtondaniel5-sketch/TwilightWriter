#include "../includes/twilightwriter.h"

void handle_up_key(t_c *c)
{
	if (c->vis_y == YOFFSET && c->scroll_offset != 0)
		c->scroll_offset -= 1;
	if (c->vis_y > YOFFSET)
		c->vis_y -= 1;
}
void handle_down_key(t_c *c)
{
	if (c->vis_y == c->max_y - 1)
		c->scroll_offset += 1;
	if (c->vis_y < c->max_y - 1)
		c->vis_y += 1;
}
void handle_right_key(t_c *c)
{
	if (c->vis_x < c->max_x - 1)
		c->vis_x += 1;	
}
void handle_left_key(t_c *c)
{
	if (c->vis_x > XOFFSET)
		c->vis_x -= 1;	
}