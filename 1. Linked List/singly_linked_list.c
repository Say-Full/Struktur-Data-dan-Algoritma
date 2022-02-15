#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Digunakan key pada setiap node untuk mempermudah penghapusan krn key ini digunakan sbg identifier / pengenal setiap node.
struct node {
    int data;
    int key;
    struct node *next;
};

// Pointer head yg bertipe struct node ini sbnrnya hanya menggunakan elemen next dari struct node tanpa membutuhkan elemen data dan key krn tujuan pointer head ini hanya menunjuk node paling kiri (hanya menyimpan alamat memori dari node yg sedang ditunjuk, yaitu node paling kiri) pd linked list.
struct node *head = NULL;



// Memeriksa apakah linked list kosong.
// Jika kosong akan mengembalikan true. Kita bs gunakan boolean krn dh masukin library stdbool.h
bool isEmpty()
{
    return head == NULL;
}


// Krn library stdbool.h sbnrnya hanya dipkk untuk fungsi ini saja dan fungsi ini bs jg kita pkk return integer dmn 0 berarti false dan selain 0 (seperti 1) berarti true, jd bs kita buat :
// int isEmpty()
// {
//     return head == NULL;
// }


// Menghitung panjang / bnyk node di linked list.
int panjang()
{
    int panjang = 0;

    // Membuat node baru yg berguna sbg pointer untuk menjelajahi setiap node yg ada.
    // Jd current ini bermula menunjuk node yg sedang ditunjuk oleh head (di ekspresi pertama pada parameter for) dgn cara mengisi nilai current dgn nilai yg ada di pointer head, yaitu current = head. Cara pengisian ini bs dilakukan krn MEREKA BERDUA TIPENYA SAMA, yaitu struct node * dan pada kasus ini, current tdk membutuhkan nilai elemen data dan key dari struct node, melainkan yg dibutuhkan hanya elemen next yg berguna untuk menunjuk ke node-node.
    struct node *current;
        
    for(current = head; current != NULL; current = current->next) {
        panjang++;
    }
        
    return panjang;
}


// Menampilkan linked list.
void cetak()
{
    struct node *ptr = head;

    printf("\n\nBentuk Linked List sekarang :\n(head)");
    while(ptr != NULL) {
        printf(" -> [%d, %d]", ptr->key, ptr->data);
        ptr = ptr->next;
    }
        
    printf(" -> NULL");
}


// Menambahkan node pada linked list.
void tambahNode(int key, int data)
{
    // Membuat node baru
    struct node *nodeBaru = (struct node *) malloc(sizeof(struct node));
    
    // Mengisi elemen pada node tersebut.
    nodeBaru->key = key;
    nodeBaru->data = data;
        
    // Node baru menunjuk ke node yg sedang ditunjuk oleh head.
    nodeBaru->next = head;
        
    // Head menunjuk ke node baru agar node terbaru menjadi node paling kiri pada linked list.
    head = nodeBaru;
}


// Memutarbalikkan urutan (reverse) linked list. Jd, pointer head nanti akan menunjuk node terbaru pd linked list yg dh diubah urutannya.
void balikkan()
{
    struct node *current = head;
    struct node *previous = NULL;
    struct node *next;
    
    while(current != NULL) {
        next = current->next;
        current->next = previous;   
        previous = current;
        current = next;
    }
        
    head = previous;
}


