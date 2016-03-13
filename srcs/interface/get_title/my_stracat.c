/*
** my_stracat.c for tetris in /home/hoarau/Code/PSU/PSU_2015_tetris
**
** Made by hoarau_v
** Login   <hoarau_v@epitech.net>
**
** Started on  Sat Mar 12 17:41:10 2016 hoarau_v
** Last update Sun Mar 13 22:40:28 2016 Paul Wery
*/

# include <stdlib.h>

int	mystrlen(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

char	*my_stracat(char *dest, char *src)
{
  char	*result;
  int	i;
  int	j;

  if ((result = malloc(sizeof(char) * (1 + mystrlen(dest) +
				       mystrlen(src)))) == NULL)
    return (NULL);
  i = 0;
  if (dest != NULL)
    {
      while (dest[i] != '\0')
	{
	  result[i] = dest[i];
	  i += 1;
	}
      free(dest);
    }
  j = 0;
  if (src != NULL)
    while (src[j] != '\0')
      result[i++] = src[j++];
  result[i] = '\0';
  return (result);
}
