void push(int);
int pop();
int isempty();
void initqueue();

struct node{
             int index;
             node* link;
           }*front,*rear;



void push(int n)
{
  node *newptr;
  newptr = new node;
  newptr -> index = n;
  newptr -> link = NULL;
  if(newptr == NULL)
	  exit(0);
  else
  {
    if(front == NULL)
    {
       front = newptr;
       rear = newptr;
    }
    else
    {
       rear -> link = newptr;
       rear = newptr;
    }
  }
}

int pop()
{
  node *save;	
  if(front == NULL)
	  exit(0);
  else
  {
    save = front;
	int info = save -> index;
	if(front == rear)
		rear = NULL;
    front = front -> link;
	save -> link = NULL;
    delete save;
	return info;
  }
}

int isempty()
{
  if(front == NULL)
	  return 0;
  else
      return 1;
}

void initqueue() {
	front=NULL;
    rear=NULL;
}
