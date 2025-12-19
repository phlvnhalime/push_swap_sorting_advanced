/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 01:30:38 by hpehliva          #+#    #+#             */
/*   Updated: 2025/12/19 17:31:14 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static void	mark_and_free(t_stack **nodes, int *lis_len, int *lis_prev, int i)
{
	while (i != -1)
	{
		nodes[i]->keep = true;
		i = lis_prev[i];
	}
	free(nodes);
	free(lis_len);
	free(lis_prev);
}

void	mark_lis_keep(t_stack *a)
{
	int		n;
	int		best_len[2];
	int		*lis_len;
	int		*lis_prev;
	t_stack	**nodes;

	clear_keep(a);
	n = count_elements(a);
	if (n <= 0)
		return ;
	nodes = (t_stack **)malloc(sizeof(t_stack *) * n);
	lis_len = (int *)malloc(sizeof(int) * n);
	lis_prev = (int *)malloc(sizeof(int) * n);
	if (!nodes || !lis_len || !lis_prev)
		exit(1);
	added_notes_a(nodes, a);
	compute_lis(lis_len, lis_prev, nodes, n);
	best_len[0] = 0;
	best_len[1] = 0;
	set_best_len(best_len, n, lis_len);
	mark_and_free(nodes, lis_len, lis_prev, best_len[1]);
}

/*
	Zone push strategy:
	- keep nodes stay in A
	- others go to B
	- if pushed element is > median => rb (send to bottom)
*/
void	zone_push_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	median;
	int	i;

	size = count_elements(*a);
	median = size / 3;
	i = 0;
	while (i < size)
	{
		if ((*a)->keep)
			ra(a, false);
		else
		{
			pb(b, a, false);
			if (*b && (*b)->index > median)
				rb(b, false);
		}
		i++;
	}
}

/*
  For example stack A has 6 elements.
  Stack a = [3,1,6,2,5,4]

  Stack b = []
  indicators = [2,0,5,1,4,3]
	- First ordered element with starting 0 till length of the stack.
	- index = [1,2,3,4,5,6]
  After assigning indicators, stack a will be like this:
  3 -> 2i
  1 -> 0i
  6 -> 5i
  2 -> 1i
  5 -> 4i
  4 -> 3i
  They will compare with each other to mark_lis_keep
*/
void	assign_indicators(t_stack **a)
{
	t_stack	*curr;
	t_stack	*small;
	int		i;
	int		len;

	len = count_elements(*a);
	if (!*a)
		return ;
	curr = *a;
	while (curr)
	{
		curr->index = -1;
		curr = curr->next;
	}
	i = 0;
	while (i < len)
	{
		small = find_smallest_element(*a);
		if (small) 
			small->index = i;
		i++;
	}
}
