#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE_62   62500 
#define ARR_SIZE_125 125000
#define ARR_SIZE_250 250000
#define ARR_SIZE_375 375000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr + (i + 1), arr + high);
    return (i + 1);
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void selectionSort(int* arr, int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr + min_idx, arr + i);
    }
}

void randomFillArray(int* arr, int seed, int arr_size){
    srand(seed);
    for(int i = 0 ; i < arr_size; i++){
        arr[i] = rand() % 100;    
    }
}

double media(double* arr, int arr_size){
    double media = 0;
    if(arr != NULL && arr_size >= 0){
        for(int i = 0; i < arr_size; i++){
            media += arr[i];
        }
    }
    else{
        printf("ERRO");
        media = -1;
    }
    return media/arr_size;
}

int main(){

    clock_t inicio, fim;
    double tempo;

    double* tempos_quick_62 = malloc(sizeof(double)*50);

    double* tempos_quick_125 = malloc(sizeof(double)*50);

    double* tempos_quick_250 = malloc(sizeof(double)*50);

    double* tempos_quick_375 = malloc(sizeof(double)*50);

    double* tempos_selec_62 = malloc(sizeof(double)*50);

    double* tempos_selec_125 = malloc(sizeof(double)*50);

    double* tempos_selec_250 = malloc(sizeof(double)*50);

    double* tempos_selec_375 = malloc(sizeof(double)*50);


	
    //Bloco 62.500

    int* arrQuick = malloc(sizeof(int)*ARR_SIZE_62);

    int* arrSelec = malloc(sizeof(int)*ARR_SIZE_62);

    for(int i = 0; i < 50; i++){

        randomFillArray(arrQuick,i,ARR_SIZE_62);
        
        inicio = clock();
        quickSort(arrQuick, 0, ARR_SIZE_62);
        fim = clock();

        tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        tempos_quick_62[i] = tempo;
                
    }

    printf("Media de tempo para QuickSort em array de tamanho 62.500: %lf segundos\n",media(tempos_quick_62,50));

    printf("Seleção 62.500: 0 porcento concluido\n");

    for(int i = 0; i < 50; i++){

        randomFillArray(arrSelec,i,ARR_SIZE_62);
    
        inicio = clock();
        selectionSort(arrSelec,ARR_SIZE_62);
        fim = clock();

        tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        tempos_selec_62[i] = tempo;

        printf("Seleção 62.500: %d porcento concluido\n",(i+1)*2);
        fflush(stdout);
        
    }
    
    printf("Media de tempo para SelectionSort em array de tamanho 62.500: %lf segundos\n",media(tempos_selec_62,50));

    free(arrQuick);
    arrQuick = NULL;

    free(arrSelec);
    arrSelec = NULL;

	//Bloco 125.000


    arrQuick = malloc(sizeof(int)*ARR_SIZE_125);

    arrSelec = malloc(sizeof(int)*ARR_SIZE_125);

    for(int i = 0; i < 50; i++){

        randomFillArray(arrQuick,i,ARR_SIZE_125);
        
        inicio = clock();
        quickSort(arrQuick, 0, ARR_SIZE_125);
        fim = clock();

        tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        tempos_quick_125[i] = tempo;
                
    }

    printf("Media de tempo para QuickSort em array de tamanho 125.000: %lf segundos\n",media(tempos_quick_125,50));

    printf("Seleção 125.000: 0 porcento concluido\n");

    for(int i = 0; i < 50; i++){

        randomFillArray(arrSelec,i,ARR_SIZE_125);
    
        inicio = clock();
        selectionSort(arrSelec,ARR_SIZE_125);
        fim = clock();

        tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        tempos_selec_125[i] = tempo;

        printf("Seleção 125.000: %d porcento concluido\n",(i+1)*2);
        fflush(stdout);
        
    }
    
    printf("Media de tempo para SelectionSort em array de tamanho 125.000: %lf segundos\n",media(tempos_selec_125,50));

    free(arrQuick);
    arrQuick = NULL;

    free(arrSelec);
    arrSelec = NULL;


    //Bloco 250.000

    arrQuick = malloc(sizeof(int)*ARR_SIZE_250);

    arrSelec = malloc(sizeof(int)*ARR_SIZE_250);

    for(int i = 0; i < 50; i++){

        randomFillArray(arrQuick,i,ARR_SIZE_250);
        
        inicio = clock();
        quickSort(arrQuick, 0, ARR_SIZE_250);
        fim = clock();

        tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        tempos_quick_250[i] = tempo;
                
    }

    printf("Media de tempo para QuickSort em array de tamanho 250.00: %lf segundos\n",media(tempos_quick_250,50));

    printf("Seleção 250.000: 0 porcento concluido\n");

    for(int i = 0; i < 50; i++){

        randomFillArray(arrSelec,i,ARR_SIZE_250);
    
        inicio = clock();
        selectionSort(arrSelec,ARR_SIZE_250);
        fim = clock();

        tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        tempos_selec_250[i] = tempo;

        printf("Seleção 250.000: %d porcento concluido\n",(i+1)*2);
        fflush(stdout);
        
    }
    
    printf("Media de tempo para SelectionSort em array de tamanho 250.000: %lf segundos\n",media(tempos_selec_250,50));

    free(arrQuick);
    arrQuick = NULL;

    free(arrSelec);
    arrSelec = NULL;


	//Bloco 375.000

    arrQuick = malloc(sizeof(int)*ARR_SIZE_375);

    arrSelec = malloc(sizeof(int)*ARR_SIZE_375);

    for(int i = 0; i < 50; i++){

        randomFillArray(arrQuick,i,ARR_SIZE_375);
        
        inicio = clock();
        quickSort(arrQuick, 0, ARR_SIZE_375);
        fim = clock();

        tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        tempos_quick_375[i] = tempo;
                
    }

    printf("Media de tempo para QuickSort em array de tamanho 375.000: %lf segundos\n",media(tempos_quick_375,50));

    printf("Seleção 375.000: 0 porcento concluido\n");

    for(int i = 0; i < 50; i++){

        randomFillArray(arrSelec,i,ARR_SIZE_375);
   
        inicio = clock();
        selectionSort(arrSelec,ARR_SIZE_375);
        fim = clock();

        tempo = ((double)(fim-inicio)) / CLOCKS_PER_SEC;
        tempos_selec_375[i] = tempo;

        printf("Seleção 375.000: %d porcento concluido\n",(i+1)*2);
        fflush(stdout);
        
    }
    
    printf("Media de tempo para SelectionSort em array de tamanho 375.000: %lf segundos\n",media(tempos_selec_375,50));

    free(arrQuick);
    arrQuick = NULL;

    free(arrSelec);
    arrSelec = NULL;

    return 0;
}