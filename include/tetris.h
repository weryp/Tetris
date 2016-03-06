/*
** tetris.h for tetris in /home/wery_p/rendu/PSU_2015_tetris/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 06:40:29 2016 Paul Wery
** Last update Sun Mar  6 02:10:08 2016 Paul Wery
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# define WIDTH_NEED (48)
# define HEIGHT_NEED (22)
# define START_INTERFACE_H (6)
# define WIDTH_TAB_SCORE (20)
# define GAP (4)

# define UNUSED __attribute__((unused))

# include <sys/stat.h>
# include "print_param.h"

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
  int		key;
  int		form;
  int		nb_tet;
  int		tet_start;
  int		tetrimino;
  int		time_end;
  int		height_time;
  float		level;
  int		key_left;
  int		key_right;
  int		key_turn;
  int		key_drop;
  int		key_quit;
  int		key_pause;
  int		lines;
  int		cols;
  int		hide_tet;
}		t_events;

typedef struct	s_score
{
  int		time;
  int		best_player;
  int		level;
}		t_score;

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
void		clear_tetrimino(char **map, t_start_pos *pos, t_obj *obj);
int		moove_tetrimino(char **map, t_tetris *list,
				t_events *ev, int turn);
void		ini_events(t_events *ev, t_tetris *list);
int		moove_tetrimino_next(char **map, t_events *ev,
				     t_tetris *list);
int		change_form(char **map, t_tetris *it,
			    t_start_pos *pos, t_events *ev);
int		error_size(t_events *ev);
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
void		ini_game(t_events *ev);
void		load_params_tetris(t_events *ev, char **av);
int		opt(char *str, char *src_one,
		    char *src_two, char *src_three);

#endif /* !TETRIS_H_ */
