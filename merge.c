#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30

int *createVet(int len){
    int *vet;
    srand(time(NULL));
    vet = (int *)malloc(len * sizeof(int));
    for (int i=0;i<len;i++){
        *(vet + i) = rand()%MAX;
    }
    return vet;
}

void intercala(int *vet, int start, int mid , int end){
    int *aux,i = start, j = mid +1, k=0;
    aux = (int *)malloc((end-start+1) * sizeof(int));
    while (i<=mid && j<=end){
        if (vet[i] <= vet[j]){
            aux[k] = vet[i];
            i++;
        }
        else{
            aux[k] = vet[j];
            j++;
        }
        k++;
    }
    while (i<= mid){
        aux[k] = vet[i];
        k++;
        i++;
    }
    while (j <= end){
        aux[k] = vet[j];
        k++;
        j++;
    }
    for (k=start;k<=end;k++){
        vet[k] = aux[k-start];
    }
    free(aux);
}

void mergeSort(int *vet, int start, int end){
    clock_t Mstart, Mend;
    if (start < end){
        int mid = (start+end)/2;
        mergeSort(vet, start, mid);
        mergeSort(vet,mid+1,end);
        intercala(vet,start,mid,end);
    }
}

void printVet(int *vet, int len){
    for (int i=0;i<len;i++){
        printf("%d\n",*(vet+i));
    }
}

int main(){
    int *vet,len;
    scanf("%d",&len);
    vet = createVet(len);
    clock_t mStart = clock(), mEnd;
    mergeSort(vet, 0,len-1);
    mEnd = clock();
    double final = ((double)mEnd-mStart)/CLOCKS_PER_SEC;
    printf("%.8lf segundos",final);
    return 0;
}