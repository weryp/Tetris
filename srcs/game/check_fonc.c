/*
** check_fonc.c for check_fonc in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Mar 15 20:13:20 2016 Paul Wery
** Last update Tue Mar 15 23:16:02 2016 Paul Wery
*/

#include <unistd.h>

int	check_line(char *buffer, int n)
{
  if (buffer[n] == ' ')
    {
      while (buffer[n] == ' ' && buffer[n] != '\0')
	n += 1;
      if (buffer[n] == '\n' || buffer[n] == '\0')
	return (-1);
    }
  return (0);
}

int	check_fonc(int fonc, char **av, int n)
{
  if ((fonc == -1 && av[n][0] == '-' && av[n][1] != '\0') ||
      (n == 1 && fonc == - 1 && av[n][0] == '-' && av[n][1] == '\0')
      || (n > 1 && fonc == -1 && av[n][0] == '-' && av[n][1] == '\0'
	  && ((av[n - 1][0] == '-' && (av[n - 1][1] == '-' ||
				       av[n - 1][1] == '\0')) ||
	      av[n - 1][0] != '-')) ||
      (n > 1 && av[n][0] != '-' && av[n - 1][0] != '-')
      || av[1][0] != '-' ||
      (av[n][0] == '-' && av[n][1] != '-' && av[n][1] != '\0'
       && av[n + 1] != NULL && av[n + 1][0] == '-' &&
       av[n][1] != 'd' && av[n][1] != 'w' && av[n + 1][1] != '\0')
      || (n > 1 && av[n][0] != '-' && av[n - 1][0] == '-'
	  && (av[n - 1][1] == 'd' || av[n - 1][1] == 'w'
	      || av[n - 1][1] == '\0'))
      || (av[n][0] == '-' && av[n][1] == '-'
	  && av[n + 1] != NULL && av[n + 1][0] != '-'))
    return (-1);
  return (0);
}
