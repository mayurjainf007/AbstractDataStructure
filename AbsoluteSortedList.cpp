#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	Node* next; 
	int data; 
}; 
void push(Node** head, int data) { 
	Node* newNode = new Node; 
	newNode->next = (*head); 
	newNode->data = data; 
	(*head) = newNode; 
} 
void printList(Node* head) { 
	while (head != NULL) { 
		cout << head->data; 
		if (head->next != NULL) 
			cout << " -> "; 
		head = head->next; 
	} 
	cout<<endl; 
} 
void sortList(Node** head) { 
	Node* prev = (*head); 
	Node* curr = (*head)->next; 
	while (curr != NULL) { 
		if (curr->data < prev->data) { 
			prev->next = curr->next; 
			curr->next = (*head); 
			(*head) = curr; 
			curr = prev; 
		} 
		else
			prev = curr; 
		curr = curr->next; 
	} 
} 

int main() { 
	Node* head = NULL; 
	push(&head, -5); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, -2); 
	push(&head, 1); 
	push(&head, 0); 

	cout << "Original list :\n"; 
	printList(head); 

	sortList(&head); 

	cout << "\n Sorted list According to Absolute Value :\n"; 
	printList(head); 

	return 0; 
} 

