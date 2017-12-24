/*
** basics.c for basics in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Fri Feb 19 18:39:40 2016 Yan Poinssot
** Last update Sat Feb 27 20:20:55 2016 Yan Poinssot
*/

#include <lapin.h>
#include "./include/tekgui.h"

unsigned int		tekgetpixel(t_bunny_pixelarray	*pix,
				    int			x,
				    int			y)
{
  unsigned int		colour;

  if (x < pix->clipable.clip_width && y < pix->clipable.clip_height
      && x >= 0 && y >= 0)
    colour = ((int *)pix->pixels)[y * pix->clipable.clip_width + x];
  return (colour);
}

void			background(t_bunny_pixelarray	*pix,
				   t_color		*color)
{
  int			counter;

  counter = 0;
  while (counter < ((pix->clipable.clip_width * pix->clipable.clip_height)))
    {
      ((unsigned int *)pix->pixels)[counter] = color->full;
      counter++;
    }
}

int			initialize(t_bunny_position	*current,
				   t_bunny_position	*pos,
				   int			*a,
				   int			*b)
{
  int			var;

  current->x = pos[0].x;
  current->y = pos[0].y;
  var = (pos[1].x - pos[0].x);
  *a = (var < 0) ? -var : var;
  var = (pos[1].y - pos[0].y);
  *b = (var < 0) ? -var : var;
  var = ((*a) > (*b) ? (*a) / 2 : -(*b) / 2);
  return (var);
}

void			 tekline(t_bunny_pixelarray	*pix,
				 t_bunny_position	*pos,
				 t_color		*color)
{
  t_bunny_position	current;
  int			a;
  int			b;
  int			angle;
  int			check;

  angle = initialize(&current, pos, &a, &b);
  tekpixel(pix, &pos[1], color);
  while (current.x != pos[1].x || current.y != pos[1].y)
    {
      tekpixel(pix, &current, color);
      check = angle;
      if (check > -a)
	{
          angle = angle - b;
          current.x = current.x + ((current.x < pos[1].x) ? 1 : -1);
	}
      if (check < b)
	{
	  angle = angle + a;
	  current.y = current.y + ((current.y < pos[1].y) ? 1 : -1);
	}
    }
}
