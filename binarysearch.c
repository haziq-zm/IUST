//Binary Search
#include<stdio.h>

int binarySearch(int a[],int low, int high, int x);

int main()
{
	int a[100];
	int n,i,x;
	printf("How many elements are in your array: ");
	scanf("%d",&n);
	printf("Enter elements in ascending order: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter number to be searched: ");
	scanf("%d",&x);
	
	printf("Array is: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
		
	int index=binarySearch(a,0,n-1,x);
	
	if(index==-1)
		printf("\nNumber not found");
	else
		printf("\nNumber found at index: %d",index);
}

int binarySearch(int a[],int low, int high, int x)
{
	if(low<=high)
	{
		int mid=low+(high-low)/2;
		
		if(a[mid]==x)
			return mid;
		else if(a[mid]>x)
			return binarySearch(a,low,mid-1,x);
		else
			return binarySearch(a,mid+1,high,x);
	}
	else
		return -1;
}

