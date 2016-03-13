/*
** update_display.c for tetris in /home/hoarau_v/Systeme_Unix/PSU_2015_tetris
**
** Made by victor hoarau
** Login   <hoarau_v@epitech.net>
**
** Started on  Mon Feb 29 16:17:42 2016 victor hoarau
** Last update Sun Mar 13 18:42:46 2016 Victor Hoarau
*/

# include <ncurses.h>
# include "print_param.h"

void	print_nbr(int nb, int line, int col)
{
  char	c[2];

  c[1] = '\0';
  if (nb > 9)
    print_nbr(nb / 10, line, col - 1);
  c[0] = nb % 10 + 48;
  mvprintw(line, col, c);
}

void	print_title(char *title)
{
  if (title != NULL)
    mvprintw(0, 0, title);
  else
    mvprintw(0, 0, "TETRIS");
}

void	print_state_game(t_display_env *data)
{
  int	line;
  int	col;

  line = (LINES / 2) - 6;
  col = (COLS / 2) - ((data->ev->cols + 2 + 26 + data->ev->m_w) / 2);
  mvprintw(line + 0, col, "/------------------\\");
  mvprintw(line + 1, col, "|                  |");
  print_score(data, line, col);
  mvprintw(line + 4, col, "|                  |");
  mvprintw(line + 5, col, "|                  |");
  print_level(data, line, col);
  mvprintw(line + 7, col, "|                  |");
  print_timer(line, col);
  mvprintw(line + 9, col, "|                  |");
  mvprintw(line + 10, col, "\\------------------/");
}
