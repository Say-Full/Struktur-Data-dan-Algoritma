#include <stdio.h>
#include<time.h>

void shellSort(int data[], int ukuran)
{
    for(int gap = ukuran / 2; gap > 0; gap /=2) {
        // Lakuin Insertion Sort
        for(int i = gap; i < ukuran; i++) {
            int nilai = data[i];
            int j;
            
            for(j = i; j >= gap && data[j - gap] > nilai; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = nilai;
        }
    }
}

int main()
{
    int data[] = {23, 20, 45, 20, -12, 39};
    int ukuran = sizeof(data) / sizeof(data[0]);

    // Menghitung interval waktu
    clock_t waktu;
    waktu = clock();
    shellSort(data, ukuran);
    waktu = clock() - waktu;
    printf("\n\nDurasi proses pengurutan : %ld ms\n\n", waktu);

    return 0;
}