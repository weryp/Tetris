/*
** elems_state_game.c for elems_state_game in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 12 01:29:03 2016 Paul Wery
** Last update Sun Mar 13 19:21:12 2016 Victor Hoarau
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
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
  mvprintw(line + 6, col, "| Level      ");
  mvprintw(line + 6, col + 16, "00");
  mvprintw(line + 6, col + 18, " |");
  print_nbr(data->ev->level, line + 6, col + 13 + 4);
}

int	get_high_score(void)
{
  int	n;
  int	i;
  int	fd;
  char	buffer[6];

  n = 0;
  i = 0;
  while (n < 6)
    buffer[n++] = '\0';
  if ((fd = open("datas/high_score", O_RDONLY)) == -1)
    return (0);
  if (read(fd, buffer, 5) == -1)
    return (0);
  n = 0;
  while (n < 5 && buffer[n] != '\0')
    i = (i * 10) + (buffer[n++] - 48);
  close(fd);
  return (i);
}

void	print_score(t_display_env *data, int line, int col)
{
  int	high_score;

  mvprintw(line + 2, col, "| High Score ");
  mvprintw(line + 2, col + 18, " |");
  high_score = get_high_score();
  print_nbr(high_score, line + 2, col + 13 + 4);
  mvprintw(line + 3, col, "| Score      ");
  mvprintw(line + 3, col + 18, " |");
  print_nbr(data->ev->score, line + 3, col + 13 + 4);
}
