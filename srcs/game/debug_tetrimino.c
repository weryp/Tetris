/*
** debug_tetrimino.c for debug_tetrimino in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar 10 22:11:21 2016 Paul Wery
** Last update Fri Mar 11 12:30:13 2016 Paul Wery
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

int	first_check(char *buffer)
{
  int	n;

  n = 0;
  while (buffer[n] != '\n' && buffer[n] != '\0')
    {
      if (buffer[n] == ' ' || buffer[n] == '\t' ||
	  (buffer[n] > 47 && buffer[n] < 58))
	n = n;
      else
	return (-1);
      n += 1;
    }
  return (n);
}

int	second_check(char *buffer, int n, t_tetris *elem)
{
  int	ok;
  int	i;

  i = 0;
  ok = 0;
  while (buffer[n] != '\0')
    {
      i = 0;
      while (buffer[n] != '\n' && buffer[n] != '\0')
	{
	  i += 1;
	  n += 1;
	}
      if (i > elem->obj.width)
	return (-1);
      if (i == elem->obj.width)
	ok = 1;
      if (buffer[n] != '\0')
	n += 1;
    }
  if (ok == 0)
    return (-1);
  return (0);
}

int	check_tet(char *buffer, t_tetris *elem,
		  int n, int nb_lines)
{

  if ((n = first_check(buffer)) == -1)
    return (-1);
  if (buffer[n] == '\0')
    return (-1);
  n += 1;
  if (second_check(buffer, n, elem) == -1)
    return (-1);
  while (buffer[n] != '\0')
    {
      while (buffer[n] != '\n' && buffer[n] != '\0')
	{
	  if (buffer[n] != '*' && buffer[n] != ' ')
	    return (-1);
	  n += 1;
	}
      if (buffer[n] != '\0')
	n += 1;
      nb_lines += 1;
    }
  if (nb_lines != elem->obj.height)
    return (-1);
  return (0);
}

void	aff_content(char *buffer, t_tetris *elem)
{
  int	n;

  n = 0;
  my_putstr("Size ");
  my_putnbr(elem->obj.width);
  my_putstr("*");
  my_putnbr(elem->obj.height);
  my_putstr(" : Color ");
  my_putnbr(elem->obj.color);
  my_putstr(" :\n");
  while (buffer[n] != '\n' && buffer[n] != '\0')
    n += 1;
  if (buffer[n] != '\0')
    n += 1;
  while (buffer[n] != '\0')
    {
      my_putchar(buffer[n]);
      n += 1;
    }
  if (buffer[n - 1] != '\n')
    my_putchar('\n');
}

void		debug_tetrimino(t_tetris *elem)
{
  char		*path;
  char		*buffer;
  int		fd;

  if ((path = my_path(elem->name, "tetriminos/")) == NULL)
    return ;
  if ((fd = open(path, O_RDONLY)) == -1)
    return ;
  if ((buffer = alloc_buffer(fd, path)) == NULL)
    return ;
  if (check_tet(buffer, elem, 0, 0) == -1)
    {
      my_putstr("Error\n");
      delete_elem(elem);
    }
  else
    aff_content(buffer, elem);
  free(path);
  free(buffer);
  close(fd);
}
