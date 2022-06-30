#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 9999

int *createArray(int len){
    int *vet;
    srand(time(NULL));
    vet = (int *)malloc(len* sizeof(int));
    for (int i=0;i<len;i++){
        vet[i] = rand() % MAX;
    }
    return vet;
}

void printArray(int *vet, int len){
    for(int i=0;i<len;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

void *countingSort(int *vet, int len){
    int *aux, max = 0;
    clock_t cStart = clock(), cEnd;
    int i=0,j=0;
    for (;i<len;i++){
        if (vet[i] > max) max = vet[i];
    }
    aux = (int *)calloc(max+1, sizeof(int));
    
    for (i=0;i<len;i++){
        aux[vet[i]]++;
    }
    i =0;
    while(j<max+1){
        if (aux[j]!=0){
            vet[i] = j;
            i++;
            aux[j]--;
        }
        else{
            j++;
        }
    }
    cEnd = clock();
    double final = ((double)cEnd-cStart)/CLOCKS_PER_SEC;
    printf("%.8lf segundos\n", final);
}
int main(){
    int *vet, len;
    scanf("%d",&len);
    vet = createArray(len);
    countingSort(vet, len);
    return 0;
}