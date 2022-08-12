#include <stdio.h>
#include <stdlib.h>
#define Max 10

int Q1[Max];
int Q2[Max];
int q1_front,q1_rear = -1;
int q2_front,q2_rear = -1;

void insert_Q1(int val){
    if(q1_rear == Max - 1){
        printf("Queue Overflow\n");
    }else if(q1_front == -1 && q1_rear == -1){
        q1_front=q1_rear=0;
    }else{
        q1_rear = q1_rear + 1;
    }
    Q1[q1_rear] = val;
}

int delete_Q1(){
    int val;
    if(q1_front == -1 || q1_front>q1_rear){
        printf("Queue Underflow\n");
    }else{
        val = Q1[q1_front];
        q1_front++;
        if(q1_front>q1_rear){
            q1_front=q1_rear=-1;
        }
    }
    return val;
}


void insert_Q2(int val){
    if(q2_rear == Max - 1){
        printf("Queue Overflow\n");
    }else if(q2_front == -1 && q2_rear == -1){
        q2_front=q2_rear=0;
    }else{
        q2_rear = q2_rear + 1;
    }
    Q2[q2_rear] = val;
}

int delete_Q2(){
    int val;
    if(q2_front == -1 || q2_front>q2_rear){
        printf("Queue Underflow\n");
    }else{
        val = Q2[q2_front];
        q2_front++;
        if(q2_front>q2_rear){
            q2_front=q2_rear=-1;
        }
    }
    return val;
}


//Stack implementation

void push(int val){

    if(q1_front == -1 || q1_front > q1_rear){
            insert_Q1(val);

    }else{
        while(q1_front != -1){
            insert_Q2(delete_Q1());
        }

        insert_Q1(val);

        while(q2_front != -1){
            insert_Q1(delete_Q2());
        }
    }
}

int pop(){
    int val;
    if(q1_front == -1 || q1_front > q1_rear){
        printf("Stack Empty\n");
    }else{
        val = delete_Q1();
    }
    return val;
}

int peek(){
	int val;
	if(q1_front == -1 || q1_front > q1_rear){
		printf("Stack is Empty");
	}else{
		val = Q1[q1_front];
	}
	return val;
}


int main() {

    int option;
    int val;
    do{
        printf("Choose one from below choices\n  1. Push\n  2. Pop\n  3. Peek\n  4. Exit\nChoice : ");
        scanf("%d",&option);

        switch(option){

        case 1:
            printf("Enter Value : ");
            scanf("%d",&val);
            push(val);
            printf("\n\n");
            break;
        case 2:
            printf("Pop value = %d\n",pop());
            printf("\n\n");
            break;
        case 3:
        	printf("Peek Value = %d\n",peek());
        	printf("\n\n");
			break;
        default:
            printf("\nEnd\n");
            return 0;
        }

    }while(option != 4);

    printf("\nEnd\n");

    return 0;
}

