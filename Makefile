##
## Makefile for fdf in /home/chapui_s/rendu/MUL_2013_fdf
## 
## Made by chapui_s
## Login   <chapui_s@epitech.net>
## 
## Started on  Sun Dec  8 23:22:02 2013 chapui_s
## Last update Sun Dec  8 23:22:18 2013 chapui_s
##

SRC	= main.c \
	  get_next_line.c \
	  linked_list.c \
	  map.c \
	  my_getnbr.c \
	  my_str_to_wordtab.c \
	  utils.c \
	  disp_fdf.c \
	  get_in_list.c \
	  print_line.c \
	  errors.c \
	  move_map.c \
	  rot_map.c \
	  events.c \
	  free_wordtab.c

NAME	= fdf

CFLAGS	= -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	gcc -c $(SRC) -O3
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
