#ifndef sorter_h
#define sorter_h

#include <iostream>
#include <vector>



template <typename T>
class Sorter
{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(int i, int j, std::vector<T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};
};


template <typename T>
class SelectionSort : public Sorter<T>
{
    public:
    SelectionSort() {};
    ~SelectionSort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i+1; j < arr.size(); j++)
            {
                if (arr[j] < arr[min])
                    min = j;
            }
            Sorter<T>::swap(i, min, arr);
        }        
    };
};


template <typename T>
class BubbleSort : public Sorter<T>
{
    public:
    BubbleSort() {};
    ~BubbleSort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            bool no_swap = true;
            for (size_t j = 0; j < arr.size() - i-1; j++)
            {
                if (arr[j] > arr[j+1]) {
                    Sorter<T>::swap(j, j+1, arr);
                    no_swap = false;
                }
            }
            if (no_swap)
                break;
        }        
    };
};

template <typename T>
class InsertionSort : public Sorter<T>
{
    public:
    InsertionSort() {};
    ~InsertionSort() {};

    void sort(std::vector<T> &arr)
    {
        T key;
        for (size_t i = 1; i < arr.size(); i++)
        {
            key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }        
    };
};

template <typename T>
class MergeSort : public Sorter<T>
{

    


    public:
    MergeSort() {};
    ~MergeSort() {};

 

    void sort(std::vector<T> &arr)
    {
        mergesort(arr, 0, arr.size()-1);
    };

    // 1 3 5 2 7 4 6 2 0
    // 0 1 2 3 4 5 6 7 8
    void mergesort(std::vector<T> &arr, int l, int r)
    {
        if (l < r) {
            int m = l + (r-l) / 2;
            
            mergesort(arr, l, m);
            mergesort(arr, m+1, r);

            merge(arr, l, m, r);
        }
    }

    // 1 3 5 1 2 4 0 5 6 7 4 6 2 0
    // - - - l - m - - r - - - - - 
    // L = [1 2 4], R = [0 5 6]
    void merge(std::vector<T> &arr, int l, int m, int r)
    {
        /* insert your code here*/

        // declare variables
        int leftLength = m-l+1;
        int rightLength = r - m;
        std::vector<T> L;
        std::vector<T> R; 
        
        // fill temporal arrays left | right
        for (int i=0; i < leftLength; i++) // Left Array
            L.push_back(arr[l+i]);

    
        for (int i =0; i < rightLength; i++) // Right Array TODO: Fix maybe
            R.push_back(arr[m + 1 + i]);


        int i = 0 , j = 0, k = l;
        
        while(i < leftLength && j < rightLength)
        {
            if (L[i] < R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
                
        if( j < rightLength)
        {
            for(j; j < rightLength; j++)
            {
                arr[k] = R[j];
                k++;
            }
        }
        else
        {
            for (i; i < leftLength; i++)
            {
                arr[k] = L[i];
                k++;
            }
            
        }
        

        // compare values from left and right, and place in arr while i < n1 and j < n2

        // missing vals from i and j
    }
};


#endif