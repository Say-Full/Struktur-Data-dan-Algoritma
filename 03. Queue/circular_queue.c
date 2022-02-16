#include <stdio.h>
#define UKURAN 5

int queue[UKURAN];
int front = -1;
int rear = -1;



int isEmpty()
{
    // return rear == -1;
    // return front == -1;
    // return (front == -1) || (rear == -1);
    return (front == -1) && (rear == -1);
}


// Klo ketika pointer rear dimajukan dan ternyata nilainya sama dgn pointer front, berarti terjadi overflow, yaitu kita ingin menambah data di slot yg sudah ada datanya.
int isFull()
{
    return ((rear + 1) % UKURAN) == front;
}


void enQueue(int data)
{
    if(isFull()) {
        printf("\nQueue penuh (overflow) !");
    }
    else {
        if(isEmpty()) {
            front = rear = 0;
            queue[rear] = data;
        }
        else {
            // Alasan knp update nilai rear dgn cara (rear + 1) % UKURAN dr pd rear++ adlh krn klo pointer rear dh sampe ujung queue, maka penambahan data selanjutnya dilakukan pd awal queue, yaitu indeks 0.
            // Cnthnya klo array nya berukuran 5 (berarti kita bs isi data pd indeks 0 sampai dgn indeks 4), skrng pointer rear berada di indeks 4, ketika ingin diisi data yg baru, maka pointer rear maju dgn cara : (rear + 1) % UKURAN = (4 + 1) % 5 = 5 % 5 = 0. Jd penambahan data dilakukan pd indeks 0.
            // Klo pointer rear sedang berada di indeks 0, jika dilakukan penambahan data, berarti : (0 + 1) % 5 = 1 % 5 = 1. Jd dilakukan penambahan data pd indeks 1.
            // Klo pointer rear sedang berada di indeks 1, jika dilakukan penambahan data, berarti : (1 + 1) % 5 = 2 % 5 = 2. Jd dilakukan penambahan data pd indeks 2.
            rear = (rear + 1) % UKURAN;
            queue[rear] = data;
        }
    }
}


void deQueue()
{
    if(isEmpty()) {
        printf("\nQueue kosong !");
    }
    else {
        printf("\nItem yang dihapus : %d", queue[front]);
        front = (front + 1) % UKURAN;

        if(front > rear) {
            front = rear = -1;
        }
    }
}


int peek()
{
    return queue[front];
}


void cetak()
{
    if(isEmpty()) {
        printf("\nQueue kosong !");
        return;
    }

    printf("\nIsi queue :");

    if(rear >= front) {
        for(int i = front; i <= rear; i++) {
            printf(" %d", queue[i]);
        }
    }
    else {
        for(int i = front; i < rear; i++) {
            printf(" %d", queue[i]);
        }

        for(int i = 0; i <= rear; i++) {
            printf(" %d", queue[i]);
        }
    }
}







int main()
{
    // enQueue(7);
    // enQueue(8);
    // enQueue(99);
    // enQueue(-12);
    // enQueue(23);

    // printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    // cetak();
    // printf("\n\n");



    // deQueue();
    // deQueue();
    // enQueue(27);
    // printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    // printf("\n\n");



    // enQueue(28);
    // printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    // printf("\n\n");

    return 0;
}









/*
Circular Queue / Ring Buffer diperkenalkan untuk mengatasi permasalahan overflow di Linear / Simple Queue, yaitu jika kita punya queue yg berukuran 5, awalnya kita isi 5 data sehingga queue penuh, lalu kita hapus 2 data sehingga 2 slot kosong dan 3 slot berisi, kita tdk bs menambahkan data baru pd slot 1 dan 2 krn pointer rear sudah berada di ujung queue yg menandakan queue sudah penuh dan tdk bs melakukan operasi enqueue.

Pd Circular Queue, pointer rear bs 
*/