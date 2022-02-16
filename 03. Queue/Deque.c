#include <stdio.h>
#define UKURAN 5

int queue[UKURAN];
int front = -1;
int rear = -1;



int isEmpty()
{
    return (front == -1) && (rear == -1);
}


int isFull()
{
    return (front == 0 && rear == UKURAN - 1) || (front == rear + 1);
}


// enQueueFront = insertFront = Tambah item dr bagian dpn queue dgn menggunakan pointer front
void enQueueFront(int data)
{
    if(isFull()) {
        printf("Queue penuh !");
    }
    else if(isEmpty()) {
        rear = front = 0;
        queue[front] = data;

    }
    else if(front == 0) {
        front = UKURAN - 1;
        queue[front] = data;
    }
    else {
        front--;
        queue[front] = data;
    }
}


// Blh jg buatnya
// void enQueueFront(int data)
// {
//     if(isFull()) {
//         printf("Queue penuh !");
//         return;
//     }

//     if(isEmpty()) {
//         rear = front = 0;

//     }
//     else if(front == 0) {
//         front = UKURAN - 1;
//     }
//     else {
//         front--;
//     }
    
//     queue[front] = data;
// }


// enQueueRear = insertRear = Tambah item dr bagian blkng queue dgn menggunakan pointer rear
void enQueueRear(int data)
{
    if(isFull()) {
        printf("Queue penuh !");
        return;
    }
    
    if(isEmpty()) {
        front = rear = 0;
    }
    else if(rear == UKURAN - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    
    queue[rear] = data;
}


// deQueueFront = deleteFront = Menghapus item dr bagian dpn queue dgn menggunakan pointer front)
void deQueueFront()
{
    if(isEmpty()) {
        printf("Queue kosong !");
        return;
    }

    if(front == rear) {
        printf("\nItem yang dihapus : %d", queue[front]);
        front = rear = -1;
    }
    else if(front == UKURAN - 1) {
        printf("\nItem yang dihapus : %d", queue[front]);
        front = 0;
    }
    else {
        printf("\nItem yang dihapus : %d", queue[front]);
        front++;

        // Bs jg kita buat printf("\nItem yang dihapus : %d", queue[front++]);
    }
}


// deQueueRear = deleteRear = Menghapus item dr bagian blkng queue dgn menggunakan pointer rear
void deQueueRear()
{
    if(isEmpty()) {
        printf("Queue kosong !");
        return;
    }
    
    if(front == rear) {
        printf("\nItem yang dihapus : %d", queue[rear]);
        front = rear = -1;
    }
    else if(rear == 0) {
        printf("\nItem yang dihapus : %d", queue[rear]);
        rear = UKURAN - 1;
    }
    else {
        printf("\nItem yang dihapus : %d", queue[rear--]);
    }
}


// Sama aja dgn peekFront()
int getFront()
{
    // Anggap klo nilai yg dikembalikan adlh -1 berarti queue nya kosong.
    if(isEmpty()) {
        printf("Queue kosong !");
        return -1;
    }

    return queue[front];
}


// Sama aja dgn peekRear()
int getRear()
{
    // Anggap klo nilai yg dikembalikan adlh -1 berarti queue nya kosong.
    if(isEmpty()) {
        printf("Queue kosong !");
        return -1;
    }

    return queue[rear];
}


void cetak()
{
    if(isEmpty()) {
        printf("\nQueue kosong !");
    }
    else {
        printf("\nIsi queue :");
        for(int i = 0; i < UKURAN; i++) {
            printf(" %d", queue[i]);
        }
    }
}






int main()
{
    enQueueRear(7);
    enQueueRear(8);
    enQueueRear(99);
    enQueueRear(-12);
    enQueueRear(23);

    // printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    // cetak();
    // printf("\n\n");



    deQueueRear();
    deQueueRear();
    enQueueRear(27);
    // printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    // printf("\n\n");



    enQueueRear(28);
    printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    printf("\n\n");

    return 0;
}











/*
Operasi utama di deque (Double Ended Queue) :
insertFront
insertLast
deleteFront
deleteRear

Operasi tambahan :
getFront
getRear
isEmpty
isFull

Deque adlh pengembangan dr queue yg bs beroperasi layaknya queue maupun stack.
*/