/*
** params_two.c for params_two in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 04:48:27 2016 Paul Wery
** Last update Sun Mar  6 01:40:21 2016 Paul Wery
*/

#include <curses.h>
#include "tetris.h"

int	get_nb(char *str, int param, int n)
{
  int	i;

  i = 0;
  param -= 1;
  if (param > 0)
    {
      while (str[n] != ',' && str[n] != '\0')
	{
	  if (str[n] > 47 && str[n] < 58)
	    n += 1;
	  else
	    return (-1);
	}
      n += 1;
    }
  while (str[n] != '\0' && str[n] != ',')
    {
      if (str[n] > 47 && str[n] < 58)
	i = (i * 10) + (str[n] - 48);
      else
	return (-1);
      n += 1;
    }
  return (i);
}

int	hide_tet(t_events *ev, char *param, char *content)
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
  ev->hide_tet = ret;
  return (0);
}

int	size_map(t_events *ev, char *param, char *content UNUSED)
{
  int	n;
  int	ret_one;
  int	ret_two;

  n = 0;
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  ret_one = get_nb(param, 1, n + 1);
  ret_two = get_nb(param, 2, n + 1);
  if (ret_one == -1 || ret_two == -1 ||
      ret_one == 0 || ret_two == 0)
    return (-1);
  ev->lines = ret_one;
  ev->cols = ret_two;
  return (0);
}

int	key_pause(t_events *ev, char *param, char *content)
{
  int	n;
  int	i;

  n = 0;
  i = 0;
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (content != NULL && param[n] == '\0' && content[1] == '\0')
    ev->key_pause = content[0];
  else if (param[n] != '\0')
    {
      while (param[n] != '\0')
	{
	  n += 1;
	  i += 1;
	}
      if (i != 2)
        return (-1);
      ev->key_pause = param[n - 1];
    }
  else if (param[n] == '\0' && content != NULL && content[1] != '\0')
    return (-1);
  return (0);
}

int	key_quit(t_events *ev, char *param, char *content)
{
  int	n;
  int	i;

  n = 0;
  i = 0;
  while (param[n] != '=' && param[n] != '\0')
    n += 1;
  if (content != NULL && param[n] == '\0' && content[1] == '\0')
    ev->key_quit = content[0];
  else if (param[n] != '\0')
    {
      while (param[n] != '\0')
	{
	  n += 1;
	  i += 1;
	}
      if (i != 2)
        return (-1);
      ev->key_quit = param[n - 1];
    }
  else if (param[n] == '\0' && content != NULL && content[1] != '\0')
    return (-1);
  return (0);
}
