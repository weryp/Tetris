/*
** tetris.h for tetris in /home/wery_p/rendu/PSU_2015_tetris/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 06:40:29 2016 Paul Wery
** Last update Mon Feb 29 15:55:39 2016 Paul Wery
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# define WIDTH_NEED (42)
# define HEIGHT_NEED (20)
# define START_INTERFACE_H (6)
# define WIDTH_TAB_SCORE (20)
# define GAP (4)

# include "print_param.h"

typedef struct	s_obj
{
  int		tetrimino;
  int		form;
  int		color;
  char		size[5];
  int		state;
}		t_obj;

typedef struct	s_tetris
{
  int		width;
  int		height;
  t_obj		obj;
}		t_tetris;

typedef struct	s_score
{
  int		time;
  int		best_player;
  int		level;
}		t_score;

#endif /* !TETRIS_H_ */
