#include <iostream>
using namespace std;

int binary(int arr[],int x,int y,int n)
{
	int mid1,mid2,s;
	
	if(y>=x)
		{	
			s = (y-x)/3;		
			mid1 = x +2*s;
			mid2 = x+s ;	
		if (arr[mid1] == n)	
			{
				return mid1;
			}
		if (arr[mid2] == n)
			{
				return mid2;
			}
		if (arr[mid1] > n)
			{
				return binary(arr,x,mid1-1,n);
			}
		else if (arr[mid2]>n)
			{
				return binary(arr,mid1+1,mid2-1,n);
			}
		else 
			{
				return binary(arr,mid2+1,y,n);
			}
		}
		
	return -1;

}

int main()
{
	int arr[] = {-1,2,12,26,28,32,57};	
	int length,i,n,index ;
	
	cout << "Input Array is : " ;
	length = sizeof(arr)/sizeof(arr[0]);
	
	for(i=0;i<length;i++)
    {
        cout<<arr[i]<<" ";
    }
		
	cout <<"Enter the number to be searched" << endl ;    
    cin >> n; 
    index=binary(arr,0,length-1,n);
    
    if(index == -1)
    {
    	cout << "Number not available in the array" << endl;
	}
	else
	{
    	cout << "Position = " << index << endl ;
	}    
    return 0;	
}
