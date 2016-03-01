/*
** create_form_tetriminos.c for create_form_tetriminos in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Mar  1 06:23:37 2016 Paul Wery
** Last update Wed Mar  2 00:08:22 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

char	**create_tetrimino_two(t_obj *obj, int x, int y)
{
  char	**tetrimino;

  if ((tetrimino = malloc(sizeof(char*) * (obj->height + 1))) == NULL)
    return (NULL);
  while (y < obj->height)
    {
      x = 0;
      if ((tetrimino[y] = malloc(obj->width + 2)) == NULL)
        return (NULL);
      while (x < obj->width)
	{
	  tetrimino[y][x] = obj->tetrimino[obj->width - 1 - x][y];
	  x += 1;
	}
      tetrimino[y][x++] = '\n';
      tetrimino[y][x++] = '\0';
      y += 1;
    }
  tetrimino[y] = NULL;
  return (tetrimino);
}

char	**create_tetrimino_three(t_obj *obj, int x, int y)
{
  char	**tetrimino;

  if ((tetrimino = malloc(sizeof(char*) * (obj->height + 1))) == NULL)
    return (NULL);
  while (y < obj->height)
    {
      x = 0;
      if ((tetrimino[y] = malloc(obj->width + 2)) == NULL)
        return (NULL);
      while (x < obj->width)
	{
	  tetrimino[y][x] = obj->tetrimino[obj->height - 1 - y]
	    [obj->width - 1 - x];
	  x += 1;
	}
      tetrimino[y][x++] = '\n';
      tetrimino[y][x++] = '\0';
      y += 1;
    }
  tetrimino[y] = NULL;
  return (tetrimino);
}

char	**create_tetrimino_fourth(t_obj *obj, int x, int y)
{
  char	**tetrimino;

  if ((tetrimino = malloc(sizeof(char*) * (obj->height + 1))) == NULL)
    return (NULL);
  while (y < obj->height)
    {
      x = 0;
      if ((tetrimino[y] = malloc(obj->width + 2)) == NULL)
        return (NULL);
      while (x <  obj->width)
	{
	  tetrimino[y][x] = obj->tetrimino[x][obj->height - 1 - y];
	  x += 1;
	}
      tetrimino[y][x++] = '\n';
      tetrimino[y][x++] = '\0';
      y += 1;
    }
  tetrimino[y] = NULL;
  return (tetrimino);
}

int	load_obj_form(t_obj *obj, int form)
{
  int	save;

  save = obj->width;
  obj->width = obj->height;
  obj->height = save;
  obj->form = form;
  obj->state = 0;
  return (0);
}

int	create_others_forms(t_tetris *list, t_obj *obj)
{
  char	**tetrimino;

  load_obj_form(obj, 4);
  if ((tetrimino =
       create_tetrimino_fourth(obj, 0, 0)) == NULL)
    return (-1);
  add_next_form(list->next, obj, tetrimino);
  load_obj_form(obj, 3);
  if ((tetrimino =
       create_tetrimino_three(obj, 0, 0)) == NULL)
    return (-1);
  add_next_form(list->next, obj, tetrimino);
  load_obj_form(obj, 2);
  if ((tetrimino =
       create_tetrimino_two(obj, 0, 0)) == NULL)
    return (-1);
  add_next_form(list->next, obj, tetrimino);
  return (0);
}
