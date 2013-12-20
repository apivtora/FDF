/*
** my_str_to_wordtab.c for strw in /home/chapui_s/rendu/Piscine-C-Jour_08/ex_04
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Oct  9 11:32:12 2013 chapui_s
** Last update Sat Dec  7 23:49:58 2013 chapui_s
*/

#include <stdlib.h>

int	is_it_alpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  if (c >= 'A' && c <= 'Z')
    return (1);
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	count_words(char *str)
{
  int	i;
  int	nb_words;

  i = 0;
  nb_words = 0;
  while (str[i])
  {
    while (str[i] && str[i] == ' ')
      i = i + 1;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
      i = i + 1;
    nb_words = nb_words + 1;
    while (str[i] && str[i] != ' ')
      i = i + 1;
  }
  return (nb_words);
}

void	dup_n_car(char *new_str, char *str, int begin, int end)
{
  int	i;

  i = 0;
  while (begin <= end)
  {
    new_str[i] = str[begin];
    begin = begin + 1;
    i = i + 1;
  }
  new_str[i] = '\0';
}

int	save_words(char **tab, char *str, int nb_words)
{
  int	i;
  int	begin;
  int	word_cur;
  int	is_nb;

  word_cur = 0;
  i = 0;
  while (word_cur < nb_words)
  {
    is_nb = 0;
    while (str[i] && is_it_alpha(str[i]) == 0 && ++i);
    begin = i;
    while (str[i] && is_it_alpha(str[i]) == 1 && ++i);
    if (str[begin + 1] != 'x')
    {
      if ((tab[word_cur] = (char*)malloc(sizeof(char) * ((i - 1) - begin + 2)))
	  == NULL)
	return (-1);
      dup_n_car(tab[word_cur], str, begin, i - 1);
      is_nb = 1;
    }
    i = i + 1;
    (is_nb == 1) ? (word_cur = word_cur + 1) : (0);
  }
  return (0);
}

char	**my_str_to_wordtab(char *str)
{
  int	nb_words;
  char	**tab;

  nb_words = count_words(str);
  if ((tab = (char**)malloc(sizeof(char*) * (nb_words + 1))) == NULL)
    return (NULL);
  if ((save_words(tab, str, nb_words)) == -1)
    return (NULL);
  if ((tab[nb_words] = (char*)malloc(sizeof(char))) == NULL)
    return (NULL);
  tab[nb_words][0] = 0;
  return (tab);
}
