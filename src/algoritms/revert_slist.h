#include <iostream>
#include "ms_common.h"

using namespace std;

template<typename T>
void print_nodes(ms_common::__Node<T> * node);

void ms_test_revert_linked_list(int length)
{
	if (length <= 1 )
	{
		return;
	}
	ms_common::__Node<int> * _node = new ms_common::__Node<int>(0);
	ms_common::__Node<int> * head = _node;
	for (int i = 1; i < length ; i++ )
	{
		_node->next = new ms_common::__Node<int>(i);
		_node = _node->next;
	}

	_node = NULL;
	print_nodes(head);

	ms_common::__Node<int> * tmp = NULL;
	ms_common::__Node<int> * reverse_list = NULL;

	while(head)
	{

		tmp = head;
		head = head->next;

		tmp->next = reverse_list;
		reverse_list = tmp;


	}

	head = reverse_list;
	print_nodes(head);

}

template<typename T>
void print_nodes(ms_common::__Node<T> * node)
{

    while(node != NULL) 
    {
        printf("%2d ", node->value);
        node=node->next;
    }

    cout<<'\n';
}