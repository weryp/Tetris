/*
** debug_next.c for debug_next.c in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Mar  7 02:45:29 2016 Paul Wery
** Last update Sun Mar 13 00:19:32 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void	aff_name(char *name)
{
  int	n;

  n = 0;
  while (name[n] != '.' && name[n] != '\0')
    {
      write(1, &name[n], 1);
      n += 1;
    }
}

void	delete_elem(t_tetris *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free_content(elem);
  free(elem);
}

void		exchange_elems(t_tetris *elem_one,
			       t_tetris *elem_two)
{
  t_tetris	*it;

  it = elem_one;
  elem_one->prev->next = elem_two;
  elem_two->next->prev = elem_one;
  elem_one->next = elem_two->next;
  elem_two->prev = it->prev;
  elem_one->prev = elem_two;
  elem_two->next = elem_one;
}

int	asc_order(char *name_one, char *name_two)
{
  int	n;

  n = 0;
  while (name_one[n] == name_two[n] &&
	 name_one[n] != '\0' && name_two[n] != '\0')
    n += 1;
  if (name_one[n] > name_two[n])
    return (1);
  return (0);
}

void		put_in_order(t_tetris *list)
{
  t_tetris	*it;
  int		not_yet;

  not_yet = 1;
  while (not_yet == 1)
    {
      not_yet = 0;
      it = list->next;
      while (it != list && it->next != list)
	{
	  if (asc_order(it->name, it->next->name) == 1)
	    {
	      exchange_elems(it, it->next);
	      not_yet = 1;
	    }
	  it = it->next;
	}
    }
}
