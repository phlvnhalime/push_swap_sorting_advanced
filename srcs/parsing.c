/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:00:00 by hpehliva          #+#    #+#             */
/*   Updated: 2025/12/19 15:08:06 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static bool	parse_conditions_utils(char **parts, t_stack **stack_a)
{
	int		j;
	long	num;

	j = 0;
	while (parts[j])
	{
		if (invalid_entries(parts[j]))
			return (ft_free_split(parts), false);
		num = ft_atol(parts[j]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_free_split(parts), false);
		if (check_dub(*stack_a, (int)num))
			return (ft_free_split(parts), false);
		add_to_stack(stack_a, (int)num);
		j++;
	}
	ft_free_split(parts);
	return (1);
}

bool	parse_and_init(t_stack **stack_a, int ac, char **av)
{
	int		i;
	char	**parts;

	i = 1;
	while (i < ac)
	{
		parts = ft_split(av[i], ' ');
		if (!parts || !parts[0])
		{
			if (parts)
				ft_free_split(parts);
			return (false);
		}
		if (!parse_conditions_utils(parts, stack_a))
			return (false);
		i++;
	}
	return (true);
}
