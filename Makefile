# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 05:15:37 by kpawlows          #+#    #+#              #
#    Updated: 2023/02/24 07:49:46 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRC_DIR	=	src/
OBJ_DIR	=	obj/
CC 		=	gcc
FLAGS	=	-Wall -Werror -Wextra
LIBFT	=	$(SRC_DIR)libft/libft.a
GNL		=	$(SRC_DIR)gnl/libgnl.a
MLX		=	$(SRC_DIR)mlx/libmlx.a
MLX_F	=	-framework OpenGL -framework AppKit
AR 		=	ar -rcs
LINK 	=	$(CC) $(FLAGS)
RM		=	rm -f
SRC 	= 	$(SRC_DIR)main.c \
			$(SRC_DIR)so_long.c \
			$(SRC_DIR)check_map_1.c \
			$(SRC_DIR)check_map_2.c \
			$(SRC_DIR)draw.c \
			$(SRC_DIR)handle.c \
			$(SRC_DIR)init.c \
			$(SRC_DIR)move.c \
			$(SRC_DIR)dbg_utils.c
OBJ		=	$(SRC:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME) link

$(NAME): $(SRC)
	@$(MAKE) -C $(SRC_DIR)libft
	@$(MAKE) -C $(SRC_DIR)gnl
	@$(MAKE) -C $(SRC_DIR)mlx
	@$(CC) $(FLAGS) -c $(SRC)
	@mv *.o $(SRC_DIR)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	
link : $(NAME) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(GNL) $(MLX) $(MLX_F)  -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@$(RM) $(OBJ)
	@cd $(SRC_DIR)libft && $(MAKE) clean 
	@cd $(SRC_DIR)gnl && $(MAKE) clean 
	@cd $(SRC_DIR)mlx && $(MAKE) clean
	@$(RM) $(SRC_DIR)libft/libft.a
	@printf "[$(NAME)]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@cd $(SRC_DIR)libft && $(MAKE) fclean
	@cd $(SRC_DIR)gnl && $(MAKE) fclean
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"