#ifndef Heap_HPP
#define Heap_HPP

#include <iostream>

template <typename T>
class MinHeap{
    T *h;
    int size, m;
public:
    MinHeap(int n) : size(n), m(-1) {
        h = new T[n];
    }
    
    MinHeap(T *arr, int n) : size(n){
        h = new T[n];
        
        for (m = 0; m < n; ++m)
            h[m] = arr[m];
        --m;

        for ( int i = n / 2 - 1; i >= 0; --i )
            heapify(i);
    }
    
    ~MinHeap(){
        if (size>0)
            delete[] h;
    }
    
    void insertElement(const T &value){
        if (m + 1 < size){
            ++m;
            h[m] = value;
            std::swap(h[m], h[0]);
            heapify(0);
        }
    }

    T getMin(){
        return h[0];
    }

    int getSize(){
        return size;
    }
    
    int number_elements(){
        return m + 1;
    }

    T extractMin(){
        T temp = h[0];
        h[0] = h[m];
        --m;
        heapify(0);

        return temp;
    }

    void heapify(int i){
        int child = 2 * i + 1;
        

        while( child <= m ) {
            if( child + 1 <= m && h[child+1] < h[child] )
                ++child;
            if( h[child] < h[i]  ){
                std::swap <T> (h[child], h[i]);
                i = child;
                child = 2 * i + 1;
            }
            else
                break;
        }
    }


};


#endif