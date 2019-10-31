#include<stdio.h>
#include<stdlib.h>

typedef struct{

	int key;
}qu;
qu *queue;
void full();
void display();

int front=0, rear=0;
int capacity = 4;

void push(qu element){
	rear = (rear+1)%capacity;
    if(front == rear){
            full();
            printf("%d\n",queue[0].key );
    }
    queue[rear] = element;

}

qu pop(){
    if(front == rear){
            printf("error"); exit(0);
    }
    else       
            front = (front+1)%capacity;
            return queue[front];
    
}

void full(){
    int start;
    qu *nq;    
    start = (front+1)%capacity;
    nq = (qu*)malloc(2*capacity*sizeof(qu));
    if(start<2){
        for(int i=start;i<(capacity+start-1);i++)
            nq[i-start] = queue[i];
    }   
    else{
        int k=0;
        for(int i=start;i<capacity;i++)
                   nq[k++] = queue[i];
        for(int i=0; i<(rear+1); i++)
                    nq[k++] = queue[i];     
    }
    front = 2*capacity-1;
    rear = capacity-1;
    capacity*=2;
    free(queue);
    queue = nq;
}

void dispaly(){
	int i;
	if(front!=rear){
		for(i=(front+1)%capacity;i!=rear;i = (i+1)%capacity)
			printf("%d // ",queue[i].key);
		printf("%d // ",queue[i].key);
	}

}


void main(){
	
	int option;
	queue = (qu*)malloc(sizeof(qu)*capacity);
	option = 0;
	while(option!=4){
		
		printf("  1 to push \n 2 to pop \n 3 to display \n 4 to exit\n");
		scanf("%d", &option);
		switch(option){
			qu element;
			case 1: printf("enter the element------");
				scanf("%d",&(element.key));
				push(element);
				break;
			case 2: printf("--%d--",(pop()).key);
				break;
			case 3: dispaly();
					break;
			default: 	printf("invalid input");

		}
	}
}

