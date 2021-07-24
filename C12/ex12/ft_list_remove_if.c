#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*next;
	t_list	*curr;

	prev = 0;
	next = (*begin_list);
	while (next)
	{
		if (cmp(next->data, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = next->next;
			else
				prev->next = next->next;
			curr = next;
			next = next->next;
			free_fct(curr->data);
			free(curr);
		}
		else
		{
			prev = next;
			next = prev->next;
		}
	}
}
