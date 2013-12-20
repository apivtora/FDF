/*
** utils.c for fdf in /home/chapui_s/travaux/fdf/fdf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Nov 23 19:33:14 2013 chapui_s
** Last update Sat Dec  7 17:00:40 2013 chapui_s
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i])
    write(1, &str[i++], 1);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

void	swap_int(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

unsigned int	val_abs(int nb)
{
  if (nb < 0)
    return (-nb);
  return (nb);
}
