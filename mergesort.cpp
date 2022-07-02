#include "mergesort.h"

MergeSort::MergeSort(int difficulty) : difficulty(difficulty){}

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
    n1=q-p+1;  //dimensione array sx
    n2=r-q;    //dimensione array dx
    int L[n1],R[n2];
    //inizializzo array sx
    for(i=0;i<n1;i++)
    {
        L[i]=data[p+i];
    }
    //inizializzo array dx
    for(j=0;j<n2;j++)
    {
        R[j]=data[q+j+1];
    }
    i=0,j=0;
    //Confronto e faccio il merge in un nuovo array ordinato
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
    //Se l'array sx ha più elementi del dx metto gli elementi rimanenti nell'array iniziale
    while(i<n1)
    {
        data[k++]=L[i++];
    }
    //Se l'array dx ha più elementi del sx metto gli elementi rimanenti nell'array iniziale
    while(j<n2)
    {
        data[k++]=R[j++];
    }
}

void MergeSort::sorting(){
        emit startSorting(true);
        int *array;
        int size;
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
       int curr_size;  //current size degli algoritmi di cui fare il merge
       int left_start; // inizio dell'array sx
       emit isRunningSorting(true);
       emit result(5);
       // faccio la merge dei due storro array
       for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
       {
           for (left_start=0; left_start<n-1; left_start += 2*curr_size)
           {
               int mid = min(left_start + curr_size - 1, n-1);

               int right_end = min(left_start + 2*curr_size - 1, n-1);

               merge(array, left_start, mid, right_end);
           }
       }

       emit stopSorting(true);
}
