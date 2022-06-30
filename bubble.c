#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *V, int N){
    for (int i = N-1; i>0; i--){
        for (int j=0; j<i;j++){
            if (V[j] > V[j+1]){
                int aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;
            }
        }
    }
    for (int i = 0; i < N; i++) printf("%d ", V[i]);
}

int main(){
    int n, *vet;
    scanf("%d", &n);
    vet = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &vet[i]);
    bubbleSort(vet, n);
    return 0;
}