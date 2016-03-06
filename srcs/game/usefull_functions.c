/*
** usefull_functions.c for usefull_functions in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 21:05:52 2016 Paul Wery
** Last update Tue Mar  1 03:29:21 2016 Paul Wery
*/

int	size_line(char *str, int n)
{
  int	i;

  i = 0;
  while (str[n] != '\n' && str[n] != '\0')
    {
      n += 1;
      i += 1;
    }
  return (i);
}

int	my_strlen(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    n += 1;
  return (n);
}

void	cop_string(char *name, char *src)
{
  int	n;

  n = 0;
  while (src[n] != '\0')
    {
      name[n] = src[n];
      n += 1;
    }
}

int	start_buffer(char *buffer, int param, int n)
{
  int	i;

  i = 1;
  while (i < param)
    {
      while (buffer[n] > 47 && buffer[n] < 58 && buffer[n] != '\0')
	n += 1;
      while((buffer[n] == ' ' || buffer[n] == '\t') && buffer[n] != '\0')
	n += 1;
      i += 1;
    }
  return (n);
}

int	get_params(char *buffer, int param)
{
  int	n;
  int	val;

  n = 0;
  val = 0;
  while((buffer[n] == ' ' || buffer[n] == '\t') && buffer[n] != '\0')
    n += 1;
  n = start_buffer(buffer, param, n);
  while (buffer[n] != ' ' && buffer[n] != '\t'
	 && buffer[n] != '\0' && buffer[n] != '\n')
    {
      if (buffer[n] > 47 && buffer[n] < 58)
	val = (val * 10) + (buffer[n] - 48);
      else
	return (-1);
      n += 1;
    }
  return (val);
}
