#include "ft_list.h"
#include <stdlib.h>

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
