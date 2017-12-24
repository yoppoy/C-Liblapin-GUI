/*
** graphics_action_s.c for graphics_action_s in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sun Feb 28 16:45:38 2016 Yan Poinssot
** Last update Wed Mar  2 09:53:33 2016 Yan Poinssot
*/

#include <lapin.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "./include/tekgui.h"

char			get_key(t_bunny_keysym		key)
{
  if (key >= 0 && key <= 25)
    return ((char)(key + 97));
  else if (key >= 26 && key <= 36)
    return ((char)(key + 22));
  else if (key == 57)
    return (' ');
  else if (key == 58)
    return ('\n');
  else if (key >= 47 && key >= 48)
    return ((char)(key - 7));
  else if (key == BKS_SEMICOLON)
    return (':');
  else if (key == BKS_COMMA)
    return (',');
  else if (key == BKS_PERIOD)
    return ('.');
  else if (key == BKS_SLASH)
    return ('/');
  else if (key == BKS_QUOTE)
    return ('"');
  else if (key == BKS_QUOTE)
    return ('"');
  else
    return ('!');
}

t_bunny_response	key(t_bunny_event_state		state,
			    t_bunny_keysym		key,
			    void			*data)
{
  t_win			*gui;
  t_item		*item;
  char			let;

  gui = (t_win *)(data);
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && (item = get_writtenbox(gui->gui)) != NULL)
    {
      if (key == BKS_BACKSPACE)
	{
	  if ((item->text)[0] != '\0')
	    (item->text)[my_strlen(item->text) - 1] = '\0';
	}
      else if ((let = get_key(key)) != '!')
	add_let(&(item->text), let);
      if (item->argument != NULL && item->function != NULL)
	item->function(item->argument);
      else if (item->function != NULL)
	item->function(item->text);
    }
  return (GO_ON);
}

t_bunny_response	mouse(t_bunny_event_state	state,
			      t_bunny_mouse_button	button,
			      void			*data)

{
  t_win			*gui;
  int			temp;
  static int		pos = -1;
  char			state_s;
  char			l;

  gui = (t_win *)(data);
  if (state == GO_DOWN && button == 0)
    {
      l = check_item(bunny_get_mouse_position(), gui->gui->list, &pos);
      temp = pos;
      if (l == 'c')
	set_checked(&(gui->gui->list), temp);
      gui->gui->clicked = 1;
    }
  else if (state == GO_UP && button == 0)
    {
      if (!((l = check_item(bunny_get_mouse_position(), gui->gui->list,
			    &temp)) == 't' && temp == pos && temp != -1))
	gui->gui->clicked = 0;
      if (gui->gui->list->item.function == tekfunction("change_background"))
	change_background(gui->gui);
    }
  state_s = (gui->gui->clicked == 1) ? '1' : '0';
  set_selected(&(gui->gui->list), temp, state_s);
  pos = (state == GO_UP) ? -1 : pos;
  return (GO_ON);
}

char			*pick_color()
{
  static int		rand = -1;

  rand++;
  if (rand == 5)
    rand = 0;
  if (rand == 0)
    return ("red");
  if (rand == 1)
    return ("blue");
  if (rand == 2)
    return ("pink");
  if (rand == 3)
    return ("purple");
  return ("brown");
}

int			change_color(char *name, t_list **list)
{
  t_list		*item;

  item = *list;
  write(1, "h", 1);
  if (name == NULL)
    return (-1);
  while (item != NULL)
    {
      if (my_strcmp(name, item->item.name) != -1)
	{
	  bunny_free(item->item.color);
	  (item->item.color) = my_strcpy(pick_color());
	  return (0);
	}
      item = item->next;
    }
  my_putstr_err("Error: Component name doesn't match any item\n");
  return (-1);
}
