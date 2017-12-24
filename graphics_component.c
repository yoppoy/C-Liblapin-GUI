/*
** button.c for button in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Mon Feb 22 13:37:13 2016 Yan Poinssot
** Last update Tue Mar  1 18:53:20 2016 Yan Poinssot
*/

#include <lapin.h>
#include <stdio.h>
#include "./include/tekgui.h"

void			draw_button(t_item		item,
				    t_bunny_pixelarray	*pix,
				    t_tekgui		gui)
{
  t_color		color;
  unsigned int		paint[2];
  t_bunny_position	pos[2];
  t_bunny_pixelarray	*write[2];

  extract_color(paint, item);
  color.full = paint[0];
  square(pix, item.pos, item.dim, &color);
  color.full = paint[1];
  if (item.border != NULL)
    square_line(pix, item.pos, item.dim, &color);
  if (item.state == '1')
    selected(pix, item.pos, item.dim, &color);
  write[0] = pix;
  write[1] = gui.font;
  item.pos.x += 2;
  item.pos.y += 2;
  pos[0] = item.pos;
  pos[1] = item.dim;
  color.full = WHITE;
  center(&pos[1], &pos[0], item.text);
  if (item.text != NULL)
    write_text(write, pos, item.text, &color);
}

void			draw_textbox(t_item		item,
				     t_bunny_pixelarray	*pix,
				     t_tekgui		gui)
{
  t_color		color;
  unsigned int		paint[2];
  t_bunny_position	pos[2];
  t_bunny_pixelarray	*write[2];

  pos[0].y = 4;
  pos[0].x = item.dim.x;
  extract_color(paint, item);
  color.full = WHITE;
  square(pix, item.pos, item.dim, &color);
  gradient(pix, item.pos, pos[0], paint);
  color.full = paint[1];
  if (item.border != NULL)
    square_line(pix, item.pos, item.dim, &color);
  if (item.state == '1')
    selected(pix, item.pos, item.dim, &color);
  item.pos.y += 6;
  item.pos.x += 3;
  item.dim.y -= 6;
  item.dim.x -= 3;
  pos[0] = item.pos;
  pos[1] = item.dim;
  write[0] = pix;
  write[1] = gui.font;
  write_text(write, pos, (const char *)(item.text), &color);
}

void			draw_checkbox(t_item			item,
				      t_bunny_pixelarray	*pix)
{
  t_color		color;
  unsigned int		paint[2];
  t_bunny_position	pos[2];

  pos[0].y = 4;
  pos[0].x = item.dim.x;
  extract_color(paint, item);
  color.full = WHITE;
  item.dim.y = item.dim.x;
  square(pix, item.pos, item.dim, &color);
  gradient(pix, item.pos, pos[0], paint);
  color.full = paint[1];
  if (item.border != NULL)
    square_line(pix, item.pos, item.dim, &color);
  if (item.check == '1')
    checked(pix, item.pos, item.dim, &color);
}
