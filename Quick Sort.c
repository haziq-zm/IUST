int partition(int a[], int low, int high);
void quickSort(int a[],int low, int high);
void swap(int *a,int *b);

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
	quickSort(a,0,j);
	printf("Sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
		
	printf("\nTime Complexity: The time complexity of Quick Sort is typically O(n log n) for the best and average cases. Quick Sort achieves this efficiency because, on average, it divides the input into roughly equal-sized partitions. However, in the worst case, when the pivot choice consistently leads to unbalanced partitions, the time complexity can degrade to O(n^2).");
	printf("\nSpace Complexity: Space complexity for Quick Sort is O(log n) in the best and average cases. In the worst case, it is O(n) due to the recursive function calls and auxiliary space used on the call stack.");

}
void quickSort(int a[],int low, int high)
{
	if(low<high)
	{
		int pi=partition(a,low,high);
		quickSort(a,low,pi-1);
		quickSort(a,pi+1,high);
	}
}
int partition(int a[], int low, int high)
{
	int i=low,j;
	int pivot=a[low];
	for(j=low+1;j<=high;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i],&a[low]);
	return i;
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
