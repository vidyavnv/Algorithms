using namespace std;
#include<iostream>
void mergesort(int array[],int,int);
void merge(int array[],int,int,int);
int mid, i, j, n1, n2;
int array[20];
int main()
{
  int n, start, end;
  cout<<"Enter no. of elements: ";
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>array[i];
  start = 0;
  end = n - 1;
  mergesort(array,0 ,n-1);
  for(int k = 0;k < n;k++)
    cout<<array[k];
  return 0;
}
void mergesort(int array[],int start,int end)
{
  cout<<"\nOriginal array: ";
  for(int m=start;m<=end;m++)
      cout<<array[m];
  if(start < end)
  {
    mid = (start + end) / 2;
    mergesort(array,start,mid);
    cout<<"second merge sort"<<endl;
    cout<<"mid+1  end:    "<<mid+1<<end<<endl;
    mergesort(array,mid+1,end);
    merge(array,start,mid,end);
  }
}
void merge(int array[],int start, int mid,int end)
{
  int left[10],right[10];
  cout<<"start    mid    end:"<<start<<"  "<<mid<<"   "<<end<<endl;  
  n1 = mid - start + 1;
  n2 = end - mid;
  cout<<"n1 and n2:"<<n1<<"  "<<n2;
  //int *left,*right;
 // left = new int(n1);
  //right = new int(n2);
  for(i = 0;i < n1;i++)
     left[i] = array[start + i  ];
  for(j = 0;j < n2;j++)
     right[j] = array[mid + j + 1 ];
  left[i] = 9999;
  right[j] = 9999;
  cout<<"\nleft array: ";
  for(int m = 0;m < n1;m++)
      cout<<left[m];
  cout<<endl;
  cout<<"\nright array: ";
  for(int p = 0;p < n2;p++)
     cout<<right[p];
  i = 0;
  j = 0;
  for (int k = start;k <= end;k++)
  {
    if(left[i]  <= right[j])
    {
      array[k] = left[i];
      i++;
    }
    else
    {
      array[k] = right[j];
      j++;
    }
  }
  cout<<"\nSorted array: ";
  for(int s = start;s <= end;s++)
    cout<<array[s];
  cout<<endl;
//  delete[] left;
  //delete[] right;
}

