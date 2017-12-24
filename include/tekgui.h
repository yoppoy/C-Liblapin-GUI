/*
** my.h for functions in /home/poinss_y/Infographie/gfx_fdf2
**
** Made by yan poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Mon Dec 14 12:15:46 2015 yan poinssot
** Last update Wed Mar  2 09:48:52 2016 Yan Poinssot
*/

#ifndef TEKGUI_H_
#define TEKGUI_H_

#include <lapin.h>

typedef struct		s_item
{
  char			*type;
  char			*name;
  char			*color;
  char			*text;
  char			*img;
  char			*border;
  char			state;
  char			check;
  void			(*function)(void *);
  void			*argument;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_bunny_position	dim;
}			t_item;

typedef struct		s_list
{
  t_item		item;
  struct s_list		*next;
}			t_list;

typedef struct          s_tekgui
{
  unsigned int		*background;
  int			clicked;
  int			max_ram;
  t_list		*list;
  char			*font_adress;
  t_bunny_pixelarray	*font;
} t_tekgui;

typedef struct		s_win
{
  t_tekgui		*gui;
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}                       t_win;

void		set_max_heap_size(size_t);

void		tekpixel(t_bunny_pixelarray		*pix,
			 t_bunny_position      		*pos,
			 t_color			*color);

void		*tekfunction(const char			*funcname);

void		tektext(t_bunny_pixelarray		*out,
			const char			*str,
			t_bunny_pixelarray		*font_png);

int		parse(t_list				**item,
		      const char			*file);

int		read_ini(t_list				**item,
			 t_bunny_ini			*ini);

int		bunny_ini_get_nbr(t_bunny_ini		*ini,
				  char			*sc,
				  char			*field,
				  int			n);

void		free_item(t_item			*item);

int		create_item(t_item			*item);

int		add_node(t_list				**list,
			 t_item				item);

int		free_all(t_list				**list);

int		my_strlen(char				*word);

void		my_putstr(char				*word);

void		my_putstr_err(char			*word);

char		*my_malloc(int				num);

char		*my_strcpy(char				*word);

int		my_strcmp(char				*word,
			  char				*words);

int		my_getnbr(char				*num);

int		check_num(char				*word);

void		add_let(char				**item,
			char				let);

char		check_item(const t_bunny_position	*pos,
			   t_list			*list,
			   int				*poss);

int		set_selected(t_list			**list,
			     int			pos,
			     char			state);

int		set_checked(t_list			**list,
			    int				pos);

t_item		*get_writtenbox(t_tekgui		*gui);

void		square(t_bunny_pixelarray		*pix,
		       t_bunny_position			pos,
		       t_bunny_position			dim,
		       t_color				*color);

void		square_line(t_bunny_pixelarray		*pix,
			    t_bunny_position		pos,
			    t_bunny_position		dim,
			    t_color			*color);

void		selected(t_bunny_pixelarray		*pix,
			 t_bunny_position		pos,
			 t_bunny_position		dim,
			 t_color			*color);

void		checked(t_bunny_pixelarray		*pix,
			t_bunny_position		pos,
			t_bunny_position		dim,
			t_color				*color);

void		circle_out(t_bunny_pixelarray		*pix,
			   t_bunny_position		*pos,
			   double			radius,
			   t_color			*color);

void		circle_in(t_bunny_pixelarray		*pix,
			  t_bunny_position		*pos,
			  int				radius,
			  t_color			*color);

void		gradient(t_bunny_pixelarray		*pix,
			 t_bunny_position		pos,
			 t_bunny_position		dim,
			 unsigned int			*sec);

void		write_text(t_bunny_pixelarray	       	**pix,
			   t_bunny_position		*set,
			   const char			*str,
			   t_color			*col);

void		draw_button(t_item			item,
			    t_bunny_pixelarray		*pix,
			    t_tekgui			gui);

void		draw_textbox(t_item			item,
			     t_bunny_pixelarray		*pix,
			     t_tekgui			gui);

void		draw_radio(t_item			item,
			   t_bunny_pixelarray		*pix);

int		draw_image(t_item			item,
			   t_bunny_pixelarray		*pix,
			   t_tekgui			gui);

void		draw_checkbox(t_item			item,
			      t_bunny_pixelarray	*pix);

void		center(t_bunny_position			*dim,
		       t_bunny_position			*pos,
		       char				*word);

unsigned int	tekgetpixel(t_bunny_pixelarray		*pix,
			    int				x,
			    int				y);

void		background(t_bunny_pixelarray		*pix,
			   t_color			*color);

void		tekline(t_bunny_pixelarray		*pix,
			t_bunny_position		*pos,
			t_color				*color);

void		paste_pix(t_bunny_pixelarray		*copy,
			  t_bunny_pixelarray		*out,
			  t_bunny_position		pos,
			  t_bunny_position		dim);

void		extract_color(unsigned int		back[2],
			      t_item			item);

int		load_image(t_item			*new);

t_tekgui	*tekgui_load(const char			*file);

void		tekgui_display(t_bunny_pixelarray	*pix,
			       t_tekgui			*gui);

int		change_color(char			*name,
			     t_list			**list);

void		change_background(t_tekgui		*gui);

char		*pick_color();

char		get_key(t_bunny_keysym			key);

t_bunny_response	key(t_bunny_event_state		state,
			    t_bunny_keysym		key,
			    void			*data);

t_bunny_response	mouse(t_bunny_event_state	state,
			      t_bunny_mouse_button	button,
			      void			*data);

#endif
