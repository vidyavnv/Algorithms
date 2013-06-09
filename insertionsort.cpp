using namespace std;
#include<iostream>
int main()
{
  int n,i,j,key;
  int a[20];
  cout<<"Enter no. of elements: ";
  cin>>n;
  for(i = 0;i < n;i++)
    cin>>a[i];
  for( i = 0; i < n ; i++)
  {
    key = a[i];
    j = i - 1;
    while(j-- >= 0 && a[j + 1] > key)
      a[j + 2] = a[j + 1];
    a[j + 2] = key;
  }
  for(i = 0;i < n;i++)
    cout<<a[i];
  return 0;
}

