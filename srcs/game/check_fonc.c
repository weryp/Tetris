/*
** check_fonc.c for check_fonc in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Mar 15 20:13:20 2016 Paul Wery
** Last update Tue Mar 15 20:39:31 2016 Paul Wery
*/

int	check_fonc(int fonc, char **av, int n)
{
  int	i;

  i = 0;
  if (n > 1)
    while (av[n - 1][i] != '\0')
      i += 1;
  if ((fonc == -1 && av[n][0] == '-') ||
      (n > 1 && av[n][0] != '-' && av[n - 1][0] != '-')
      || av[1][0] != '-' ||
      (n > 1 && av[n - 1][i - 1] == '=' && av[n][0] != '-'))
    return (-1);
  return (0);
}
