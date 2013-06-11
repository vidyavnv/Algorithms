using namespace std;
#include<iostream>
void mergesort(int a[],int,int);
void merge(int a[],int,int,int);
int main()
{
  int *a;
  int i,n;
  cout<<"enter no of elements: ";
  cin>>n;
  a = new int[n];
  for(i = 0;i<n;i++)
    cin>>a[i];
  mergesort(a,0,n-1);
  for(i = 0;i<n;i++)
    cout<<a[i];
  delete[] a;
  return 0;
}
void mergesort(int a[],int start,int end)
{
  int mid;
  if(start<end)
  {
    mid = (start + end)/2;
    cout<<"\nmid: "<<mid<<"\n";
    mergesort(a,start,mid);
    mergesort(a,mid+1,end);
    merge(a,start,mid,end);
  }
}
void merge(int a[],int start,int mid,int end)
{
  int *left,*right;
  int n1,n2;
  n1 = mid - start + 1;
  n2 = end - mid;
  left = new int[n1 + 1];
  right = new int[n2 + 1];
  int i=0;
  int j=0;
  for(;i<n1;i++)
    left[i] = a[start + i];
  for(;j<n2;j++)
    right[j] = a[mid + j +1];
  left[i] = 32767;
  right[j] = 32767;
  int k=0,l=0;
  for(i = start;i<=end;i++)
  {
    if(left[k]<=right[l])
    {
      a[i] = left[k];
      k++;
    }
    else
    {
      a[i] = right[l];
      l++;
    }
  }
  delete[] left;
  delete[] right;
}
