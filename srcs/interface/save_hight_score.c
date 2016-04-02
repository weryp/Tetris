/*
** save_hight_score.c for save_hight_score in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 12 17:32:21 2016 Paul Wery
** Last update Sat Apr  2 20:01:19 2016 Paul Wery
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "print_param.h"

void	save_in_file(char *buffer)
{
  int	fd;

  if ((fd = open("datas/high_score", O_CREAT | O_APPEND | O_WRONLY
		 | O_TRUNC, S_IRUSR | S_IWUSR)) == - 1)
    return ;
  if (write(fd, buffer, 5) == -1)
    return ;
  close(fd);
}

void	save_score(int score)
{
  int	n;
  int	save;
  char	buffer[6];

  n = 0;
  save = score;
  while (n < 6)
    buffer[n++] = '\0';
  n = 0;
  while (save > 0)
    {
      save /= 10;
      n += 1;
    }
  while (n >= 0)
    {
      buffer[n] = score % 10 + 48;
      score /= 10;
      n -= 1;
    }
  save_in_file(buffer);
}

void	save_high_score(int score_player)
{
  int	high_score;

  high_score = get_high_score();
  if (score_player > high_score)
    save_score(score_player);
}
