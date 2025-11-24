#ifndef TWILIGHT_WRITER_H
# define TWILIGHT_WRITER_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <ncurses.h>

# define INIT_BUFFER_SIZE 1024
# define CTRLX 24
# define YOFFSET 2
# define XOFFSET 2

typedef struct s_c {
	char *buffer;
	unsigned long buffer_length;

	unsigned int max_x;
	unsigned int max_y;
	unsigned int vis_x;
	unsigned int vis_y;
	unsigned long line_count;
	unsigned long scroll_yoffset;
	unsigned long scroll_xoffset;
	unsigned long current_line;
	unsigned long current_line_length;

} t_c;



void	init_c(t_c *c, char *filename);
void	draw_pane(int max_y, int max_x);
char	*open_file(t_c *c, char *filename);
void	draw_buffer(t_c *c);

unsigned long check_line_length(t_c *c);

void handle_up_key(t_c *c);
void handle_down_key(t_c *c);
void handle_right_key(t_c *c);
void handle_left_key(t_c *c);
void handle_character_key(t_c *c);

#endif