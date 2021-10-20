//Queue Implementation  Using Linked List
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
};
class Queue{
	Node *first;
	Node *last;
	int totalElements;
	
	public:
	Queue(){
		first = NULL;
		last = NULL;
		totalElements = 0;
	}
	
	void enqueue(int val){
		Node *newNode = new Node;
		newNode->next = NULL;
		newNode->data = val;
		
		if(first == NULL){
			first = newNode;
			last = newNode;
			totalElements++;
		}else{
			last->next = newNode;
			last = newNode;
			totalElements++;
		}
	}
	
	void dequeue(){
		if(first == NULL){
			cout<<"Queue already empty"<<endl;
			return ;
		}if(first == last){
			last = NULL;
		}
		Node *temp = first;
		first = first->next;
		free(temp);
		totalElements--;
	}
	
	int peek(){
		if(first!=NULL){
			return first->data;
		}else{
			return -1;
		}
	}
	
	bool isEmpty(){
		if(totalElements == 0){
			return true;
		}else{
			return false;
		}
	}
};
int main(){
	Queue myQueue;
	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);
	myQueue.dequeue();
	myQueue.dequeue();
	cout<<myQueue.peek()<<endl;
	cout<<(myQueue.isEmpty()?"Empty":"Non-Empty")<<endl;
	return 0;
}
