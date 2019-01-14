/*

Insertion sort
Time complexity Best case: O(n2)
Time complexity Worst case: O(n2)

In this algorithm we have to insert the element at appropriate position
while sorting.

*/

#include<stdio.h>
#include<malloc.h>

// This function accept base address of an array 
// and number of elements in that array


void merge(int arr[],int min,int mid,int max)
{
	int tmp[30];
	int i,j,k,m;
	j=min;
	m=mid+1;

	for(i=min; j<=mid && m<=max ; i++)
	{
		if(arr[j]<=arr[m])
		{
			tmp[i]=arr[j];
			j++;
		}
		else
		{
			tmp[i]=arr[m];
			m++;
		}
	}
	
	if(j>mid)
	{
		for(k=m; k<=max; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=j; k<=mid; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}

	for(k=min; k<=max; k++)
	{
		arr[k]=tmp[k];
	}
}

void part(int arr[],int min,int max)
{
	int mid;

	if(min<max)
	{
		mid=(min+max)/2;
	
		part(arr,min,mid);
		part(arr,mid+1,max);

		merge(arr,min,mid,max);
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
	for(i = 0; i < no; i++)
	{
		printf("\nElement %d : ",i + 1);
		scanf("%d",&p[i]);
	}

	printf("All the elements accepted succesfully\n\n");

	part(p,0,no-1);

	printf("\n\nElements after sorting : \n");
	
	for(i = 0; i < no; i++)
	{
		printf(" %d ,",p[i]);
	}

	return 0;
}