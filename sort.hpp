//
//  sort.hpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/11.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include "vector.h"

void bubblesort(Vector<int> & v);

void insertionsort(Vector<int> & v);

void mergesort(Vector<int> & v);

void quicksort(Vector<int> & v);

template <typename Type>
int retpivot(Vector<Type> & v, int p, int q, int (cmpFn)(Type, Type)){
    Type pivot = v[p];
    int i = p;
    int j = i+1;
    Type temp;
    while(j <= q){
        if(cmpFn(v[j], pivot) < 0){
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            
        }
        j++;
    }
    temp = v[p];
    v[p] = v[i];
    v[i] = temp;
    return i;
}

template <typename Type>
void quicksortInner(Vector<Type> & v, int p, int q, int (cmpFn)(Type, Type)){
    if(p < q){
        int pivot = retpivot(v, p, q, cmpFn);
        quicksortInner(v, p, pivot-1, cmpFn);
        quicksortInner(v, pivot+1, q, cmpFn);
    }
}

template <typename Type>
int OperatorCmp(Type t1, Type t2){
    if(t1 < t2) return -1;
    else if (t1 > t2) return 1;
    else return 0;
}

template <typename Type>
void Sort(Vector<Type> & v, int (cmpFn)(Type, Type) = OperatorCmp){
    quicksortInner(v, 0, v.size()-1, cmpFn);
}


#include <stdio.h>

#endif /* sort_hpp */
