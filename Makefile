# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 21:16:21 by bahn              #+#    #+#              #
#    Updated: 2021/09/01 15:29:07 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -static-libasan -g

PUSH_SWAP		= push_swap
CHECKER			= checker
PS_WITH_STK		= push_swap_with_stack

INCFLAGS		= -I./includes -I./libft

LIB_DIR			= ./libft
LINK_LIBFT		= -Llibft -lft

SRCS_PATH		= ./srcs/
BONUS_PATH		= ./bonus/

FRAME_SRCS			= $(addprefix $(SRCS_PATH), $(addprefix frame/, frame.c))
FRAME_OBJS			= $(FRAME_SRCS:.c=.o)

STACK_SRCS			= $(addprefix $(SRCS_PATH), $(addprefix stack/, stack.c))
STACK_OBJS			= $(STACK_SRCS:.c=.o)

OPERATION_SRCS		= $(addprefix $(SRCS_PATH), $(addprefix operation/, swap.c push.c rotate.c reverse_rotate.c))
OPERATION_OBJS		= $(OPERATION_SRCS:.c=.o)

COMMAND_SRCS		= $(addprefix $(SRCS_PATH), $(addprefix command/, command.c))
COMMAND_OBJS		= $(COMMAND_SRCS:.c=.o)

EXCEPTION_SRCS		= $(addprefix $(SRCS_PATH), $(addprefix exception/, exception.c))
EXCEPTION_OBJS		= $(EXCEPTION_SRCS:.c=.o)

UTILS_SRCS			= $(addprefix $(SRCS_PATH), $(addprefix utils/, sort_check.c length.c element.c))
UTILS_OBJS			= $(UTILS_SRCS:.c=.o)

PUSHSWAP_SRCS		= $(addprefix $(SRCS_PATH), push_swap.c a_to_b.c b_to_a.c scope_1.c scope_2.c scope_3.c pivot.c revert.c)
PUSHSWAP_OBJS		= $(PUSHSWAP_SRCS:.c=.o)

CHECKER_SRCS		= $(addprefix $(BONUS_PATH), checker.c get_next_line.c)
CHECKER_OBJS		= $(CHECKER_SRCS:.c=.o)

TEST_SRCS			= $(addprefix ./dir_for_test/, print.c $(addprefix operation/, push.c swap.c rotate.c reverse_rotate.c))

all				: $(PUSH_SWAP)

bonus			: $(CHECKER)

test			: $(PS_WITH_STK)

$(PS_WITH_STK)	: $(OBJS) $(FRAME_OBJS) $(STACK_OBJS) $(COMMAND_OBJS) $(UTILS_OBJS) $(EXCEPTION_OBJS) $(PUSHSWAP_OBJS)
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(TEST_SRCS) $(LINK_LIBFT) -o $@

$(PUSH_SWAP) 	: $(OBJS) $(FRAME_OBJS) $(STACK_OBJS) $(OPERATION_OBJS) $(COMMAND_OBJS) $(UTILS_OBJS) $(EXCEPTION_OBJS) $(PUSHSWAP_OBJS)
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

$(CHECKER)		: $(OBJS) $(FRAME_OBJS) $(STACK_OBJS) $(OPERATION_OBJS) $(COMMAND_OBJS) $(UTILS_OBJS) $(EXCEPTION_OBJS) $(CHECKER_OBJS)
				$(MAKE) all
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

.c.o			:
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean			:
				$(MAKE) -C $(LIB_DIR) clean
				rm -fv $(OBJS) $(FRAME_OBJS) $(STACK_OBJS) $(OPERATION_OBJS) $(COMMAND_OBJS) \
				$(UTILS_OBJS) $(EXCEPTION_OBJS) $(PUSHSWAP_OBJS) $(CHECKER_OBJS)

fclean			: clean
				$(MAKE) -C $(LIB_DIR) fclean
				rm -fv $(PUSH_SWAP) $(CHECKER) $(PS_WITH_STK)

re				: fclean all

.PHONY			: all clean fclean re
