/*
** print_all.c for print_all in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Apr  2 20:01:48 2016 Paul Wery
** Last update Sat Apr  2 20:15:13 2016 Paul Wery
*/

#include "print_param.h"

int		print_all(t_display_env *data, char *header)
{
  static int	turn = 0;

  attron(COLOR_PAIR(6));
  if (turn == 0)
    print_header(header);
  print_state_game(data);
  if (data->ev->hide_tet == 0)
    print_next_tetrimino(data);
  attroff(COLOR_PAIR(6));
  turn = 1;
  return (0);
}
