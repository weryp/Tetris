/*
** free_all.c for free_all in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Mar  7 14:12:52 2016 Paul Wery
** Last update Sun Mar 13 01:38:08 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void	free_map(char **map)
{
  int	n;

  n = 0;
  while (map[n] != NULL)
    {
      free(map[n]);
      n += 1;
    }
  free(map);
}

void	free_tetrimino(t_obj *obj)
{
  int	n;

  n = 0;
  while (obj->tetrimino[n] != NULL)
    {
      free(obj->tetrimino[n]);
      n += 1;
    }
  free(obj->tetrimino);
}

void		free_content(t_tetris *it)
{
  t_tetris	*next;
  t_tetris	*del;

  next = it->next_form;
  free(it->name);
  free_tetrimino(&it->obj);
  while (next != it)
    {
      free_tetrimino(&next->obj);
      del = next;
      next = next->next_form;
      free(del);
    }
}

void		free_all(t_tetris *list, char **map,
			 char **color_map)
{
  t_tetris	*it;

  it = list->next;
  while (it != list)
    {
      free_content(it);
      it = it->next;
    }
  free_map(map);
  free_map(color_map);
  delete_list(&list);
}
