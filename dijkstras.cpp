using namespace std;

#include<iostream>


struct vertices{
	int parent;
	int distance;
	int flag;
}vertex[5];

int adj[5][5]={{0,10,0,0,5},
               {0,0,1,0,2},
               {0,0,0,4,0},
               {7,0,6,0,0},
               {0,3,9,2,0}};

void initialize_node()
{
  for(int i=0;i<5;i++)        
  {
	vertex[i].parent=-1;
	vertex[i].distance=999;
	vertex[i].flag=0;
  } 
  int startvertex=1;
  vertex[startvertex].parent=-1;         
  vertex[startvertex].distance=0;
  vertex[startvertex].flag=0;
}


int EXTRACT_MIN(vertices vertex[5])
{
	int j=0;
	int small_node=0,smallest=0;
	while((vertex[j].flag)==1)
	{
	  	  j++;
	}
	small_node=j;
	smallest=vertex[j].distance;

	for(j=j+1;j<5;j++)
	{
     	if(vertex[j].distance<smallest && vertex[j].flag==0)
	    {
		  smallest=vertex[j].distance;
		  small_node=j;
	    }
	}
	vertex[small_node].flag=1;
    return small_node;
}

int main()
{
	initialize_node();
	int u;	
	int S[5];
	int k=0;
	while(k<5)
	{
		u=EXTRACT_MIN(vertex);
		S[k]=u;
		k++;
		for(int q=0;q<=4;q++)
		{
			if(adj[u][q]!=0)
			{
			  if(vertex[q].distance>vertex[u].distance+adj[u][q])
			  {
				vertex[q].distance=vertex[u].distance+adj[u][q];
		        vertex[q].parent=u;
			  }
			}
		}
	}
		for(int r=0;r<5;r++)
	    			cout<<vertex[r].distance<<endl;
	return 0;
}



