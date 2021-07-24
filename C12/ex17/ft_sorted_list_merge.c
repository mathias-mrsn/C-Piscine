#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list;

	list = (*begin_list1);
	while (list)
	{
		if (!(list->next))
		{
			list->next = begin_list2;
			break ;
		}
		list = list->next;
	}
	if (!(list))
		*begin_list1 = begin_list2;
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

void	ft_sorted_list_merge(t_list **begin_list1,
t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_sort_list(begin_list1, cmp);
}
