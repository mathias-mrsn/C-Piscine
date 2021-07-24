#include "ft_list.h"

void	ft_swap(void	**s1, void	**s2)
{
	void	*tmp;

	tmp = (*s1);
	(*s1) = (*s2);
	(*s2) = tmp;
}

void	ft_list_sort(t_list **begin_list, int(*cmp)())
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
