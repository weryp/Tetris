/*
** my_list.c for my_list in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 20:51:07 2016 Paul Wery
** Last update Mon Mar  7 15:18:49 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void		empty_list(t_tetris *root)
{
  t_tetris	*it;
  t_tetris	*save;

  it = root->next;
  while (it != root)
    {
      save = it->next;
      free(it);
      it = save;
    }
}

void	delete_list(t_tetris **root)
{
  empty_list(*root);
  free(*root);
  *root = NULL;
}

int		add_next_form(t_tetris *elem, t_obj *obj,
			      char **tetrimino)
{
  t_tetris	*new_form;

  if ((new_form = malloc(sizeof(*new_form))) == NULL)
    return (-1);
  new_form->obj.width = obj->width;
  new_form->obj.height = obj->height;
  new_form->obj.color = obj->color;
  new_form->obj.tetrimino = tetrimino;
  new_form->obj.form = obj->form;
  new_form->obj.state = obj->state;
  new_form->next_form = elem->next_form;
  elem->next_form = new_form;
  return (0);
}

int		add_elem_next(t_tetris *elem, char *name, t_obj *obj)
{
  t_tetris	*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (-1);
  new_elem->name = name;
  new_elem->obj.width = obj->width;
  new_elem->obj.height = obj->height;
  new_elem->obj.color = obj->color;
  new_elem->obj.tetrimino = obj->tetrimino;
  new_elem->obj.form = obj->form;
  new_elem->obj.state = obj->state;
  new_elem->next = elem->next;
  new_elem->prev = elem;
  elem->next->prev = new_elem;
  elem->next = new_elem;
  new_elem->next_form = new_elem;
  return (0);
}

t_tetris	*create_list(void)
{
  t_tetris	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    return (NULL);
  root->prev = root;
  root->next = root;
  root->next_form = NULL;
  return (root);
}
