/*
** functions.c for functions in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Thu Feb 25 00:34:34 2016 Yan Poinssot
** Last update Fri Feb 26 14:11:54 2016 Yan Poinssot
*/

#include <lapin.h>
#include "./include/tekgui.h"

char		*my_strcpy(char *word)
{
  char		*back;
  int		count;

  if (word == NULL)
    return (NULL);
  if ((back = my_malloc(sizeof(char *) * my_strlen(word) + 1)) == NULL)
    return (NULL);
  count = -1;
  while (word[++count] != '\0')
    back[count] = word[count];
  back[count] = '\0';
  return (back);
}
