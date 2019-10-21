
#include <iostream>
#include <stdio.h>

using namespace std;

class Node
{
public:
  Node *lchild;
  int data;
  Node *rchild;
};

class Queue
{
private:
  int front;
  int rear;
  int size;
  Node **Q;
public:
  Queue()
  {
    front=rear=-1;
    size=10;
    Q=new Node*[size];
  }
  Queue(int size)
  {
    front=rear=-1;
    this->size=size;
    Q=new Node*[this->size];
  }
    void enqueue(Node *x);
    Node *dequeue();
    void Display();
    int isEmpty(){return front==rear;}

};


  void Queue::enqueue(Node *x)
  {
    if(rear==size-1)
    cout<<"Queue Full\n";
    else
    {
      rear++;
      Q[rear]=x;
    }
  }
  Node *Queue::dequeue()
  {
    Node *x=NULL;
    if(front==rear)
      cout<<"Queue is Empty\n";
    else
    {
      front++;
      x = Q[front];
    }
    return x;
  }

  void Queue::Display()
  {
    for(int i=front+1;i<=rear;i++)
      cout<<Q[i]<<" ";
     cout<<endl;
  }


class Tree
{
 Node *root;
 public:
 Tree(){root=NULL;}

 void CreateTree();

 void Preorder(Node *p);
 void Preorder(){Preorder(root);}

 void Postorder(Node *p);
 void Postorder(){Postorder(root);}

 void Inorder(Node *p);
 void Inorder(){Inorder(root);}

 void LevelOrder(Node *p);
 void LevelOrder(){LevelOrder(root);}

 void IPreOrder(Node *p);
 void IPreOrder() {IPreOrder(root);}

 void IInorder( Node *p);
 void IInorder( ) {IInorder(root);}

 int Height(Node *root);
 int Count(Node *root)
};

void Tree::CreateTree()
{
 Node *p,*t;
 int x;
 Queue q(100);

 cout<<"Enter root value : ";
 cin>>x;
 root=new Node;
 root->data=x;
 root->lchild = root->rchild = NULL;
 q.enqueue(root);

 while(!q.isEmpty())
 {
 p=q.dequeue();
 cout<<"enter left child of "<<p->data<<": ";
 cin>>x;
 if(x!=-1)
 {
   t=new Node;
   t->data=x;
   t->lchild=t->rchild=NULL;
   p->lchild=t;
   q.enqueue(t);
 }
 cout<<"enter right child of "<<p->data<<": ";
 cin>>x;
 if(x!=-1)
 {
   t=new Node;
   t->data=x;
   t->lchild=t->rchild=NULL;
   p->rchild=t;
   q.enqueue(t);
 }
 }
}
void Tree::Preorder( Node *p)
{
 if(p)
 {
 cout<<" "<<p->data;
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}
void Tree::Inorder( Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
  cout<<" "<<p->data;
 Inorder(p->rchild);
 }
}
void Tree::Postorder( Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
  cout<<" "<<p->data;
 }
}
void Tree::LevelOrder( Node *root)
{
 Queue q(100);

 cout<<" "<<root->data;
 q.enqueue(root);

 while(!q.isEmpty())
 {
 root=q.dequeue();
 if(root->lchild)
 {
 cout<<" "<<root->lchild->data;
 q.enqueue(root->lchild);
 }
 if(root->rchild)
 {
  cout<<" "<<root->rchild->data;
  q.enqueue(root->rchild);
 }
 }
}
int Tree::Height( Node *root)
{
 int x=0,y=0;
 if(root==0)
 return 0;
 x=Height(root->lchild);
 y=Height(root->rchild);
 if(x>y)
 return x+1;
 else
 return y+1;

}
int Tree::Count(Node *root)
{
 if(root)
 return count(root->lchild)+count(root->rchild)+1;
 return 0;
}
//Stack Iterative
class Stack
{
 int size;
 int top;
 Node **S;
public:
  Stack()
  {
    size=10;
    top=-1;
    S=new Node*[size];
  }
  Stack(int size)
  {
    this->size=size;
    top=-1;
    S=new Node*[this->size];
  }
void push(Node *x);
Node *pop();
int isEmpty();
int isFull();

};


void Stack::push(Node *x)
{
 if(top==size-1)
 cout<<"Stack overflow\n";
 else
 {
 top++;
 S[top]=x;
 }

}
Node *Stack::pop()
{
 Node *x=NULL;

 if(top==-1)
 cout<<"Stack Underflow\n";
 else
 {
 x=S[top--];
 }
 return x;
}

int Stack::isEmpty()
{
 if(top==-1)
 return 1;
 return 0;
}
int Stack::isFull()
{
 return top==size-1;
}

void Tree::IPreOrder( Node *p)
{
  Stack stk(100);

 while(p || !stk.isEmpty())
 {
 if(p)
 {
 cout<<" "<<p->data;
 stk.push(p);
 p=p->lchild;
 }
 else
 {
 p=stk.pop();
 p=p->rchild;
 }
 }
}

void Tree::IInorder( Node *p)
{
 Stack stk(100);
 while(p || !stk.isEmpty())
 {
 if(p)
 {
 stk.push(p);
 p=p->lchild;
 }
 else
 {
 p=stk.pop();
 cout<<" "<<p->data;
 p=p->rchild;
 }
 }
}



int main()
{
 // Tree t;
 // t.CreateTree();
 // cout<<"Preorder ";
 // t.Preorder();
 // cout<<endl;
 // cout<<"Inorder ";
 // t.Inorder();
 // cout<<endl;
 // cout<<"Postorder ";
 // t.Postorder();
 // cout<<endl<<endl;


  Tree t;
  t.CreateTree();

  t.IPreOrder();
  cout<<endl;
  t.IInorder();
  cout<<endl;

 return 0;
}
