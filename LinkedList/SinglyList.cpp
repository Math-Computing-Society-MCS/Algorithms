//creation
//insertion
//deletion
//Traversing
//Searching
#include<stdio.h>
#include<stdlib.h>

struct SinglyList{
	int data;
	struct SinglyList* next;
};

void insertion(struct SinglyList** node,int data){
	struct SinglyList* nextNode=(struct SinglyList*)malloc(sizeof(struct SinglyList));
	nextNode->data=data;
	nextNode->next=NULL;
	struct SinglyList** temp=(struct SinglyList**)malloc(1);
	(*temp)=(*node);
	if((*node)==NULL){
		(*node)=nextNode;
		return;
	}
	while((*temp)->next!=NULL){
		(*temp)=(*temp)->next;
	}
	(*temp)->next=nextNode;
}

void deletion(struct SinglyList** node,int data){
	struct SinglyList** temp=(struct SinglyList**)malloc(1);
	(*temp)=(*node);
	if((*node)->data==data){
		(*node)=(*node)->next;
		printf("%d is deleted\n",data);
		return;
	}
	while((*temp)->next!=NULL){
		if((*temp)->next->data==data){
			(*temp)->next=(*temp)->next->next;
			printf("%d is deleted\n",data);
			return;
		}
		(*temp)=(*temp)->next;
	}
	printf("Not found\n");
}

void traversing(struct SinglyList** node){
	struct SinglyList** temp=(struct SinglyList**)malloc(1);
	(*temp)=(*node);
	while((*temp)!=NULL){
		printf("%d - > ",(*temp)->data);
		(*temp)=(*temp)->next;
	}
	printf("\n");
}

void searching(struct SinglyList** node,int data){
	struct SinglyList** temp=(struct SinglyList**)malloc(1);
	(*temp)=(*node);
	int pos=1;
	while((*temp)!=NULL){
		if((*temp)->data==data){
			printf("Found at %dth position\n",pos);
			return;
		}
		(*temp)=(*temp)->next;
		pos+=1;
	}
	printf("Not found\n");
}

void concatination(struct SinglyList** node,int data){
	
}

int main(){
	struct SinglyList** node=(struct SinglyList**)malloc(1);
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
