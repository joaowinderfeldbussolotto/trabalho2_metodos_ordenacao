#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#define MAX 1000
#define LEN 10000

double getTimeInSeconds(struct timeval start, struct timeval stop){
   return ((double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
}

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
        if(mode == 3){
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

void swap(int i, int j, int *v)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
// MERGE SORT IMPLEMENTATION 

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
    if (start < end){
        int mid = (start+end)/2;
        mergeSort(vet, start, mid);
        mergeSort(vet,mid+1,end);
        intercala(vet,start,mid,end);
    }
}

void mergeSortStart(int *vet, int len){
      struct timeval start, stop;
      gettimeofday(&start, NULL);
      mergeSort(vet, 0,len-1);
      gettimeofday(&stop, NULL);
      double time = getTimeInSeconds(start, stop);
      printf("%.8lf segundos\n", time);

}

int getMaxNumber(int *vet, int len){
  int max = 0;
  int i =0;
  for(; i < len; i++){
    if(vet[i] > vet[max]){
      max = i;
    }
  }
  return vet[max];
}

void countingSort2(int *vet, int len, int pos){
    int number = 10;
    int *aux = (int *)malloc(len*sizeof(int));
    int *count = (int *)calloc(number, sizeof(int));
    for (int i=0; i<len; i++){
        count[(vet[i]/pos) %number]++;
    }
    for (int i=1;i<number;i++){
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

void radixSort(int *vet, int len){
  struct timeval start, stop;
  gettimeofday(&start, NULL);
  int maxNumber = getMaxNumber(vet, len);
  int pos = 1;
  for(; maxNumber/pos > 0; pos *=10){
    countingSort2(vet,len, pos);
  }
  gettimeofday(&stop, NULL); 
  double time = getTimeInSeconds(start, stop);
    printf("%.8lf segundos\n", time);
}





void countingSort(int *vet, int len){
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
    gettimeofday(&stop, NULL);
    double time = getTimeInSeconds(start, stop);
    printf("%.8lf segundos\n", time);
}

// HEAP SORT IMPLEMENTATION 

void createHeap(int *vet, int i, int len){
  int max = i;

  int left = (2*i) +1;
  int right = (2*i) +2;

  if(left < len && vet[left] > vet[max]){
    max = left;
  }
  if(right < len && vet[right] > vet[max]){
    max = right;
  }

  if (max != i){
    swap(i, max,vet);
    createHeap(vet,max,len);
  }

}



void heapSort(int *vet, int len){
  struct timeval start, stop;
  gettimeofday(&start, NULL);
  int k  = (len/2) - 1;
  for(; k >=0; k--){
    createHeap(vet, k, len);
  }

  for (k = len-1; k > 0; k--){
    swap(0,k,vet);
    createHeap(vet, 0, k);
  }
  gettimeofday(&stop, NULL);
  double time = getTimeInSeconds(start, stop);
  printf("%.8lf segundos\n", time);
}

// QUICK SORT IMPLEMENTATION

int partition(int *v, int low, int high)
{
    int pivot_index = low + (rand() % (high - low));
    if(pivot_index != high){
      swap(pivot_index, high,v);
    }

    int i = low;
    for (int j = low; j < high; j++)
    {
        if (v[j] < v[high])
        {
      
            swap(i, j, v);
            i++;
        }
    }
    swap(i, high, v);
    return i;
}

void quickSort(int *v, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(v, low, high);
        quickSort(v, low, pivot_index - 1);
        quickSort(v, pivot_index + 1, high);
    }
}
void quickSortStart(int *v, int lenght)
{
    struct timeval start, stop;
    gettimeofday(&start, NULL);
    srand(time(NULL));
    quickSort(v, 0, lenght - 1);
    gettimeofday(&stop, NULL);
    printf("%.8lf segundos\n", getTimeInSeconds(start, stop));

    
}


void printInfo(int len, int mode){
  printf("Tamanho: %d\n", len);
  if(mode == 1){
    printf("Vetor crescente\n");
    return;
  } 
  if(mode == 2){
    printf("Vetor decrescente\n");
    return;
  }
  printf("Vetor aleatorio\n");
    
}






int main(int argc, char *argv[]){
    int *vet, len, mode;
    if (argc > 2)
    {
        char *charNum = argv[1];
        len = atoi(*(argv + 1));
        mode = atoi(*(argv + 2));
    }
    else
    {
        len = LEN;
        mode = 3;
    }

  
    vet = createArray(len, mode);
    printInfo(len, mode);
    //printArray(vet, len);
    //countingSort(vet, len);
    //mergeSortStart(vet, len);
    //radixSort(vet, len);
    //heapSort(vet, len);
    quickSortStart(vet, len);
    printf("-----------------ORDENADNO------\n"); printArray(vet, len);
    return 0;
}

