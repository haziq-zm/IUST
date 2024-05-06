#include<stdio.h>

void merge(int a[], int l, int mid, int h);
void mergeSort(int a[],int i, int j);

int main()
{
	int a[100];
	int n,i;
	printf("How many elements are in your array: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int j=n-1;
	mergeSort(a,0,j);
	printf("Sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
		
	printf("\nTime Complexity: Merge Sort divides the array into two equal halves, recursively sorts each half, and then merges them together. This division and merging process continues until the entire array is sorted. The time complexity is consistently O(n log n) in all cases.\n");
	printf("Space Complexity: Merge Sort has a space complexity of O(n) for the temporary array used during the merging process.");
}

void merge(int a[], int l, int mid, int h)
{
		int i=l; int j=mid+1; int k=l;
		int b[h+1];
		while(i<=mid && j<=h)
		{
			if(a[i]<=a[j])
				b[k++]=a[i++];
			else
				b[k++]=a[j++];
		}
		while(i<=mid)
			b[k++]=a[i++];
		
		while(j<=h)
			b[k++]=a[j++];
		
		for(i=l;i<=h;i++)//changes elemets in a
			a[i]=b[i];
}

void mergeSort(int a[], int i, int j)
{
	if(i<j)
	{
		int mid=i+(j-i)/2;
		mergeSort(a,i,mid);
		mergeSort(a,mid+1,j);
		merge(a,i,mid,j);
	}
}