// Mengurutkan (sort) linked list berdasarkan nilai elemen data terkecil ke nilai elemen data terbesar dr setiap node.
void urutkan()
{
    struct node *current;
    struct node *next;
    int i, j, tempKey, tempData;
    int ukuran = panjang();
    int k = ukuran ;
        
    for(i = 0; i < ukuran - 1; i++, k--) {
        current = head;
        next = head->next;
            
        for (j = 1; j < k; j++) {
            // Jika nilai elemen data node skrng lbh besar dr pd nilai elemen data pd node selanjutnya, maka tukar nilai elemen data dan nilai elemen key pd 2 node trsbt tp jgn tukar isi elemen next.
            if(current->data > next->data) {
                // Swap (tukar) nilai elemen data.
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                // Swap (tukar) nilai elemen key.
                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            
            // Lanjutkan pemeriksaan dgn cara node current dan node next menunjuk node setelahnya.
            current = current->next;
            next = next->next;
        }
    }   
}


// Mencari suatu node berdasarkan key / kunci yg diberikan
struct node * cari(int key)
{
    // Current digunakan untuk menjelajahi setiap node yg ada di linked list dan jika ditemukan node yg dicari, maka current akan menyimpan data yg disimpan oleh node trsbt, yaitu elemen data, key, dan pointer next. Jadi, awalnya current hanya sekedar pointer krn menyimpan data elemen-elemen yg ada di pointer head, yaitu nilai elemen data pd pointer head yg nilainya tdk prnh diisi, nilai elemen key pd pointer head yg nilainya tdk prnh diisi, dan nilai elemen next pd pointer head yg berisi alamat memori node paling kiri. Jika ditemukan node yg dicari, current akan menyimpan data yg ada dlm node yg dicari trsbt.
    struct node *current = head;

    // Klo linked list nya kosong / gk ada node yg terdaftar di linked list, maka gausah lakukan pencarian.
    if(isEmpty()) {
        return NULL;
    }

    // Menjelajahi setiap node untuk mencari node mana yg memiliki key yg sama dgn key yg dicari.
    // Pencarian berlangsung hingga nilai elemen key pada struct node current sama dgn key yg dicari atw current menunjuk ke NULL yg berarti gk ada node lg setelah current.
    while(current->key != key) {
        // Klo gk ada node lg setelahnya, maka pencarian berakhir (lngsng return untuk mengakhiri).
        if(current->next == NULL) {
            return NULL;
        }
        else {
            // Lanjutkan pencarian dgn cara current menunjuk ke node setelahnya.
            current = current->next;
        }
    }      
        
    // Jika key yg dicari ditemukan pd suatu node / link, maka kembalikan node / link trsbt.
    return current;
}


// Menghapus node terbaru / paling kiri.
// Sebelum hapus, cek dlu apakah linked list nya kosong atw tdk. Klo kosong berarti gk ada node yg bs dihapus. Klo gk kosong baru bs lanjut proses.
// Fungsi ini mengembalikan data yg bertipe struct node *, yaitu node yg dihapus.
struct node * hapusNodeTerbaru()
{
    // Klo linked list kosong, maka diberi pemberitahuan.
    if(isEmpty()) {
        printf("\n\nMaaf, tidak bisa melakukan proses penghapusan karena linked list kosong !");
        return NULL;
    }

    // Menyimpan node yg ingin dihapus.
    struct node *tempLink = head;
    
    // Nilai pointer head diisi dgn nilai pd pointer yg ingin dihapus.
    // Tujuannya agar head menunjuk node yg sedang ditunjuk oleh node yg ingin dihapus.
    head = head->next;
        
    // Mengembalikan node yang telah dihapus / dilupakan (remember me to forget).
    return tempLink;
}


// Hapus suatu node berdasarkan key.
// Sebelum hapus, cek dlu apakah linked list nya kosong atw tdk. Klo kosong berarti gk ada node yg bs dihapus. Klo gk kosong baru bs lanjut proses.
// Untuk menghapus suatu node, kita hrs cari dlu node yg ingin dihapus. Proses pencariannya ini agak sedikit berbeda dari proses pencarian di fungsi cari.
struct node * hapus(int key)
{
    // Klo linked list kosong, maka diberi pemberitahuan.
    if(isEmpty()) {
        printf("Maaf, tidak bisa melakukan proses penghapusan karena linked list kosong !");
        return NULL;
    }

    // Membuat 2 node baru yg berguna untuk menjelajahi setiap node yg ada.
    struct node *current = head;

    // Node previous yg akan menjadi node yg ingin dihapus.
    struct node *previous = NULL;
        
    // Klo linked list nya kosong, lngsng berhenti.

    // Menjelajahi setiap node untuk mencari node mana yg memiliki key yg sama dgn key yg dicari.
    // Pencarian berlangsung hingga nilai elemen key pada struct node current sama dgn key yg dicari atw current menunjuk ke NULL yg berarti gk ada node lg setelah current.
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
    // Klo node yg ingin dihapus bkn node yg sedang ditunjuk oleh pointer head, maka previous menunjuk ke node setelah node yg ingin dihapus. Krn node yg ingin dihapus skrng sedang dipegang oleh current dan current menunjuk ke pointer setelahnya, maka pointer previous menunjuk ke pointer yg sedang ditunjuk oleh pointer current.
    if(current == head) {
        head = head->next;
    }
    else {
        previous->next = current->next;
    }    
        
    // Kembalikan node yg dihapus, yaitu node yg sedang dipegang oleh current.
    return current;
}





int main()
{
    // cetak();



    tambahNode(1, 8);
    tambahNode(2, 77);
    tambahNode(3, 23);
    tambahNode(4, -17);
    tambahNode(5, 9);
    // cetak();



    // balikkan();
    // cetak();



    // urutkan();
    // cetak();



    // struct node *cariNode = cari(2);
    // if(cariNode == NULL) {
    //     printf("\n\nNode tidak ditemukan !");
    // }
    // else {
    //     printf("\n\nNode [%d, %d] ditemukan !", cariNode->key, cariNode->data);
    // }



    // hapus(3);
    // cetak();



    // hapusNodeTerbaru();
    // cetak();



    // Menghapus semua node satu per satu hingga kosong
    while(!isEmpty()) {
        struct node *nodeDihapus = hapusNodeTerbaru();
        printf("\nNode yang dihapus : [%d, %d]", nodeDihapus->key, nodeDihapus->data);
    }
    cetak();
    


    printf("\n\n\n");

    return 0;
}










/*
Implementasi / kode program linked list bs bermcm-mcm dan bs dimodifikasi sesukanya yg penting kuat dasar pemahamannya dan ngerti apa yg dimodifikasi.
Cnthnya di modul prof TFA, untuk pointer head menggunakan struct khusus yg isinya adlh pointer untuk menunjuk ke node setelahnya dan jg berisi variabel untuk menghitung jmlh node pd linked list trsbt.

Penambahan dilakukan pd bagian depan (paling dekat dgn head / paling kiri).
Proses penambahan di linked list adlh node terbaru menunjuk ke node paling kiri, yaitu node yg sedang ditunjuk oleh pointer node head. Lalu head (pointer node head) menunjuk ke node terbaru.

Node pd linked list diurutkan berdasarkan urutan penambahan / pendaftaran node, bkn berdasarkan nilai data dr node yg diinput. Jd untuk pencariannnya digunakan linear search. Proses pencarian gk bs pkk Binary Search krn linked list gk punya indeks, untuk pemeriksaannya tetap hrs dimulai dr simpul / node head. Linked list jg gk bs dibagi 2 bagian kyk array. Jd, walaupun node pd linked list dh diurutkan berdasarkan nilai data pd tiap node, tetap aja gk bs pkk binary search.

Pada proses penghapusan, dicari dlu node yg ingin dihapus baru node tersebut dihapus. Jika kita ingin hapus node kedua paling kiri, maka node paling kiri menunjuk node yg ditunjuk oleh node kedua paling kiri, yaitu node ketiga paling kiri. Lalu node kedua paling kiri tdk menunjuk kemana-mana (isi nilai pointer di node kedua paling kiri dgn NULL).

Penambahan = O(1)
Pencarian = O(n)
Penghapusan = pencarian + hapus = O(n)

Operasi utama pd linked list adlh traverse, insertion, deletion, dan reverse.
*/