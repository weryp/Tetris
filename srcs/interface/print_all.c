/*
** print_all.c for print_all in /home/hoarau/Code/PSU/PSU_2015_tetris
**
** Made by Victor Hoarau
** Login   <hoarau_v@epitech.net>
**
** Started on  Sat Mar  5 20:11:47 2016 Victor Hoarau
** Last update Sun Mar 13 22:46:43 2016 Paul Wery
*/

# include "print_param.h"

int		print_all(t_display_env *data, char *title)
{
  static int	turn = 0;

  attron(COLOR_PAIR(6));
  if (turn == 0)
    print_title(title);
  print_state_game(data);
  print_next_tetrimino(data);
  attroff(COLOR_PAIR(6));
  turn = 1;
  return (0);
}
