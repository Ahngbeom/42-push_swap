/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:08:05 by bahn              #+#    #+#             */
/*   Updated: 2021/08/22 19:28:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_command(t_command *cmd_list)
{
    t_command *ptr;

	if (cmd_list == NULL)
		return ;
    ptr = cmd_list;
    while (ptr != NULL)
    {
		ft_putendl_fd(ptr->cmd, 1);
        ptr = ptr->next;
    }
	ft_putstr_fd("\0", 1);
}

int	main(int argc, char *argv[])
{
	t_frame *frame;

	invalid_arg(argc, argv);
	frame = frame_init();
	stack_init(frame, argv);
	if (check_asc(frame->a) == FALSE)
		a_to_b(frame, length(frame->a), NULL);
	print_command(frame->cmd_list);
	frame_free(frame);
	return (0);
}
