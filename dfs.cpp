using namespace std;

#include<iostream>

void DFS_VISIT(int);

struct graph_node {
                    int color;
                    int parent;
                    int finished;
                    int discovery;
                  }g_node[6];
int t = 0;
int adj[6][6] = {
                    {0,1,0,1,0,0},
                    {0,0,1,0,0,0},
                    {0,0,0,1,0,0},
                    {0,1,0,0,0,0},
                    {0,0,1,0,0,1},
                    {0,0,0,0,0,1},
                   };
int main()
{
  int i,j;
  for(i = 0;i < 6 ;i++)
  {
    g_node[i].color = -1;
    g_node[i].parent = -1;
  }
  for(i = 0;i < 6;i++)
  {
    if(g_node[i].color == -1)
       DFS_VISIT(i);
  }
  for(i = 0;i < 6 ;i++)
  {
    cout<<i<<"\n";
    cout<<"color: "<<g_node[i].color<<"\n";
    cout<<"discovery: "<<g_node[i].discovery<<"\n";
    cout<<"finished: "<<g_node[i].finished<<"\n";
    cout<<"parent: "<<g_node[i].parent<<"\n";
  }
  return 0;
}

void DFS_VISIT(int l)
{
  t = t + 1;
  g_node[l].color = 0;
  g_node[l].discovery = t;
  for(int j = 0;j < 6;j++)
  {
      if(adj[l][j] == 1 && g_node[j].color == -1)
        {
           g_node[j].parent = l;
           DFS_VISIT(j);
        }
  }
  g_node[l].color = 1;
  t = t + 1;
  g_node[l].finished = t;
}
