/*
** get_next_line.c<CPE_2015_getnextline> for get_next_line in /home/hoarau/Code/CPE/CPE_2015_getnextline
**
** Made by hoarau
** Login   <hoarau_v@epitech.net>
**
** Started on  Mon Mar  7 23:12:38 2016 hoarau
** Last update Sun Mar 13 19:22:45 2016 Paul Wery
*/

# include "get_next_line.h"

char		add_car(const int fd)
{
  static char	buf[READ_SIZE];
  static char	*buffer;
  static int	length = 0;
  char		c;

  if (length == 0)
    {
      if (length = read(fd, buf, READ_SIZE) == -1)
	return (-1);
      buffer = (char*)&buf;
      if (length == 0)
	return ('\0');
    }
  c = *buffer;
  length -= 1;
  buffer++;
  return (c);
}

char	*my_realloc(char *str, int size)
{
  char	*tmp;
  int	i;

  i = 0;
  if ((tmp = malloc(size)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i += 1;
    }
  tmp[size] = '\0';
  free(str);
  return (tmp);
}

char	*get_next_line(const int fd)
{
  int	i;
  char	*str;
  char	c;

  if ((str = malloc(READ_SIZE + 1)) == NULL || fd < 0)
    return (NULL);
  i = 0;
  if (c = add_car(fd) == -1)
    return (NULL);
  while (c != '\0' && c != '\n')
    {
      str[i++] = c;
      c = add_car(fd);
      if (i % READ_SIZE == 0)
	if ((str = my_realloc(str, READ_SIZE + i + 1)) == NULL)
	  return (NULL);
    }
  str[i] = '\0';
  if (c == '\0' && str[0] == '\0')
    return (NULL);
  return (str);
}
