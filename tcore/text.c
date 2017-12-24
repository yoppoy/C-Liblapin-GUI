/*
** tekpixel.c for functions in /home/poinss_y/Documents/Infographie/chromatic_2042
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed Feb 10 09:12:08 2016 Yan Poinssot
** Last update Sun Feb 28 17:27:32 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	"my.h"

static void		tekletter(t_bunny_pixelarray	*pix,
				  char			c)
{
  pix->clipable.clip_x_position = (int)(c) * 5;
  pix->clipable.clip_y_position = 0;
  pix->clipable.clip_height = 7;
  pix->clipable.clip_width = 5;
}

unsigned int		get_pixel(t_bunny_pixelarray	*pix,
				  t_bunny_position	*pos,
				  int			width)
{
  t_color		*back;

  back = ((t_color *)(pix->pixels));
  return (back[width * pos->y + pos->x].full);
}

void			add_pix(t_bunny_pixelarray	*font,
				t_bunny_pixelarray	*pix,
				t_bunny_position	anchor,
				int			origin)
{
  t_bunny_position	pos;
  t_bunny_position	outpos;
  t_color		color;

  pos.x = font->clipable.clip_x_position;
  outpos.x = anchor.x;
  while (outpos.x < (anchor.x + font->clipable.clip_width))
    {
      outpos.y = anchor.y;
      pos.y = 0;
      while (pos.y < font->clipable.clip_height)
	{
	  color.full = get_pixel(font, &pos, origin);
	  if (get_pixel(font, &pos, origin) == 4278386945)
	    tekpixel(pix, &outpos, &color);
	  pos.y++;
	  outpos.y++;
	}
      outpos.x++;
      pos.x++;
    }
}

void			tektext(t_bunny_pixelarray	*out,
				const char		*str,
				t_bunny_pixelarray	*fontpng)
{
  int			a;
  t_bunny_position	ac;
  int			origin;

  origin = fontpng->clipable.clip_width;
  ac.x = 0;
  ac.y = 0;
  a = 0;
  if (out->clipable.clip_width < 5)
    a = -1;
  while (a >= 0 && str[a] != '\0')
    {
      if (ac.x > out->clipable.clip_width - 5 ||
	  (str[a] == '\n'))
	{
	  if (str[a] == '\n')
	    a++;
	  ac.y += 8;
	  ac.x = 0;
	}
      tekletter(fontpng, str[a]);
      add_pix(fontpng, out, ac, origin);
      ac.x += 1 + fontpng->clipable.clip_width;
      a++;
    }
}
