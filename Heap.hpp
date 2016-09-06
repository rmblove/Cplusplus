//
//  Heap.hpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/12.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp


#include <stdio.h>
class Heap
{
public:
    Heap();
    ~Heap();
    const int size();
    bool isEmpty();
    void push(int newElem);
    int pop();
    int* getarray();
    
private:
    int ARRAY_LENTH = 20;
    
    int *heap;
     
    void freeHeap(int * & t);
    
    void  DoubleHeap();
    
    
};

#endif /* Heap_hpp */
