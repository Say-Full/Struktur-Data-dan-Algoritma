#include <stdio.h>
#define UKURAN 5

// Krn kita pkk stack dgn mengimplementasikan array, maka stack ini dpt diisi secara efisien dr indeks 0 hingga indeks UKURAN - 1, yaitu hingga indeks 7.
int stack[UKURAN];

// Pointer top bernilai -1 krn di bhs C indeks pd array dimulai dr indeks 0.
int top = -1;



int isEmpty()
{
    // Klo pointer top msh bernilai -1, berarti stack nya kosong.
    if(top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}


// Bs jd buat nya gini :
// int isEmpty()
// {
//     if(top == -1) {
//         return 1;
//     }
    
//     return 0;
// }


// Klo mw masukin library stdbool.h, fungsi isEmpty bs kita buat menjadi :
// bool isEmpty()
// {
//     return top == -1;
// }


int isFull()
{
    // Klo pointer top sedang bernilai / menunjuk slot stack paling atas, maka stack nya dh penuh.
    if(top == UKURAN - 1) {
        return 1;
    }
    else {
        return 0;   
    }
}


int peek()
{
    return stack[top];
}


void push(int data)
{
    if(isFull()) {
        printf("\n\nStack nya penuh woy !\n");
    }
    else {
        top++;
        stack[top] = data;
        // Blh kita buat stack[++top] = data;
    }
}


// Proses penghapusan stack yg mengimplementasikan array ni cuma geser pointer top ke bawah, lalu kita asumsikan bahwa slot yg di atas pointer top itu dh dihapus walaupun sbnrnya dlm memori komputer kita msh ada dan bs kita hard code untuk mengaksesnya.
int pop()
{ 
    if(isEmpty()) {
        printf("\n\nStack nya kosong bruh !\n");

        // Bs buat return '\0'; yg berarti NULL tp dlm tipe int untuk mengindikasikan bahwa fungsi ini tdk mengembalikan nilai yg ada dlm stack untuk menyatakan bahwa stack nya kosong.
        // Atw asumsikan -1 berarti data dlm stack tdk ditemukan.
        return -1;
    }
    else {
        int data = stack[top];
        top--;
        // Blh kita buat data = stack[top--];
        return data;
    }
}






int main()
{
    // printf("\n\nApakah stack kosong ? %s", isEmpty() ? "Ya, stack kosong." : "Tidak, stack tidak kosong.");
    // printf("\n\nApakah stack penuh ? %s", isFull() ? "Ya, stack penuh." : "Tidak, stack tidak penuh.");
    // printf("\n\n");





    // push(7);
    // push(8);
    // push(99);

    // printf("\n\nApakah stack kosong ? %s", isEmpty() ? "Ya, stack kosong." : "Tidak, stack tidak kosong.");
    // printf("\n\nApakah stack penuh ? %s", isFull() ? "Ya, stack penuh." : "Tidak, stack tidak penuh.");
    // printf("\n\n");





    // push(77);
    // push(-50);

    // printf("\n\nApakah stack kosong ? %s", isEmpty() ? "Ya, stack kosong." : "Tidak, stack tidak kosong.");
    // printf("\n\nApakah stack penuh ? %s", isFull() ? "Ya, stack penuh." : "Tidak, stack tidak penuh.");
    // printf("\n\nData teratas pada stack : %d", peek());
    // printf("\n\n");





    // printf("\n\nMenghapus data pada stack ! Data yg dihapus bernilai : %d", pop());
    // printf("\n\nData teratas pada stack : %d", peek());
    // printf("\n\n");





    // printf("\n\nMengosongkan stack !");
    // while(!isEmpty()) {
    //     pop();
    // }
    // printf("\n\nData teratas pada stack : %d", peek());
    // printf("\n\nApakah stack kosong ? %s", isEmpty() ? "Ya, stack kosong." : "Tidak, stack tidak kosong.");
    // printf("\n\nApakah stack penuh ? %s", isFull() ? "Ya, stack penuh." : "Tidak, stack tidak penuh.");
    // printf("\n\n");

    return 0;
}








/*
Stack bs menggunakan array atw linked list.
Klo pkk array, ukuran stack nya sebesar ukuran array yg didefinisikan. Klo pkk linked list, ukuran memorinya sampe memory heap pd perangkat trsbt gk tersisa lg untuk membuat node baru untuk linked list nya, biasa disebut overflown.
Untuk time complexity setiap operasi stack yg menggunakan array sama dgn stack yg menggunakan linked list.

Operasi-operasi pd stack :
- Push
- Pop
- Peek / get
- isEmpty
- isFull
*/
