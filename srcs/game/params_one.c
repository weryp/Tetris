/*
** params_one.c for params_one in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 04:06:36 2016 Paul Wery
** Last update Tue Mar 15 23:28:36 2016 Paul Wery
*/

#include <ncurses.h>
#include "tetris.h"

int		key_drop(t_events *ev, char *param, char *content)
{
  static int	turn = 0;
  int		n;

  n = 0;
  if (turn == 1)
    return (-1);
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (param[n] == '\0' && content == NULL)
    return (-1);
  if (content != NULL && param[n] == '\0')
    copstr(ev->key_drop, content, 0);
  else
    {
      if (param[n] != '\0' && param[n + 1] != '\0')
	n += 1;
      else
	return (-1);
      copstr(ev->key_drop, param, n);
    }
  turn = 1;
  return (0);
}

int		key_turn(t_events *ev, char *param, char *content)
{
  static int	turn = 0;
  int		n;

  n = 0;
  if (turn == 1)
    return (-1);
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (param[n] == '\0' && content == NULL)
    return (-1);
  if (content != NULL && param[n] == '\0')
    copstr(ev->key_turn, content, 0);
  else
    {
      if (param[n] != '\0' && param[n + 1] != '\0')
	n += 1;
      else
	return (-1);
      copstr(ev->key_turn, param, n);
    }
  turn = 1;
  return (0);
}

int		key_right(t_events *ev, char *param, char *content)
{
  static int	turn = 0;
  int		n;

  n = 0;
  if (turn == 1)
    return (-1);
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (param[n] == '\0' && content == NULL)
    return (-1);
  if (content != NULL && param[n] == '\0')
    copstr(ev->key_right, content, 0);
  else
    {
      if (param[n] != '\0' && param[n + 1] != '\0')
	n += 1;
      else
	return (-1);
      copstr(ev->key_right, param, n);
    }
  turn = 1;
  return (0);
}

int		key_left(t_events *ev, char *param, char *content)
{
  static int	turn = 0;
  int		n;

  n = 0;
  if (turn == 1)
    return (-1);
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (param[n] == '\0' && content == NULL)
    return (-1);
  if (content != NULL && param[n] == '\0')
    copstr(ev->key_left, content, 0);
  else
    {
      if (param[n] != '\0' && param[n + 1] != '\0')
	n += 1;
      else
	return (-1);
      copstr(ev->key_left, param, n);
    }
  return (0);
}

int		level(t_events *ev, char *param, char *content)
{
  static int	turn = 0;
  int		n;
  int		ret;

  n = 0;
  if (turn == 1)
    return (-1);
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (param[n] == '\0' && content != NULL)
    ret = get_nb(content, 1, 0);
  else
    ret = get_nb(param, 1, n + 1);
  if (ret == -1)
    return (-1);
  ev->level = ret;
  turn = 1;
  return (0);
}
