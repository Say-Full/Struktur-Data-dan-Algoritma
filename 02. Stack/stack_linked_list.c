#include <stdio.h>
#include <stdlib.h>

struct node {
    int nilai;
    struct node *next;
};

struct node *head = NULL;


int isEmpty()
{
    if(head == NULL) {
        return 1;
    }
    
    return 0;
}


int peek()
{
    if(isEmpty()) {
        printf("\n\nStack nya kosong bruh !\n");

        return -1;
    }

    return head->nilai;
}


void push(int data)
{
    struct node *ptr = (struct node *) malloc(sizeof(struct node));

    if(ptr == NULL) {
        printf("Gagal dalam mengalokasikan memori !");
    }

    ptr->nilai = data;

    if(head == NULL) {
        ptr->next = NULL;
        head = ptr;
    }
    else {
        ptr->next = head;
        head = ptr;
    }
}


void pop()
{ 
    if(isEmpty()) {
        printf("\n\nStack nya kosong bruh !\n");
        
        return;
    }
    
    struct node *ptr = head;
    head = head->next;

    printf("%d", ptr->nilai);
    free(ptr);
}


void cetak()
{
    struct node *ptr = head;

    if(isEmpty()) {
        printf("\n\nStack nya kosong !");
    }

    printf("\n\nIsi stack sekarang :");
    while(ptr != NULL) {
        printf(" %d", ptr->nilai);
        ptr = ptr->next;
    }
}










int main()
{
    // printf("\n\nApakah stack kosong ? %s", isEmpty() ? "Ya, stack kosong." : "Tidak, stack tidak kosong.");
    // printf("\n\n");

    



    // push(7);
    // push(-8);
    // push(99);

    // printf("\n\nApakah stack kosong ? %s", isEmpty() ? "Ya, stack kosong." : "Tidak, stack tidak kosong.");
    // printf("\n\nData teratas pada stack : %d", peek());
    // printf("\n\n");





    // printf("\n\nMenghapus data pada stack ! Data yg dihapus bernilai : ");
    // pop();
    // printf("\n\nData teratas pada stack : %d", peek());
    // cetak();
    // printf("\n\n");
    
    return 0;
}