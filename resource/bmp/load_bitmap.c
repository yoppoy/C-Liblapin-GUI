/*
** load_bitmap.c for load_bmp in /home/poinss_y/Documents/Infographie/gfx_tekgui/resource/bmp
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed Mar  2 01:58:34 2016 Yan Poinssot
** Last update Wed Mar  2 01:58:35 2016 Yan Poinssot
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		"./base.h"

t_bunny_pixelarray	*my_loadnoalpha(t_bunny_pixelarray *pix,
					int fd, t_hbmp *hbmp)
{
  t_bunny_position	pos;
  t_color		g_color;
  char			take_color[3];

  pos.y = hbmp->height;
  while (pos.y > 0)
    {
      pos.x = 0;
      while (pos.x < hbmp->width && read(fd, take_color, 3) == 3)
	{
	  g_color.argb[0] = take_color[2];
	  g_color.argb[1] = take_color[1];
	  g_color.argb[2] = take_color[0];
	  g_color.argb[3] = 255;
	  ((unsigned int *)pix->pixels)
	    [(pos.y - 1) * hbmp->width + pos.x] = g_color.full;
	  pos.x++;
	}
      pos.y--;
    }
  return (pix);
}

t_bunny_pixelarray	*my_loading(t_bunny_pixelarray *pix,
				    int fd, t_hbmp *hbmp)
{
  t_bunny_position	pos;
  t_color		g_color;
  char			take_color[4];
  unsigned int		save;

  pos.y = hbmp->height;
  while (pos.y > 0)
    {
      pos.x = 0;
      while (pos.x < hbmp->width && read(fd, take_color, 4) == 4)
	{
	  g_color.full = (*(unsigned int *)take_color);
	  save = g_color.argb[0];
	  g_color.argb[0] = g_color.argb[2];
	  g_color.argb[2] = save;
	  ((unsigned int *)pix->pixels)
	    [(pos.y - 1) * hbmp->width + pos.x] = g_color.full;
	  pos.x++;
	}
      pos.y--;
    }
  return (pix);
}

t_bunny_pixelarray	*load_bitmap(const char *name_file)
{
  t_bunny_pixelarray	*pix;
  int			fd;
  t_hbmp		*hbmp;

  if ((fd = open(name_file, O_RDONLY)) == -1)
    return (NULL);
  if ((hbmp = bunny_malloc(sizeof(t_hbmp))) == NULL)
    return (NULL);
  if (read(fd, hbmp, sizeof(t_hbmp)) == -1)
    return (NULL);
  if (hbmp->id != 0x4D42 || hbmp->cprs != 0 || hbmp->p_bit != 1 ||
      hbmp->width <= 0 || hbmp->height <= 0 || hbmp->head_size != 40)
    return (NULL);
  if (hbmp->bits_pix != 32 && hbmp->bits_pix != 24)
    return (NULL);
  read(fd, NULL, hbmp->pos_pix - 54);
  pix = bunny_new_pixelarray(hbmp->width, hbmp->height);
  if (hbmp->bits_pix == 32)
    pix = my_loading(pix, fd, hbmp);
  else
    pix = my_loadnoalpha(pix, fd, hbmp);
  close(fd);
  bunny_free(hbmp);
  return (pix);
}
