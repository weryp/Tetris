/*
** display_env.c for display_env in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Apr  2 20:02:13 2016 Paul Wery
** Last update Sat Apr  2 20:14:32 2016 Paul Wery
*/

#include <stdlib.h>
#include <ncurses.h>
#include "print_param.h"

void	print_nbr(int nb, int line, int col)
{
  char	c[2];

  c[1] = '\0';
  if (nb > 9)
    print_nbr(nb / 10, line, col - 1);
  c[0] = nb % 10 + 48;
  mvprintw(line, col, c);
}

void	print_header(char *header)
{
  if (header != NULL)
    {
      mvprintw(0, 0, header);
      free(header);
    }
  else
    mvprintw(0, 0, "TETRIS");
}

void	print_state_game(t_display_env *data)
{
  int	line;
  int	col;

  line = (LINES / 2) - 6;
  col = (COLS / 2) - ((data->ev->cols + 2 + 26 + data->ev->m_w) / 2);
  mvprintw(line + 0, col, STATE_GAME_TOP_BOX);
  mvprintw(line + 1, col, STATE_GAME_M_BOX);
  print_score(data, line, col);
  mvprintw(line + 4, col, STATE_GAME_M_BOX);
  mvprintw(line + 5, col, STATE_GAME_M_BOX);
  print_level(data, line, col);
  mvprintw(line + 7, col, STATE_GAME_M_BOX);
  print_timer(line, col);
  mvprintw(line + 9, col, STATE_GAME_M_BOX);
  mvprintw(line + 10, col, STATE_GAME_TOP_BOX);
}
