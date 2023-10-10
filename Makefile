# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporras <mporras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 02:38:37 by mporras-          #+#    #+#              #
#    Updated: 2022/10/23 21:55:13 by mporras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 	=	push_swap
LIB 		 	=	libft.a
LIB_DIR			=	libft
SRC_DIR			=	srcs
OBJ_DIR			=	objs
OBJS_SUBS		=	objs
BONUS_DIR		=	bonus
SRCS_FILES	 	=	ps_actions.c \
					ps_candidates_to_pull.c \
					ps_cases_solve.c \
					ps_clear_stacks.c \
					ps_check_solve.c \
					ps_do_actions.c \
					ps_find_cuts.c \
					ps_loading_checks.c \
					ps_loading_utils.c \
					ps_nodes_get.c \
					ps_presort.c \
					ps_small_cases.c \
					ps_solver_utils.c \
					ps_spin_sort.c \
					ps_sub_stacks.c \
					ps_utils.c \
					push_swap.c
SRCS 		 	=	$(addprefix $(SRC_DIR)/,$(SRCS_FILES))
OBJS		 	=	$(addprefix $(OBJ_DIR)/,$(SRCS_FILES:.c=.o))
CC			 	=	gcc
RM			 	= 	rm	-rf
CFLAGS		 	=	-Wall -Wextra -Werror
INCLUDES	 	=	-Iinc -Ilibft

all: $(OBJS_SUBS) libs $(NAME)
 
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIB_DIR)/$(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIB_DIR)/$(LIB) inc/push_swap.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS_SUBS):
	-mkdir $(OBJS_SUBS)

libs:
	$(MAKE) -C $(LIB_DIR)

bonus:
	$(MAKE) -C $(BONUS_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(OBJS_SUBS)

re:	fclean libs $(OBJS_SUBS) $(NAME)

.PHONY: all clean fclean re push_swap
