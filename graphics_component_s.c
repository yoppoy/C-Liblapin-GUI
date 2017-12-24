/*
** graphics_image.c for image_box in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sat Feb 27 12:56:58 2016 Yan Poinssot
** Last update Tue Mar  1 18:20:27 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	"./include/tekgui.h"

int			load_image(t_item			*new)
{
  if (new->img != NULL)
    {
      if ((new->pix = bunny_load_pixelarray((const char *)(new->img))) == NULL)
	{
	  my_putstr_err("Error: image couldn't be loaded");
	  return (-1);
	}
      my_putstr("Loaded 1 image\n");
    }
  return (0);
}

void			paste_pix(t_bunny_pixelarray		*copy,
				  t_bunny_pixelarray		*out,
				  t_bunny_position		pos,
				  t_bunny_position		dim)
{
  t_bunny_position	actual;
  t_bunny_position	select;
  t_color		color;

  actual.y = pos.y - 1;
  select.y = 0;
  while (++actual.y < pos.y + dim.y)
    {
      actual.x = pos.x - 1;
      select.x = 0;
      while (++actual.x < pos.x + dim.x)
	{
	  if ((color.full = tekgetpixel(copy, select.x, select.y)) != 0)
	    tekpixel(out, &actual, &color);
	  select.x++;
	}
      select.y++;
    }
}

int	                   draw_image(t_item			item,
				      t_bunny_pixelarray	*pix,
				      t_tekgui			gui)
{
  t_color		color;
  unsigned int		paint[2];
  t_bunny_position      pos[2];
  t_bunny_pixelarray	*write[2];

  extract_color(paint, item);
  if (item.pix != NULL)
    paste_pix(item.pix, pix, item.pos, item.dim);
 if (item.text != NULL)
    {
      write[0] = pix;
      write[1] = gui.font;
      pos[0] = item.pos;
      pos[1] = item.dim;
      color.full = WHITE;
      write_text(write, pos, item.text, &color);
    }
  color.full = paint[1];
  if (item.border != NULL)
    square_line(pix, item.pos, item.dim, &color);
  return (0);
}
