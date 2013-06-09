using namespace std;
#include<iostream>
int main()
{
  int i,j,n;
  int a[20],temp;
  cout<<"Enter no. of elements: ";
  cin>>n;
  for(i = 0;i < n;i++)
    cin>>a[i];
  for(i = 0;i < n - 2;i++)
  {
    for(j = 0;j < n - i - 1 ;j++)
    {
      if(a[j] > a[j + 1])
      {
        //temp = a[j];
        //a[j] = a[j + 1];
        //a[j + 1] = temp; 
        a[j + 1] = a[j] + a[j + 1];
        a[j] = a[j + 1] - a[j];
        a[j + 1] = a[j + 1] - a[j];
      }
    }
  }
  for(i = 0;i<n;i++)
    cout<<a[i];
 return 0;
}
