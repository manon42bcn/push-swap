# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 02:38:37 by mporras-          #+#    #+#              #
#    Updated: 2022/02/27 02:38:44 by mporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 =	push-swap
LIB 		 =	libft.a
LIB_DIR 	 =	libft/
SRC_DIR		 =	srcs
SRCS_FILES	 =	ps_actions.c \
			  	ps_actions_utils.c \
			  	ps_cases_solve.c \
			  	ps_do_actions.c \
			  	ps_load_stack.c \
			  	ps_loading_utils.c \
			  	ps_small_cases.c \
			  	ps_solver_utils.c \
			  	ps_stack_utils.c \
			  	ps_utils.c
#BONUS_FILES	 = ft_printf_bonus.c \
			   ft_printf_input_bonus.c \
			   ft_printf_utils_bonus.c \
			   ft_token_hexa_bonus.c \
			   ft_token_numbers_bonus.c \
			   ft_token_process_bonus.c \
			   ft_token_strings_bonus.c
#BONUS_SRCS	 = $(addprefix $(SRC_DIR)/,$(BONUS_FILES))
#BONUS_OBJS	 = $(BONUS_FILES:.c=.o)
SRCS 		 =	$(addprefix $(SRC_DIR)/,$(SRCS_FILES))
OBJS		 =	$(SRCS_FILES:.c=.o)
CC			 =	gcc
RM			 = 	rm	-f
CFLAGS		 =	-Wall -Wextra -Werror
INCLUDES	 =	-Iinc/push_swap.h
INCLUDES_BNS =	inc/ft_printf_bonus.h

all: $(NAME)
 
$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_DIR)$(LIB)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)

$(LIB):
	$(MAKE) bonus -C $(LIB_DIR)

bonus: $(BONUS_OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar	rcs	$(NAME)	$(BONUS_OBJS)
	ranlib $(NAME)

$(BONUS_OBJS): $(BONUS_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES_BNS) $(BONUS_SRCS)

clean:
	$(MAKE) -C ./libft fclean
	$(RM) $(OBJS) #$(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re bonus
