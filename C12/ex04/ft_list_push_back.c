#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (!tmp)
		*begin_list = ft_create_elem(data);
	else
	{
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = ft_create_elem(data);
				return ;
			}
			else
				tmp = tmp->next;
		}
	}
}
