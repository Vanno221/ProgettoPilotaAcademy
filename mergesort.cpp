#include "mergesort.h"

MergeSort::MergeSort(int difficulty, int id) : difficulty(difficulty){
   this->id = id;
}

int MergeSort::getDifficulty(){
    return this->difficulty;
}

void MergeSort::setDifficulty(int difficulty){
    this->difficulty = difficulty;
}

int MergeSort::min(int a, int b) {
    return a <= b ? a : b;
}

void MergeSort::merge(int data[],int p, int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;                                                //left array lenght
    n2=r-q;                                                  //right array lenght
    int L[n1],R[n2];

    //initialize left array
    for(i=0;i<n1;i++)
    {
        L[i]=data[p+i];
    }

    //initialize right array
    for(j=0;j<n2;j++)
    {
        R[j]=data[q+j+1];
    }
    i=0,j=0;
    //Compare and merge into a new array
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            data[k]=L[i++];
        }
        else
        {
            data[k]=R[j++];
        }
    }
    //If the left array has more element than the right one, put remained elements into initial array
    while(i<n1)
    {
        data[k++]=L[i++];
    }
    //If the right array has more element than the left one, put remained elements into initial array
    while(j<n2)
    {
        data[k++]=R[j++];
    }
}

void MergeSort::sorting(){

        QString id = QString::number(this->id);
        emit statusThread("Start Thread: " + id);
        int *array = nullptr;
        int size;
        double progress = 0.0;
        double tmp_progress = 0;

        //Check difficulty and create array

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
       int n = size;
       int curr_size;  //Current size algorithms of which make the merge
       int left_start; //Start left array


       // Merge the two arrays
       emit statusThread("Running Thread: " + id);

       for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
       {
           for (left_start=0; left_start<n-1; left_start += 2*curr_size)
           {
               int mid = min(left_start + curr_size - 1, n-1);

               int right_end = min(left_start + 2*curr_size - 1, n-1);

               merge(array, left_start, mid, right_end);

               progress = (static_cast<double> (100))/(size);
               //qDebug() << progress;
               tmp_progress += progress;


               if (tmp_progress >= 1){
                   //qDebug() << tmp_progress;
                   emit result(tmp_progress);
                   tmp_progress -= 1;
               }
           }


       }



       emit statusThread("Terminated Thread: " + id);
       emit stopSorting();

       if (array != nullptr)
            delete [] array;
}
