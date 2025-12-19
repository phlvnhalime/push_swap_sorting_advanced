/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indicators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 01:30:38 by hpehliva          #+#    #+#             */
/*   Updated: 2025/12/19 09:27:22 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"


/*
	Compute LIS on `index` (rank) in current stack order.
	Mark LIS nodes as keep=true (never pushed to B).
*/
void	mark_lis_keep(t_stack *a)
{
	int		n;
	int		i;
	int		j;
	int		best_len;
	int		best_end;
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
	i = 0;
	/*
		nodes[0] = value 3 (index2)
		nodes[1] = value 1 (index0)
		nodes[2] = value 6 (index5)
		nodes[3] = value 2 (index1)
		nodes[4] = value 5 (index4)
		nodes[5] = value 4 (index3)
	*/
	while (a)
	{
		nodes[i++] = a;
		a = a->next;
	}
	i = 0;
	while (i < n)
	{
		lis_len[i] = 1;
		lis_prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (nodes[j]->index < nodes[i]->index && lis_len[j] + 1 > lis_len[i])
			{
				lis_len[i] = lis_len[j] + 1;
				lis_prev[i] = j;
			}
			j++;
		}
		i++;
	}
	best_len = 0;
	best_end = 0;
	i = 0;
	while (i < n)
	{
		if (lis_len[i] > best_len)
		{
			best_len = lis_len[i];
			best_end = i;
		}
		i++;
	}
	i = best_end;
	while (i != -1)
	{
		nodes[i]->keep = true;
		i = lis_prev[i];
	}
	free(nodes);
	free(lis_len);
	free(lis_prev);
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
void assign_indicators(t_stack **a)
{
    t_stack *curr;
    t_stack *small;
    int i;
    int len;

    len = count_elements(*a);
    if(!*a)
      return ;
    curr = *a;
    while(curr)
    {
      curr->index = -1;
      curr = curr->next;
    }
    i = 0;
    while(i < len)
    {
      small = find_smallest_element(*a);
      if(small)
        small->index = i;
      i++;
    } 
}
