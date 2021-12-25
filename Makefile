# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 20:49:40 by crendeha          #+#    #+#              #
#    Updated: 2021/12/22 15:34:59 by crendeha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		cub3D
LIBFT_PATH		=		libft/
MLX_PATH		=		mlx/
LIBFT			=		$(LIBFT_PATH)libft.a
MLX				=		$(MLX_PATH)libmlx.a
SRC_PATH		=		src/
SRC 			= 		main.c																						\
						gnl/get_next_line.c																			\
						errors/errors.c																				\
						drawing/initialize_textures.c      drawing/draw.c         	        drawing/draw_utils.c 	\
						drawing/dda.c				       drawing/draw_floor_and_ceil.c 	drawing/draw_walls.c	\
						drawing/handle_keys_and_mouse.c    drawing/handle_moves.c									\
						parsing/read_conv_map.c		 	   parsing/process_start.c          parsing/get_map.c		\
						parsing/get_map_2.c			       parsing/check_valid_map.c	    parsing/map_utils.c		\
						parsing/get_textures.c		       parsing/get_textures_2.c		    parsing/init_mapinfo.c	\
						parsing/rgb.c
OBJ 			=		$(patsubst %.c,%.o,$(addprefix $(SRC_PATH),$(SRC)))
D_FILES 		=		$(patsubst %.c,%.d,$(addprefix $(SRC_PATH),$(SRC)))
OPTFLAGS 		=		-O2
CFLAGS 			= 		-Wall -Wextra -Werror

all 			: 		$(LIBFT) $(MLX) $(NAME)

$(LIBFT)		:
						make -s -C $(LIBFT_PATH)

$(MLX)		:
						make -s -C $(MLX_PATH)

$(NAME)		 	:		$(OBJ)
						gcc $(CFLAGS) $(OPTFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
						@echo "cub3D is ready to launch"

%.o 			: 		%.c
						gcc $(CFLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

test			:
						@gcc test.c -lmlx -framework OpenGL -framework AppKit
						@echo "OK. MLX READY\n"

clean 			: 
						@make -C $(LIBFT_PATH) clean
						@make -C $(MLX_PATH) clean
						@rm -f $(OBJ) $(D_FILES)

fclean 			: 		clean
						@make -C $(LIBFT_PATH) fclean
						@rm -f $(NAME)

re 				: 		fclean all

.PHONY			: 		all clean fclean re
