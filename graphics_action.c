/*
** graphics_action.c for  in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Thu Feb 25 00:14:29 2016 Yan Poinssot
** Last update Wed Mar  2 09:46:42 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"./include/tekgui.h"

static char	extract_correct(t_list			*item)
{
  if (my_strcmp("button", item->item.type) != -1)
    return ('b');
  if (my_strcmp("textbox", item->item.type) != -1)
    return ('t');
  if (my_strcmp("checkbox", item->item.type) != -1)
    return ('c');
  if (my_strcmp("imagebox", item->item.type) != -1)
    return ('i');
  if (my_strcmp("radiobutton", item->item.type) != -1)
    return ('r');
  return ('a');
}

char		check_item(const t_bunny_position	*pos,
			   t_list			*list,
			   int				*position)
{
  t_list	*item;
  static int	check = -1;

  item = list;
  (*position) = 0;
  while (item != NULL && (*position) > -1)
    {
      if (pos->x >= item->item.pos.x && pos->y >= item->item.pos.y &&
	  pos->x < item->item.pos.x + item->item.dim.x &&
	  pos->y < item->item.pos.y + item->item.dim.y)
	{
	  if (extract_correct(item) != 'a')
	    {
	      if (item->item.argument != NULL && item->item.function != NULL &&
		  ++check == 1)
		item->item.function(item->item.argument);
	      check = (check == 1) ? -1 : check;
	      return (extract_correct(item));
	    }
	}
      (*position)++;
      item = item->next;
    }
  (*position) = -1;
  return ('a');
}

int		set_selected(t_list			**list,
			     int			pos,
			     char			state)
{
  int		count;
  static int	c=0;
  t_list	*item;

  item = *list;
  while (item != NULL)
    {
      item->item.state = '0';
      item = item->next;
    }
  if (pos == -1)
    return (-1);
  item = *list;
  count = -1;
  while (++count < pos)
    (item = item->next);
  c++;
  item->item.state = state;
  return (0);
}

int		set_checked(t_list			**list,
			     int			pos)
{
  int		count;
  t_list	*item;

  item = *list;
  count = -1;
  while (++count < pos)
    (item = item->next);
  if (item->item.check == '1')
    item->item.check = '0';
  else
    item->item.check = '1';
  return (0);
}
