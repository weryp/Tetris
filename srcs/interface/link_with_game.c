/*
** link_with_game.c for link_with_game in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar 11 22:12:26 2016 Paul Wery
** Last update Sat Mar 12 00:21:05 2016 Paul Wery
*/

#include "print_param.h"

void		link_with_game(t_events *ev,
			       t_tetris *list)
{
  t_display_env	data;

  data.ev = ev;
  data.list = list;
  print_all(&data);
}
