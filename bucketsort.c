#include <stdio.h>
#include <stdlib.h>

// Definindo o tamanho máximo do array
#define MAX 10
 
// Definindo o número de baldes
#define NUM_BUCKETS 10

// Definindo a estrutura do balde
struct Node {
    int value;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}
 
// Função para ordenar usando o Bucket Sort
void bucketSort(int array[], int n) {
    // Criando o array de baldes
    struct Node* buckets[NUM_BUCKETS];
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = NULL;
    }
    
    // Adicionando os valores nos baldes
    for (int i = 0; i < n; i++) {
        int index = NUM_BUCKETS * array[i] / (MAX + 1);
        struct Node* node = newNode(array[i]);
        if (buckets[index] == NULL) {
            buckets[index] = node;
        } else {
            struct Node* current = buckets[index];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    }
 
    // Ordenando os baldes
    for (int i = 0; i < NUM_BUCKETS; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
    }
}

// Função principal
int main() {
    int array[MAX] = {7, 10, 3, 8, 2, 6, 1, 5, 9, 4};
    printf("Array antes da ordenação:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\nArray depois da ordenação:\n");
    bucketSort(array, MAX);
    printf("\n");
    return 0;
}
