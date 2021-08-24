# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 21:16:21 by bahn              #+#    #+#              #
#    Updated: 2021/08/25 04:01:04 by bahn             ###   ########.fr        #
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
SRCS_FNAME		= a_to_b.c b_to_a.c \
					frame.c stack.c command.c \
					sort_check.c exception.c \
					scope_1.c scope_2.c scope_3.c \
					pivot.c revert.c \
					length.c element.c \

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FNAME))
OBJS			= $(SRCS:.c=.o)

OPERATION_DIR		= $(addprefix $(SRCS_DIR), operation/)
OPERATION_FNAME		= swap.c push.c rotate.c reverse_rotate.c
OPERATION_SRCS		= $(addprefix $(OPERATION_DIR), $(OPERATION_FNAME))
OPERATION_OBJS		= $(OPERATION_SRCS:.c=.o)

PUSHSWAP_SRCS		= ./srcs/push_swap.c
PUSHSWAP_OBJS		= $(PUSHSWAP_SRCS:.c=.o)

CHECKER_SRCS		= ./bonus/checker.c ./bonus/get_next_line.c
CHECKER_OBJS		= $(CHECKER_SRCS:.c=.o)

TEST_SRCS			= ./dir_for_test/print.c \
					 ./dir_for_test/operation/push.c \
					 ./dir_for_test/operation/swap.c \
					 ./dir_for_test/operation/rotate.c \
					 ./dir_for_test/operation/reverse_rotate.c \

all				: $(PUSH_SWAP)

bonus			: $(CHECKER)

test			: $(OBJS) $(PUSHSWAP_OBJS)
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(TEST_SRCS) $(LINK_LIBFT) -o push_swap_with_stack

$(PUSH_SWAP) 	: $(OBJS) $(OPERATION_OBJS) $(PUSHSWAP_OBJS)
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

$(CHECKER)		: $(OBJS) $(OPERATION_OBJS) $(CHECKER_OBJS)
				$(MAKE) all
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

.c.o			:
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean			:
				$(MAKE) -C $(LIB_DIR) clean
				rm -fv $(OBJS) $(OPERATION_OBJS) $(PUSHSWAP_OBJS) $(CHECKER_OBJS)

fclean			: clean
				$(MAKE) -C $(LIB_DIR) fclean
				rm -fv $(PUSH_SWAP) $(CHECKER) push_swap_with_stack

re				: fclean all

.PHONY			: all clean fclean re
