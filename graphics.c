/*
** display.c for display in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Mon Feb 22 11:24:12 2016 Yan Poinssot
** Last update Wed Mar  2 09:42:28 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	"./include/tekgui.h"

void		read_basic_ini(t_tekgui			*gui,
			       t_bunny_ini		*ini)
{
  gui->font_adress = (char *)(bunny_ini_get_field(ini, NULL, "font", 0));
  if ((gui->max_ram = bunny_ini_get_nbr(ini, NULL, "max_ram", 0)) == -1)
    gui->max_ram = 15;
  gui->background = bunny_malloc(sizeof(unsigned int) * 2);
  (gui->background)[0] =0xFFFFFF;
  (gui->background)[1] = 16579836;
}

t_tekgui	*tekgui_load(const char			*file)
{
  t_list	*item;
  t_bunny_ini	*ini;
  t_tekgui	*gui;

  item = NULL;
  if ((ini = bunny_load_ini(file)) == NULL)
    {
      my_putstr_err("Error: ini filedoesn't exist\n");
      return (NULL);
    }
  if (read_ini(&item, ini) == 1 ||
      (gui = bunny_malloc(sizeof(t_tekgui))) == NULL)
    {
      if (gui == NULL)
	my_putstr_err("Error: Failed to allocate memory\n");
      return (NULL);
    }
  gui->list = item;
  read_basic_ini(gui, ini);
  if ((gui->font = bunny_load_pixelarray(gui->font_adress)) == NULL)
    {
      my_putstr("Error: couldn't load font");
      return (NULL);
    }
  return (gui);
}

int		manage(t_list				*comp,
		       t_bunny_pixelarray		*pix,
		       t_tekgui				gui)
{
  if (my_strcmp(comp->item.type, "button") != -1)
    draw_button(comp->item, pix, gui);
  else if (my_strcmp(comp->item.type, "textbox") != -1)
    draw_textbox(comp->item, pix, gui);
  else if (my_strcmp(comp->item.type, "checkbox") != -1)
    draw_checkbox(comp->item, pix);
  else if (my_strcmp(comp->item.type, "imagebox") != -1)
    draw_image(comp->item, pix, gui);
  return (0);
}

void			tekgui_display(t_bunny_pixelarray	*pix,
				       t_tekgui			*gui)
{
  t_list		*list;
  t_bunny_position	pos[2];

  if (pix != NULL && gui != NULL)
    {
      bunny_set_key_response(&key);
      bunny_set_click_response(&mouse);
      set_max_heap_size(gui->max_ram);
      pos[0].x = 0;
      pos[0].y = 0;
      pos[1].x = pix->clipable.clip_width;
      pos[1].y = pix->clipable.clip_height;
      gradient(pix, pos[0], pos[1], gui->background);
      list = gui->list;
      manage(list, pix, *gui);
      while ((list = list->next) != NULL)
	manage(list, pix, *gui);
    }
}
