//C program to perform insertion and searching operations on Linked Lists.......
//insertion at head
//insertion at tail
//insertion at position
//search the data in the Linked List 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


void create(struct node *p){
    int x;
    printf("Enter the element :");
    scanf("%d",&x);
    struct node *nn = malloc(sizeof(struct node));
    nn->data = x;
    if (p->next==NULL){
        nn->next = p->next;
        p->next = nn;
    }
    else {
    while(p->next!=NULL){
        p = p->next;
    }
    nn->next = p->next;
    p->next =nn;
    }
}


void insertathead(struct node *p,int data){
    struct node *nn = malloc(sizeof(struct node));
   
    nn->data = data;
    nn->next = p->next;
    p->next = nn;
    
}


void insertattail(struct node *head,int data){
    struct node *nn = malloc(sizeof(struct node));
    struct node *p = head;
    
    nn->data = data;
    nn->next = NULL;
    
    if(p==NULL){
        p = nn;

    } 
    else{
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = nn;
    }
}

int search(struct node *pp,int data){
    struct node *p = pp;
    while(p->next!=NULL){
        if (p->data ==data){
            return 1;
        }
        p = p->next;
    }
    return 0;
}


void insertatpos(struct node *head,int data,int pos){
    int i;
    struct node *nn = malloc(sizeof(struct node));
    nn->data = data;
    struct node *p = head;
    if (p == NULL){
        p = nn;
    }
    else {
        for (i=0;i<pos-1;i++){
            p = p->next;
        }
        nn->next = p->next;
        p->next = nn;
    }
}

void display(struct node *ptr){
    while (ptr->next!=NULL){
        ptr = ptr->next;
        printf("%d->",ptr->data);
    }
    printf("NULL");
}


int main() {
    int val,hval,tval,posval,position,find;
    struct node *head;
    head = malloc(sizeof(struct node));
    head->next=NULL;
    int n,i;
    printf("Enter the size :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        create(head);
    }
    display(head);
    printf("\nEnter the data of the node to insert at head :");
    scanf("%d",&hval);
    insertathead(head,hval);
    printf("\n");
    display(head);
    printf("\nEnter the data of the node to insert at tail :");
    scanf("%d",&tval);
    insertattail(head,tval);
    display(head);
    printf("\nEnter the data to search in the Linked List :");
    scanf("%d",&find);
    if (search(head,find)==1){
        printf("Data Found!!");
    }
    else{
        printf("Got lost in the Nebula!!Lost..:( RIP Data..");
    }
    printf("\nEnter the data & position of the node to insert at that position :");
    scanf("%d %d",&posval,&position);
    insertatpos(head,posval,position);
    display(head);
    
    return 0;
}