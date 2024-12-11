#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node *top = NULL;
int isEmpty()
{
   if(top==NULL)
   {
      return 1;
   }
   else{
      return 0;
    }
}
void push(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(newNode));
    if(newNode==NULL)
    {
        printf("Stack underflow\n");
    }
    newNode->data=data;
    newNode->link=NULL;
    newNode->link=top;
    top=newNode;
}
int pop()
{
    struct node*temp;
    int val;
    if(isEmpty())
    {
       printf("Stack Underflow");
    }
    temp=top;
    val=temp->data;
    top=temp->link;
    free(temp);
    return val;

}
int peek()
{
	if(isEmpty())
	{
		printf("Stack underflow");
	}
	return top->data;
}
void search(int item)
{
	struct node *temp=top;
	int flag=0;
	while(temp!=NULL)
	{
		if(item==temp->data)
		{
			printf("%d is Included in the stack\n",temp->data);
			flag=1;
		}
		temp=temp->link;
	}
	if(flag!=1){
		printf("\nElement not found\n");
	}
}
void print()
{
	struct node*temp=top;
	if(isEmpty())
	{
		printf("Stack Underflow\n");
	}
	printf("The Stack Elements are\n\n");
	while(temp)
	{		printf("%d\t",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
int main()
{
	int choice,data,sitem;
	while(1)
	{
		printf("\n");
		printf("1.Push\n2.Pop\n3.Print the Top element\n4.Print all the Stack Element\n5.Search Element\n6.Exit");
		printf("\n\nPlease Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			 printf("Enter the element to be Pushed\n");
			 scanf("%d",&data);
			 push(data);
			 break;
			case 2:
			 data=pop();
			 printf("%d Element Removed\n",data);
			 break;
			case 3:
			 printf("The Top most Element of the Stack is %d\n",peek());
			 break;
			case 4:
			 print();
			 break;
			case 5:
			 printf("Enter the item to be searched\n");
			 scanf("%d",&sitem);
			 search(sitem);
			 break;
			case 6:
			 exit(1);
			default:
			 printf("!!!Wrong Choice!!!\n");
		}
	}
	return 0;
}
