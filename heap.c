#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30
/*struct fnode{
    struct fnode *left, *right;
    int id;
};
typedef struct fnode node;

typedef struct troot{
    node *first;
}root;

node *newNode(int id){
    node *new;
    new = (node *)malloc(sizeof(node));
    new->id = id;
    new->left = NULL;
    new->right = NULL;
    return new;
}

root startTree(root raiz, int id){
     raiz.first = newNode(id);
     return raiz;
}

root insert(root raiz,int id){
    node *aux = raiz.first; 
    node *prev = raiz.first; 

    if (raiz.first == NULL){
        raiz = startTree(raiz,id);
        return raiz;
    }
    while (aux != NULL){
        prev = aux;
        aux = aux->left;
    }
    aux = newNode(id);
    prev->left = aux;
    return raiz;
}

void printRoot(root raiz){
    node *aux = raiz.first;
    while (aux != NULL){
        printf("%d ",aux->id);
        aux = aux->left;
    }
}*/
int *createVet(int len){
    srand(time(NULL));
    int *newVet;
    newVet = (int *)malloc(len * sizeof(int));
    for (int i=0;i<len;i++){
        newVet[i] = rand() % MAX;
    }
    return newVet;
}

void printVet(int *vet, int len){
    for (int i=0;i<len;i++){
        printf("%d\n",vet[i]);
    }
}

int pai(int i){
    return (i-1)/2;
}

int filhoLeft(int i){
    return (2 * i)+1;
}

int filhoRight(int i){
    return (2*i)+2;
}

int * heapSort(int *vet, int len){
    int *vetAux;
    vetAux = (int *)malloc(len * sizeof(int));
    for (int i=0;i<len;i++){
        vetAux[i] = vet[i];
        int j = i;
        while(vetAux[pai(j)] < vetAux[j]){
            int aux = vetAux[j];
            vetAux[j] = vetAux[pai(j)];
            vetAux[pai(j)] = aux;
            j = pai(j);
        }
    }
    return vetAux;
}


int main(){
    int len,*vet,id;
    scanf("%d",&len);
    vet = createVet(len);
    clock_t start = clock(), end;
    vet = heapSort(vet,len);
    printVet(vet,len);
    end = clock();
    double final = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%.8lf segundos\n", final);
    // root raiz;
    // raiz.first = NULL;
    // raiz = insert(raiz,4);
    // raiz = insert(raiz,7);
    // raiz = insert(raiz,49);
    // printRoot(raiz);
    return 0;
}