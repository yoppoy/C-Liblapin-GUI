/*
** graphics_color.c for color in /home/poinss_y/Documents/Infographie/save/gfx_tekgui
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sat Feb 27 19:00:33 2016 Yan Poinssot
** Last update Tue Mar  1 16:48:18 2016 Yan Poinssot
*/

#include	<lapin.h>
#include	"./include/tekgui.h"

static void		extract_color_s(unsigned int	back[2],
					t_item		item)
{
  if (my_strcmp(item.color, "yellow") == 0)
    {
      back[0] = 55295;
      back[1] = 1940429;
    }
  else if (my_strcmp(item.color, "orange") == 0)
    {
      back[0] = 36095;
      back[1] = 26317;
    }
  else if (my_strcmp(item.color, "green") == 0)
    {
      back[0] = 4033390;
      back[1] = 3107669;
    }
  else if (my_strcmp(item.color, "turquoise") == 0)
    {
      back[0] = 13485312;
      back[1] = 9143808;
    }
  else if (my_strcmp(item.color, "white") == 0)
    {
      back[0] = 16777215;
      back[1] = 13882323;
    }
}

void			extract_color(unsigned int	back[2],
				      t_item		item)
{
  back[0] = 9470064;
  back[1] = 5395026;
  if (my_strcmp(item.color, "blue") == 0)
    {
      back[0] = 14772545;
      back[1] = 9125927;
    }
  else if (my_strcmp(item.color, "pink") == 0)
    {
      back[0] = 11240191;
      back[1] = 9005261;
    }
  else if (my_strcmp(item.color, "purple") == 0)
    {
      back[0] = 16724123;
      back[1] = 9116245;
    }
  else if (my_strcmp(item.color, "red") == 0)
    {
      back[0] = 3881966;
      back[1] = 2302859;
    }
  else
    extract_color_s(back, item);
}
