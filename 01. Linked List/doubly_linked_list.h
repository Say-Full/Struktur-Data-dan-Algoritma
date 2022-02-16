#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Di Doubly linked list, tiap node memiliki pointer yg menunjuk ke node setelahnya (pointer next) dan pointer yg menunjuk ke node sblmnya (pointer prev).
struct node {
    int data;
    int key;
    struct node *next;
    struct node *prev;
};

// Pointer head selalu menunjuk ke node paling kiri.
struct node *head = NULL;

// Pointer last selalu menunjuk ke node paling kanan.
struct node *last = NULL;



bool isEmpty()
{
    return head == NULL;
}


int panjang()
{
    int panjang = 0;
    struct node *current;
        
    for(current = head; current != NULL; current = current->next) {
        panjang++;
    }
        
    return panjang;
}


// Mencetak linked list dari kiri ke kanan.
// Traversing dimulai dr pointer head (paling kiri) dan terus lanjut ke node setelahnya (lanjut ke kanan).
void cetakMaju()
{
    struct node *ptr = head;

    printf("\n\nBentuk Linked List dari kiri ke kanan :\n(head), NULL ");
    while(ptr != NULL) {
        printf("[%d, %d] ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
        
    printf("NULL");
}


// Mencetak linked list dari kanan ke kiri.
// Traversing dimulai dr pointer last (paling kanan) dan terus lanjut ke node sebelumnya (lanjut ke kiri).
void cetakMundur()
{
    struct node *ptr = last;

    printf("\n\nBentuk Linked List dari kanan ke kiri :\nNULL ");
    while(ptr != NULL) {
        printf("[%d, %d] ", ptr->key, ptr->data);
        ptr = ptr->prev;
    }
        
    printf("(head), NULL");
}


// Menambahkan node dari kiri / depan pada linked list.
// Penambahan node dilakukan dgn memanfaatkan pointer head.
void tambahNodeDariKiri(int key, int data)
{
    struct node *nodeBaru = (struct node *) malloc(sizeof(struct node));
    
    nodeBaru->key = key;
    nodeBaru->data = data;

    // Klo linked list msh kosong, maka node yg ingin ditambah akan menjadi node paling kiri dan node pointer last bernilai node terbaru trsbt.
    // Klo linked list tdk kosong, maka pointer prev pd head menunjuk node terbaru itu.
    if(isEmpty()) {
        last = nodeBaru;
    }
    else {
        head->prev = nodeBaru;
    }
        
    // Node baru menunjuk ke node yg sedang ditunjuk oleh head.
    nodeBaru->next = head;
        
    // Head menunjuk ke node baru agar node terbaru menjadi node paling kiri pada linked list.
    head = nodeBaru;
}


// Menambahkan node dari kanan / belakang pada linked list.
// Penambahan node dilakukan dgn memanfaatkan pointer last.
void tambahNodeDariKanan(int key, int data)
{
    struct node *nodeBaru = (struct node *) malloc(sizeof(struct node));
    
    nodeBaru->key = key;
    nodeBaru->data = data;

    // Klo linked list msh kosong, maka node yg ingin ditambah akan menjadi node paling kiri dan node pointer last bernilai node terbaru trsbt.
    // Klo linked list tdk kosong, maka pointer next pd last menunjuk node terbaru itu dan pointer prev pd node terbaru menunjuk node last agar node yg sedang ditunjuk oleh pointer prev di node last disalin ke pointer prev di node terbaru.
    if(isEmpty()) {
        last = nodeBaru;
    }
    else {
        last->next = nodeBaru;
        nodeBaru->prev = last;
    }
        
    // last menunjuk ke node baru agar node terbaru menjadi node paling kanan pada linked list.
    last = nodeBaru;
}


// Menambahkan node baru setelah suatu node berdasarkan suatu key.
// Fungsi ini mengembalikan nilai boolean krn bs aja operasi pd fungsi ini gagal krn key yg dicari tdk ditemukan.
bool tambahSetelah(int key, int newKey, int data)
{
    // Node current digunakan untuk menjelajahi / mencari node mana yg sesuai dgn key yg diminta. Node current memulia pencarian dari kiri dgn memanfaatkan head.
    struct node *current = head;

    if(isEmpty()) {
        return false;
    }

    while(current->key != key) {
        if(current->next == NULL) {
            return false;
        }
        else {
            current = current->next;
        }
    }

    struct node *nodeBaru = (struct node *) malloc(sizeof(struct node));
    
    nodeBaru->key = newKey;
    nodeBaru->data = data;

    // Klo node yg dicari adlh node paling kanan dan ingin menambahkan node baru setelah node paling kanan ini, maka pointer next pd node terbaru menunjuk ke NULL dan node last menunjuk ke node terbaru agar node terbaru ini menjadi node yg paling kanan.
    // Klo node yg dicari bkn node yg paling kanan dan ingin menambahkan node baru setelah node ini, maka pointer next pd node terbaru menunjuk ke node yg sedang ditunjuk oleh node ini dan pointer prev pd node setelah node ini menunjuk ke node terbaru.
    if(current == last) {
        nodeBaru->next = NULL;
        last = nodeBaru;
    }
    else {
        nodeBaru->next = current->next;
        current->next->prev = nodeBaru;
    }

    // Pointer prev pd node terbaru menunjuk ke node skrng.
    nodeBaru->prev = current;

    // Pointer next pd node skrng menunjuk ke node terbaru.
    current->next = nodeBaru;
    
    return true;
}


// Menghapus node terbaru / paling kiri dgn memanfaatkan pointer head.
// Sebelum hapus, cek dlu apakah linked list nya kosong atw tdk. Klo kosong berarti gk ada node yg bs dihapus. Klo gk kosong baru bs lanjut proses.
struct node * hapusNodeTerbaru()
{
    // Cek apakah pointer next pada node head menunjuk ke NULL yg berarti linked list nya kosong.
    if(head->next == NULL) {
        printf("\n\nMaaf, tidak bisa melakukan proses penghapusan karena linked list kosong !");
        return NULL;
    }

    struct node *tempLink = head;
    
    // Pointer prev pd node setelah node yg ingin dihapus (node kedua paling kiri) menunjuk ke NULL.
    head->next->prev = NULL;

    // Node head bernilai node setelah node yg ingin dihapus (node kedua paling kiri).
    head = head->next;
        
    // Mengembalikan node yang telah dihapus.
    return tempLink;
}


// Menghapus node terlama / paling kanan dgn memanfaatkan pointer last.
// Sebelum hapus, cek dlu apakah linked list nya kosong atw tdk. Klo kosong berarti gk ada node yg bs dihapus. Klo gk kosong baru bs lanjut proses.
struct node * hapusNodeTerlama()
{
    // Cek apakah pointer next pada node head menunjuk ke NULL yg berarti linked list nya kosong.
    if(head->next == NULL) {
        printf("\n\nMaaf, tidak bisa melakukan proses penghapusan karena linked list kosong !");
        return NULL;
    }

    struct node *tempLink = last;
    
    // Pointer next pd node sebelum node yg ingin dihapus (node kedua paling kanan) menunjuk ke NULL.
    last->prev->next = NULL;

    // Node last bernilai node sebelum node yg ingin dihapus (node kedua paling kanan).
    last = last->prev;
    
    // Mengembalikan node yang telah dihapus.
    return tempLink;
}


// Hapus suatu node berdasarkan key.
// Sebelum hapus, cek dlu apakah linked list nya kosong atw tdk. Klo kosong berarti gk ada node yg bs dihapus. Klo gk kosong baru bs lanjut proses.
// Untuk menghapus suatu node, kita hrs cari dlu node yg ingin dihapus. Proses pencariannya ini agak sedikit berbeda dari proses pencarian di fungsi cari.
struct node * hapus(int key)
{
    if(isEmpty()) {
        printf("\n\nMaaf, tidak bisa melakukan proses penghapusan karena linked list kosong !");
        return NULL;
    }

    struct node *current = head;

    // Node previous yg akan menjadi node yg ingin dihapus.
    struct node *previous = NULL;
        
    if(isEmpty()) {
        return NULL;
    }

    while(current->key != key) {
        // Klo gk ada node lg setelahnya, maka pencarian berakhir (lngsng return untuk mengakhiri).
        if(current->next == NULL) {
            return NULL;
        }
        else {
            // Previous menyimpan nilai elemen-elemen struct node pada node current skrng.
            previous = current;
            // Current menunjuk ke node selanjutnya untuk melanjutkan pencarian.
            current = current->next;
        }
    }

    // Klo node yg ingin dihapus adlh node yg sedang ditunjuk oleh pointer head, maka penghapusannya cukup dgn cara pointer head menunjuk ke node setelah node yg ingin dihapus.
    // Klo node yg ingin dihapus bkn node yg sedang ditunjuk oleh pointer head, maka node sblm current (node sblm node yg ingin dihapus) menunjuk ke node setelah current (node setelah node yg ingin dihapus).
    if(current == head) {
        head = head->next;
    }
    else {
        current->prev->next = current->next;
    }   

    // Klo node yg ingin dihapus adlh node terakhir (node paling kanan), maka pointer last menunjuk ke node sebelum node yg ingin dihapus (node kedua paling kanan).
    // Klo node yg ingin dihapus bkn node yg terakhir (node paling kanan), maka pointer prev pada node setelah node yg ingin dihapus menunjuk ke node sebelum node yg ingin dihapus.
    if(current == last) {
        last = current->prev;
    }
    else {
        current->next->prev = current->prev;
    }    
        
    // Kembalikan node yg dihapus, yaitu node yg sedang dipegang oleh current.
    return current;
}









/*
Bedanya klo di doubly linked list ni setiap node punya pointer prev yg berguna untuk mengakses node sebelumnya. Jd kita bs buat node pointer last yg berguna untuk menunjuk node paling kanan dr linked list dan dr node pointer last ini kita bs traverse dari node yg paling kanan ke node yg paling kiri.
*/