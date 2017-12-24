/*
** function.c for functions in /home/poinss_y/Documents/PSU/PSU_2015_minitalk
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Mon Feb  8 13:25:36 2016 Yan Poinssot
** Last update Wed Mar  2 00:32:47 2016 Yan Poinssot
*/

#include <lapin.h>
#include <unistd.h>
#include "./include/tekgui.h"

int		my_strlen(char *word)
{
  int		i;

  i = 0;
  while (word[i] != '\0')
    i++;
  return (i);
}

int		my_strcmp(char *word, char *words)
{
  int		a;

  a = 0;
  while (word[a] == words[a])
    {
      if (word[a] == '\0' && words[a] == '\0')
	return (0);
      a++;
    }
  return (-1);
}

void		my_putstr(char *word)
{
  write(1, word, my_strlen(word));
}

void		my_putstr_err(char *word)
{
  write(2, word, my_strlen(word));
}

char		*my_malloc(int num)
{
  char		*back;

  if ((back = bunny_malloc(num)) == NULL)
    {
      my_putstr_err("Error: invalid allocation of memory --abort\n");
      bunny_free(back);
      return (NULL);
    }
  return (back);
}
