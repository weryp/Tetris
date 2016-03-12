/*
** moove_tetrimino.c for moove_tetrimino in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Mar  2 16:40:24 2016 Paul Wery
** Last update Fri Mar 11 17:54:19 2016 Paul Wery
*/

#define _POSIX_SOURCE
#define _BSD_SOURCE
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

int	change_form(char **map, t_tetris *it,
		    t_start_pos *pos, t_events *ev)
{
  int	x;
  int	y;
  int	n;
  int	i;

  n = 0;
  y = pos->start_y;
  while (y < pos->end_y)
    {
      i = 0;
      x = pos->start_x;
      while (x < pos->end_x)
	{
	  if (it->obj.tetrimino[n][i] == '*')
	    map[y][x] = '*';
	  i += 1;
	  x += 1;
	}
      n += 1;
      y += 1;
    }
  clear_map(map, ev);
  aff_map_color(map, it, pos, ev);
  return (0);
}

void	time_event(char **map, t_events *ev,
		   t_start_pos pos, t_tetris *list)
{
  int	my_time;

  ev->time_end += 1;
  usleep(1);
  my_time = 5000 - (((int)ev->level - 1) * 200);
  if (my_time < 0 || my_time == 0)
    my_time = 1;
  if (ev->time_end == my_time)
    {
      ev->height_time += 1;
      if (check_moove(map, ev->it, &pos) == 0)
	{
	  pos.start_y += 1;
	  pos.end_y += 1;
	  change_form(map, ev->it, &pos, ev);
	}
      else
	{
	  change_form(map, ev->it, &pos, ev);
	  ini_events(ev, list);
	  clean_line(map, ev);
	}
      ev->time_end = 0;
    }
}

void		event_tetrimino_next(char **map, t_events *ev,
				     t_tetris *list)
{
  t_start_pos	pos;

  check_border(&ev->pos, ev);
  pos.start_x = ev->pos.start_x;
  pos.start_y = ev->pos.start_y + ev->height_time;
  pos.end_x = ev->pos.end_x;
  pos.end_y = ev->pos.end_y + ev->height_time;
  check_border(&pos, ev);
  change_form(map, ev->it, &pos, ev);
  clear_tetrimino(map, &pos, &ev->it->obj);
  ev->tet_start = 1;
  time_event(map, ev, pos, list);
}

void	event_tetrimino(char **map, t_events *ev,
			t_tetris *list)
{
  clear_tetrimino(map, &ev->pos, &ev->it->obj);
  if (cstr(ev->key, ev->key_turn) == 1 && check_change_form(ev, map) == 0)
    {
      ev->form += 1;
      if (ev->form == 4)
	ev->form = 0;
      ev->it = ev->it->next_form;
      ev->pos.end_x = ev->pos.start_x + ev->it->obj.width;
      ev->pos.end_y = ev->pos.start_y + ev->it->obj.height;
    }
  if (cstr(ev->key, ev->key_left) == 1 || cstr(ev->key, ev->key_right) == 1)
    {
      clear_tetrimino(map, &ev->pos, &ev->it->obj);
      if (cstr(ev->key, ev->key_left) == 1 && check_side_left(ev, map) == 0)
	{
	  ev->pos.start_x -= 1;
	  ev->pos.end_x -= 1;
	}
      if (cstr(ev->key, ev->key_right) == 1 && check_side_right(ev, map) == 0)
	{
	  ev->pos.start_x += 1;
	  ev->pos.end_x += 1;
	}
    }
  event_tetrimino_next(map, ev, list);
}

int		moove_tetrimino(char **map, t_tetris *list,
				t_events *ev, int turn)
{
  ev->it = list->next;
  /*if (ev->tetrimino == 0)
    ev->tetrimino = rand() % (ev->nb_tet - 1) + 1;*/
  while (turn < ev->tetrimino)
    {
      turn += 1;
      ev->it = ev->it->next;
    }
  turn = 0;
  while (turn < ev->form)
    {
      turn += 1;
      ev->it = ev->it->next_form;
    }
  if (ev->tet_start == 0)
    {
      ini_pos(&ev->pos, ev);
      if (end_game(map, &ev->pos, &ev->it->obj) == -1)
	return (-1);
    }
  if (moove_tetrimino_next(map, ev, list) == -1)
    return (0);
  event_tetrimino(map, ev, list);
  return (0);
}
