/*
** linked_list.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Nov 23 20:30:31 2013 chapui_s
** Last update Sun Dec  8 22:01:59 2013 chapui_s
*/

#include <stdlib.h>
#include "fdf.h"

t_map	*my_create_elem(int x, int y)
{
  t_map	*new;

  new = NULL;
  if ((new = (t_map*)malloc(sizeof(t_map))) == NULL)
    return (NULL);
  new->x = x;
  new->y = y;
  new->next = NULL;
  return (new);
}

int	push_back(t_map **begin_list, int x, int y)
{
  t_map	*list;

  list = *begin_list;
  if (list)
  {
    while (list->next)
      list = list->next;
    if ((list->next = my_create_elem(x, y)) == NULL)
      return (-1);
  }
  else
    if ((*begin_list = my_create_elem(x, y)) == NULL)
      return (-1);
  return (0);
}

int	count_elem(t_map *list)
{
  t_map	*tmp;
  int	i;

  i = 0;
  tmp = list;
  while (tmp)
  {
    i = i + 1;
    tmp = tmp->next;
  }
  return (i);
}

void	free_list(t_infos_mlx *infos_mlx)
{
  t_map	*tmp;
  t_map	*tmp_next;

  tmp = infos_mlx->map;
  while (tmp)
  {
    tmp_next = tmp->next;
    free(tmp);
    tmp = tmp->next;
  }
}
