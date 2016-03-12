/*
** ini_game.c for ini_game in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 03:56:19 2016 Paul Wery
** Last update Fri Mar 11 22:31:20 2016 Paul Wery
*/

#include "tetris.h"
#include <unistd.h>

void	ini_key(char *key)
{
  int	n;

  while (n < 5)
    {
      key[n] = '\0';
      n += 1;
    }
}

int	debug(t_events *ev, char *param UNUSED, char *content UNUSED)
{
  ev->debug = 1;
  return (0);
}

void	load_params_tetris(t_events *ev, char **av)
{
  int	(*params[11])(t_events*, char*, char*);
  int	fonc;
  int	n;

  n = 1;
  while (av[n] != NULL)
    {
      fonc = opt(av[n], "-l;--level=;-kl;--key-left=;-kr;--key-right=;",
		 "-kt;--key-turn=;-kd;--key-drop=;-kq;--key-quit=;",
		 "-kp;--key-pause=;-w;--without-next;-d;--debug;--map-size=;");
      params[0] = level;
      params[1] = key_left;
      params[2] = key_right;
      params[3] = key_turn;
      params[4] = key_drop;
      params[5] = key_quit;
      params[6] = key_pause;
      params[7] = hide_tet;
      params[8] = debug;
      params[9] = size_map;
      params[10] = '\0';
      if (fonc != -1)
	(*params[fonc])(ev, av[n], av[n + 1]);
      n += 1;
    }
}

void	copstr(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[n] != '\0' && i < 5)
    {
      dest[i] = src[n];
      i += 1;
      n += 1;
    }
  while (i < 5)
    dest[i++] = '\0';
}

void	ini_game(t_events *ev, t_term_num *num)
{
  ev->level = 1;
  copstr(ev->key_left, num->kl, 0);
  copstr(ev->key_right, num->kr, 0);
  copstr(ev->key_turn, num->ku, 0);
  copstr(ev->key_drop, num->kd, 0);
  copstr(ev->key_quit, "q", 0);
  copstr(ev->key_pause, " ", 0);
  ev->lines = 20;
  ev->cols = 10;
  ev->hide_tet = 0;
  ev->debug = 0;
  ev->score = 0;
}
