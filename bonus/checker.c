/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:08:05 by bahn              #+#    #+#             */
/*   Updated: 2021/08/20 22:52:41 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	arg_len;
	char	**stack_a;
	char	**stack_b;
	int	read_size;
	char	cmd[4];
	int	cmd_cnt;

	printf("\n#######################\n");
	printf("####### CHECKER #######");
	printf("\n#######################\n\n");

	if ((arg_len = invalid_arg(argc, argv)) < 0)
		exit(0);
	if (!(stack_a = (char **)ft_calloc(arg_len + 1, sizeof(char *))))
		return (1);

	i = 0;
	while (i < arg_len)
	{
		stack_a[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	stack_a[i] = NULL;
	stack_b = NULL;


	cmd_cnt = 0;
	if (check_ascending(stack_a, stack_b))
	{
		print_stack(stack_a, stack_b);
		printf("OK:::Ascending Sort SUCCESS !!! - %d\n", cmd_cnt);
	}
	else
	{
		while ((read_size = read(0, cmd, 4)) > 0)
		{
			cmd[read_size - 1] = '\0';

			//branch_command(cmd, read_size, stack_a, stack_b);
			//*
			if (ft_strncmp(SWAP_A, cmd, read_size) == 0)
				swap_stack(stack_a);
			if (ft_strncmp(SWAP_B, cmd, read_size) == 0)
				swap_stack(stack_b);
			if (ft_strncmp(SWAP_S, cmd, read_size) == 0)
			{
				swap_stack(stack_a);
				swap_stack(stack_b);
			}

			if (ft_strncmp(PUSH_A, cmd, read_size) == 0)
				stack_a = push_stack(stack_a, stack_b);
			if (ft_strncmp(PUSH_B, cmd, read_size) == 0)
				stack_b = push_stack(stack_b, stack_a);

			if (ft_strncmp(ROTATE_A, cmd, read_size) == 0)
				rotate_stack(stack_a);
			if (ft_strncmp(ROTATE_B, cmd, read_size) == 0)
				rotate_stack(stack_b);
			if (ft_strncmp(ROTATE_R, cmd, read_size) == 0)
			{
				rotate_stack(stack_a);
				rotate_stack(stack_b);
			}

			if (ft_strncmp(REVERSE_ROTATE_A, cmd, read_size) == 0)
				reverse_rotate_stack(stack_a);
			if (ft_strncmp(REVERSE_ROTATE_B, cmd, read_size) == 0)
				reverse_rotate_stack(stack_b);
			if (ft_strncmp(REVERSE_ROTATE_R, cmd, read_size) == 0)
			{
				reverse_rotate_stack(stack_a);
				reverse_rotate_stack(stack_b);
			}
			//*/
			cmd_cnt++;
			print_stack(stack_a, stack_b);

			if (check_ascending(stack_a, stack_b))
			{
				printf("OK:::Ascending Sort SUCCESS !!! - %d\n", cmd_cnt);
				break ;
			}
		}
	}
	if (stack_a != NULL)
		free(stack_a);
	if (stack_b != NULL)
		free(stack_b);

	return (0);
}
