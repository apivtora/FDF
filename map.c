/*
** map.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Nov 23 22:04:48 2013 chapui_s
** Last update Sun Dec  8 20:59:22 2013 chapui_s
*/

#include <stdlib.h>
#include <math.h>
#include "fdf.h"

void	convert_to_paral(int x, int y, int z, t_tmp_coord *tmp)
{
  tmp->x = x + CSTE_PARAL * z;
  tmp->y = y + (CSTE_PARAL / 2) * z;
}

int		stock_in_list(t_map **map, char **word_tab, int y)
{
  t_tmp_coord	coord_2d;
  int		x;
  int		z;
  int		tmp;

  x = 0;
  while (word_tab[x][0])
  {
    z = my_getnbr(word_tab[x]);
    convert_to_paral(x, y, z, &coord_2d);
    tmp = coord_2d.x;
    coord_2d.x = (coord_2d.y);
    coord_2d.y = -tmp;
    if ((push_back(map, coord_2d.x, coord_2d.y)) == -1)
      return (-1);
    x = x + 1;
  }
  return (0);
}

void	*bad_map(char *str)
{
  my_putstr_error(str);
  return (NULL);
}

int	search_bad_car(char *str)
{
  int	i;

  i = 0;
  while (str[i])
  {
    if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 'x'
	  || str[i] == ',' || str[i] == ' ' || str[i] == '\n'
	  || (str[i] >= 'a' && str[i] <= 'f')
	  || (str[i] >= 'A' && str[i] <= 'F')))
      return (-1);
    i = i + 1;
  }
  return (0);
}

t_map	*get_map(int *nb_lines)
{
  char	*str;
  char	**word_tab;
  t_map	*map;

  *nb_lines = 0;
  map = NULL;
  word_tab = NULL;
  while ((str = get_next_line(0)))
  {
    if (search_bad_car(str) == -1)
      return (bad_map("map error: bad caractere in file\n"));
    if ((word_tab = my_str_to_wordtab(str)) == NULL)
      return (bad_map("could not alloc\n"));
    if ((stock_in_list(&map, word_tab, *nb_lines)) == -1)
      return (bad_map("could not alloc\n"));
    free_wordtab(word_tab);
    free(str);
    *nb_lines = *nb_lines + 1;
    if (*nb_lines >= 10000)
      return (bad_map("map error: too long or bad file\n"));
  }
  if (map == NULL)
    bad_map("map error\n");
  return (map);
}
