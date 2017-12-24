/*
** my.h for functions in /home/poinss_y/Infographie/gfx_fdf2
**
** Made by yan poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Mon Dec 14 12:15:46 2015 yan poinssot
** Last update Sat Feb 27 20:31:32 2016 Yan Poinssot
*/

#ifndef MY_H_
#define MY_H_

#include <lapin.h>

void		tekpixel(t_bunny_pixelarray	*pix,
			 t_bunny_position	*pos,
			 t_color		*color);

void		*tekfunction(const char		*funcname);

void		tektext(t_bunny_pixelarray	*out,
			const char		*str,
			t_bunny_pixelarray	*font_png);
#endif
