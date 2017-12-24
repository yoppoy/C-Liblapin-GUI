/*
** parse.c for parse in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed Feb 17 16:58:20 2016 Yan Poinssot
** Last update Wed Mar  2 09:23:07 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	<unistd.h>
#include	"./include/tekgui.h"

char		*get_scope(int n)
{
  char		*word;
  int		count;
  int		m;

  count = 0;
  m = n;
  while (m != 0)
    {
      m = m / 10;
      count++;
    }
  word = bunny_malloc(sizeof(char) * (count + 6));
  word[0] = 'i';
  word[1] = 't';
  word[2] = 'e';
  word[3] = 'm';
  count = 4;
  while (n != 0)
    {
      word[count] = (n % 10) + 48;
      n = n / 10;
      count++;
    }
  word[count] = '\0';
  return (word);
}

int		bunny_ini_get_nbr(t_bunny_ini *ini, char *sc, char *field, int n)
{
  int		back;
  char		*temp;

  temp = (char *)(bunny_ini_get_field(ini, sc, field, n));
  if (temp == NULL)
    return (-1);
  else if (check_num(temp) == 0 && temp[0] != '-')
    back = my_getnbr(temp);
  else
    {
      my_putstr_err("Error: ");
      my_putstr_err(temp);
      my_putstr_err(" not a positive number\n");
      back = -1;
    }
  return (back);
}

int		extract_ini(t_bunny_ini *ini, char *sc, t_item *new)
{
  new->name = my_strcpy((char *)(bunny_ini_get_field(ini, sc, "name", 0)));
  new->color = my_strcpy((char *)(bunny_ini_get_field(ini, sc, "color", 0)));
  new->pos.x = bunny_ini_get_nbr(ini, sc, "position", 0);
  new->pos.y = bunny_ini_get_nbr(ini, sc, "position", 1);
  new->dim.x = bunny_ini_get_nbr(ini, sc, "dimension", 0);
  new->dim.y = bunny_ini_get_nbr(ini, sc, "dimension", 1);
  new->text = my_strcpy((char *)(bunny_ini_get_field(ini, sc, "text", 0)));
  new->img = my_strcpy((char *)(bunny_ini_get_field(ini, sc, "img", 0)));
  new->border = my_strcpy((char *)(bunny_ini_get_field(ini, sc, "border", 0)));
  new->check = (bunny_ini_get_nbr(ini, sc, "check", 0) == 1) ? '1' : '0';
  if ((bunny_ini_get_field(ini, sc, "function", 0)) != NULL)
    new->function = tekfunction((bunny_ini_get_field(ini, sc, "function", 0)));
  new->argument = (void *)(bunny_ini_get_field(ini, sc, "function", 1));
  new->state = '0';
  if (new->name == NULL || new->pos.x == -1 || new->pos.y == -1)
    {
      if (new->name == NULL)
	my_putstr_err("Error: item missing required field (type, name, pos)\n");
      return (1);
    }
  if (new->text == NULL)
    {
      new->text = bunny_malloc(sizeof(char) * 1);
      new->text[0] = '\0';
    }
  return (0);
}

int		check_type(char *type)
{
  if (my_strcmp(type, "button") == 0);
  else if (my_strcmp(type, "textbox") == 0);
  else if (my_strcmp(type, "checkbox") == 0);
  else if (my_strcmp(type, "imagebox") == 0);
  else if (my_strcmp(type, "radiobutton") == 0);
  else
    {
      my_putstr_err("Error: ");
      my_putstr_err(type);
      my_putstr_err(" unknown type\n");
      return (-1);
    }
  return (0);
}

int		read_ini(t_list **item, t_bunny_ini *ini)
{
  char		*sc;
  t_item	new;
  int		a;

  a = 1;
  while (a > 0)
    {
      sc = get_scope(a);
      create_item(&new);
      if ((new.type = (char *)(bunny_ini_get_field(ini, sc, "type", 0)))
	  == NULL)
	return (0);
      if (check_type(new.type) == -1 || extract_ini(ini, sc, &new) == 1 ||
	  load_image(&new) == -1)
	return (1);
      add_node(item, new);
      my_putstr("Notif: Added one new item: --");
      my_putstr(new.name);
      write(1, " : ", 3);
      my_putstr(new.type);
      write(1, "--\n", 3);
      a++;
    }
  bunny_free(sc);
  return (0);
}
