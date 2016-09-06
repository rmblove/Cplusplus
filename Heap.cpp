//
//  Heap.cpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/12.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#include "Heap.hpp"
#include <iostream>

Heap::Heap(){
    int size = ARRAY_LENTH + 1;
    heap = new int[size];
}

Heap::~Heap(){
    delete [] heap;
}

int*
Heap::getarray(){
    return heap;
}

const int
Heap::size(){
    return heap[0];
}

bool
Heap::isEmpty(){
    return (heap[0] == 0);
}

void
Heap::DoubleHeap(){
    ARRAY_LENTH *= 2;
    int size = ARRAY_LENTH + 1;
    int *p = new int[size];
    for(int i = 0; i <= Heap::size(); i++){
        p[i] = heap[i];
    }
    int *temp = heap;
    heap = p;
    delete [] temp;
}

void
Heap::push(int newElem){
    if(Heap::size() >= Heap::ARRAY_LENTH) DoubleHeap();
    heap[0]++;
    int curpos = heap[0];
    int temp = 0;
    heap[curpos] = newElem;
    int nextpos = curpos/2;
    while (nextpos > 0) {
        if(heap[curpos] > heap[nextpos]) {
            temp = heap[curpos];
            heap[curpos] = heap[nextpos];
            heap[nextpos] = temp;
            curpos = nextpos;
            nextpos = nextpos/2;
        }
        else break;
    }
}

int
Heap::pop(){
    if(size() == 0){
        std::cerr <<"Can't pop a element from a empty heap." << std::endl;
        exit(0);
    }
    else if(size() == 1){
        heap[0]--;
        return heap[1];
    }
    else{
        int result = heap[1];
        heap[1] = heap[size()];
        heap[0]--;
        int temp = 0;
        int curpos = 1;
        while (curpos*2 <= heap[0]) {
            if (heap[curpos*2+1] > heap[curpos*2]){
                if(heap[curpos] > heap[curpos*2+1]) break;
                temp = heap[curpos];
                heap[curpos] = heap[curpos*2+1];
                heap[curpos*2+1] = temp;
                curpos = curpos*2+1;
            }
            else{
                if(heap[curpos] > heap[curpos*2]) break;
                temp = heap[curpos];
                heap[curpos] = heap[curpos*2];
                heap[curpos*2] = temp;
                curpos = curpos*2;
            }
        }
        return result;
    }
}