#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;



bool isEmpty()
{
    return head == NULL;
}


int panjang()
{
    if(isEmpty()) {
        return 0;
    }

    int panjang = 0;

    struct node *current = head->next;
        
    while(current != head) {
        panjang++;
        current = current->next;
    }
    
    return panjang;
}


void cetak()
{
    struct node *ptr = head;

    printf("\n\nBentuk Linked List sekarang :\n");
    if(!isEmpty()) {
        while(ptr->next != ptr) {
            printf("[%d, %d] -> ", ptr->key, ptr->data);
            ptr = ptr->next;
        }
    }
}


void tambahNode(int key, int data)
{
    struct node *nodeBaru = (struct node *) malloc(sizeof(struct node));
    
    nodeBaru->key = key;
    nodeBaru->data = data;
        
    if(isEmpty()) {
        head = nodeBaru;
        head->next = head;
    }
    else {
        nodeBaru->next = head;
        head = nodeBaru;
    }
}


struct node * hapusNodeTerbaru()
{
    struct node *tempLink = head;

    // Klo gk ada node, maka lngsng keluar.
    // Klo head menunjuk ke dirinya sendiri, berarti linked list nya sbnrnya kosong.
    if(isEmpty()) {
        printf("\n\nMaaf, tidak bisa melakukan proses penghapusan karena linked list kosong !");
        return NULL;
    }
    else if(head->next == head) {
        head = NULL;
        return tempLink;
    }
    
    head = head->next;
        
    return tempLink;
}