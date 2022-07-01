#include "mergesort.h"

MergeSort::MergeSort(int difficulty) : difficulty(difficulty)
{

}

void MergeSort::sorting(){

    for(int i = 0; i < 34; i++){
     int z = 3;

     emit result(z);
    }
}

int MergeSort::getDifficulty(){
    return this->difficulty;
}

void MergeSort::setDifficulty(int difficulty){
    this->difficulty = difficulty;
}
