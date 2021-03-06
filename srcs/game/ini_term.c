/*
** ini_term.c for ini_term.c in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Mar  7 17:59:56 2016 Paul Wery
** Last update Sun Mar 13 02:03:35 2016 Paul Wery
*/

#include "tetris.h"
#include <ncurses.h>
#include <term.h>
#include <unistd.h>

int	conv(char *str)
{
  int	val;
  int	n;

  val = 0;
  n = 0;
  while (str[n] != '\0')
    {
      val = (val * 10) + (str[n] - 48);
      n += 1;
    }
  return (val);

}

int	ini_term(t_term_num *num)
{
  int	ret;

  if (setupterm(NULL, 0, &ret) == -1)
    return (-1);
  num->kl = tigetstr("kcub1");
  num->kr = tigetstr("kcuf1");
  num->ku = tigetstr("kcuu1");
  num->kd = tigetstr("kcud1");
  return (0);
}
