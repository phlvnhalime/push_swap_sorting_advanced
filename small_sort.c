/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:30:00 by hpehliva          #+#    #+#             */
/*   Updated: 2025/12/17 21:31:03 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_value(t_stack *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

static int	find_pos(t_stack *a, int value)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->value == value)
			return (pos);
		pos++;
		a = a->next;
	}
	return (0);
}

static void	bring_pos_to_top(t_stack **a, int pos)
{
	int	size;

	size = count_nodes(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, false);
	}
	else
	{
		while (pos++ < size)
			rra(a, false);
	}
}

static void	sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, false);
	else if (x > y && y > z)
	{
		sa(a, false);
		rra(a, false);
	}
	else if (x > y && y < z && x > z)
		ra(a, false);
	else if (x < y && y > z && x < z)
	{
		sa(a, false);
		ra(a, false);
	}
	else if (x < y && y > z && x > z)
		rra(a, false);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	min;
	int	pos;

	size = count_nodes(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, false);
		return ;
	}
	while (size > 3)
	{
		min = find_min_value(*a);
		pos = find_pos(*a, min);
		bring_pos_to_top(a, pos);
		pb(b, a, false);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b, false);
}
