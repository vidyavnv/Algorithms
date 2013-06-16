using namespace std;
#include<iostream>
int main()
{
  int n,max,i,min;
  int *array,*count,*sorted;
  cout<<"Enter number of elements: ";
  cin>>n;
  
  array = new int[n];
  sorted = new int[n];
  cout<<"Enter elements: ";
  for(i = 0;i < n;i++)
    cin>>array[i];

  max = array[0];
  min =  array[0];
  for(i = 1;i < n;i++)
  {
    if(array[i] > max)
      max = array[i];
    if(array[i] < min)
      min = array[i];
  }
 

  count = new int[max+1];
  for(i = 0;i <= max; i++)
    count[i] = 0;

  for(int i = 0;i < n;i++)
    count[array[i]]++;

  for(i = 1;i <= max;i++)
     count[i] = count[i] + count[i-1];
   
  for(i = n - 1;i >= 0; i--)
  {
    sorted[count[array[i]]] = array[i];
    count[array[i]]--;
  }

  for(i = min;i < n;i++)
    cout<<endl<<sorted[i];

  delete[] array;
  delete[] sorted;
  delete[] count;

  return 0;
}
