/*
** fdf.h for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Nov 23 19:31:42 2013 chapui_s
** Last update Sun Dec  8 22:36:12 2013 chapui_s
*/

#ifndef FDF_H_
# define FDF_H_

typedef struct	s_map
{
  int		x;
  int		y;
  struct s_map	*next;
}		t_map;

typedef struct	s_line
{
  int		x1;
  int		x2;
  int		y1;
  int		y2;
}		t_line;

typedef struct	s_infos_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  t_map		*map;
  int		nb_lines;
}		t_infos_mlx;

typedef struct	s_tmp_coord
{
  int		x;
  int		y;
}		t_tmp_coord;

#define	CSTE_PARAL	0.5
#define HEIGHT		860
#define WIDTH		1200

unsigned int	val_abs(int nb);
char		**my_str_to_wordtab(char *str);
char		*get_next_line(const int fd);
void		my_putstr(char *str);
void		my_show_wordtab(char **tab);
void		my_putnbr(int nb);
int		push_back(t_map **begin_list, int x, int y);
int		my_getnbr(char *str);
t_map		*get_map(int *nb_lines);
void		show_map(t_map *map);
int		disp_fdf(t_map *map, t_infos_mlx *infos_mlx, int nb_lines,
			 int first);
int		count_list(t_map *list);
int		get_x(t_map *map, int at, int nb_lines);
t_line		get_coord(int x1, int y1, int x2, int y2);
void		print_line(t_line c, t_infos_mlx *infos_mlx,
			   unsigned int color);
void		my_pixel_put_to_image(int x, int y, unsigned int color,
				      t_infos_mlx *infos_mlx);
void		swap_int(int *a, int *b);
int		get_coef(t_map *map, int x_min, int x_max);
void		get_x_min_max(t_map *map, int *min, int *max);
void		get_y_min_max(t_map *map, int *min, int *max);
void		move_right_map(t_infos_mlx *infos_mlx);
void		move_left_map(t_infos_mlx *infos_mlx);
void		rot_map(t_infos_mlx *infos_mlx);
int		gerer_expose(void *param);
void		put_blackout(t_infos_mlx *infos_mlx);
int		gerer_clavier(int keycode, void *param);
int		transform_coord(t_line *c, t_infos_mlx *infos_mlx);
void		clean_exit(t_infos_mlx *infos_mlx);
void		free_wordtab(char **wordtab);

#endif /* !FDF_H_ */
