/*
** main.c for maintest in /home/poinss_y/Documents/Infographie/chromatic_2042
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed Feb 10 09:10:22 2016 Yan Poinssot
** Last update Tue Mar  1 16:56:13 2016 Yan Poinssot
*/

#include <lapin.h>
#include <unistd.h>
#include "./../include/tekgui.h"

t_bunny_response	loop(void			*import)
{
  t_win			*data;
  t_bunny_position	pos;

  data = (t_win *)(import);
  pos.x = 0;
  pos.y = 0;
  tekgui_display(data->pix, data->gui);
  bunny_blit(&(data->win)->buffer, &(data->pix->clipable), &pos);
  bunny_display(data->win);
  return (GO_ON);
}

int			main(int			argc,
			     char			**argv)
{
  t_win			data;
  t_bunny_pixelarray    *pix;
  t_bunny_window        *win;
  const char		*file;

  file = (const char *)(argv[1]);
  if (argc > 0 && (data.gui = tekgui_load(file)) == NULL)
    return (1);
  win = bunny_start(640, 430, false, "tek_gui");
  pix = bunny_new_pixelarray(640, 430);
  data.win = win;
  data.pix = pix;
  bunny_set_loop_main_function(&loop);
  bunny_loop(win, 30, &data);
  bunny_delete_clipable(&(pix->clipable));
  bunny_delete_clipable(&(data.gui->font->clipable));
  bunny_stop(win);
  return (0);
}
