#include <stdio.h>
#include <conio.h>
#define MAX 100 
int insert(int k);	
int remove();	
int q1[MAX],stack[100];
int top=-1;
int front=0,rear=0;
int val,like,i,k,m;
int main()
{
	printf("how many number do you like to enter:");
	scanf("%d",&like);
	for(i=0;i<like;i++){	
		printf("Enter : ");
		scanf("%d",&m);
		stack[++top]=m;
	}

	while(top!=-1){
		k=stack[top];
		top--;
		insert(k);
	}	

	while(front<rear){
   		printf("%d\t",remove());
		}
}
	
int insert(int k)
{
	q1[rear]=k;	
	rear++;	
	}	
	
int remove()
{
 	val=q1[front];	
	front++;
	return val;	
}


		
