//
//  PQueue.cpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/11.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#include "PQueue.hpp"

PQueue::PQueue(){
    head = new PQueue::Tblock;
    head->next = NULL;
}

PQueue::~PQueue(){
    PQueue::freeQueue(head);
}

void
PQueue::freeQueue(Tblock * & t){
    if(t != NULL){
        freeQueue(t->next);
        delete t;
    }
}

int
PQueue::size(){
    int size = 0;
    Tblock *t = head;
    while(t != NULL){
        size += t->used;
        t = t->next;
    }
    return size;
}

bool
PQueue::isEmpty(){
    if(PQueue::size() == 0){
        return true;
    }
    else return false;
}

int
PQueue::dequeueMax(){
    if(isEmpty()){
        std::cerr << "Can't dequeue from a empty queue." << std::endl;
        exit(1);
    }
    else{
        int max = head->block[0];
        head->used--;
        for(int i = 0; i < head->used ; i++){
            head->block[i] = head->block[i+1];
        }
        if(head->used == 0 && head->next != NULL){
            Tblock *temp = head;
            head = head->next;
            delete temp;
        }
        return max;
    }
}

void
PQueue::enqueue(int newElem){
    enqueueInner(head, newElem);
}

void
PQueue::enqueueInner(Tblock * & t, int newElem){
    if(t->used == MaxElemsPerBlock){
        Tblock *newTblock = new Tblock;
        newTblock->next = t->next;
        t->next = newTblock;
        newTblock->used = MaxElemsPerBlock/2;
        t->used = MaxElemsPerBlock/2;
        for(int i = 0; i < MaxElemsPerBlock/2; i++){
            newTblock->block[i] = t->block[i+MaxElemsPerBlock/2];
        }
        enqueueInner(t, newElem);
    }
    else if(t->next != NULL && newElem < t->next->block[0]){
        enqueueInner(t->next, newElem);        
    }
    else if(newElem < t->block[t->used-1] && t->used > MaxElemsPerBlock/2){
        if(t->next == NULL){
            Tblock *newTblock = new Tblock;
            t->next = newTblock;
        }
        enqueueInner(t->next, newElem);
    }
    else{
        t->block[t->used++] = newElem;
        for(int i = t->used-1; i > 0; i--){
            if(t->block[i] > t->block[i-1]){
                int temp = t->block[i];
                t->block[i] = t->block[i-1];
                t->block[i-1] = temp;
            }
        }
    }
}