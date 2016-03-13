/*
** delete_errors_elems.c for delete_errors_elem in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 12 20:26:45 2016 Paul Wery
** Last update Sat Mar 12 20:32:40 2016 Paul Wery
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void	delete_error_elem(t_tetris *elem)
{
  char	*path;
  char	*buffer;
  int	fd;

  if ((path = my_path(elem->name, "tetriminos/")) == NULL)
    return ;
  if ((fd = open(path, O_RDONLY)) == -1)
    return ;
  if ((buffer = alloc_buffer(fd, path)) == NULL)
    return ;
  if (check_tet(buffer, elem, 0, 0) == -1)
    delete_elem(elem);
  free(path);
  free(buffer);
  close(fd);

}

void		delete_errors_elems(t_tetris *list)
{
  t_tetris	*it;
  t_tetris	*next;

  it = list->next;
  while (it != list)
    {
      next = it->next;
      delete_error_elem(it);
      it = next;
    }

}
