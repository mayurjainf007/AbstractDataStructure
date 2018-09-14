#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node* left;
	struct node* right;
};

struct node* newnode(char data);

struct node* att(char arr[], int start, int end){
	if(start >end)
		return NULL;
	int mid = (start+end)/2;
	struct node *root = newnode(arr[mid]);
	root->left = att(arr,start,mid-1);
	root->right = att(arr,mid+1,end);
	return root;
}
struct node* newnode(char data){
	struct node* nodex = (struct node*) malloc(sizeof(struct node));
	nodex->data = data;
	nodex->left = NULL;
	nodex->right = NULL;
	return nodex;
}
void preorder(struct node* nodex){
	if(nodex == NULL)
		return ;
	printf("%c",nodex->data);
	preorder(nodex->left);
	preorder(nodex->right);
}

void postorder(struct node* nodex){
	if(nodex == NULL)
		return ;
	preorder(nodex->left);
	preorder(nodex->right);
	printf("%c",nodex->data);
}
void inorder(struct node* nodex){
	if(nodex == NULL)
		return ;
	preorder(nodex->left);
	printf("%c",nodex->data);
	preorder(nodex->right);
}

void reversearray(char *arr, int start, int end){
	while(start<end){
		char x = arr[start];
		arr[start++] = arr[end];
		arr[end--] = x;
	}
}
void updatearray(char *arr, int n){
	int size;
	for(size = 0 ;arr[size]!='\0';++size);
	reversearray(arr,0,size-1);
	reversearray(arr,0,n-1);
	reversearray(arr,n,size-1);
}
int main(){
	char *arr;
	scanf("%[^\n]",arr);
	int n;
	for(n = 0 ;arr[n]!='\0';++n);
	
	struct node *root = att(arr,0,n-1);
	preorder(root);
	printf("\n");
	
	root = att(arr,0,n-1);
	postorder(root);
	printf("\n");
	
	root = att(arr,0,n-1);
	inorder(root);
	printf("\n");

	updatearray(arr,4);
	root = att(arr,0,n-2);
	preorder(root);
	printf("\n");
	
	updatearray(arr,2);
	root = att(arr,0,n-1);
	preorder(root);
	printf("\n");

	updatearray(arr,1);
	root = att(arr,0,n-3);
	preorder(root);
	printf("\n");
	
	return 0;
}
