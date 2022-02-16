#include<stdio.h>

int binarySearch(int data[], int cari, int kiri, int kanan)
{
    while(kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if(data[tengah] == cari) {
            return tengah;
        }

        if(data[tengah] > cari) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }

    return -1;
}

int binarySearchRekursif(int data[], int cari, int kiri, int kanan)
{
    if(kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if(data[tengah] == cari) {
            return tengah;
        }

        if(data[tengah] > cari) {
            return binarySearchRekursif(data, cari, kiri, tengah - 1);
        }
        else {
            return binarySearchRekursif(data, cari, tengah + 1, kanan);
        }
    }

    return -1;
}

int main()
{
    int data[] = {0, 2, 5, 7, 9};
    int ukuran = sizeof(data) / sizeof(data[0]);
    int cari = 17;
    int hasil = binarySearchRekursif(data, cari, 0, ukuran - 1);

    if(hasil == -1) {
        printf("\nElemen tidak ditemukan !\n\n");
    }
    else {
        printf("\nElemen ditemukan di indeks : %d\n\n", hasil);
    }
}