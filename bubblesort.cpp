#include "bubblesort.h"

void BubbleSort::sorting(){

    QString id = QString::number(this->id);
    emit statusThread("Start Thread: " + id);
    int *array = nullptr;
    int size;
    double progress = 0.0;
    double tmp_progress = 0;

    switch (this->difficulty) {
    case 0: //easy
        size = 1000;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    case 1: //medium
        size = 10000;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    case 2: //hard
        size = 100000;
        array = new int [size];
        for(int i=0; i<size;i++)
                array[i] = std::rand()%101;
    break;
    }

    int length = size;
    //Keeping trace of algorithm status
    progress = (static_cast<double> (100))/size;

    emit result(progress);

    //Emitting id and thread status
    emit statusThread("Running Thread: " + id);

    for (int iter =0; iter< length; iter++) {

        for(int i=0; i< length-1; i++) {
            if (array[i] > array[i+1]) {
                std::swap(array[i], array[i+1]);
                //qDebug() << "Sono dentro il 2 for";
            }
        }

        tmp_progress += progress;

        if (tmp_progress >= 1){
            //qDebug() << tmp_progress;
            emit result(tmp_progress);
            tmp_progress -= 1;
        }
        //qDebug() << "Sono dentro il 1 for";

    }

    //qDebug() << "Finito";

    emit statusThread("Terminated Thread: " + id);
    emit stopSorting();

    if (array != nullptr)
         delete [] array;

}

int BubbleSort::getDifficulty(){
    return this->difficulty;
}

void BubbleSort::setDifficulty(int difficulty){
    this->difficulty = difficulty;
}

BubbleSort::BubbleSort(int difficulty, int id) : difficulty(difficulty){
    this->id = id;
}
