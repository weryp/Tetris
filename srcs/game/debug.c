/*
** debug.c for debug in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Mar  7 02:18:09 2016 Paul Wery
** Last update Fri Mar 11 23:58:21 2016 Paul Wery
*/

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "tetris.h"

void	my_putnbr(int nb)
{
  int	c;

  if (nb > 9)
    my_putnbr(nb / 10);
  c = nb % 10 + 48;
  write(1, &c, 1);
}

void			wait_input(void)
{
  char			key[1];
  struct termios	term;

  key[0] = '\0';
  if (ioctl(0, TCGETS, &term) == -1)
    return ;
  term.c_lflag &= ~ICANON;
  if (ioctl(0, TCSETS, &term) == -1)
    return ;
  if (read(0, key, 1) == -1)
    return ;
  if (ioctl(0, TCGETS, &term) == -1)
    return ;
  term.c_lflag = 35387;
  if (ioctl(0, TCSETS, &term) == -1)
    return ;
}

void		debug_end(t_tetris *list, int n)
{
  t_tetris	*it;
  t_tetris	*next;

  it = list->next;
  my_putstr("Tetriminos : ");
  my_putnbr(n);
  my_putstr("\n");
  while (it != list)
    {
      next = it->next;
      my_putstr("Tetriminos : Name ");
      aff_name(it->name);
      my_putstr(" : ");
      debug_tetrimino(it);
      it = next;
    }
  my_putstr("Press a key to start Tetris\n");
  wait_input();
}

void		debug_next(t_events *ev, t_tetris *list)
{
  t_tetris	*it;
  int		n;

  n = 0;
  it = list->next;
  my_putstr("Next : ");
  if (ev->hide_tet == 0)
    my_putstr("Yes\n");
  else
    my_putstr("No\n");
  my_putstr("Level : ");
  my_putnbr(ev->level);
  my_putstr("\n");
  my_putstr("Size : ");
  my_putnbr(ev->lines);
  my_putstr("*");
  my_putnbr(ev->cols);
  my_putstr("\n");
  while (it != list)
    {
      it = it->next;
      n += 1;
    }
  debug_end(list, n);
}

void	start_debug(t_events *ev, t_tetris *list)
{
  if (ev->debug == 1)
    {
      my_putstr("*** DEBUG MODE ***\n");
      my_putstr("Key Left : ");
      str_debug(ev->key_left);
      my_putstr("\n");
      my_putstr("Key Right : ");
      str_debug(ev->key_right);
      my_putstr("\n");
      my_putstr("Key Turn : ");
      str_debug(ev->key_turn);
      my_putstr("\n");
      my_putstr("Key Drop : ");
      str_debug(ev->key_drop);
      my_putstr("\n");
      my_putstr("Key Quit : ");
      str_debug(ev->key_quit);
      my_putstr("\n");
      my_putstr("Key Pause : ");
      str_debug(ev->key_pause);
      my_putstr("\n");
      debug_next(ev, list);
    }
}
