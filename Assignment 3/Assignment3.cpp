// Naga Mutya Kumar Kumtsam(nxk210028)

#include<iostream>
using namespace std;

void percolate(int arr[],int parent)
{
	int left_child,right_child,base_value;
	base_value = parent;
	left_child 	= 2 * parent;
	right_child = 2 *parent+1;
	
	if(left_child <= arr[0])
	{
		if(arr[base_value] > arr[left_child])
		{
			base_value = left_child;
		}
		if(right_child <= arr[0])
		{
			if(arr[base_value] > arr[right_child])
			{
				base_value = right_child;
			}
		}
		if(base_value != parent)
		{
			swap(arr[parent],arr[base_value]);
			percolate(arr,base_value);
		}
	}		
	return;
}

void heapsort(int arr[])
{
	while (arr[0] > 1)
	{
		swap(arr[1], arr[arr[0]]);
		arr[0]--;
		percolate(arr, 1);
	}
	return;	
}

void display(int arr[],int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}		
	cout << endl ;	
}

int main()
{
//	int arr[]={15,30,20,40,60,10,50,11,29,32,17,16,100,6,13,41};	
	int arr[] = {15,12, 11, 13, 7, 15, 19, 21, 42, 53, 29, 28, 25, 36, 18, 17}	;
	int n = (sizeof(arr)/sizeof(arr[0]))-1;	
	cout << "Initial Array is :" ;
	display(arr,n);
	
	// Implementing Flyod Algorithm
	int last_parent;
	last_parent = arr[0]/2;
	
	while(last_parent > 0)
	{
		percolate(arr, last_parent);
		last_parent--;
	}
		
	cout << "After sorting Array is :" ;
	display(arr,n);
	
	heapsort(arr);		
	cout << "After Heap sorting Array is :" ;
	display(arr,n);
}
