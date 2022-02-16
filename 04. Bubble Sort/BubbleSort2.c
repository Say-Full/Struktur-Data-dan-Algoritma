#include<stdio.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int data[], int ukuran)
{
    for(int i = 0; i < ukuran - 1; i++) {
        int tukar = 0;

        for(int j = 0; j < ukuran - 1 - i; j++) {
            if(data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
                
                tukar = 1;
            }
        }

        if(tukar == 0) {
            break;
        }

        printf("\nLangkah %d : ", i+1);
        for(int langkah = 0; langkah < ukuran; langkah++) {
            printf("%d ", data[langkah]);
        }
    }
}

int main()
{
    int data[] = {23, 20, 45, 20, -12, 39};
    int ukuran = sizeof(data) / sizeof(data[0]);

    printf("\nBubble Sort (optimal)\nData sebelum diurutkan : ");
    for(int i = 0; i < ukuran; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Menghitung interval waktu
    clock_t waktu;
    waktu = clock();
    bubbleSort(data, ukuran);
    waktu = clock() - waktu;

    printf("\n\nDurasi proses pengurutan : %ld ms\n\n", waktu);

    return 0;
}