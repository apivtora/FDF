/*
** free_wordtab.c for fdf in /home/chapui_s/rendu/MUL_2013_fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sun Dec  8 00:11:14 2013 chapui_s
** Last update Sun Dec  8 00:16:39 2013 chapui_s
*/

#include <stdlib.h>

void	free_wordtab(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab[i][0] != 0)
  {
    free(wordtab[i]);
    i = i + 1;
  }
}
