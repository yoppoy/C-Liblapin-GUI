/*
** main.c for maintest in /home/poinss_y/Documents/Infographie/chromatic_2042
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed Feb 10 09:10:22 2016 Yan Poinssot
** Last update Wed Mar  2 01:58:01 2016 Yan Poinssot
*/

#include <lapin.h>
#include <unistd.h>
#include "../../include/tekgui.h"
#include "base.h"

t_bunny_response	loop(void			*import)
{
  t_win			*data;
  t_bunny_position	pos;

  data = (t_win *)(import);
  pos.x = 0;
  pos.y = 0;
  bunny_blit(&(data->win)->buffer, &(data->pix->clipable), &pos);
  bunny_display(data->win);
  return (GO_ON);
}

int			main()
{
  t_win			data;
  t_bunny_pixelarray    *pix;
  t_bunny_window        *win;

  win = bunny_start(1000, 700, false, "tek_gui");
  pix = load_bitmap("DSC_1744.bmp");
  data.win = win;
  data.pix = pix;
  bunny_set_loop_main_function(&loop);
  bunny_loop(win, 30, &data);
  bunny_delete_clipable(&(pix->clipable));
  bunny_stop(win);
  return (0);
}
