#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*head=NULL;
void ins_beg(int item){
	if(head==NULL){
		struct node*newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=item;
		newNode->next=NULL;
		head=newNode;

	}
	else{
		struct node*newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=item;
		newNode->next=head;
		head=newNode;
		printf("\n%d is Inserted in the list",newNode->data);
	}
}
void ins_end(int item){
	struct node*temp=head;
	if(head==NULL){
		struct node*newNode=(struct node*)malloc(sizeof(struct node));
	 	newNode->data=item;
                newNode->next=NULL;
                head=newNode;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
			if(temp->next==NULL){
                                struct node*newNode=(struct node*)malloc(sizeof(struct node));
                                newNode->data=item;
                                temp->next=newNode;
                                newNode->next=NULL;
			}

	}
}
void ins_pos(int item,int pos){
	int count=2;
	struct node*temp=head;
	if(pos==1){
		ins_beg(item);
	}
	else{
		while(temp->next!=NULL){
			if(count==pos){
				struct node*newNode=(struct node*)malloc(sizeof(struct node));
                                newNode->data=item;
                                newNode->next=temp->next;
                                temp->next=newNode;

			}
			count=count+1;
			temp=temp->next;
		}
	}
}
void del_beg(){
	if(head==NULL){
		printf("\nThe List is Empty\n");
	}
	else{
		struct node*temp=head;
		head=temp->next;
		printf("\n %d is Deleted from the list",temp->data);
		free(temp);
	}
}
void del_end(){
	struct node*temp=head;
	struct node*prev;
	if(head==NULL){
		printf("\nThe List is Empty\n");
	}
	else{
		while(temp->next!=NULL){
				prev=temp;
				temp=temp->next;
		}
		prev->next=NULL;
		printf("\n%d is Deleted from the List",temp->data);
		free(temp);
	}
}
void del_pos(int pos){
	struct node*temp=head;
	struct node*prev=NULL;
	    if (pos < 1) {
	        printf("\nInvalid position\n");
	        return;
	    }
	    if (pos == 1) {
	        del_beg();
	        return;
	    }
	      while(pos!=1){
	            prev=temp;
	            temp=temp->next;
	            pos--;
	        }
	        prev->next=temp->next;
		printf("%d is Deleted from the position %d.\n",temp->data,pos+1);
	        free(temp);
	        temp=NULL;
	        return;
	        if(head!=NULL)
	                prev->next = temp->next;
	        free(temp);
}
void trav(){
	struct node*temp=head;
	if(head==NULL){
		printf("\nThe List is Empty\n\n");
	}
	else{
		printf("\nThe List Elements are:\n\n");
		while(temp->next!=NULL){
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}
int main(){
	while(1){
		int ch;
		int item;
		int cpos;
		printf("\n\n_____________Singly Linked List Operations______________\n");
		printf("1.Insertion at Begining\n2.Insertion at the End\n3.Insertion at Specific Position\n4.Deletion at Begining\n5.Deletion at the End\n6.Deletion at Specific Position\n7.Display the List\n8.Quit\n");
		printf("\nEnter your Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the Element to be Inserted: ");
				scanf("%d",&item);
				ins_beg(item);
				break;
			case 2:
				printf("\nEnter the Element to be Inserted: ");
                        	scanf("%d",&item);
                        	ins_end(item);
				break;
			case 3:
				printf("\nEnter the Element to be Inserted: ");
				scanf("%d",&item);
				printf("\nEnter the Position:");
				scanf("%d",&cpos);
				ins_pos(item,cpos);
				break;
			case 4:
				del_beg();
				break;
			case 5:
				del_end();
				break;
			case 6:
				printf("Enter the Position: ");
				scanf("%d",&cpos);
				del_pos(cpos);
				break;
			case 7:
				trav();
				break;
			case 8:
				printf("\nExiting...............\n");
				exit(1);
			default:
				printf("\n!!!!!!!! Wrong Choice !!!!!!!\n");
				break;
		}
	}
return 0;

}
