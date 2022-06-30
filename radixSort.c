#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30

int *createRandomArray(int len){
    int *vet;
    vet = (int *)malloc(len*sizeof(int));
    srand(time(NULL));
    for (int i=0; i<len; i++){
        vet[i] = rand()%MAX;
    }
    return vet;
}

void printArray(int *vet, int len){
    for (int i=0; i<len; i++){
        printf("%d ",vet[i]);
    }
}
int maxNumber(int *vet, int len){
    int max=vet[0];
    for (int i=0;i<len;i++){
        if (vet[i] > max) max = vet[i];
    }
    return max;
}
int numberOfDigits(int max){
    int number=0;
    while(max != 0){
        max = max / 10;
        number++;
    }
    return number;
}

void *countingSort(int *vet, int len, int pos){
    int number = 10;//numberOfDigits(maxNumber(vet,len));
    int *aux = (int *)malloc(len*sizeof(int));
    int *count = (int *)calloc(number, sizeof(int));
    for (int i=0; i<len; i++){
        count[(vet[i]/pos) %number]++;
    }
    for (int i=0;i<number;i++){
        count[i] = count[i] + count[i-1];
    }
    for (int i= len-1; i>=0; i--){
        count[(vet[i]/pos) %number]--;
        aux[count[(vet[i]/pos) %number]] = vet[i];
    }
    for (int i= 0; i<len; i++){
        vet[i] = aux[i];
    }
}

void *radixSort(int *vet, int len){
    clock_t start, end;
    double final;
    start = clock();
    int max = maxNumber(vet,len);
    for (int pos = 1; (max/pos) > 0;pos*=10){
        countingSort(vet,len,pos);
    }
    end = clock();
    final = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%.7lf segundos \n", final);
}

int main(){
    int *vet, len;
    scanf("%d",&len);
    vet =createRandomArray(len);
    printf("\n");
    radixSort(vet,len);
    return 0;
}