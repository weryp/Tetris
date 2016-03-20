/*
** my_realloc.c for my_realloc.c in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Mar 20 14:30:01 2016 Paul Wery
** Last update Sun Mar 20 14:35:10 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>

void	*realloc_w(char *str, int new_size)
{
  char	*buffer;
  int	n;

  n = 0;
  if ((buffer = malloc(new_size)) == NULL)
    return (NULL);
  while (n < (new_size - 1))
    {
      buffer[n] = str[n];
      n = n + 1;
    }
  while (n < new_size)
    {
      buffer[n] = '\0';
      n = n + 1;
    }
  free(str);
  return (buffer);
}
