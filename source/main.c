# include "../includes/twilightwriter.h"

void init_c(t_c *c)
{

	if (!c->filename)
	{
		c->buffer = malloc(INIT_BUFFER_SIZE);
		c->buffer[0] = 0;
		c->buffer_length = INIT_BUFFER_SIZE;
	} else {
		c->buffer = open_file(c->filename);
		c->buffer_length = strlen(c->buffer);
	}

	c->vis_x = XOFFSET;
	c->vis_y = YOFFSET;
	c->scroll_yoffset = 0;
	c->scroll_xoffset = 0;
	c->current_line = 0;
	c->current_line_length = check_line_length(c);


	long long i = 0;
	c->line_count = 1;
	while (c->buffer[i])
	{
		if (c->buffer[i] == '\n')
			c->line_count += 1;
		i += 1;
	}
}

int main(int argc, char **argv)
{
	if (argc)
	{
		t_c *c = malloc(sizeof(t_c));
		c->filename = strdup(argv[1]);
		init_c(c);

		// Initialise raw keyboard input and color formatting for ncurses
		initscr();
		raw();
		keypad(stdscr, TRUE);
		noecho();
		start_color();
		init_pair(1, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_BLACK, COLOR_GREEN);
		// ----



		while(1)
		{
			clear();
			getmaxyx(stdscr, c->max_y, c->max_x);
			c->current_line_length = check_line_length(c);
			draw_buffer(c);
			draw_pane(c->max_y, c->max_x);
			attron(COLOR_PAIR(2));
			// mvprintw(c->vis_y, c->vis_x, "%d", c->scroll_xoffset);
			move(c->vis_y, c->vis_x);
			refresh();

			int key = getch();
			if (key == CTRLX) { break; } // quit
			else if (key == CTRLS) { save_file(c, c->filename); }
			else if (key == KEY_UP) { handle_up_key(c); }
			else if (key == KEY_DOWN) { handle_down_key(c); }
			else if (key == KEY_RIGHT) { handle_right_key(c); }
			else if (key == KEY_LEFT) { handle_left_key(c); }
			else if (isprint(key)) { handle_character_key(c, key); }
			else if (key == '\n') { handle_return_key(c); }
		}
		



		endwin();	
	}

}