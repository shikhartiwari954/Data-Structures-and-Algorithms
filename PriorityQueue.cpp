//implementing a priority queue using a priority queue
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int priority;
		int data;
		Node *next;
};

class priorityQueue{
	Node *first;
	
	public:
	priorityQueue(){
		first = NULL;
	}
	
	void enQueue(int data, int p) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->priority = p;
        if(first == NULL || p < first->priority) {
            newNode->next = first;
            first = newNode;
            return;
        }
        Node *temp = first;
        while(temp->next!=NULL && temp->next->priority <= p) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deQueue() {
        // delete element first which has the highest priority
        if(first == NULL) {
            cout<<"Queue Empty Please insert Elements"<<endl;
            return;
        }
        Node *temp = first;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

    void display() {
        if(first == NULL) {
            cout<<"Queue Empty"<<endl;
            return;
        }
        Node *temp = first;
        while(temp!=NULL) {
            cout<<temp->priority<<" "<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    priorityQueue p;
    p.enQueue(10, 3);
    p.enQueue(20, 2);
    p.enQueue(40, 1);
    p.enQueue(50, 4);

    p.deQueue();
    p.display();
}
