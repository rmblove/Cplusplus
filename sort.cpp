//
//  sort.cpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/11.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#include "sort.hpp"

void bubblesort(Vector<int> & v){
    int temp;
    for(int i = 0; i < v.size()-1; i++){
        for(int j = 0; j < v.size()-i-1 ; j++)
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                
            }
    }
}

void insertionsort(Vector<int> & v){
    int temp;
    for(int i = 1; i < v.size() ;i++){
        for(int j = i; j > 0 ; j--){
            if(v[j] < v[j-1]){
                temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
        }
    }
}

Vector<int> merge2vector(Vector<int> v1, Vector<int> v2){
    Vector<int> temp;
    int size_v1 = v1.size();
    int size_v2 = v2.size();
    int pos_v1 = 0;
    int pos_v2 = 0;
    while(pos_v1 < size_v1 && pos_v2 < size_v2){
        if(v1[pos_v1] < v2[pos_v2]){
            temp.add(v1[pos_v1]);
            pos_v1++;
        }
        else{
            temp.add(v2[pos_v2]);
            pos_v2++;
        }
    }
    while(pos_v1 < size_v1){
        temp.add(v1[pos_v1]);
        pos_v1++;
    }
    while(pos_v2 < size_v2){
        temp.add(v2[pos_v2]);
        pos_v2++;
    }
    return temp;
}

Vector<int> mergesortInner(Vector<int> v){
    if(v.size() <= 1) return v;
    else if(v.size()%2 == 1) return merge2vector(mergesortInner(v.subList(0, v.size()/2)),
                                                 mergesortInner(v.subList(v.size()/2, v.size()/2+1)));
    else return merge2vector(mergesortInner(v.subList(0, v.size()/2)),
                             mergesortInner(v.subList(v.size()/2, v.size()/2)));
}

void mergesort(Vector<int> & v){
    Vector<int> temp;
    temp.addAll(v);
    v = (mergesortInner(temp));
}

int retpivot(Vector<int> & v, int p, int q){
    int pivot = v[p];
    int i = p;
    int j = i+1;
    int temp;
    while(j <= q){
        if(v[j] < pivot){
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

void quicksortInner(Vector<int> & v, int p, int q){
    if(p < q){
        int pivot = retpivot(v, p, q);
        quicksortInner(v, p, pivot-1);
        quicksortInner(v, pivot+1, q);
    }
}

void quicksort(Vector<int> & v){
    quicksortInner(v, 0, v.size()-1);
}

