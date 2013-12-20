/*
** events.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Dec  7 23:25:36 2013 chapui_s
** Last update Sun Dec  8 00:00:32 2013 chapui_s
*/

#include <stdlib.h>
#include "fdf.h"

int		gerer_expose(void *param)
{
  t_infos_mlx	*infos_mlx;

  infos_mlx = param;
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
			  infos_mlx->win_ptr,
			  infos_mlx->img, 0, 0);
}

void	put_blackout(t_infos_mlx *infos_mlx)
{
  int	i;

  i = 0;
  while (i <= HEIGHT)
  {
    print_line(get_coord(0, i, WIDTH, i), infos_mlx, 1);
    i = i + 1;
  }
}

void	clean_exit(t_infos_mlx *infos_mlx)
{
  free_list(infos_mlx);
  free(infos_mlx);
  exit(-1);
}

int		gerer_clavier(int keycode, void *param)
{
  t_infos_mlx	*infos_mlx;

  infos_mlx = param;
  if (keycode == 65307)
    clean_exit(infos_mlx);
  else if (keycode == 65363)
    move_right_map(infos_mlx);
  else if (keycode == 65361)
    move_left_map(infos_mlx);
  else if (keycode == 65362)
    move_up_map(infos_mlx);
  else if (keycode == 65364)
    move_down_map(infos_mlx);
  else if (keycode == 65451)
    zoom_map(infos_mlx, 1);
  else if (keycode == 65453)
    zoom_map(infos_mlx, 0);
  else if (keycode == 114)
    rot_map(infos_mlx);
  else if (keycode == 116)
    little_rot_map(infos_mlx);
  return (0);
}

int	transform_coord(t_line *c, t_infos_mlx *infos_mlx)
{
  if (c->x1 == c->x2 && c->y1 == c->y2)
    return (-1);
  (c->x1 > c->x2) ? (swap_int(&(c->y1), &(c->y2))) : (0);
  (c->x1 > c->x2) ? (swap_int(&(c->x1), &(c->x2))) : (0);
  return (0);
}
