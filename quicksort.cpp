using namespace std;
#include<iostream>
void quicksort(int *array,int,int);
int partition(int *array,int,int);
int main()
{
  int *array;
  int n;
  cout<<"Enter no of elements: \n";
  cin>>n;
  array = new int[n];
  for(int i = 0;i < n;i++)
    cin>>array[i];
  quicksort(array,0,n-1);
  cout<<"After sorting: \n";
  for(int j= 0;j < n;j++)
    cout<<array[j];
  return 0;
}
void quicksort(int *array,int p,int r)
{
  int q;
  if(p < r)
  {
    q = partition(array,p,r);
    quicksort(array,p,q-1);
    quicksort(array,q+1,r);
  }
}
int partition(int *array,int start,int end)
{
  int x,i,temp,j;
  x = array[end];
  i = start - 1;
  for(j = start;j<end;j++)
  {
    if(array[j] <= x)
    {
      i = i + 1;
      temp = array[j];
      array[j] = array[i];
      array[i] = temp;
    }
  }
    temp = array[i+1];
    array[i+1] = array[end];
    array[end] = temp;
  return i+1;
}
