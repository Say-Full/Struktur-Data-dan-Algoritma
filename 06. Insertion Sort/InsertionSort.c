#include<stdio.h>
#include<time.h>

void insertionSort(int data[], int ukuran)
{
    for(int i = 1; i < ukuran; i++) {
        int nilai = data[i];
        int j = i - 1;

        while(nilai < data[j] && j >= 0) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = nilai;

        printf("\nLangkah %d : ", i);
        for(int langkah = 0; langkah < ukuran; langkah++) {
            printf("%d ", data[langkah]);
        }
    }
}

int main()
{
    int data[] = {23, 20, 45, 20, -12, 39};
    int ukuran = sizeof(data) / sizeof(data[0]);

    printf("\nInsertion Sort\nData sebelum diurutkan : ");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Menghitung interval waktu
    clock_t waktu;
    waktu = clock();
    insertionSort(data, ukuran);
    waktu = clock() - waktu;

    printf("\n\nDurasi proses pengurutan : %ld ms\n\n", waktu);

    return 0;
}