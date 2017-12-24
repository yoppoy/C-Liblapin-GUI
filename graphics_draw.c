/*
** graphics.c for graph.c in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Fri Feb 19 18:56:21 2016 Yan Poinssot
** Last update Fri Feb 26 15:38:42 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	<stdio.h>
#include	"./include/tekgui.h"

void			square(t_bunny_pixelarray	*pix,
			       t_bunny_position		pos,
			       t_bunny_position		dim,
			       t_color			*color)
{
  t_bunny_position	draw;

  draw.y = pos.y;
  while (draw.y < pos.y + dim.y)
    {
      draw.x = pos.x;
      while (draw.x < pos.x + dim.x)
	{
	  tekpixel(pix, &draw, color);
	  draw.x++;
	}
      draw.y++;
    }
}

void			set_pos(t_bunny_position *pos, int x, int y)
{
  pos->x = x;
  pos->y = y;
}

void			selected(t_bunny_pixelarray	*pix,
				 t_bunny_position	pos,
				 t_bunny_position	dim,
				 t_color		*color)
{
  int			count;
  t_bunny_position	draw[2];

  count = 0;
  while (count < 6)
    {
      set_pos(&(draw[0]), pos.x + dim.x - count - 2, pos.y + dim.y - 2);
      set_pos(&(draw[1]), pos.x + dim.x - 2, pos.y + dim.y - count - 2);
      tekline(pix, draw, color);
      count++;
    }
}

void			checked(t_bunny_pixelarray	*pix,
				t_bunny_position	pos,
				t_bunny_position	dim,
				t_color			*color)
{
  t_bunny_position	draw[2];

  set_pos(&(draw[0]), pos.x, pos.y);
  set_pos(&(draw[1]), pos.x + dim.x, pos.y + dim.y);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x + 1, pos.y);
  set_pos(&(draw[1]), pos.x + dim.x, pos.y + dim.y - 1);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x, pos.y + 1);
  set_pos(&(draw[1]), pos.x + dim.x - 1, pos.y + dim.y);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x + dim.x, pos.y);
  set_pos(&(draw[1]), pos.x, pos.y + dim.y);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x + dim.x - 1, pos.y);
  set_pos(&(draw[1]), pos.x, pos.y + dim.y - 1);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x + dim.x, pos.y + 1);
  set_pos(&(draw[1]), pos.x + 1, pos.y + dim.y);
  tekline(pix, draw, color);
}

void			square_line(t_bunny_pixelarray	*pix,
				    t_bunny_position	pos,
				    t_bunny_position	dim,
				    t_color		*color)

{
  t_bunny_position	draw[2];

  set_pos(&(draw[0]), pos.x, pos.y);
  set_pos(&(draw[1]), pos.x + dim.x, pos.y);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x + dim.x, pos.y + dim.y);
  tekline(pix, draw, color);
  set_pos(&(draw[1]), pos.x, pos.y + dim.y);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x, pos.y);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x - 1, pos.y - 1);
  set_pos(&(draw[1]), pos.x + dim.x + 1, pos.y - 1);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x + dim.x + 1, pos.y + dim.y + 1);
  tekline(pix, draw, color);
  set_pos(&(draw[1]), pos.x - 1, pos.y + dim.y + 1);
  tekline(pix, draw, color);
  set_pos(&(draw[0]), pos.x - 1, pos.y - 1);
  tekline(pix, draw, color);
}
