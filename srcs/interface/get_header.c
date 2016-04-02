/*
** get_header.c for get_header in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Apr  2 20:07:50 2016 Paul Wery
** Last update Sat Apr  2 20:11:27 2016 Paul Wery
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"

char	*get_header(void)
{
  int	fd;
  char	*buffer;

  if ((fd = open("datas/header.txt", O_RDONLY)) == -1)
    return (NULL);
  if ((buffer = alloc_buffer(fd, "datas/header.txt")) == NULL)
    return (NULL);
  return (buffer);
}
