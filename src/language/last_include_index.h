#include "ms_common.h"

int base_array[] = {2,3,5,66,1,2,3,4,2,1,6,4,2,1,5,6};

int find_array[] = {4,2,1};

int subst_array[] = {77, 77, 77};


void ms_test_1()
{

	int size = sizeof(base_array)/sizeof(base_array[0]);
	for (int i = 0; i < size; i++)
	{
		printf("%2d ", base_array[i]);
	}
	printf("\n");

	int last_include_index = -1;

	int find_array_size = sizeof(find_array)/sizeof(find_array[0]);

	for ( int i = size - find_array_size -1; i > 0 ; i-- )
	{
		bool found = 1;
		for (int j = 0; j<find_array_size; j++)
		{
			if ( base_array[i+j] != find_array[j] )
			{
				found = 0;
				break;
			}
		}
		if (found)
		{
			last_include_index = i;
			break;
		}
	}

	printf ("last_include_index=%d\n",last_include_index);
	if (last_include_index >= 0)
	{
		for (int i = 0; i<find_array_size; i++)
		{
			base_array[i+last_include_index] =  subst_array[i];           

		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("%2d ", base_array[i]);
	}
	printf("\n");

}