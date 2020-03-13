#include <iostream>
#include <algorithm>

using namespace std;
int med[100];
int arr[100];
int medarr[20][5];
int pivarr[100]; 
int pivotnum, pivot;
void display(int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<< "index: "<< i <<":  ";
        cout<< arr[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
}

void startSearch(int left, int right)
{
    if((right)%5==0)
    pivotnum = (((right - left)/5 + 1)/2);
    else
    pivotnum = (((right - left)/5 + 1)/2)-1;
    //pivot = pivot;
    pivotnum = pivot%5 + 5*pivot;
    
    cout<< "\npivot: "<<pivotnum<<endl;
}


void median(int left, int right)
{
    cout<< "\nMedian Array: "<<endl;
    for (int i = left; i < right/5; i++)
    {
        med[i] = medarr[i][2];
        cout<< med[i]<<"  ";
    }
    cout<<endl;
    cout<<endl;
    startSearch(left, right);
}

void dividein5(int left, int right)
{
    cout<< "Dividing in batches of 5: \n"<<endl;
    int k = 0;
    for (int i = left; i < right/5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            medarr[i][j] = arr[k];
            ++k;
        }
        sort(medarr[i], medarr[i]+5);        
    }
    
    k = 0;
    for (int i = left; i < right/5; i++)
    {
        cout<< "Batch: "<< i+1 <<":  " <<endl;
        for (int j = 0; j < 5; j++)
        {
            cout << medarr[i][j] << "  ";
            pivarr[k] = medarr[i][j];
            ++k;
        }
        cout<<endl;
    }

    for (int i = 0; i < k; i++)
    {
        cout<< pivarr[i] << "  ";
    }
    
    median(left, right);
    
}

void createArray()
{
    int input;
    int i = 0;
    while (true)
    {        
        std::cout << "take in the values: (-1 to exit)" << std::endl;
        cin>>input;
        if (input == -1)
        {
            break;
        }
        arr[i] = input;
        ++i;
    }

    cout<< "array: "<<endl;
    display(i);
    dividein5(0,i);
}

void orderStatistics(int left, int right, int k){
    //whether k is really inside the array
    if (k <= (right - left))
    {
        //we have our pivot
        dividein5(left, right); // this will recalculate our new pivot, medarr, med
        // if pivot is k
        if (pivot == k)
        {
            cout<< k<< " th smallest element is: " << pivarr[k]<<endl;
        }

        if (pivot < k)
        {
            orderStatistics(pivot, right, pivot - k);
        }
        else
        {
            orderStatistics(left, pivot, k);
        } 
    }
    else//if it isnt
    cout<< "k greater than array"<<endl;    
}


int main(int argc, char const *argv[])
{
    createArray();
}