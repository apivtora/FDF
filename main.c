
/*
** main.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Nov 23 19:25:13 2013 chapui_s
** Last update Sat Dec  7 23:55:32 2013 chapui_s
*/

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

int	init_infos_mlx(t_infos_mlx **infos_mlx)
{
  if (((*infos_mlx)->mlx_ptr = mlx_init()) == NULL)
    return (-1);
  if (((*infos_mlx)->win_ptr = mlx_new_window((*infos_mlx)->mlx_ptr,
					      WIDTH, HEIGHT, "FDF")) == NULL)
    return (-1);
  if (((*infos_mlx)->img = mlx_new_image((*infos_mlx)->mlx_ptr,
					 WIDTH, HEIGHT)) == NULL)
    return (-1);
  (*infos_mlx)->data = mlx_get_data_addr((*infos_mlx)->img,
				      &((*infos_mlx)->bpp),
				      &((*infos_mlx)->sizeline),
				      &((*infos_mlx)->endian));
  return (0);
}

int		main(int argc, char **argv)
{
  int		nb_lines;
  t_map		*map;
  t_infos_mlx	*infos_mlx;

  if ((infos_mlx = (t_infos_mlx*)malloc(sizeof(t_infos_mlx))) == NULL)
    return (my_putstr_error("could not alloc\n"));
  if ((map = get_map(&nb_lines)) == NULL)
    return (-1);
  if ((init_infos_mlx(&infos_mlx)) == -1)
    return (my_putstr_error("mlx error -> cannot open window\n"));
  infos_mlx->map = map;
  infos_mlx->nb_lines = nb_lines;
  disp_fdf(map, infos_mlx, nb_lines, 0);
  mlx_expose_hook(infos_mlx->win_ptr, gerer_expose, infos_mlx);
  mlx_key_hook(infos_mlx->win_ptr, gerer_clavier, infos_mlx);
  mlx_loop(infos_mlx->mlx_ptr);
  return (0);
}
