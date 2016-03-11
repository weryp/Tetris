/*
** load_obj.c for load_obj in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 23:29:59 2016 Paul Wery
** Last update Fri Mar 11 17:05:50 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

char	**create_tetrimino(char *buffer, t_obj *obj, int x, int y)
{
  char	**tetrimino;
  int	n;

  n = 0;
  if ((tetrimino = malloc(sizeof(char*) * (obj->height + 1))) == NULL)
    return (NULL);
  while (buffer[n] != '\n' && buffer[n] != '\0')
    n += 1;
  n += 1;
  while (y < obj->height)
    {
      x = 0;
      if ((tetrimino[y] = malloc(obj->width + 2)) == NULL)
	return (NULL);
      while (x < obj->width && buffer[n] != '\0')
	if (buffer[n] != '\n')
	  tetrimino[y][x++] = buffer[n++];
	else
	  tetrimino[y][x++] = ' ';
      tetrimino[y][x++] = buffer[n++];
      tetrimino[y][x++] = '\0';
      y += 1;
    }
  tetrimino[y] = NULL;
  return (tetrimino);
}

int	load_obj(char *buffer, t_obj *obj)
{
  int	nb;

  if ((nb = get_params(buffer, 1)) == -1)
    return (-1);
  obj->width = nb;
  if ((nb = get_params(buffer, 2)) == -1)
    return (-1);
  obj->height = nb;
  if ((nb = get_params(buffer, 3)) == -1)
    return (-1);
  if (nb < 1 || nb > 7)
    obj->color = (rand() % 6) + 1;
  else
    obj->color = nb;
  obj->form = 1;
  obj->state = 0;
  return (0);
}

int	load_objs(char *buffer, char *name, t_tetris *list)
{
  t_obj	obj;
  char	*name_tet;

  if (load_obj(buffer, &obj) == -1)
    return (-1);
  if ((name_tet = malloc(my_strlen(name) + 1)) == NULL)
    return (-1);
  name_tet[my_strlen(name)] = '\0';
  cop_string(name_tet, name);
  obj.tetrimino = NULL;
  if ((obj.tetrimino = create_tetrimino(buffer, &obj, 0, 0)) == NULL)
    return (-1);
  if (add_elem_next(list, name_tet, &obj) == -1)
    return (-1);
  if (create_others_forms(list, &obj) == -1)
    return (-1);
  return (0);
}
