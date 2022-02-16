#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partisi(int data[], int kiri, int kanan)
{
    int pivot = data[kanan];
    int i = kiri - 1;

    for(int j = kiri; j < kanan; j++) {
        if(data[j] <= pivot) {
            i++;
            swap(&data[i], &data[j]);
        }
    }

    swap(&data[i + 1], &data[kanan]);

    return i + 1;
}

void quickSort(int data[], int kiri, int kanan)
{
    if(kiri < kanan) {
        int bagian = partisi(data, kiri, kanan);

        quickSort(data, kiri, bagian - 1);
        quickSort(data, bagian + 1, kanan);
    }
}

int main()
{
    int data[] = {23, 20, 45, 20, -12, 39};
    int ukuran = sizeof(data) / sizeof(data[0]);

    printf("\nQuick Sort\nData sebelum diurutkan : ");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Menghitung interval waktu
    clock_t waktu;
    waktu = clock();
    quickSort(data, 0, ukuran - 1);
    waktu = clock() - waktu;

    printf("\n\nDurasi proses pengurutan : %ld ms\n\n", waktu);

    return 0;
}