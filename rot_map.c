/*
** rot_map.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Dec  7 18:32:11 2013 chapui_s
** Last update Sat Dec  7 23:58:22 2013 chapui_s
*/

#include <math.h>
#include "fdf.h"

void	center_after_rot(t_map *map)
{
  t_map	*tmp;
  int	y_min;
  int	tmp_int;

  tmp = map;
  get_y_min_max(map, &y_min, &tmp_int);
  if (y_min < 0)
  {
    while (tmp)
    {
      tmp->y = tmp->y - y_min;
      tmp = tmp->next;
    }
  }
}

void	rot_map(t_infos_mlx *infos_mlx)
{
  t_map	*tmp;
  int	tmp_int;

  tmp = infos_mlx->map;
  while (tmp)
  {
    tmp_int = tmp->x;
    tmp->x = tmp->y;
    tmp->y = -tmp_int;
    tmp = tmp->next;
  }
  center_after_rot(infos_mlx->map);
  put_blackout(infos_mlx);
  disp_fdf(infos_mlx->map, infos_mlx, infos_mlx->nb_lines, 1);
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
}


void	center_little_rot(t_map *map)
{
  t_map	*tmp;
  int	x_max;
  int	tmp_int;

  tmp = map;
  get_x_min_max(map, &tmp_int, &x_max);
  if (x_max > WIDTH)
  {
    while (tmp)
    {
      tmp->x = tmp->x - (x_max - WIDTH);
      tmp = tmp->next;
    }
  }
}

void	little_rot_map(t_infos_mlx *infos_mlx)
{
  t_map	*tmp;
  int	tmp_int;

  tmp = infos_mlx->map;
  while (tmp)
  {
    tmp_int = tmp->x;
    tmp->x = (float)(tmp->x) * cos(0.3) + (float)(tmp->y) * sin(0.3) + 0.5;
    tmp->y = (float)(-(tmp_int)) * sin(0.3) + (float)(tmp->y) * cos(0.3)
      + 0.5;
    tmp = tmp->next;
  }
  center_after_rot(infos_mlx->map);
  center_little_rot(infos_mlx->map);
  put_blackout(infos_mlx);
  disp_fdf(infos_mlx->map, infos_mlx, infos_mlx->nb_lines, 1);
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
}
