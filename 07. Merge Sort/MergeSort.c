#include<stdio.h>
#include<time.h>

void merge(int data[], int kiri, int tengah, int kanan)
{
    // Array kiri
    int ukuranKiri = tengah - kiri + 1;
    int dataKiri[ukuranKiri];

    // Array kanan
    int ukuranKanan = kanan - tengah;
    int dataKanan[ukuranKanan];

    int i = 0, j = 0, k = kiri;

    // Mengisi data ke dalam array kiri
    for(int indeks = 0; indeks < ukuranKiri; indeks++) {
        dataKiri[indeks] = data[kiri + indeks];
    }

    // Mengisi data ke dalam array kanan
    for(int indeks = 0; indeks < ukuranKanan; indeks++) {
        dataKanan[indeks] = data[tengah + 1 + indeks];
    }

    // Menggabungkan array kiri dan array kanan ke dalam
    // array hasil (array data) dengan cara menyalin
    // elemen data yang nilainya lebih kecil di antara
    // setiap elemen dalam array kiri dan array kanan
    // hingga salah satu antara array kiri atau array kanan
    // elemennya sudah habis disalin
    while(i < ukuranKiri && j < ukuranKanan) {
        if(dataKiri[i] <= dataKanan[j]) {
            data[k] = dataKiri[i];
            i++;
        }
        else {
            data[k] = dataKanan[j];
            j++;
        }

        k++;
    }

    // Sisa elemen yang ada di dalam array kiri disalin
    // ke dalam array hasil (array data)
    while(i < ukuranKiri) {
        data[k] = dataKiri[i];
        i++;
        k++;
    }

    // Sisa elemen yang ada di dalam array kanan disalin
    // ke dalam array hasil (array data)
    while(j < ukuranKanan) {
        data[k] = dataKanan[j];
        j++;
        k++;
    }
}

void mergeSort(int data[], int kiri, int kanan)
{
    if(kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        mergeSort(data, kiri, tengah);
        mergeSort(data, tengah + 1, kanan);
        merge(data, kiri, tengah, kanan);
    }
}

int main()
{
    int data[] = {23, 20, 45, 20, -12, 39};
    int ukuran = sizeof(data)/sizeof(data[0]);

    printf("\nMerge Sort\nData sebelum diurutkan : ");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Menghitung interval waktu
    clock_t waktu;
    waktu = clock();
    mergeSort(data, 0, ukuran - 1);
    waktu = clock() - waktu;

    printf("\nData sebelum diurutkan : ");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", data[i]);
    }

    printf("\n\nDurasi proses pengurutan : %ld ms\n\n", waktu);

    return 0;
}