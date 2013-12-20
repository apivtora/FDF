/*
** move_map.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Dec  7 18:10:13 2013 chapui_s
** Last update Sat Dec  7 23:56:50 2013 chapui_s
*/

#include "fdf.h"

void	zoom_map(t_infos_mlx *infos_mlx, int jump)
{
  t_map	*tmp;
  int	tmp_int;

  tmp = infos_mlx->map;
  while (tmp)
  {
    if (jump == 1)
    {
      tmp->x = (float)(tmp->x) * 1.1;
      tmp->y = (float)(tmp->y) * 1.1;
    }
    else
    {
      tmp->x = (float)(tmp->x) * 0.9;
      tmp->y = (float)(tmp->y) * 0.9;
    }
    tmp = tmp->next;
  }
  put_blackout(infos_mlx);
  disp_fdf(infos_mlx->map, infos_mlx, infos_mlx->nb_lines, 1);
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
}

void	move_right_map(t_infos_mlx *infos_mlx)
{
  t_map	*tmp;
  int	tmp_int;

  tmp = infos_mlx->map;
  while (tmp)
  {
    tmp->x = tmp->x + 100;
    tmp = tmp->next;
  }
  put_blackout(infos_mlx);
  disp_fdf(infos_mlx->map, infos_mlx, infos_mlx->nb_lines, 1);
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
}

void	move_up_map(t_infos_mlx *infos_mlx)
{
  t_map	*tmp;
  int	tmp_int;

  tmp = infos_mlx->map;
  while (tmp)
  {
    tmp->y = tmp->y - 50;
    tmp = tmp->next;
  }
  put_blackout(infos_mlx);
  disp_fdf(infos_mlx->map, infos_mlx, infos_mlx->nb_lines, 1);
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
}

void	move_down_map(t_infos_mlx *infos_mlx)
{
  t_map	*tmp;
  int	tmp_int;

  tmp = infos_mlx->map;
  while (tmp)
  {
    tmp->y = tmp->y + 50;
    tmp = tmp->next;
  }
  put_blackout(infos_mlx);
  disp_fdf(infos_mlx->map, infos_mlx, infos_mlx->nb_lines, 1);
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
}

void	move_left_map(t_infos_mlx *infos_mlx)
{
  t_map	*tmp;
  int	tmp_int;

  tmp = infos_mlx->map;
  while (tmp)
  {
    tmp->x = tmp->x - 100;
    tmp = tmp->next;
  }
  put_blackout(infos_mlx);
  disp_fdf(infos_mlx->map, infos_mlx, infos_mlx->nb_lines, 1);
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
}
