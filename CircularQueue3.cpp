#include <iostream>
using namespace std;
#define N 5
int queue[N];
int front=-1,rear=-1;
void enqueue(int data)
{
 if((rear+1)%N==front)
 {
 cout<<"queue is full";
 }
 else
 {
 if(front==-1 && rear==-1)
 {
 front=rear=0;
 }
 else
 {
 rear=(rear+1)%N;
 }
 queue[rear]=data;
 cout<<"inserted"<<data<<endl;
 }
}
void dequeue()
{
 if(front==-1)
 {
 cout<<"queue is empty";
 }
 else
 {
 cout<<"deleted"<<queue[front]<<endl;
 if(front==rear)
 {
 front=rear=-1;
 }
 else
 {
 front=(front+1)%N;
 }
 }
}
void display()
{
 if(front==-1)
 {
 cout<<"Queue is empty";

 }
 else
 {
 int i=front;
 cout<<"queue elements are:"<< " ";
 while(i!=rear)
 {
 cout<<queue[i]<<" ";
 i= (i+1)%N;
 }
 }cout<<queue[rear];
}
int main()
{
 enqueue(10);
 enqueue(20);
 enqueue(30);
 enqueue(40);
 enqueue(50);
 enqueue(60);

 display();

 dequeue();
 dequeue();

 enqueue(60);
 enqueue(70);
 display();
}
