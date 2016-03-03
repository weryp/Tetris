/*
** check_ext.c for check_ext in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 00:49:00 2016 Paul Wery
** Last update Fri Mar  4 00:56:26 2016 Paul Wery
*/

int	comp_ext(char *ext_one, char *ext_two, int n)
{
  int	i;

  i = 0;
  while (ext_one[n] == ext_two[i] && ext_one[n] != '\0'
	 && ext_two[i] != '\0')
    {
      i += 1;
      n += 1;
    }
  if (ext_one[n] == '\0' && ext_two[i] == '\0')
    return (0);
  return (-1);
}

int	check_ext(char *file)
{
  int	n;

  n = 0;
  while (file[n] != '.' && file[n] != '\0')
    n += 1;
  if (file[n] != '\0')
    if (comp_ext(file, ".tetrimino", n) == 0)
      return (0);
  return (-1);
}
