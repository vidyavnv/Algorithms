using namespace std;
#include<iostream>
#include "queue.h"
struct graph_node {
                    int color;
                    int parent;
                    int distance;
                  }g_node[8];
int main()
{
  int adj[8][8] = {
                    {0,1,1,0,0,0,0,0},
                    {1,0,0,0,1,1,0,0},
                    {1,0,0,1,0,0,0,0},
                    {0,0,1,0,0,0,0,0},
                    {0,1,0,0,0,1,1,0},
                    {0,1,0,0,1,0,1,1},
                    {0,0,0,0,1,1,0,1},
                    {0,0,0,0,0,1,1,0}
                   };
  int i,j;
  for(i = 0;i < 8 ;i++)
  {
    g_node[i].color = -1;
    g_node[i].distance = -1;
    g_node[i].parent = -1;
  }
  g_node[0].distance = 0;
  g_node[0].color = 0;
  initqueue();
  push(0);
  while(isempty())
  {
   int u = pop();
    for(j = 0;j < 8;j++)
    {
      if(adj[u][j] == 1)
      {
        if(g_node[j].color == -1)
        {
          g_node[j].color = 0;
          g_node[j].parent = u;
          g_node[j].distance = g_node[u].distance + 1;
          push(j);
        }
      }
    }
    g_node[u].color = 1;
  }
  
  for(i = 0;i < 8 ;i++)
  {
    cout<<i<<"\n";
    cout<<"color: "<<g_node[i].color<<"\n";
    cout<<"distance: "<<g_node[i].distance<<"\n";
    cout<<"parent: "<<g_node[i].parent<<"\n";
  }
  return 0;
}
