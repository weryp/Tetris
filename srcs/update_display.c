/*
** update_display.c for tetris in /home/hoarau_v/Systeme_Unix/PSU_2015_tetris
** 
** Made by victor hoarau
** Login   <hoarau_v@epitech.net>
** 
** Started on  Mon Feb 29 16:17:42 2016 victor hoarau
** Last update Mon Feb 29 22:27:40 2016 victor hoarau
*/

# include "tetris.h"

void	print_title(t_title *title)
{
  my_putstr_pos(title->title, title->pos);
}

void	print_scorebox(t_scorebox *scorebox)
{
  t_pos	textpos;

  textpos.x = scorebox->pos.x + 2;
  textpos.y = scorebox->pos.y + 4;
  my_draw_ascii_rectangle_pos(scorebox->pos, scorebox->size);
  print_time(scorebox->time, scorebox->pos, scorebox->size);
  textpos.y += 2;
  my_putstr_pos_max("Your Score :", textpos, scorebox->size);
  textpos.y += 2;
  my_putstr_pos_max("Best Score :", textpos, scorebox->size);
  textpos.y += 2;
  my_putstr_pos_max("Time :", textpos, scorebox->size);
  textpos.x = scorebox->pos.x + scorebox->size.x - MAX_SCORE_SIZE - 2;
  textpos.y = scorebox->pos.y + 6;
  my_putnbr_pos_max(scorebox->player_score, textpos, scorebox->size);
  textpos.y += 2;
  my_putnbr_pos_max(scorebox->best_score, textpos, scorebox->size);
  textpos.y += 2;
  my_putnbr_pos_max(scorebox->time, textpos, scorebox->size);
}

void	print_

int	update_display_game(t_display_game_param *param)
{
  if (check_terminal_size(param))
    return (-1);
  print_title(&param->title);
  print_scorebox(&param->scorebox);
  print_nextbox(&param->nextbox);
  return (0);
}
