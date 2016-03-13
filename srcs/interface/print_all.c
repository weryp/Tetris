/*
** print_all.c for print_all in /home/hoarau/Code/PSU/PSU_2015_tetris
**
** Made by Victor Hoarau
** Login   <hoarau_v@epitech.net>
**
** Started on  Sat Mar  5 20:11:47 2016 Victor Hoarau
** Last update Sun Mar 13 18:41:42 2016 Victor Hoarau
*/

# include "print_param.h"

int	print_all(t_display_env *data, char *title)
{
  attron(COLOR_PAIR(6));
  print_title(title);
  print_state_game(data);
  print_next_tetrimino(data);
  attroff(COLOR_PAIR(6));
  return (0);
}
