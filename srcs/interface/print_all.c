/*
** print_all.c for print_all in /home/hoarau/Code/PSU/PSU_2015_tetris
**
** Made by hoarau
** Login   <hoarau_v@epitech.net>
**
** Started on  Sat Mar  5 20:11:47 2016 hoarau
** Last update Sat Mar 12 22:44:49 2016 Paul Wery
*/

# include "print_param.h"

int	print_all(t_display_env *data)
{
  attron(COLOR_PAIR(6));
  print_title();
  print_state_game(data);
  print_next_tetrimino(data);
  attroff(COLOR_PAIR(6));
  return (0);
}
