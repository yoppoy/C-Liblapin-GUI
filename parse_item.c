/*
** list.c for list in /home/poinss_y/Documents/Infographie/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed Feb 17 17:18:27 2016 Yan Poinssot
** Last update Tue Mar  1 19:02:30 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	"./include/tekgui.h"

void		free_item(t_item *item)
{
  if (item->type != NULL)
    bunny_free(item->type);
  if (item->name != NULL)
    bunny_free(item->name);
  if (item->color != NULL)
    bunny_free(item->color);
  if (item->text != NULL)
    bunny_free(item->text);
  if (item->img != NULL)
    bunny_free(item->img);
  if (item->border != NULL)
    bunny_free(item->border);
  if (item->pix != NULL)
    bunny_delete_clipable(&(item->pix->clipable));
}

int		create_item(t_item *item)
{
  if ((item = bunny_malloc(sizeof(t_item))) == NULL)
    {
      my_putstr("Error: memory allocation failed\n");
      return (1);
    }
  item->type = NULL;
  item->name = NULL;
  item->text = NULL;
  item->function = NULL;
  item->argument = NULL;
  item->border = NULL;
  item->img = NULL;
  item->pos.x = -1;
  item->pos.y = -1;
  item->dim.x = -1;
  item->dim.x = -1;
  item->state = '0';
  item->check = '0';
  return (0);
}

int		add_node(t_list **list, t_item item)
{
  t_list	*find;
  t_list	*node;

  find = *list;
  if (*list != NULL && find->next != NULL)
    while ((find = find->next)->next != NULL);
  if ((node = bunny_malloc(sizeof(t_list))) == NULL)
    {
      my_putstr_err("Error: memory couldn't be allocated\n");
      return (1);
    }
  node->item = item;
  node->next = NULL;
  if (*list == NULL)
    *list = node;
  else
    find->next = node;
  return (0);
}

int		free_all(t_list **list)
{
  t_list	*find;

  while ((*list)->next != NULL)
    {
      find = *list;
      while (find->next != NULL)
	find = find->next;
      free_item(&(find->item));
    }
  return (0);
}
