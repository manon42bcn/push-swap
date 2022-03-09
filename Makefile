# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 02:38:37 by mporras-          #+#    #+#              #
#    Updated: 2022/03/06 01:21:46 by mporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 =	push_swap
#BONUS_NAME   =	checker
LIB 		 =	libft.a
LIB_DIR 	 =	libft/
SRC_DIR		 =	srcs
#BONUS_DIR    =	bonus
SRCS_FILES	 =	ps_actions.c \
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
			  	ps_stack_utils.c \
			  	ps_sub_stacks.c \
				ps_utils.c \
				push_swap.c
#BONUS_FILES	 =	ps_checker.c \
				get_next_line.c \
				get_next_line_utils.c
#BONUS_SRCS	 = $(addprefix $(BONUS_DIR)/,$(BONUS_FILES))
#BONUS_OBJS	 = $(BONUS_FILES:.c=.o)
SRCS 		 =	$(addprefix $(SRC_DIR)/,$(SRCS_FILES))
OBJS		 =	$(SRCS_FILES:.c=.o)
CC			 =	gcc
RM			 = 	rm	-f
CFLAGS		 =	-Wall -Wextra -Werror
INCLUDES	 =	-Iinc/push_swap.h
#INCLUDES_BNS =	-Iinc/checker.h

all: $(NAME)
 
$(NAME): $(OBJS) $(LIB_DIR)$(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_DIR)$(LIB)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)

$(LIB_DIR)$(LIB):
	$(MAKE) bonus -C $(LIB_DIR)

#bonus: $(BONUS_OBJS) $(LIB_DIR)$(LIB)
#	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIB_DIR)$(LIB)

#$(BONUS_OBJS): $(BONUS_SRCS)
#	$(CC) $(CFLAGS) -c -D BUFFER_SIZE=200 $(INCLUDES_BNS) $(BONUS_SRCS)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME) $(BONUS_NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re push_swap
