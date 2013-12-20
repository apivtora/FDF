/*
** errors.c for bsq in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Dec  7 15:45:18 2013 chapui_s
** Last update Sat Dec  7 15:46:21 2013 chapui_s
*/

#include <unistd.h>

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i])
  {
    my_putchar_error(str[i]);
    i = i + 1;
  }
  return (-1);
}
