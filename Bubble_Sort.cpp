/*

Bubble sort
Time complexity : O(n2)

In this sorting algorithm we have to iterate input array from first element 
to last element while comparision we have to swap the element if required.

*/

#include<stdio.h>
#include<malloc.h>

// This function accept base address of an array 
// and number of elements in that array
void Bubble_Sort(int a[], int n)
{
	int pass = 0, i = 0, temp = 0, j = 0;

	// Loop which is used for each pass
	for(pass = n - 1; pass >= 0 ; pass--)
	{
		// Loop for comparision
		for(i = 0; i <= pass -1; i++)
		{
			if(a[i] >= a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}

		// Print the contents of array after every pass
		printf("Array after pass %d :\n",n - pass);
		for(j = 0; j < n; j++)
		{
			printf(" %d ,",a[j]);
		}
		printf("\n\n");

	}
}

int main()
{
	int *p = NULL;
	int no = 0, i = 0;
	
	printf("Enter the number of elements that you want to enter : \n");
	scanf("%d",&no);

	p = (int*)malloc(sizeof(int)*no);
	if(p == NULL)
	{
		printf("Unable to allocate the memory");
		return -1;
	}

	// Accept the elements from user
	printf("Enter the elements \n");
	for(i = 0; i < no; i++)
	{
		printf("\nElement %d : ",i + 1);
		scanf("%d",&p[i]);
	}

	printf("All the elements accepted succesfully\n\n");

	Bubble_Sort(p,no);

	printf("\n\nElements after sorting : \n");
	
	// Display the elements after sorting
	for(i = 0; i < no; i++)
	{
		printf(" %d ,",p[i]);
	}

	return 0;
}