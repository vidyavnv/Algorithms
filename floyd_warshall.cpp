using namespace std;
#include<iostream>
int min(int a,int b)
{
  if(a<b)
    return a;
  else
    return b;
}
int main()
{
  int w[5][5] = { 
                {0,3,8,999,-4},
                {999,0,000,1,7},
                {999,4,0,999,999},
                {2,999,-5,0,999},
                {999,999,999,6,0}
                
               };
  for(int k = 0;k<5;k++)
  {
   for(int i =0;i<5;i++)
   {
    for(int j =0;j<5;j++)
    {
      
        w[i][j] = min(w[i][j],w[i][k]+w[k][j]);
      }
    }
  }
  for(int i = 0;i<5;i++)
  {
    for(int j = 0;j<5;j++)
    {
      cout<<w[i][j]<<"  ";
    }
    cout<<endl;
  }
  return 0;
}
