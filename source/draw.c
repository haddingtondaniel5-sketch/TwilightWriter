# include "../includes/twilightwriter.h"

void draw_pane(int max_y, int max_x)
{
	unsigned short x = 1;
	unsigned short y = 1;

	attron(COLOR_PAIR(2));
	mvprintw(0, 0, "C");
	

	while (x < max_x) { mvprintw(0, x, "-"); x += 1; }
	while (y < max_y) { mvprintw(y, 0, "|"); y += 1; }
	mvprintw(0, (max_x / 2) - 14 , "TwilightWriter");
}

void draw_buffer(t_c *c)
{
	unsigned long i = 0;
	unsigned short vis_y = YOFFSET;
	unsigned short vis_x = XOFFSET;


	attron(COLOR_PAIR(1));

	while (i < c->buffer_length)
	{

		mvaddch(vis_y - c->scroll_offset, vis_x, c->buffer[i]);
		if (c->buffer[i] == '\n')
		{

			vis_x = XOFFSET;
			vis_y += 1;
		}
		else 
			vis_x += 1;
		
		i += 1;
	}

}