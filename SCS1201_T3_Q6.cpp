#include <stdio.h>
#include <conio.h>
#define MAX 100 
int insert(int k);	
int remove();	
int stack[100] ,q1[MAX] ;
int top=-1;
int front=0,rear=0;
int val,N,i,j,m,y;
int main()
{
	printf("Enter N : ");
	scanf("%d",&N);	
	printf("\n");
	for(i=1;i<=N;i++){
		y=i;
 		while(y!=0)	
		{
			j=y%2;
	    	y=y/2;	
      		stack[++top]=j;
		}

		while(top!=-1)	{
			j=stack[top];
			top--;
			insert(j);
			}	

		while(front<rear)	
	
    	{
   			printf("%d" ,remove());
		
		}
		printf("\n");
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
