/*
** get_in_list.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Dec  4 23:42:26 2013 chapui_s
** Last update Sat Dec  7 17:10:34 2013 chapui_s
*/

#include <stdlib.h>
#include "fdf.h"

int	get_x(t_map *map, int at, int nb_lines)
{
  int	i;
  int	to;
  t_map	*tmp;

  i = 1;
  to = at - nb_lines;
  tmp = map;
  if (tmp == NULL)
    return (0);
  if (to < 0)
    return (-1);
  while (i++ < to && tmp->next)
    tmp = tmp->next;
  if (i < to)
    return (-1);
  return (tmp->x);
}

int	get_y(t_map *map, int at, int nb_lines)
{
  int	i;
  int	to;
  t_map	*tmp;

  i = 1;
  to = at - nb_lines;
  tmp = map;
  if (tmp == NULL)
    return (-1);
  if (to < 0)
    return (-1);
  while (i++ < to && tmp->next)
    tmp = tmp->next;
  if (i < to)
    return (-1);
  return (tmp->y);
}

void	get_x_min_max(t_map *map, int *min, int *max)
{
  t_map	*tmp;

  tmp = map;
  *min = tmp->x;
  *max = tmp->x;
  while (tmp)
  {
    if (tmp->x < *min)
      *min = tmp->x;
    if (tmp->x > *max)
      *max = tmp->x;
    tmp = tmp->next;
  }
}

void	get_y_min_max(t_map *map, int *min, int *max)
{
  t_map	*tmp;

  tmp = map;
  *min = tmp->y;
  *max = tmp->y;
  while (tmp)
  {
    if (tmp->y < *min)
      *min = tmp->y;
    if (tmp->y > *max)
      *max = tmp->y;
    tmp = tmp->next;
  }
}

int	get_coef(t_map *map, int x_min, int x_max)
{
  t_map	*tmp;
  int	y_min;
  int	y_max;
  int	coef;

  tmp = map;
  y_min = tmp->y;
  y_max = tmp->y;
  coef = 1;
  get_x_min_max(map, &x_min, &x_max);
  while (tmp)
  {
    if (tmp->y < y_min)
      y_min = tmp->y;
    if (tmp->y > y_max)
      y_max = tmp->y;
    tmp = tmp->next;
  }
  if (y_max == 0)
    y_max = 1;
  while (y_min * coef >= -(HEIGHT) + 50 && (y_max * coef) < HEIGHT - 250
         && x_min * coef >= 0 && x_max * coef <= WIDTH - 50)
    coef = coef + 1;
  return (coef - 1);
}
