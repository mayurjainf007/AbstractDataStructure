#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *left;
struct node *right;
struct node *neighbour;
};

void connectRecur(struct node* p);
void connect (struct node *p){
	p->neighbour = NULL;
	connectRecur(p);
}
void connectRecur(struct node* p){
	if (!p)
		return;
	if (p->right)
		p->right->neighbour = p->left;
	if (p->left)
		p->left->neighbour = (p->neighbour)? p->neighbour->right: NULL;
	connectRecur(p->left);
	connectRecur(p->right);
}
struct node* newnode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->neighbour = NULL;
	return(node);
}
int main(){
	struct node *root = newnode(10);
	root->left	 = newnode(8);
	root->right	 = newnode(2);
	root->left->left = newnode(3);
	connect(root);
	printf("Following are populated neighbour pointers in the tree (-1 is printed if there is no neighbour) \n");
	printf("neighbour of %d is %d \n", root->data,root->neighbour? root->neighbour->data: -1);
	printf("neighbour of %d is %d \n", root->left->data,root->left->neighbour? root->left->neighbour->data: -1);
	printf("neighbour of %d is %d \n", root->right->data,root->right->neighbour? root->right->neighbour->data: -1);
	printf("neighbour of %d is %d \n", root->left->left->data,root->left->left->neighbour? root->left->left->neighbour->data: -1);
	return 0;
}

