/*
** load_tetriminos.c for load_tetriminos in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 21:13:21 2016 Paul Wery
** Last update Fri Mar 11 02:33:47 2016 Paul Wery
*/

#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

char		*alloc_buffer(int fd, char *file)
{
  char		*buffer;
  t_stat	my_stat;
  int		size;

  stat(file, &my_stat);
  if ((buffer = malloc((int)my_stat.st_size)) == NULL)
    return (NULL);
  if (read(fd, buffer, (int)my_stat.st_size) == -1)
    return (NULL);
  size = (int)my_stat.st_size;
  buffer[size - 1] = '\0';
  return (buffer);
}

char	*my_path(char *file, char *tet)
{
  char	*path;
  int	n;
  int	i;

  if ((path = malloc(my_strlen(file) + my_strlen(tet) + 1)) == NULL)
    return (NULL);
  n = 0;
  i = 0;
  while (n < my_strlen(tet))
    {
      path[n] = tet[n];
      n += 1;
    }
  while (i < my_strlen(file))
    path[n++] = file[i++];
  path[n] = '\0';
  return (path);
}

int	load_tetrimino(t_dir *file, t_tetris *list)
{
  int	fd;
  char	*file_name;
  char	*buffer;

  buffer = NULL;
  file_name = NULL;
  if (file->d_name[0] == '.' || check_ext(file->d_name) == -1)
    return (0);
  if ((file_name = my_path(file->d_name, "tetriminos/")) == NULL)
    return (-1);
  if ((fd = open(file_name, O_RDONLY)) == -1)
    return (-1);
  if ((buffer = alloc_buffer(fd, file_name)) == NULL)
    return (-1);
  if (load_objs(buffer, file->d_name, list) == -1)
    return (-1);
  close(fd);
  free(file_name);
  free(buffer);
  return (0);
}

int	load_tetriminos(t_tetris *list)
{
  DIR	*directory;
  t_dir	*file;

  if ((directory = opendir("tetriminos")) == NULL)
    return (-1);
  while ((file = readdir(directory)) != NULL)
    if (load_tetrimino(file, list) == -1)
      return (-1);
  closedir(directory);
  return (0);
}
