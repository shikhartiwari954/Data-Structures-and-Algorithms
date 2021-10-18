//implementation of singly linked list
#include<bits/stdc++.h>
using namespace std;
//class Node
class Node{
	public:
	int data;
	Node *link;
};

//class implementing linked list
class linkedList{
	Node *head;
	Node *tail;
	int totalNodes;
	
	public:
		linkedList(){
			//initialising the node to null value
			head = NULL;
			tail = NULL;
			totalNodes = 0;
		}
		
	void append(int element){
		//inserting at the end of linked list(O(1) time complexity)
		Node *newNode = new Node;//creating a node to store data
		newNode->data = element;//filling data with element
		newNode->link = NULL;//initially setting link to null
		
		if(head == NULL){ //check if head is null i.e. linked list is empty...
			head = newNode;
			tail = newNode;
			totalNodes++;
		}else{//if not then
			tail->link = newNode;
			tail = newNode;
			totalNodes++;
		}
	}
	
	void preAppend(int element){
		//inserting at the end of linked list(O(1) time complexity)
		Node *newNode = new Node;//creating a node to store data
		newNode->data = element;//filling data with element
		newNode->link = NULL;//initially setting link to null
		
		if(head == NULL){ //check if head is null i.e. linked list is empty...
			head = newNode;
			tail = newNode;
			totalNodes++;
		}else{//if not then
			newNode->link = head;
			head = newNode;
			totalNodes++;
		}
	}
	
	//function to insert a value in a linked list (0 based indexing)
	void insert(int index, int value){
		//creating a new node
		Node *newNode = new Node;
		newNode->data = value;
		newNode->link = NULL;
		
		Node *currentNode = head;
		
		int count = 0;
		
		if(head == NULL){ //check if head is null i.e. linked list is empty...
			head = newNode;
			tail = newNode;
			totalNodes++;
		}else if(index == 0){
			this->preAppend(value);
		}else{
			while(currentNode != NULL){
			if(count == index-1){
				newNode->link = currentNode->link;
				currentNode->link = newNode;
				this->totalNodes++;
				break;
			}else{
				currentNode = currentNode->link;
				count++;
			}		
		}
		}
	}
	
	//function remove an element from a given index
	void remove(int index){
		int count = 0;
		
		Node *temp = head;
		
		for(int i = 0; temp!=NULL && i < index - 1; i++) {
                    temp = temp->link;
                }
                if(temp == NULL || temp->link == NULL) {
                    return;
                }
                Node *link = temp->link->link;  // creating link between temp and node after the node that is being deleted.
                free(temp->link);
                temp->link = link;
                totalNodes--;
                return;
	}
	
	//creating a function to display all the elements
	vector<int> display(){
		vector<int>v;
		Node *currentNode = head;
		while(currentNode != NULL){
			v.push_back(currentNode->data);
			currentNode = currentNode->link;
		} 
		return v;
	}
	
};
int main(){
	linkedList myList;
	myList.append(1);
	myList.append(2);
	myList.append(3);
	myList.append(4);
	myList.append(5);
	myList.preAppend(0);
//	myList.insert(2,-1);
	myList.remove(3);
	vector<int>v = myList.display();
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
