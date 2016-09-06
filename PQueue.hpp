//
//  PQueue.hpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/11.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#ifndef _PQueue_hpp
#define _PQueue_hpp

#include <stdio.h>
#include <iostream>

class PQueue
{
public:
    PQueue();
    ~PQueue();
    int size();
    bool isEmpty();
    void enqueue(int newElem);
    int dequeueMax();
private:
    const static int MaxElemsPerBlock = 10;
    struct Tblock {
        int used = 0;
        int block[MaxElemsPerBlock];
        Tblock *next = NULL;
    };
    Tblock *head;
    
    void freeQueue(Tblock * & t);
    void enqueueInner(Tblock * & t, int newElem);
    
    
};


#endif /* _PQueue_hpp */
