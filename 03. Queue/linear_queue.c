#include <stdio.h>
#define UKURAN 5

int queue[UKURAN];

// Pointer front digunakan untuk menghapus data.
int front = -1;

// Pointer rear digunakan untuk menambah data.
int rear = -1;



// Jika pointer front dan/atau rear bernilai -1 menandakan queue-nya kosong.
int isEmpty()
{
    return rear == -1;
}


// Jika pointer rear bernilai UKURAN - 1 menandakan queue-nya penuh.
int isFull()
{
    return rear == UKURAN - 1;
}


// Fungsi untuk menambahkan (insert / add) data ke dlm queue.
void enQueue(int data)
{
    if(isFull()) {
        printf("\nQueue penuh !");
    }
    else {
        // Klo sblmnya queue nya kosong, maka majukan pointer front ke indeks 0.
        if(isEmpty()) {
            front = 0;
        }

        // Majukan pointer rear dan isi data pd posisi pointer rear skrng.
        rear++;
        queue[rear] = data;
        // Bs jg kita buat queue[++rear] = data;
    }
}


// Fungsi untuk menghapus (remove) data dr queue.
void deQueue()
{
    if(isEmpty()) {
        printf("\nQueue kosong !");
    }
    else {
        printf("\nItem yang dihapus : %d", queue[front]);
        front++;
        // Bs jg kita buat printf("\nItem yang dihapus : %d", queue[front++]);

        // Klo pointer front sudah melewati pointer rear, itu menandakan queue sudah dihapus sampai kosong, maka pointer front dan rear kembali bernilai -1 untuk menandakan queue sedang kosong.
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
    }
    else {
        printf("\nIsi queue :");
        for(int i = front; i <= rear; i++) {
            printf(" %d", queue[i]);
        }
    }
}


// Blh jg buatnya :
// void cetak()
// {
//     if(isEmpty()) {
//         printf("\nQueue kosong !");
//         return;
//     }

//     printf("\nIsi queue :");
//     for(int i = front; i <= rear; i++) {
//         printf(" %d", queue[i]);
//     }
// }





int main()
{
    enQueue(7);
    enQueue(8);
    enQueue(99);
    enQueue(-12);
    enQueue(23);

    // printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    // cetak();
    // printf("\n\n");



    // deQueue();
    // deQueue();
    // enQueue(27);
    // printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    // printf("\n\n");



    // while(!isEmpty()) {
    //     deQueue();
    // }
    // printf("\n\nApakah queue penuh ? %s", isFull() ? "Ya, queue penuh." : "Tidak, queue tidak penuh.");
    // printf("\n\n");

    return 0;
}









/*
Operasi utama pd Linear Queue adlh :
enqueue / add / insert
dequeue / remove

operasi tambahan pd Linear Queue :
isEmpty
isFull

Pd Queue, digunakan pointer front dan rear yg bernilai -1 ketika queue sedang kosong.
Di Linear / Simple Queue, pointer front berguna untuk menghapus data dan pointer rear berguna untuk menambah data.

Di Linear Queue dpt terjadi overflow krn tdk dpt menambahkan data baru walaupun ada ruang yg tersedia krn penambahan data hanya dpt dilakukan oleh pointer rear.
Cnthnya jika kita punya queue dgn ukuran 5, lalu kita tambahkan 5 data ke dlm queue trsbt, lalu kita hapus 2 data sehingga kondisi slot queue nya adlh 2 slot kosong dan 3 slot berisi, dan ketika kita ingin menambahkan 2 data lg, ini tdk bs dilakukan krn pointer rear sudah berada di ujung queue (tdk bs melakukan proses enqueue krn pointer rear sudah berada di ujung queue dan dikira queue sudah penuh). Permasalahan ini diatasi dengan menggunakan circular queue.
*/