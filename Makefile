# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 19:25:52 by ehouot            #+#    #+#              #
#    Updated: 2023/05/30 16:47:04 by ehouot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_PATH	=	./ft_printf/

GNL_PATH	= 	./get_next_line/

SRC 		= 	./main.c \
				./parsing.c \
				./pathing.c \
				./count_line.c \
				./key_hook.c \
				./keys.c \
				./print_sprites.c \
				./initialize.c \
				./ft_tabdup.c \
				./is_door_open.c \
				
SRC_PRINTF	=	 $(addprefix $(PRINTF_PATH), ft_printf.c \
				ft_printf_c_s.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_printf_d_i.c \
				ft_printf_u.c \
				ft_printf_percent.c \
				ft_printf_hexa.c \
				ft_printf_p.c)

SRC_GNL		=	 $(addprefix $(GNL_PATH), get_next_line.c \
				get_next_line_utils.c)

OBJ 		= $(SRC:.c=.o) $(SRC_PRINTF:.c=.o) $(SRC_GNL:.c=.o)

HEADER		= ./

CC 			= clang

MLX			= -lmlx -framework OpenGL -framework AppKit

RM 			= rm -f

CFLAGS 		= -Wall -Werror -Wextra

ifdef DEBUG
	CFLAGS += -fsanitize=address -g3
endif

NAME 		= so_long

all:		$(NAME)

.c.o:
			@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			@$(CC) $(MLX) $(CFLAGS) $(OBJ) -I $(HEADER) -o $(NAME)

debug:
	${MAKE} DEBUG=1

clean:
			@$(RM) $(OBJ)

fclean: 	clean
			@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: 	all clean fclean re 