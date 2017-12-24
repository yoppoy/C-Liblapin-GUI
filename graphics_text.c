/*
** graph_text.c for graph_text in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue Feb 23 18:45:13 2016 Yan Poinssot
** Last update Sat Feb 27 20:34:49 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	<stdio.h>
#include	"./include/tekgui.h"

void		center(t_bunny_position			*dim,
		       t_bunny_position			*pos,
		       char				*word)
{
  int		xlength;
  int		count;
  double	a;

  xlength = my_strlen(word) * 6;
  if (dim->x > xlength)
    pos->x += (dim->x / 2) - (xlength / 2);
  count = -1;
  a = 0;
  while (word[(int)(++count)] != '\0')
    {
      if ((count * 6) % dim->x == 0)
	a += 1.0;
    }
  if (dim->x < xlength)
    a = a * 8;
  else
    a = a * 4;
  pos->y += (dim->y / 2) - a;
}

void		add_let(char				**text,
			char				let)
{
  char		*field;
  int		count;

  field = bunny_malloc(sizeof(char) * (my_strlen((*text)) + 2));
  count = -1;
  while ((*text)[++count] != '\0')
    field[count] = (*text)[count];
  field[count] = let;
  field[count + 1] = '\0';
  (*text) = field;
}

t_item		*get_writtenbox(t_tekgui		*gui)
{
  t_list	*list;

  list = gui->list;
  while (list != NULL)
    {
      if (list->item.state == '1')
	{
	  if (my_strcmp(list->item.type, "textbox") != -1)
	    return (&(list->item));
	  return (NULL);
	}
      list = list->next;
    }
  return (NULL);
}

static void		write_let(t_bunny_pixelarray	**pix,
				  t_bunny_position	pos,
				  const char		let,
				  t_color		*color)
{
  t_bunny_position	current;
  t_bunny_position	print;

  current.y = -1;
  print.y = pos.y;
  while (++current.y < 7)
    {
      print.x = pos.x;
      current.x = (int)(let) * 5 - 1;
      while (++current.x < (((int)(let) * 5) + 5))
	{
	  if (tekgetpixel(pix[1], current.x, current.y) != 0)
	    tekpixel(pix[0], &print, color);
	  print.x++;
	}
      print.y++;
    }
}

void			write_text(t_bunny_pixelarray	**pix,
				   t_bunny_position	*set,
				   const char		*str,
				   t_color		*color)
{
  int			a;
  t_bunny_position	ac;

  a = -1;
  ac.y = set[0].y;
  ac.x = set[0].x;
  while (str[++a] != '\0' && ac.y < set[0].y + set[1].y &&
	 a < my_strlen((char *)(str)))
    {
      if (ac.x > set[1].x + set[0].x - 6 || (str[a] == '\n'))
	{
	  if (str[a] == '\n')
	    a++;
	  ac.y += 8;
	  ac.x = set[0].x;
	}
      if (ac.y < set[0].y + set[1].y - 5 && str[a] != '\n' && str[a] != '\0')
	write_let(pix, ac, str[a], color);
      ac.x += 6;
    }
}
