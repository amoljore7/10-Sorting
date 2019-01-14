/*

Bubble sort (Improved)
Time complexity Best case: O(n)

In this sorting algorithm we have to iterate input array from first element 
to last element while comparision we have to swap the element if required.

In normal bubble sort after arraygets completely sorted still we have to perform
remaining passess.
This problem is overcomed by using flag in improved version.

*/

#include<stdio.h>
#include<malloc.h>

// This function accept base address of an array 
// and number of elements in that array
void Bubble_Sort_Improved(int a[], int n)
{
	int pass = 0, i = 0, temp = 0, j = 0, swapped = 1;

	// Loop which is used for each pass
	for(pass = n - 1;( pass >= 0 && swapped == 1); pass--)
	{
		swapped = 0;
		// Loop for comparision
		for(i = 0; i <= pass -1; i++)
		{
			if(a[i] >= a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				// Turn the flag which indicates that swapping is performed
				swapped = 1;
			}
		}

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

	printf("Enter the elements \n");

	// Accept the elements from user
	for(i = 0; i < no; i++)
	{
		printf("\nElement %d : ",i + 1);
		scanf("%d",&p[i]);
	}

	printf("All the elements accepted succesfully\n\n");

	Bubble_Sort_Improved(p,no);

	printf("\n\nElements after sorting : \n");
	
	// Print the elements after sorting
	for(i = 0; i < no; i++)
	{
		printf(" %d ,",p[i]);
	}

	return 0;
}