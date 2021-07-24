#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*list;
	unsigned int	i;

	i = 0;
	list = begin_list;
	while (list && i <= nbr)
	{
		if (i == nbr)
			return (list);
		list = list->next;
		i++;
	}
	return (0);
}
