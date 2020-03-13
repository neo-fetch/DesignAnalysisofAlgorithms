#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct piv
{
    int pivot1;
    int pivot2;
};

typedef struct piv piv;


class Pivot { 
    vector<int> vec; 
  
public: 
    Pivot(vector<int> v)  
    { 
       vec = v; 
    }
    void append(int v)
    {
        vec.push_back(v);
    } 
    void print() 
    { 
        /// print the value of vector 
        for (int i = 0; i < vec.size(); i++) 
            cout << vec[i] << " ";
        cout<<endl; 
    }
    void sortobj()
    {
    cout<<"Elements before sorting"<<endl;
    for (const auto &i: vec)
        cout << i << ' '<<endl;
        cout<<"Elements after sorting"<<endl;
        sort(vec.begin(), vec.end());
    for (const auto &i: vec)
        cout << i << ' '<<endl;
    }

    piv partition() 
    {
        int left = 0, right = vec.size() - 1;
        int pivotIndex = right/2;
        int pivotValue = vec[right];
        int upperlimit = left + right;
        piv p;
        p.pivot1 = left-1;
        p.pivot2 = right;
        int tmp;
        while(p.pivot2<=upperlimit)
        {
            if (vec[p.pivot2] < pivotValue)
            {
                tmp = vec[p.pivot1];
                vec[p.pivot1] = vec[p.pivot2];
                vec[p.pivot2] = tmp;
                p.pivot1++;
                p.pivot2++;
            }

            else if (vec[p.pivot2] < pivotValue)
            {
                tmp = vec[p.pivot2];
                vec[p.pivot2] = vec[upperlimit];
                vec[upperlimit] = tmp;
                upperlimit--;
            }
            else
            {
                p.pivot2++;
            }
            
        }
        return p;
        // int pivotValue = vec[pivotIndex];
        // int i = left, j = right;
        // int temp;
        // for (auto i = left; i <=pivotIndex ; i++)
        // {
        //     cout<< "vec[" << i << "] = "<<vec[i]<<" ";
        // }
        // cout << endl;
        // while(i <= j) {
        //     while(vec[i] < pivotValue) {
        //         i++;
        //     }
        //     while(vec[j] >= pivotValue) {
        //         j--;
        //     }
        //     if(i <= j) {
        //         temp = vec[i];
        //         vec[i] = vec[j];
        //         vec[j] = temp;
        //         i++;
        //         j--;
        //     }
        // }
        // return i-1;
    } 
}; 


int main(int argc, char const *argv[])
{
    vector<int> vec;
    int i;
    Pivot obj(vec);  
    for (;;)
    {
        cout<< "enter element"<<endl;
        cin>>i;
        if(i==-1)
        break;
        else 
        obj.append(i);
        obj.print();
    }
   // obj.sortobj();
    piv pivt = obj.partition();
    cout<<"\n\n\n"<< pivt.pivot1<<pivt.pivot2<<"\n\n\n";
    obj.print(); 
    
    return 0;   
}
