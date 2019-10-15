//creation
//insertion
//deletion
//Traversing
//Searching
#include<stdio.h>
#include<stdlib.h>

struct DoublyList{
	int data;
	struct DoublyList* next;
	struct DoublyList* prev;
};

void insertion(struct DoublyList** node,int data){
	struct DoublyList* newnode=(struct DoublyList*)malloc(3);
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	if((*node)==NULL){
		(*node)=newnode;
		return;
	}
	while((*node)->next!=NULL){
		
		(*node)=(*node)->next;
	}
	(*node)->next=newnode;
	newnode->prev=(*node);
}

void deletion(struct DoublyList** node,int data){
	if((*node)->prev==NULL && (*node)->next==NULL && (*node)->data==data){
		(*node)=NULL;
		return;
	}
	while((*node)->prev!=NULL){
		(*node)=(*node)->prev;
	}
	if((*node)->data==data){
		(*node)=(*node)->next;
		(*node)->prev=NULL;
	}
	while((*node)->next!=NULL){
		bool check=false;
		if((*node)->data==data){
			(*node)=(*node)->prev;
			(*node)->next=(*node)->next->next;
			(*node)->next->prev=(*node);
			return;
		}
		(*node)=(*node)->next;
	}
	if((*node)->data==data){
		(*node)=(*node)->prev;
		(*node)->next=(*node)->next->next;
	}
}

void traversing(struct DoublyList** node){
	while((*node)->prev!=NULL){
		(*node)=(*node)->prev;
	}
	while((*node)->next!=NULL){
		printf("%d - >",(*node)->data);
		(*node)=(*node)->next;
	}
	printf(" %d \n",(*node)->data);
}

void searching(struct DoublyList** node,int data){
	while((*node)->prev!=NULL){
		(*node)=(*node)->prev;
	}
	while((*node)->next!=NULL){
		if((*node)->data==data){
			printf("%d found\n",data);
			return;
		}
		(*node)=(*node)->next;
	}
	if((*node)->data==data){
		printf("%d found\n",data);
	}
	else{
		printf("not found\n");
	}
}

int main(){
	struct DoublyList** node=(struct DoublyList**)malloc(1);
	(*node)=NULL;
	int opt,data,position;
	while(1){
		printf("1>insertion\n2>deletion\n3>Traversing\n4>searching\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:printf("Enter data : ");
				scanf("%d",&data);
				insertion(node,data);
				break;
			case 2:printf("Enter data : ");
				scanf("%d",&data);
				deletion(node,data);
				break;
			case 3:traversing(node);
				break;
			case 4:printf("Enter data : ");
				scanf("%d",&data);
				searching(node,data);
				break;
			default:return 0;
				break;
		}
	}
	return 0;
}
