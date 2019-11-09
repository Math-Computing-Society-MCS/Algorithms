//creation
//insertion
//deletion
//Traversing
//Searching
#include<stdio.h>
#include<stdlib.h>

struct CircSingly{
	int data;
	struct CircSingly* next;
};

void insertion(struct CircSingly** first,struct CircSingly** last,int data){
	struct CircSingly* node=(struct CircSingly*)malloc(2);
	node->data=data;
	node->next=(*first);
	if((*first)==NULL && (*last)==NULL){
		(*first)=node;
		(*last)=node;
		return;
	}
	(*last)->next=node;
	node->next=(*first);
	(*last)=node;
}

void deletion(struct CircSingly** first,struct CircSingly** last,int data){
	if((*first)->data==data){
		(*first)=(*first)->next;
		return;
	}
	do{
		if((*first)->next->data==data){
			(*first)->next=(*first)->next->next;
			continue;
		}
		(*first)=(*first)->next;
	}while((*first)->next!=(*last));
	if((*last)->data==data){
		(*last)=(*first);
		(*first)->next=(*first)->next->next;
		(*first)=(*first)->next;
		return;
	}
	(*first)=(*first)->next;
	(*first)=(*first)->next;
}

void traversing(struct CircSingly** first,struct CircSingly** last){
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

void searching(struct CircSingly** first,struct CircSingly** last,int data){
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
	struct CircSingly** first=(struct CircSingly**)malloc(1);
	struct CircSingly** last=(struct CircSingly**)malloc(1);
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
