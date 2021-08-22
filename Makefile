# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 21:16:21 by bahn              #+#    #+#              #
#    Updated: 2021/08/22 17:36:24 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

PUSH_SWAP		= push_swap
CHECKER			= checker

INCFLAGS		= -I./includes -I./libft

LIB_DIR			= ./libft
LINK_LIBFT		= -Llibft -lft

SRCS_DIR		= ./srcs/
SRCS_NAME		= a_to_b.c b_to_a.c \
					frame.c stack.c command.c sort_check.c exception.c\
					length.c element.c pivot.c \
					swap.c push.c rotate.c reverse_rotate.c
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS			= $(SRCS:.c=.o)

PUSHSWAP_SRCS		= ./srcs/push_swap.c
PUSHSWAP_OBJS		= $(PUSHSWAP_SRCS:.c=.o)

CHECKER_SRCS		= ./bonus/checker.c ./bonus/get_next_line.c
CHECKER_OBJS		= $(CHECKER_SRCS:.c=.o)

all				: $(PUSH_SWAP)

bonus			: $(CHECKER)

$(PUSH_SWAP) 	: $(OBJS) $(PUSHSWAP_OBJS)
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

$(CHECKER)		: $(OBJS) $(CHECKER_OBJS)
				$(MAKE) all
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

.c.o			:
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean			:
				$(MAKE) -C $(LIB_DIR) clean
				rm -fv $(OBJS) $(PUSHSWAP_OBJS) $(CHECKER_OBJS)

fclean			: clean
				$(MAKE) -C $(LIB_DIR) fclean
				rm -fv $(PUSH_SWAP) $(CHECKER)

re				: fclean all

.PHONY			: all clean fclean re
