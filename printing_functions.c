/*
** printing_functions.c for tetris in /home/hoarau_v/Systeme_Unix/PSU_2015_tetris
**
** Made by victor hoarau
** Login   <hoarau_v@epitech.net>
**
** Started on  Mon Feb 29 18:40:00 2016 victor hoarau
** Last update Wed Mar  2 12:54:42 2016 Paul Wery
*/

# include "tetris.h"

void	my_putchar_pos(char c, t_pos pos)
{
  mvaddch(pos.y, pos.x, c);
}

void	my_putstr_pos_max(char *str, t_pos pos,
			  t_pos max, WINDOW *new_win)
{
  t_pos	i;
  t_pos	protect;
  int	j;

  j = 0;
  i.y = pos.y;
  getmaxyx(new_win, protect.x, protect.y);
  max.x = (max.x > protect.x) ? protect.x : max.x;
  max.y = (max.y > protect.y) ? protect.y : max.y;
  while (i.y < max.y && str[j] != '\0')
    {
      i.x = pos.x;
      while (i.x < max.s && str[j] != '\0')
	{
	  my_putchar_pos(str[j++], i);
	  i.x += 1;
	}
      i.y += 1;
    }
}
