#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int data[], int ukuran, int pivot)
{
    int terbesar = pivot;
    int nodeKiri = 2 * pivot + 1;
    int nodeKanan = 2 * pivot + 2;

    if(nodeKiri < ukuran && data[nodeKiri] > data[terbesar]) {
        terbesar = nodeKiri;
    }

    if(nodeKanan < ukuran && data[nodeKanan] > data[terbesar]) {
        terbesar = nodeKanan;
    }

    if(terbesar != pivot) {
        swap(&data[pivot], &data[terbesar]);
        heapify(data, ukuran, terbesar);
    }
}

void heapSort(int data[], int ukuran)
{
    for(int i = ukuran / 2 - 1; i >= 0; i--) {
        heapify(data, ukuran, i);
    }

    for(int i = ukuran - 1; i >= 0; i--) {
        swap(&data[0], &data[i]);
        heapify(data, i, 0);
    }
}

int main()
{
    int data[] = {23, 20, 45, 20, -12, 39};
    int ukuran = sizeof(data) / sizeof(data[0]);

    printf("\nMerge Sort\nData sebelum diurutkan : ");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Menghitung interval waktu
    clock_t waktu;
    waktu = clock();
    heapSort(data, ukuran);
    waktu = clock() - waktu;

    printf("\n\nDurasi proses pengurutan : %ld ms\n\n", waktu);

    return 0;
}