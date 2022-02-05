#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    struct node* prev;
    int value;
    int size;
    struct node* next;
}node;

node* H;
int garbage = 0;

node* create(){
    node* t = malloc(sizeof(node));
    printf("Enter the value : ");
    scanf("%d",&(t->value));
    printf("Enter the size : ");
    scanf("%d",&(t->size));
    t->next=NULL;
    t->prev=NULL;
    return t;
}

void insert(node* t){ // inserting at front
    if(H==NULL){
        H=t;
    }
    else{
        node* p = H;
        while(p->next){
            p=p->next;
        }
        p->next=t;
        t->prev=p;
    }
}

void display(){
    printf("\nThe current list is         : ");
    node* p = H;
    if(p){
        while(p->next){
            if(p->value!=INT_MIN){
                printf("%d -> ",p->value);
            }
            else{
                printf("# -> ");
            }
            p=p->next;
        }
        if(p->value!=INT_MIN){
            printf("%d -> ",p->value);
        }
        else{
            printf("# -> ");
        }
    }

    printf("\nThe corresponding sizes are : ");
    p = H;
    if(p){
        while(p->next){
            printf("%d -> ",p->size);
            p=p->next;
        }
        printf("%d -> ",p->size);
    }
    printf("\n");
}

void garbageCollection(){
    node * p =H;
    
    if(p){
        while(p->next){
            if(p->value==INT_MIN){
                garbage += p->size;
            }
            p=p->next;
        }
        if(p->value==INT_MIN){
            garbage += p->size;
        }
    }
    printf("The amount of garbage collected is : %d",garbage);

}

void delete(){
    int n;
    printf("Enter the number of elements to delete : ");
    scanf("%d",&n);
    while(n--){
        int pos;
        printf("Enter the pos to delete : ");
        scanf("%d",&pos);  
        node* p = H;      
        for(int i =2;i<=pos;i++){
            p=p->next;
        }
        p->value=INT_MIN;
        display();
                
    }
}

int main(){
    int n,pos;
    while (1){
 		printf("\n\n============================");
		printf("\n1.Display\n2.Insert\n3.Delete\n4.Exit");
		printf("\n============================");
	    printf("\nEnter Choice : ");
	    fflush(stdin);
	    scanf("%d", &n);
 		node* t;
	    switch (n) {
            case 1:
                display();
                break;
            case 2:
                t=create();
                insert(t);
                display();
            
                break;
            case 3:
                delete();
                garbageCollection();
                break;
            case 4:
                exit(0);
            default :
                printf("Wrong option selected");
        }
    }
}