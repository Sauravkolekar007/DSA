#include <iostream>
#include<stack>

using namespace std;
typedef struct n
{
char info;
struct n *ls;
struct n *rs;
}Node;
class ExpressionTree
{
Node *root;
char postfix[50];
public:
ExpressionTree();
Node * getNode(char info);
bool isOperator(char ch);
void convertToExpTree();
void inOrder(Node *cuurentRoot);//LVR
void preOrder(Node *cuurentRoot);//VLR
void postOrder(Node *cuurentRoot);//LRV
void demo();
int menu();
};

ExpressionTree::ExpressionTree()
{
root = NULL;
cout<<"\n Enter postfix input:";
cin>>postfix;
}

Node * ExpressionTree::getNode(char info)
{
Node *new1;
new1 = new Node; // allocate memory for new node
if(new1== NULL)
{
cout<<"\n Memory allocation error";
cout<<"\n Terminating the program";
exit(-1);
}
//If memory is allocated
new1->ls= NULL;
new1->rs= NULL;
new1->info = info;
return new1;
}
bool ExpressionTree::isOperator(char ch)
{
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
return true;
else
return false;
}
void ExpressionTree::convertToExpTree()
{
int k;
stack <Node *> st;
Node *opnd1, *opnd2, *opr, *new1;
k=0;
while(postfix[k] != '\0')
{
if(isOperator(postfix[k]))

{// if input is operator
opnd2 = st.top(); // read top most operand on stack
st.pop();// delete top most operand on stack
opnd1= st.top(); //Read topmost operand on stack
st.pop();// delete top most operand from stack
opr = getNode(postfix[k]);// crate a node of operator
opr->ls= opnd1;
opr->rs= opnd2;
st.push(opr);
k++;
}
else// if input is operand
{
new1= getNode(postfix[k]);
st.push(new1); // create a new node and push on stack
//st.push(getNode(postfix[k]));
k++; // go to next input
}
}
root= st.top();// Expression tree is on stack top
st.pop();
}
void ExpressionTree::inOrder(Node *currentRoot)
{
stack <Node *> st;
//LVR
Node *temp;
if(currentRoot == NULL)
return ;
temp= currentRoot;
while(temp!= NULL || !st.empty() )
{// if temp is not null or stack is not empty

while(temp!= NULL)
{
st.push(temp);
temp= temp->ls;
} //L
temp = st.top();// temp points to topmost item in satck
st.pop();// remove topmost item from stack
cout<<temp->info <<" "; //V
temp= temp->rs;
}
}
void ExpressionTree::preOrder(Node *currentRoot)
{
stack <Node *> st;
if(currentRoot == NULL)
return ;
Node *temp;
temp = currentRoot;
st.push(temp);
//VLR
while(!st.empty())
{
temp = st.top();
st.pop();// delete from stack
cout<<temp->info<<" "; //V
if(temp->rs)
st.push(temp->rs); //R
if(temp->ls)
st.push(temp->ls); //L
}
}
void ExpressionTree::postOrder(Node *currentRoot)

{
stack <Node *> st1,st2;
Node *temp;
if(currentRoot== NULL)
return;
temp = currentRoot;
st1.push(temp);
while(!st1.empty())
{
temp = st1.top();
st1.pop(); //L
st2.push(temp);//R
if(temp->ls)
st1.push(temp->ls);
if(temp->rs)
st1.push(temp->rs);
}
//pop and display the stack 2
while(!st2.empty())
{
temp= st2.top();
st2.pop();
cout<<temp->info<<" ";
}
}

void ExpressionTree::demo()
{
convertToExpTree();
while(1)
{
switch(menu())

{
case 1://infix output
cout<<"\n Infix output of given expression is \n";
inOrder(root);
break;
case 2:// prefix output
cout<<"\n prefix output of given expression is \n";
preOrder(root);
break;
case 3://postfix output
cout<<"\n postfix output of given expression is \n";
postOrder(root);
break;
case 4:
exit(0);
}
}
}
int ExpressionTree::menu()
{
int ch;
cout<<"\n Enter"
"\n1: infix output"
"\n2: for prefix output"
"\n3: for postfix output"
"\n4: for terminate the program"
"\n Enter your choice...";
cin>>ch;
return ch;
}
int main()
{

ExpressionTree t;
t.demo();
return 0;
}
