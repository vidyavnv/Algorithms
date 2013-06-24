using namespace std;
#include<iostream>
void binary_search(int array[],int beg,int end,int val);
int mid;
int main()
{
  int n,found = 0,i,value;
  int array[10];
  cin>>n;
  //array = new int[n];
  for(i = 0;i < n;i++)
    cin>>array[i];
  cin>>value;
  binary_search(array,0,n-1,value);
  //delete[] array;
  return 0;
}
void binary_search(int array[],int beg,int end,int val)
{
  if(end < beg)
  {
    cout<<"Not found";
    exit(0);
  }
  else 
  {
    mid = (beg + end) /2 ;
    cout<<"mid: "<<mid<<endl;
    cout<<"array[mid]: "<<array[mid]<<endl;
    if(array[mid] > val)
      binary_search(array,beg,mid-1,val);
    else if (array[mid] < val)
      binary_search(array,mid+1,end,val);
    else
    { cout<<"finally mid";
      cout<<endl<<"mid: "<<mid<<endl;
    }
  }
}
