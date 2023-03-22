#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node{
	int data;
	struct node *nextNode;	
};
struct node *startNode=0, *lastNode=0, *newNode, *ptr;

struct node* getNode(){
	newNode=(struct node *)malloc(sizeof(struct node));
	printf("Insert Data : ");
	scanf("%d",&newNode->	data);
	newNode->	nextNode=NULL;
	return newNode;
}

void insert();
void deleteListItem();
void traverse();
void insertAtBegining();
void insertAtMiddle();
void insertAtEnd();
void DeleteAtBegining();
void DeleteAtEnd();
void insertMiddleBeforeOperation(int);
void insertMiddleAfterOperation(int);

int main(int argc, char** argv) {
	printf("Linked list is Empty. Add an item...\n");
	struct node *newNode=getNode();
	startNode=newNode;
	lastNode=newNode;
	newNode->nextNode=newNode;
	printf("\n");
	int oper;
	printf("Enter list operation (1-Insert, 2-Delete, 4-Traverse) : ");
	scanf("%d",&oper);
	while(oper!=-1){
		switch(oper){    
		case 1:    
			insert();
		 break;   
		case 2:    
			deleteListItem();
		 break;    
    	case 4:    
    		traverse();
		 break;
		default:     ;
		    printf("Invalid...\n\n");
		}
		printf("Enter list operation (1-Insert, 2-Delete, 4-Traverse) : ");
		scanf("%d",&oper);
	}	
	return 0;
}
void insert(){
		printf("Insert Node at (1-Begining, 2-Middle, 3-End) : ");
		int insertOp;
		scanf("%d",&insertOp);
		
		switch(insertOp){    
		case 1:    
	    	insertAtBegining(); 
	 	break;   
		case 2:    
		    insertAtMiddle();
	 	break;  
	    case 3:    
		    insertAtEnd();
	 	break;	
	    	
		default:     
	    	printf("Invalid insert operation...");
		}    	

	printf("\n\n");	
}
void deleteListItem(){
	printf("Delete Node from (1-Begining, 2-End) : ");
	int deleteOp;
	scanf("%d",&deleteOp);
	
	switch(deleteOp){    
	case 1:    
    	DeleteAtBegining(); 
 	break;   
	case 2:    
	    DeleteAtEnd();
 	break;  
        	
	default:
		printf("Invalid Delete operation...\n");
	}
	printf("\n");
}
void traverse(){
	if(startNode==0){
		printf("List is Empty...\nYou can't traverse...'");
	}else{
		printf("You are to Print List...\n");
		struct node *ptr=startNode;
		while(ptr->nextNode!=startNode){
			printf("%d ",ptr->data);
			ptr=ptr->nextNode;
		}
		printf("%d",ptr->data);	
	}
	printf("\n\n");
}
void insertAtBegining(){
		printf("You are to Insert at the Begining ...\n");
		struct node *newNode=getNode();
		newNode->nextNode=startNode;
		startNode=newNode;
		lastNode->nextNode=startNode;
		printf("\n\n");
}
void insertAtMiddle(){
	int data;
	if(startNode==0){
		printf("List is Empty...\nYou can't Insert at middle ...'");
	}else{
		printf("You are to Insert at Middle ...\n");
		int insertMiddleOperation;
		printf("1-Insert before specific node , 2-Insert after specific node : ");
		scanf("%d",&insertMiddleOperation);
		switch(insertMiddleOperation){    
		case 1:   
			printf("Enter data of the specific node : ");
			scanf("%d",&data); 
	    	insertMiddleBeforeOperation(data); 
	 	break;   
		case 2:    
			printf("Enter data of the specific node : ");
			scanf("%d",&data);
		    insertMiddleAfterOperation(data);
	 	break;  
	        	
		default:
			printf("Invalid Delete operation...");
		}
	}
	printf("\n");
}
void insertAtEnd(){
	if(startNode==0){
		printf("List is Empty...\nYou can't Insert at end ...");
	}else{	
		printf("You are to Insert at the End ...\n");
		struct node *newNode=getNode();
		lastNode->nextNode=newNode;
		lastNode=newNode;
		lastNode->nextNode=startNode;
	}
	printf("\n");
}
void DeleteAtBegining(){
	if(startNode==0){
		printf("List is Empty...\nYou can't Delete at begining ...");
	}else{
		ptr=startNode;
		printf("You are to Delete from the Begining ...\n");
		startNode=startNode->nextNode;
		lastNode->nextNode=startNode;
		free(ptr);
	}
	printf("\n");
}
void DeleteAtEnd(){
	if(startNode==0){
		printf("List is Empty...\nYou can't Delete at end ...");
	}else{
			printf("You are to Delete from the End ...\n");
			struct node *ptr=startNode;
			while(ptr->nextNode!=lastNode){
				ptr=ptr->nextNode;
			}
			
		lastNode=ptr;
		free(ptr->nextNode);
		lastNode->nextNode=startNode;	 
	}
	printf("\n");
}
void insertMiddleBeforeOperation(int data){
	if(startNode==0){
		printf("List is Empty...\nYou can't Insert at middle ...");
	}else if(startNode->data==data){
		struct node *newNode=getNode();
		newNode->nextNode=startNode;
		startNode=newNode;
		lastNode->nextNode=startNode;			
	}else{
		struct node *ptr=startNode;
		while(ptr->nextNode->data!=data){
			ptr=ptr->nextNode;
		}
		struct node *newNode=getNode();
		newNode->nextNode=ptr->nextNode;
		ptr->nextNode=newNode;
	}
	printf("\n");
}
void insertMiddleAfterOperation(int data){
	if(startNode==0){
		printf("List is Empty...\nYou can't Insert at middle ...");
	}else if(startNode->data==data){
		struct node *newNode=getNode();
		newNode->	nextNode=startNode->nextNode;
		startNode->nextNode=newNode;
	}else{
		struct node *ptr=startNode;
		while(ptr->data!=data){
			ptr=ptr->nextNode;
		}
		struct node *newNode=getNode();
		newNode->nextNode=ptr->nextNode;
		ptr->nextNode=newNode;
	}
	printf("\n");
}

