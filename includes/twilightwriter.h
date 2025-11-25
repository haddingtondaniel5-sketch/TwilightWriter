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
# define CTRLS 19
# define YOFFSET 2
# define XOFFSET 2

typedef struct s_c {
	char	*buffer;
	size_t	buffer_length;
	char	*filename;
	size_t	max_x;
	size_t	max_y;
	size_t	vis_x;
	size_t	vis_y;
	size_t	line_count;
	size_t	scroll_yoffset;
	size_t	scroll_xoffset;
	size_t	current_line;
	size_t	current_line_length;
	size_t	current_line_cursor;

} t_c;



void	init_c(t_c *c);
void	draw_pane(int max_y, int max_x);
char	*open_file(char *filename);
int 	save_file(t_c *c, const char *filename);
void	draw_buffer(t_c *c);

size_t	check_line_length(t_c *c);

void handle_up_key(t_c *c);
void handle_down_key(t_c *c);
void handle_right_key(t_c *c);
void handle_left_key(t_c *c);
void handle_character_key(t_c *c, int key);
void handle_return_key(t_c *c);
void handle_tab_key(t_c *c);
void handle_backspace_key(t_c *c);

#endif