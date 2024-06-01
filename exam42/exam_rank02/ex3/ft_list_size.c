/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:
*/
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


int	ft_list_size(t_list *begin_list)
{
	int	i;
	
	i = 0;
	while (begin_list != '\0')
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


int main()
{
    // Creating a linked list for demonstration purposes
    t_list node3 = { NULL, "Node 3" };
    t_list node2 = { &node3, "Node 2" };
    t_list node1 = { &node2, "Node 1" };
    
    // Point to the start of the list
    t_list *list_start = &node1;
    
    // Call ft_list_size to get the number of elements in the list
    int size = ft_list_size(list_start);
    
    // Print the size of the list
    printf("Size of the list: %d\n", size);

    return 0;
}
*/
