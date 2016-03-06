/*
** ini_game.c for ini_game in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 03:56:19 2016 Paul Wery
** Last update Sun Mar  6 01:16:54 2016 Paul Wery
*/

#include <curses.h>
#include "tetris.h"

int	debug(t_events *ev UNUSED, char *param UNUSED, char *content UNUSED)
{
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
      params[9] = size_map;;
      params[10] = '\0';
      if (fonc != -1)
	(*params[fonc])(ev, av[n], av[n + 1]);
      n += 1;
    }
}

void	ini_game(t_events *ev)
{
  ev->level = 1;
  ev->key_left = KEY_LEFT;
  ev->key_right = KEY_RIGHT;
  ev->key_turn = KEY_UP;
  ev->key_drop = KEY_DOWN;
  ev->key_quit = 27;
  ev->key_pause = 32;
  ev->lines = 20;
  ev->cols = 10;
  ev->hide_tet = 0;
}
