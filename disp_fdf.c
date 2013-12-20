/*
** disp_fdf.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Dec  4 22:39:36 2013 chapui_s
** Last update Sun Dec  8 22:24:23 2013 chapui_s
*/

#include <stdlib.h>
#include "fdf.h"

void	center_vertical(t_map *map)
{
  int	y_min;
  int	y_max;
  int	coef;
  t_map	*tmp;

  get_y_min_max(map, &y_min, &y_max);
  coef = (HEIGHT / 2) - ((y_max + y_min) / 2);
  if (coef < 0)
    coef = -coef;
  tmp = map;
  while (tmp)
  {
    tmp->y = tmp->y - coef;
    tmp = tmp->next;
  }
}

void	center_map(t_map *map)
{
  t_map	*tmp;
  int	coef;
  int	x_max;
  int	x_min;

  tmp = map;
  coef = get_coef(map, x_min, x_max);
  while (tmp)
  {
    tmp->x = tmp->x * coef + 50;
    tmp->y = tmp->y * coef + HEIGHT;
    tmp = tmp->next;
  }
  get_x_min_max(map, &x_min, &x_max);
  coef = (WIDTH / 2) - ((x_max + x_min) / 2);
  tmp = map;
  while (tmp)
  {
    tmp->x = tmp->x + coef;
    tmp = tmp->next;
  }
  center_vertical(map);
}

void	get_tmp(int *x, int *y, t_map **tmp)
{
  if (*tmp)
  {
    *x = (*tmp)->x;
    *y = (*tmp)->y;
    *tmp = (*tmp)->next;
  }
}

int		disp_fdf(t_map *map, t_infos_mlx *infos_mlx, int nb_lines,
			 int first)
{
  t_map		*tmp;
  int		line_actual;
  int		i;
  int		x;
  int		y;

  line_actual = 1;
  if (first == 0)
    center_map(map);
  tmp = map;
  i = 2;
  get_tmp(&x, &y, &tmp);
  while (tmp)
  {
    if ((x != tmp->x || y != tmp->y) && i % (nb_lines * line_actual + 1) != 0)
      print_line(get_coord(x, y, tmp->x, tmp->y), infos_mlx, 0);
    if (get_x(map, i, nb_lines) != -1 && get_y(map, i, nb_lines) != -1)
      print_line(get_coord(get_x(map, i, nb_lines), get_y(map, i, nb_lines),
			   tmp->x, tmp->y), infos_mlx, 0);
    get_tmp(&x, &y, &tmp);
    (i++ % (nb_lines + 1) == 0) ? (line_actual = line_actual + 1) : (0);
  }
  return (0);
}
