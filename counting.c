#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 9999

int *createArray(int len, int mode){
    //mode : 1:crescente, 2: decrescente, 3: aleatorio.
    int *vet;
    srand(time(NULL));
    vet = (int *)malloc(len* sizeof(int));
    for (int i=0;i<len;i++){
        if(mode == 1){
            vet[i] = i;
        }
        if(mode == 2){
            vet[i] = len - i;
        }
        else{
            vet[i] = rand() % MAX;
        }
    }
    return vet;
}

void printArray(int *vet, int len){
    for(int i=0;i<len;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}
double getTimeInSeconds(struct timeval start, struct timeval stop){
   return ((double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
}

void *countingSort(int *vet, int len){
    int *aux, max = 0;
    struct timeval start, stop;
    gettimeofday(&start, NULL);
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
    double time = getTimeInSeconds(start, stop);
    printf("%.8lf segundos\n", time);
}
int main(){
    int *vet, len;
    scanf("%d",&len);
    vet = createArray(len,3);
    countingSort(vet, len);
    return 0;
}