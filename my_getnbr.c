/*
** my_getnbr.c for getnbr in /home/chapui_s/rendu/Piscine-C-Jour_04
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Thu Oct  3 10:01:07 2013 chapui_s
** Last update Sat Dec  7 16:55:21 2013 chapui_s
*/

#include <stdlib.h>

int	check_int(unsigned int nb, int positive)
{
  if (nb > 2147483647)
  {
    if (positive == 1)
      return (0);
    else
    {
      if (nb > 2147483648)
	return (0);
    }
  }
  return (1);
}

int		my_getnbr(char *str)
{
  unsigned int	nb;
  int		positive;
  int		i;

  nb = 0;
  i = 0;
  positive = 1;
  if (str == NULL)
    return (0);
  while (str[i] == '+' || str[i] == '-')
    i = i + 1;
  if (str[i - 1] == '-')
    positive = 0;
  while(str[i] >= '0' && str[i] <= '9')
  {
    nb = nb * 10;
    nb = nb + str[i] - '0';
    i = i + 1;
    if (check_int(nb, positive) == 0)
      return (0);
  }
  if (positive == 1)
    return ((int)nb);
  else
    return ((int)-nb);
}
