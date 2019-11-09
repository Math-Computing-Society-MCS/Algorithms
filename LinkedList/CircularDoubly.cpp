//creation
//insertion
//deletion
//Traversing
//Searching
#include<stdio.h>
#include<stdlib.h>

struct CircDoubly{
	int data;
	struct CircDoubly* next;
	struct CircDoubly* prev;
};

void insertion(struct CircDoubly** first,struct CircDoubly** last,int data){
	struct CircDoubly* node=(struct CircDoubly*)malloc(3);
	node->data=data;
	if((*first)==NULL && (*last)==NULL){
		(*first)=node;
		(*last)=node;
		return;
	}
	
	node->next=(*first);
	node->prev=(*last);
	(*last)->next=node;
	(*last)=node;
}

void deletion(struct CircDoubly** first,struct CircDoubly** last,int data){
	if((*first)->data==data){
		(*first)=(*first)->next;
		return;
	}
	bool ifyes=true;
	while((*last)!=(*first)){
		if((*first)->data==data && ifyes){
			(*first)=(*first)->prev;
			(*first)->next=(*first)->next->next;
			(*first)->next->prev=(*first);
			ifyes=false;
		}
		(*first)=(*first)->next;
	}
	if(ifyes && (*last)->data==data){
		(*last)=(*last)->prev;
		(*last)->next=(*last)->next->next;
		(*last)->next->prev=(*last);
	}
	(*first)=(*first)->next;
}

void traversing(struct CircDoubly** first,struct CircDoubly** last){
	while((*last)!=(*first)){
		printf("%d - > ",(*first)->data);
		(*first)=(*first)->next;
	}
	if((*last)==(*first) && (*last)!=NULL){
		printf("%d - > ",(*first)->data);
		(*first)=(*first)->next;
	}
	printf("\n");
}

void searching(struct CircDoubly** first,struct CircDoubly** last,int data){
	bool ifyes=false;
	while((*last)!=(*first)){
		if((*first)->data==data && !ifyes){
			printf("found\n");
			ifyes=true;
			continue;
		}
		(*first)=(*first)->next;
	}
	if((*last)==(*first) && (*last)!=NULL){
		if((*first)->data==data){
			printf("found\n");
			ifyes=true;
		}
		(*first)=(*first)->next;
	}
	if(ifyes==false)
		printf("Not found\n");
}

int main(){
	struct CircDoubly** first=(struct CircDoubly**)malloc(1);
	struct CircDoubly** last=(struct CircDoubly**)malloc(1);
	(*first)=NULL;
	(*last)=NULL;
	int opt,data,position;
	while(1){
		printf("1>insertion\n2>deletion\n3>Traversing\n4>searching\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:printf("Enter data : ");
				scanf("%d",&data);
				insertion(first,last,data);
				break;
			case 2:printf("Enter data : ");
				scanf("%d",&data);
				deletion(first,last,data);
				break;
			case 3:traversing(first,last);
				break;
			case 4:printf("Enter data : ");
				scanf("%d",&data);
				searching(first,last,data);
				break;
			default:return 0;
				break;
		}
	}
	return 0;
}
