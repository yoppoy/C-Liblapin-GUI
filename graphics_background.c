/*
** graphics_background.c for background in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue Feb 23 15:56:49 2016 Yan Poinssot
** Last update Wed Mar  2 09:43:39 2016 Yan Poinssot
*/

#include <lapin.h>
#include "./include/tekgui.h"

void			change_background(t_tekgui	*gui)
{
  char			*colour;

  colour = pick_color();
  (gui->background)[0] =0xFFFFFF;
  (gui->background)[1] = 16579836;
  if (my_strcmp(colour, "blue") == 0)
    {
      (gui->background)[0] = 14772545;
      (gui->background)[1] = 9125927;
    }
  else if (my_strcmp(colour, "pink") == 0)
    {
      (gui->background)[0] = 11240191;
      (gui->background)[1] = 9005261;
    }
  else if (my_strcmp(colour, "purple") == 0)
    {
      (gui->background)[0] = 16724123;
      (gui->background)[1] = 9116245;;
    }
  else if (my_strcmp(colour, "red") == 0)
    {
      (gui->background)[0] = 3881966;
      (gui->background)[1] = 2302859;
    }
}

void			set_rgb(double			rgb[3][2],
				double			height,
				t_bunny_color		f,
				t_bunny_color		s)
{
  (rgb)[0][0] = (double)(s.argb[0] - f.argb[0]) / height;
  (rgb)[1][0] = (double)(s.argb[1] - f.argb[1]) / height;
  (rgb)[2][0] = (double)(s.argb[2] - f.argb[2]) / height;
  (rgb)[0][1] = (double)(f.argb[0]);
  (rgb)[1][1] = (double)(f.argb[1]);
  (rgb)[2][1] = (double)(f.argb[2]);
}

void			gradient(t_bunny_pixelarray	*pix,
				 t_bunny_position	set,
				 t_bunny_position	dim,
				 unsigned int		*col)
{
  t_color		color;
  double		rgb[3][2];
  t_bunny_position	pos;
  t_bunny_color		f;
  t_bunny_color		s;

  f.full = col[0];
  s.full = col[1];
  set_rgb(rgb, (double)(dim.y), f, s);
  pos.y = set.y - 1;
  while (++pos.y < set.y + dim.y)
    {
      color.full = f.full;
      pos.x = set.x - 1;
      while (++pos.x < set.x + dim.x)
	tekpixel(pix, &pos, &color);
      rgb[0][1] += rgb[0][0];
      rgb[1][1] += rgb[1][0];
      rgb[2][1] += rgb[2][0];
      f.argb[0] = (int)(rgb[0][1]);
      f.argb[1] = (int)(rgb[1][1]);
      f.argb[2] = (int)(rgb[2][1]);
    }
 }
