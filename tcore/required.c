/*
** correction.c for required in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Mon Feb 15 17:48:12 2016 Yan Poinssot
** Last update Sun Feb 28 13:40:56 2016 Yan Poinssot
*/

#include        <lapin.h>
#include	<dlfcn.h>
#include	<stdio.h>
#include	"my.h"

void		tekpixel(t_bunny_pixelarray	*pix,
			 t_bunny_position	*pos,
			 t_color		*color)
{
  if (pos->x < pix->clipable.clip_width && pos->y < pix->clipable.clip_height
      && pos->x >= 0 && pos->y >= 0)
    ((t_color *)(pix->pixels))
      [pix->clipable.clip_width * pos->y + pos->x] = *color;
}

void		*tekfunction(const char		*funcname)
{
  void		*handle;
  void		*back;

  handle = dlopen(NULL, RTLD_LAZY | RTLD_NOW);
  back = dlsym(handle, funcname);
  return (back);
}
