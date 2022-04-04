#include<stdio.h>
#define UKURAN 10

int array[UKURAN];
int array[UKURAN] = { [0 ... UKURAN - 1] = -1};

// Fungsi hash
int hashing(int key)
{
    return (key % UKURAN);
}

void masukkan_data(int data)
{
    // key = indeks atw posisi tmpt data (bisa jadi angka atau karakter atau string atau lainnya) ini akan ditempatkan
    int key = hashing(data);

    if(array[key] == -1) {
        // Klo indeks tmpt mw kita taruh data ini msh kosong, maka simpan data ini di indeks trsbt
        array[key] = data;
        printf("\n%d disimpan di indeks %d\n", data, key);
    }
    else {
        printf("\nGagal memasukkan data %d karena terjadi bentrokan (collision)!\nIndeks %d sudah diisi dengan data %d\n", data, key, array[key]);
    }
}

void hapus_data(int data)
{
    int key = hashing(data);

    if(array[key] == data) {
        array[key] = -1;
        printf("\nBerhasil menghapus data %d yang disimpan di indeks %d\n", data, key);
    }
    else {
        printf("\n%d tidak ditemukan!\n", data);
    }
}

void cari_data(int data)
{
    int key = hashing(data);

    if(array[key] == data) {
        printf("\n%d ditemukan di indeks %d\n", data, key);
    }
    else {
        printf("\n%d tidak ditemukan!\n", data);
    }
}

int main()
{
    // Menginisialisasi nilai awal setiap indeks dlm array
    // for(int i = 0; i < UKURAN; i++) {
    //     array[i] = -1;
    // }

    printf("\n\nProses memasukkan data ke dalam struktur data hash :\n");
    int data[] = {4, 13, 7, 3, 7, 8};
    for(int i = 0; i < (sizeof(data)/sizeof(data[0])); i++) {
        masukkan_data(data[i]);
    }

    printf("\n\n\t-------------------\n\nContoh penghapusan data dari struktur data hash :\n");
    hapus_data(4);

    printf("\n\n\t-------------------\n\nContoh pencarian data dalam struktur data hash :\n");
    cari_data(4);
    cari_data(13);
    cari_data(3);
    cari_data(7);

}

/*
Teknik hashing dengan menggunakan fungsi (data % ukuran) tanpa mengatasi masalah duplikasi data dan collision (chaining, linear probing, quadratic probing, dll.).
*/