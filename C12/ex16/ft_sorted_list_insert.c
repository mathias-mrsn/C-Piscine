#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	if (!new)
		return ;
	new->next = *begin_list;
	*begin_list = new;
}

void	ft_swap(void	**s1, void	**s2)
{
	void	*tmp;

	tmp = (*s1);
	(*s1) = (*s2);
	(*s2) = tmp;
}

void	ft_sort_list(t_list **begin_list, int(*cmp)())
{
	t_list	*tmp;

	tmp = *begin_list;
	while (tmp)
	{
		if (!tmp->next)
			return ;
		if (cmp(tmp->data, tmp->next->data) > 0)
		{
			ft_swap(&tmp->data, &tmp->next->data);
			tmp = *begin_list;
		}
		else
			tmp = tmp->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_sort_list(begin_list, cmp);
}
