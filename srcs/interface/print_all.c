/*
** print_all.c for print_all in /home/hoarau/Code/PSU/PSU_2015_tetris
**
** Made by hoarau
** Login   <hoarau_v@epitech.net>
**
** Started on  Sat Mar  5 20:11:47 2016 hoarau
** Last update Sun Mar  6 02:39:33 2016 Paul Wery
*/

# include "print_param.h"

t_pos	update_term_size(WINDOW *term)
{
  t_pos	result;

  getmaxyx(term, result.y, result.x);
  return (result);
}

void	set_poses(t_display_game_param *data)
{
  data->title.pos.x = TITLE_POSX(data);
  data->title.pos.y = TITLE_POSY(data);
  data->scorebox.pos.x = SCOREBOX_POSX(data);
  data->scorebox.pos.y = SCOREBOX_POSY(data);
  data->nextbox.pos.x = NEXTBOX_POSX(data);
  data->nextbox.pos.y = NEXTBOX_POSy(data);
}

int	print_all(t_display_game_param *data)
{
  data->term_size = update_term_size(data->term);
  if (data->term_size.x < T_MIN_WIDTH || data->term_size.y < T_MIN_HEIGHT)
    return (-1);
  set_poses(data);
  print_scorebox(data);
  print_nextbox(data);
  print_title(data);
  return (0);
}
