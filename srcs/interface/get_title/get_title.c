/*
** get_title.c for tetris in /home/hoarau/Code/PSU/PSU_2015_tetris
**
** Made by hoarau_v
** Login   <hoarau_v@epitech.net>
**
** Started on  Sat Mar 12 17:41:33 2016 hoarau_v
** Last update Sun Mar 13 23:01:57 2016 Paul Wery
*/

# include "get_next_line.h"
# include "print_param.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_title(char *path)
{
  int	fd;
  char	*title;
  char	*tmp;

  title = NULL;
  tmp = NULL;
  if ((fd = open(path, O_RDONLY)) < 0)
    return (NULL);
  while ((tmp = get_next_line(fd)) != NULL)
    {
      title = my_stracat(title, tmp);
      title = my_stracat(title, "\n");
      free(tmp);
    }
  close(fd);
  return (title);
}
