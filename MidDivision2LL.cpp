#include <iostream>
using namespace std;
struct Node
{
	char data;
	struct Node* left, *right;
	Node(char data)
	{	this->data = data;
		left = right = NULL;}
};
void printPostorder(struct Node* node)
{	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->data << " ";
}
void printInorder(struct Node* node)
{	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}
void printPreorder(struct Node* node)
{	if (node == NULL)
		return;
	cout << node->data << " ";
	printPreorder(node->left); 
	printPreorder(node->right);
} 
int main()
{	struct Node *root ;
	root = new Node('A');
	root->left = new Node('B');
	root->right = new Node('C');
	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->left = new Node('F');
	root->right->right = new Node('G');

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root); 

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}
