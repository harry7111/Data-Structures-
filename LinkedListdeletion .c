//c program to delete linked list...
//At head,tail,specific position and condition..


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



void FirstNodeDeletion(struct node *head)
{
    struct node *temp,*ptr;
    
    if(head == NULL)
    {
        printf(" There are no node in the list.");
    }
    else
    {
        temp = head->next; 
        ptr = head;
        head = temp->next;
        ptr->next = head;
        printf("\nData of node 1 which is being deleted is :  %d\n", temp->data);
        free(temp);  
    }
}


void tailNodeDeletion(struct node *head){
    int i;
    struct node *temp ,*pn;
    if (head==NULL){
        return 0;
    }
    else{
        temp = head;
        while (temp->next!=NULL){
            pn = temp;
            temp = temp->next;
        }
        pn->next=temp;
        printf("\nData of Last node which is being deleted is :  %d\n", temp->data);
        free(temp);
        pn->next=NULL;
    }
}

void deleteatpos(struct node *head,int pos){
    int i;
    struct node *temp ,*pn;
    temp = pn = head;
    for (i=0;i<pos;i++){
        temp = temp->next;
    }
    for (i=0;i<pos-1;i++){
        pn = pn->next;
    }
    pn->next = temp->next;
    free(temp);
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


void display(struct node *ptr){
    while (ptr->next!=NULL){
        ptr = ptr->next;
        printf("%d ",ptr->data);

    }

}


int main() {
    int pos;
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

     FirstNodeDeletion(head);
     display(head);
     
     tailNodeDeletion(head);
     display(head);
     
     printf("\nEnter the position of the Linked list to delete : ");
     scanf("%d",&pos);
     deleteatpos(head,pos);
     display(head);
     
     
     return 0;
    
}
