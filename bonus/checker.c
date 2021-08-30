/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:08:05 by bahn              #+#    #+#             */
/*   Updated: 2021/08/31 00:35:58 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static	void	push_operation(t_frame *frame, char *cmd)
{
	if (cmd[1] == 'a')
		push_a(frame);
	else if (cmd[1] == 'b')
		push_b(frame);
	else
		ft_puterr();
}

static	void	swap_operation(t_frame *frame, char *cmd)
{
	if (cmd[1] == 'a')
		swap_a(frame);
	else if (cmd[1] == 'b')
		swap_b(frame);
	else if (cmd[1] == 's')
		swap_s(frame);
	else
		ft_puterr();
}

static	void	rotate_operation(t_frame *frame, char *cmd)
{
	if (ft_strlen(cmd) == 2)
	{
		if (cmd[1] == 'a')
			rotate_a(frame);
		else if (cmd[1] == 'b')
			rotate_b(frame);
		else if (cmd[1] == 'r')
			rotate_r(frame);
	}
	else if (ft_strlen(cmd) == 3 && cmd[1] == 'r')
	{
		if (cmd[2] == 'a')
			reverse_rotate_a(frame);
		else if (cmd[2] == 'b')
			reverse_rotate_b(frame);
		else if (cmd[2] == 'r')
			reverse_rotate_r(frame);
	}
	else
		ft_puterr();
}

static	void	select_operation(t_frame *frame, char *cmd)
{
	if (cmd[0] == 'p')
		push_operation(frame, cmd);
	else if (cmd[0] == 's')
		swap_operation(frame, cmd);
	else if (cmd[0] == 'r')
		rotate_operation(frame, cmd);
	else
		ft_puterr();
}

int	main(int argc, char *argv[])
{
	t_frame	*frame;
	char	*cmd;

	invalid_arg(argc, argv);
	frame_init(&frame);
	stack_init(frame, argv);
	while (get_next_line(0, &cmd) > 0)
	{
		select_operation(frame, cmd);
		if (cmd != NULL)
			free(cmd);
		cmd = NULL;
	}
	if (check_asc(frame->a) == TRUE && frame->b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (cmd != NULL)
		free(cmd);
	frame_free(frame);
	return (0);
}
