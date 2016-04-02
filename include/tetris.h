/*
** tetris.h for tetris in /home/wery_p/rendu/PSU_2015_tetris/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 06:40:29 2016 Paul Wery
** Last update Sat Apr  2 20:13:02 2016 Paul Wery
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# define UNUSED __attribute__((unused))

# include <sys/stat.h>
# include <ncurses.h>

typedef struct dirent t_dir;
typedef struct stat t_stat;

typedef struct	s_start_pos
{
  int		start_x;
  int		start_y;
  int		end_x;
  int		end_y;
}		t_start_pos;

typedef struct	s_obj
{
  int		width;
  int		height;
  int		color;
  char		**tetrimino;
  int		form;
  int		state;
}		t_obj;

typedef struct		s_tetris
{
  char			*name;
  t_obj			obj;
  struct s_tetris	*prev;
  struct s_tetris	*next;
  struct s_tetris	*next_form;
}			t_tetris;

typedef struct	s_events
{
  t_tetris	*it;
  t_start_pos	pos;
  int		form;
  int		nb_tet;
  int		tet_start;
  int		tetrimino;
  int		tet_next;
  int		time_end;
  int		height_time;
  float		level;
  int		score;
  char		key[6];
  char		key_left[6];
  char		key_right[6];
  char		key_turn[6];
  char		key_drop[6];
  char		key_quit[6];
  char		key_pause[6];
  int		lines;
  int		cols;
  int		hide_tet;
  int		debug;
  int		m_w;
  int		m_h;
  char		**color_map;
}		t_events;

typedef struct	s_co
{
  int		x;
  int		y;
  int		n;
  int		i;
}		t_co;

typedef struct	s_term_num
{
  char		*kl;
  char		*kr;
  char		*ku;
  char		*kd;
}		t_term_num;

typedef struct	s_ini
{
  t_tetris	*tet;
  t_term_num	num;
  t_events	ev;
  SCREEN	*scr;
}		t_ini;

int		get_params(char *buffer, int param);
void		cop_string(char *name, char *src);
int		my_strlen(char *str);
int		size_line(char *str, int n);
int		load_tetriminos(t_tetris *list);
int		load_objs(char *buffer, char *name, t_tetris *list);
t_tetris	*create_list(void);
int		add_elem_next(t_tetris *elem, char *name, t_obj *obj);
int		add_next_form(t_tetris *elem, t_obj *obj, char **tetrimino);
void		delete_list(t_tetris **root);
void		aff_tetrimino(char **tetrimino);
int		create_others_forms(t_tetris *list, t_obj *obj);
void		aff_map(char **map, t_events *ev);
void		ini_pos(t_start_pos *pos, t_events *ev);
int		check_moove(char **map, t_tetris *it, t_start_pos *pos);
void		clear_tetrimino(char **map, t_start_pos *pos, t_obj *obj,
				t_events *ev);
int		moove_tetrimino(char **map, t_tetris *list,
				t_events *ev, int turn);
void		ini_events(t_events *ev, t_tetris *list);
int		moove_tetrimino_next(char **map, t_events *ev,
				     t_tetris *list);
int		change_form(char **map, t_tetris *it,
			    t_start_pos *pos, t_events *ev);
int		error_size(t_events *ev, SCREEN *scr, t_tetris *list);
void		ini_colors(void);
void		aff_map_color(char **map, t_tetris *it,
			      t_start_pos *pos, t_events *ev);
void		check_border(t_start_pos *pos, t_events *ev);
int		check_change_form(t_events *ev, char **map);
int		check_side_left(t_events *ev, char **map);
int		check_side_right(t_events *ev, char **map);
void		clear_map(char **map, t_events *ev);
int		check_ext(char *file);
void		clean_line(char **map, t_events *ev);
int		end_game(char **map, t_start_pos *pos, t_obj *obj);
void		end_message(char **map, t_events *ev);
int		key_drop(t_events *ev, char *param, char *content);
int		key_turn(t_events *ev, char *param, char *content);
int		key_right(t_events *ev, char *param, char *content);
int		key_left(t_events *ev, char *param, char *content);
int		level(t_events *ev, char *param, char *content);
int		hide_tet(t_events *ev, char *param, char *content);
int		size_map(t_events *ev, char *param, char *content);
int		key_pause(t_events *ev, char *param, char *content);
int		key_quit(t_events *ev, char *param, char *content);
int		get_nb(char *str, int param, int n);
void		ini_game(t_events *ev, t_term_num *num);
int		load_params_tetris(t_events *ev, char **av, int n);
int		opt(char *str, char *src_one,
		    char *src_two, char *src_three);
void		help(int ac, char **av, int state);
void		my_putstr(char *str);
void		free_all(t_tetris *list, char **map, char **color_map);
int		ini_term(t_term_num *num);
int		cstr(char *str, char *src);
void		copstr(char *dest, char *str, int n);
int		ini_end_read(int state);
void		start_debug(t_events *ev, t_tetris *list);
char		*alloc_buffer(int fd, char *file);
void		put_in_order(t_tetris *list);
void		aff_name(char *name);
void		delete_elem(t_tetris *elem);
int		check_tet(char *buffer, t_tetris *elem,
			  int n, int nb_lines);
void		debug_tetrimino(t_tetris *elem);
void		delete_errors_elems(t_tetris *list);
char		*my_path(char *file, char *tet);
void		my_putchar(char c);
void		my_putnbr(int nb);
void		str_debug(char *str);
void		generate_tetrimino(t_events *ev);
void		free_content(t_tetris *it);
void		error_params(int ac, char **av);
int		check_fonc(int fonc, char **av, int n);
int		check_line(char *buffer, int n);
char		*realloc_w(char *str, int new_size);
int		go_point(char *file, int n);
char		*get_header(void);

# include "print_param.h"

#endif /* !TETRIS_H_ */
