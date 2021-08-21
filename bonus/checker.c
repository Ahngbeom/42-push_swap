/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:08:05 by bahn              #+#    #+#             */
/*   Updated: 2021/08/22 03:01:06 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static	void	select_operation(t_frame *frame, char *cmd)
{
	if (ft_strncmp(SWAP_A, cmd, ft_strlen(cmd)) == 0)
		swap_a(frame);
	else if (ft_strncmp(SWAP_B, cmd, ft_strlen(cmd)) == 0)
		swap_b(frame);
	else if (ft_strncmp(SWAP_S, cmd, ft_strlen(cmd)) == 0)
		swap_s(frame);
	else if (ft_strncmp(PUSH_A, cmd, ft_strlen(cmd)) == 0)
		push_a(frame);
	else if (ft_strncmp(PUSH_B, cmd, ft_strlen(cmd)) == 0)
		push_b(frame);
	else if (ft_strncmp(ROTATE_A, cmd, ft_strlen(cmd)) == 0)
		rotate_a(frame);
	else if (ft_strncmp(ROTATE_B, cmd, ft_strlen(cmd)) == 0)
		rotate_b(frame);
	else if (ft_strncmp(ROTATE_R, cmd, ft_strlen(cmd)) == 0)
		rotate_r(frame);
	else if (ft_strncmp(REVERSE_ROTATE_A, cmd, ft_strlen(cmd)) == 0)
		reverse_rotate_a(frame);
	else if (ft_strncmp(REVERSE_ROTATE_B, cmd, ft_strlen(cmd)) == 0)
		reverse_rotate_b(frame);
	else if (ft_strncmp(REVERSE_ROTATE_R, cmd, ft_strlen(cmd)) == 0)
		reverse_rotate_r(frame);
	else
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_frame	*frame;
	char	*cmd;

	invalid_arg(argc, argv);
	frame = frame_init();
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
