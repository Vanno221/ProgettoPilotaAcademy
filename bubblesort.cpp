#include "bubblesort.h"

void BubbleSort::sorting(){
    emit statusThread("Start Thread");
    int *array;
    int size;
    double progress = 0.0;
    switch (this->difficulty) {
    case 0: //easy
        size = 100;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    case 1: //medium
        size = 1000;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    case 2: //hard
        size = 10000;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    }
    int length = size;
    progress = (static_cast<double> (100))/size;
    //start sorting
    //emit result(progress);
    emit statusThread("Thread is Running");
    for (int iter =0; iter< length -1; iter++) {
        for(int i=0; i< length-1; i++) {
            if (array[i] > array[i+1]) {
                std::swap(array[i], array[i+1]);
            }
        }

        progress = (static_cast<double> (100))/size;
        emit result(progress);

    }
    //emit result(progress);
    qDebug() << progress;
    emit statusThread("Thread is Terminated");
    emit stopSorting();

}

int BubbleSort::getDifficulty(){
    return this->difficulty;
}

void BubbleSort::setDifficulty(int difficulty){
    this->difficulty = difficulty;
}

BubbleSort::BubbleSort(int difficulty) : difficulty(difficulty)
{}
