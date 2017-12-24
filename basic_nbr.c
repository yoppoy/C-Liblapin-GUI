/*
** functions.c for functions.c in /home/poinss_y/Documents/CPE/CPE_2015_Allum1
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue Feb  9 18:31:08 2016 Yan Poinssot
** Last update Sat Feb 27 20:18:31 2016 Yan Poinssot
*/

#include <lapin.h>
#include "./include/tekgui.h"

int		check_num(char *input)
{
  int		count;

  count = 0;
  while (input[count] != '\0')
    {
      if (!(input[count] <= 57 && input[count] >= 48))
	return (1);
      count++;
    }
  return (0);
}

int		my_getnbr(char *word)
{
  int		count;
  int		result;

  count = 0;
  result = 0;

  while (word[count] != '\0')
    {
      result = (result * 10) + (word[count] - 48);
      count++;
    }
  if (word[0] == '-')
    result = result * -1;
  return (result);
}

int		my_putnbr(int nb)
{
  char		*print;
  int		temp;
  int		count;

  count = 1;
  temp = nb;
  while ((temp = temp / 10) != 0)
    count++;
  if ((print = my_malloc(sizeof(char) * (count + 1))) == NULL)
    return (1);
  print[count] = '\0';
  count--;
  while (count >= 0)
    {
      print[count] = (nb % 10) + 48;
      nb = nb / 10;
      count--;
    }
  my_putstr(print);
  free(print);
  return (0);
}
