using namespace std;
#include<iostream>
int array[20];
void mergesort(int array[],int,int);                  
void merge(int array[],int,int,int);                  
int main()
{
  int n, start, end;
  cout<<"Enter the no. of elements: ";
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>array[i];
  start = 0;
	end = n - 1;
  mergesort(array,0,n-1);
  for(int j=0;j<n;j++)
    cout<<array[j];
  return 0;
}
void mergesort(int array[],int start,int end)
{
  int mid;						/*mid local variable not global, making it 
								 global changes the value of mid during second mergesort.
								 Value of mid becomes the last value of first mergesort
								 */
  if(start < end)
  {
    mid = (start + end) /2;
    mergesort(array,start,mid);
    mergesort(array,mid+1,end);
    merge(array,start,mid,end);
  }
}
void merge(int array[],int start,int mid,int end)    
{
  int left[10];
  int right[10];
  int i,j;
  int n1 = mid - start + 1;
  int n2 = end - mid;
  for(i = 0;i < n1;i++)
    left[i] = array[start + i];                //in book it's start + i - 1 but here array starts from 0 not 1 
  for(j = 0;j < n2;j++)
    right[j] = array[mid + j + 1];            //in book it's mid + j but here array starts from 0 not 1
  left[i] = 32767;
  right[j] = 32767;
  i = 0;
  j = 0;
  for(int m = start;m <= end;m++)
  {
    if(left[i] <= right[j])
    {
      array[m] = left[i];
      i++;
    }
    else
    {
      array[m] = right[j];
      j++;
    }
  }
}
