#include<stdio.h>

int linearSearch(int data[], int ukuran, int cari)
{
    for(int i = 0; i < ukuran; i++) {
        if(data[i] == cari) {
            return i;
        }
    }

    return -1;
}

int main()
{
    int data[] = {2, 4, 0, 1, 9};
    int ukuran = sizeof(data) / sizeof(data[0]);
    int cari = 10;
    int hasil = linearSearch(data, ukuran, cari);

    if(hasil == -1) {
        printf("\nElemen tidak ditemukan !\n\n");
    }
    else {
        printf("\nElemen ditemukan di indeks : %d\n\n", hasil);
    }
}