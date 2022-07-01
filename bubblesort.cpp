#include "bubblesort.h"

void BubbleSort::sorting(){
    emit startSorting(true);
    int *array;
    int size;
    switch (this->difficulty) {
    case 1: //easy
        size = 100;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    case 2: //medium
        size = 1000;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    case 3: //hard
        size = 10000;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    }
    int length = size;
    //start sorting
    emit isRunningSorting(true);
    for (int iter =0; iter< length -1; iter++) {
        int swapped = 0;
        for(int i=0; i< length-1; i++) {
            if (array[i] > array[i+1]) {
                BubbleSort::swap(&array[i], &array[i+1]) ;
                swapped = 1;
            }
        }
        // if no swapping had occoured then list is sorted
        if (swapped == 0) {
            break;
        }
    }
    emit stopSorting(true);
}

int BubbleSort::getDifficulty(){
    return this->difficulty;
}

void BubbleSort::setDifficulty(int difficulty){
    this->difficulty = difficulty;
}

BubbleSort::BubbleSort(int difficulty) : difficulty(difficulty)
{}

void BubbleSort::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
