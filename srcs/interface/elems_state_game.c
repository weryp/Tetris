/*
** elems_state_game.c for elems_state_game in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 12 01:29:03 2016 Paul Wery
** Last update Sat Mar 12 03:21:59 2016 Paul Wery
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <time.h>
#include "print_param.h"

void	print_timer_next(int line, int col, int time)
{
  int	min;
  int	sec;

  min = time / 60;
  sec = time - (60 * min);
  mvprintw(line + 8, col, "| Timer:     ");
  mvprintw(line + 8, col + 13, "00:00");
  mvprintw(line + 8, col + 18, " |");
  print_nbr(min, line + 8, col + 14);
  print_nbr(sec, line + 8, col + 17);
}

void		print_timer(int line, int col)
{
  static int	ini = 0;
  static int	start_time = 0;
  time_t	my_time;
  int		actual_time;

  if (ini == 0)
    {
      ini = 1;
      time(&my_time);
      start_time = my_time % 10000;
    }
  time(&my_time);
  actual_time = (my_time % 10000) - start_time;
  print_timer_next(line, col, actual_time);
}

void	print_level(t_display_env *data, int line, int col)
{
  int	n;
  int	i;

  i = 4;
  n = data->ev->level;
  while (n > 9)
    {
      n /= 10;
      i -= 1;
    }
  mvprintw(line + 6, col, "| Level      ");
  mvprintw(line + 6, col + 16, "00");
  mvprintw(line + 6, col + 18, " |");
  print_nbr(data->ev->level, line + 6, col + 13 + i);
}

int	get_hight_score(void)
{
  int	n;
  int	i;
  int	fd;
  char	buffer[6];

  n = 0;
  i = 0;
  buffer[0] = '\0';
  buffer[1] = '\0';
  buffer[2] = '\0';
  buffer[3] = '\0';
  buffer[4] = '\0';
  buffer[5] = '\0';
  if ((fd = open("datas/hight_score", O_RDONLY)) == -1)
    return (0);
  if (read(fd, buffer, 5) == -1)
    return (0);
  while (n < 5 && buffer[n] != '\0')
    {
      i = (i * 10) + (buffer[n] - 48);
      n += 1;
    }
  close(fd);
  return (i);
}

void	print_score(t_display_env *data, int line, int col)
{
  int	n;
  int	i;
  int	hight_score;

  i = 4;
  mvprintw(line + 2, col, "| High Score ");
  mvprintw(line + 2, col + 18, " |");
  hight_score = get_hight_score();
  n = hight_score;
  while (n > 9)
    {
      n /= 10;
      i -= 1;
    }
  print_nbr(hight_score, line + 2, col + 13 + i);
  i = 4;
  mvprintw(line + 3, col, "| Score      ");
  mvprintw(line + 3, col + 18, " |");
  n = data->ev->score;
  while (n > 9)
    {
      n /= 10;
      i -= 1;
    }
  print_nbr(data->ev->score, line + 3, col + 13 + 4);
}
