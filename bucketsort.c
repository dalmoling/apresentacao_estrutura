#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    // Define o número de baldes
    const int num_buckets = 10;

    // Cria os baldes
    int buckets[num_buckets][n];

    // Inicializa os contadores de cada balde para zero
    int bucket_counters[num_buckets] = {0};

    // Calcula o valor máximo do array
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calcula o tamanho de cada balde
    double range = (double) (max_val + 1) / num_buckets;

    // Coloca os valores no balde correspondente
    for (int i = 0; i < n; i++) {
        int bucket_idx = (int) (arr[i] / range);
        buckets[bucket_idx][bucket_counters[bucket_idx]] = arr[i];
        bucket_counters[bucket_idx]++;
    }

    // Ordena cada balde individualmente
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_counters[i]; j++) {
            int temp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > temp) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = temp;
        }
    }

    // Combina os baldes ordenados em um único array
    int idx = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_counters[i]; j++) {
            arr[idx] = buckets[i][j];
            idx++;
        }
    }
}

int main() {
    int arr[] = {3, 8, 2, 1, 5, 6, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nArray ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
