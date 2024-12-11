#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* left;
struct Node* right;
};
//struct Node* root=NULL;
//functn to create a new node
struct Node* createnode(int data)
{
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
}

struct Node* insert(struct Node* root,int data)
{
        if(root==NULL)
        {
                root=createnode(data);

        }
        else if(data<root->data)
        {
                root->left=insert(root->left,data);
        }
        else if(data>root->data)
        { 
                root->right=insert(root->right,data);
        }
        return root;

}

struct Node* findMin(struct Node *root)
{
        while(root && root->left!=NULL)
        {
        root=root->left;
        }
        return root;
}
//dlt a node from bst
struct Node* deleteNode(struct Node* root,int data){
if(root==NULL){
        printf("The value to be deleted is not present in the tree\n");
        return root;
        }
if(data<root->data){
        root->left=deleteNode(root->left,data);
}else if(data>root->data){
        root->right=deleteNode(root->right,data);

}else{
//node with one child or no child
        if(root->left==NULL){
                struct Node* temp=root->right;
                free(root);
                return temp;
        }else if(root->right==NULL){
                        struct Node* temp=root->left;
                        free(root);
                        return temp;
        }
//node with 2 children


        struct Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
        }
        return root;
}

//search a node in bst
struct Node* search(struct Node* root,int data){
if(root==NULL||root->data==data){
        return root;
        }
if(data<root->data){
        return search(root->left,data);
        }
else{
        return search(root->right,data);
        }
}
//preorder traversal
void preorder(struct Node* root){
if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
        }
}
//inorder traversal
void inorder(struct Node* root){
if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
        }
}
//postorder traversal
void postorder(struct Node* root){
if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
        }
}
int main(){
        struct Node* root=NULL;
        int choice,value;
        struct Node* foundNode;
        while(1){
                printf("1.INSERT NODE\n2.DELETE NODE\n3.SEARCH NODE\n4.PREORDER TRAVERSAL\n5.INORDER TRAVERSAL\n6.POSTORDER TRAVERSAL\n7.EXIT\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("enter the value to be inserted :");
                                scanf("%d",&value);
                                root=insert(root,value);
                                break;
                        case 2:
                                if(root==NULL){
                                        printf("tree is empty \n");
                                }
                                else{
                                        printf("enter the value to delete:");
                                        scanf("%d",&value);
                                        root=deleteNode(root,value);
                                        }
                                break;
                        case 3:
                                if(root==NULL){
                                        printf("tree is empty");
                                }
                                else{
                                        printf("enter value to search:");
                                        scanf("%d",&value);
                                        foundNode=search(root,value);
                                        if(foundNode!=NULL){
                                                        printf("value %d found in the tree ",value);
                                                }else{
                                                        printf("value %d not found in the tree",value);
                                                }
                                        }
                                break;
                        case 4:
                        if(root==NULL){
                                        printf("tree is empty");
                                }
                                else{
                                        printf("preorder traversal:\n");
                                        preorder(root);
                                        printf("\n");
                                        }
                                break;
                        case 5:
                                if(root==NULL){
                                        printf("tree is empty");
                                }
                                else{
                                        printf("inorder traversal:\n");
                                        inorder(root);
                                        printf("\n");
                                        }
                                break;
                        case 6:
                                if(root==NULL){
                                        printf("tree is empty");
                                }
                                else{
                                        printf("postorder traversal:\n");
                                        postorder(root);
                                        printf("\n");
                                        }
                                break;
                        case 7:
                                exit(0);
                        default:
                                printf("invalid choice!please try again\n");
                        }
                }
return 0;
}
