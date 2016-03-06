/*
** params_one.c for params_one in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 04:06:36 2016 Paul Wery
** Last update Sun Mar  6 00:58:55 2016 Paul Wery
*/

#include <curses.h>
#include "tetris.h"

int	key_drop(t_events *ev, char *param, char *content)
{
  int	n;
  int	i;

  n = 0;
  i = 0;
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (content != NULL && param[n] == '\0' && content[1] == '\0')
    ev->key_drop = content[0];
  else if (param[n] != '\0')
    {
      while (param[n] != '\0')
	{
	  n += 1;
	  i += 1;
	}
      if (i != 2)
	return (-1);
      ev->key_drop = param[n - 1];
    }
  else if (param[n] == '\0' && content != NULL && content[1] != '\0')
    return (-1);
  return (0);
}

int	key_turn(t_events *ev, char *param, char *content)
{
  int	n;
  int	i;

  n = 0;
  i = 0;
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (content != NULL && param[n] == '\0' && content[1] == '\0')
    ev->key_turn = content[0];
  else if (param[n] != '\0')
    {
      while (param[n] != '\0')
	{
	  n += 1;
	  i += 1;
	}
      if (i != 2)
	return (-1);
      ev->key_turn = param[n - 1];
    }
  else if (param[n] == '\0' && content != NULL && content[1] != '\0')
    return (-1);
  return (0);
}

int	key_right(t_events *ev, char *param, char *content)
{
  int	n;
  int	i;

  n = 0;
  i = 0;
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (content != NULL && param[n] == '\0' && content[1] == '\0')
    ev->key_right = content[0];
  else if (param[n] != '\0')
    {
      while (param[n] != '\0')
	{
	  n += 1;
	  i += 1;
	}
      if (i != 2)
	return (-1);
      ev->key_right = param[n - 1];
    }
  else if (param[n] == '\0' && content != NULL && content[1] != '\0')
    return (-1);
  return (0);
}

int	key_left(t_events *ev, char *param, char *content)
{
  int	n;
  int	i;

  n = 0;
  i = 0;
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (content != NULL && param[n] == '\0' && content[1] == '\0')
    ev->key_left = content[0];
  else if (param[n] != '\0')
    {
      while (param[n] != '\0')
	{
	  n += 1;
	  i += 1;
	}
      if (i != 2)
	return (-1);
      ev->key_left = param[n - 1];
    }
  else if (param[n] == '\0' && content != NULL && content[1] != '\0')
    return (-1);
  return (0);
}

int	level(t_events *ev, char *param, char *content)
{
  int	n;
  int	ret;

  n = 0;
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (param[n] == '\0' && content != NULL)
    ret = get_nb(content, 1, 0);
  else
    ret = get_nb(param, 1, n + 1);
  if (ret == -1)
    return (-1);
  ev->level = ret;
  return (0);
}
