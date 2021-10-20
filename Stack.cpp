//stack data structure implementation using Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int value;
	Node *next;
};

class Stack{
	
	Node *top;
	int length;
	
	public:
		Stack(){
			top = NULL;
			length = 0;
		}
		
	int peek(){
		if(top == NULL){
			return -1;
		}else{
			return top->value;	
		}	
	}	
	
	void push(int value){
		Node *newNode = new Node;
		newNode->value = value;
		newNode->next = NULL;
		
		if(top == NULL){
			top = newNode;
			length++;
		}else{
			newNode->next = top;
			top = newNode;
			length++;
		}
	}
	
	void pop(){
		if(top == NULL){
			cout<<"-1"<<endl;
		}else{
			Node *current = top;
			cout<<current->value<<endl;
			top = top->next;
			free(current);
			length--;	
		}	
	}
	
	void display(){
		if(top == NULL){
			cout<<"Stack Empty"<<endl;
		}else{
			Node *currentNode = top;
			for(long long int i = 0 ; i<length && currentNode!=NULL;i++){
				cout<<currentNode->value<<" ";
				currentNode = currentNode->next;
			}
			cout<<endl;
		}
	}
		
	bool isEmpty(){
		if(length == 0){
			return true;
		}else{
			return false;
		}
	}	
};
int main(){
	Stack myStack;
	myStack.push(5);
	myStack.push(4);
	myStack.push(3);
	myStack.push(2);
	myStack.push(1);
	myStack.push(100);
	myStack.pop();
	cout<<myStack.peek()<<endl;
	myStack.display();
	cout<<(myStack.isEmpty() ? "empty" : "non-empty")<<endl;
	return 0;
}
