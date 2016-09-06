//
//  heaque.hpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/12.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#ifndef heaque_hpp
#define heaque_hpp

#include <stdio.h>


#include <iostream>




template <typename T>
class heaque {
public:
    heaque();
    ~heaque();
    const int size();
    bool isEmpty();
    void push(int key, T newElem);
    T pop();
    
    
private:
    struct Tcell{
        int key;
        T Val;
    };
    
    int ARRAY_LENTH = 20;
    
    int USED = 0;
    
    int elemsize = sizeof(Tcell);
    
    void *head;
    
    void freeheaque(T * & t);
    
    void  Doubleheaque();
    
    void exchangelem(int pos1, int pos2);
    
    //typename heaque<T>::Tcell* getarray();
};




template <typename T>
heaque<T>::heaque(){
    int elemnum = ARRAY_LENTH + 1;
    head = malloc(elemnum * elemsize);
}

template <typename T>
heaque<T>::~heaque(){
    free(head);
}

/* this is not safe to use.
template <typename T>
typename heaque<T>::Tcell
*heaque<T>::getarray(){
    return head;
}
*/

template <typename T>
const int
heaque<T>::size(){
    return USED;
}

template <typename T>
bool
heaque<T>::isEmpty(){
    return (USED == 0);
}

template <typename T>
void
heaque<T>::Doubleheaque(){
    ARRAY_LENTH *= 2;
    int elemnum = ARRAY_LENTH + 1;
    head = realloc(head, elemnum * elemsize);
}

template <typename T>
void
heaque<T>::exchangelem(int pos1, int pos2){
    memcpy((Tcell*)head,(Tcell*)head + pos1*elemsize, elemsize);
    memcpy((Tcell*)head + pos1*elemsize,(Tcell*)head + pos2*elemsize, elemsize);
    memcpy((Tcell*)head + pos2*elemsize,(Tcell*)head, elemsize);
}



template <typename T>
void
heaque<T>::push(int key,T newElem){
    if(heaque::size() >= heaque::ARRAY_LENTH) Doubleheaque();
    USED++;
    int curpos = USED;
    ((Tcell*)head)->key = key;
    ((Tcell*)head)->Val = newElem;
    memcpy((Tcell*)head + USED*elemsize, (Tcell*)head, elemsize);
    //std::cout << ((Tcell*)head + USED*elemsize)->Val;
    int nextpos = curpos/2;
    while (nextpos > 0) {
        if(((Tcell*)head + curpos*elemsize)->key > ((Tcell*)head + nextpos*elemsize)->key) {
            heaque<T>::exchangelem(curpos, nextpos);
            curpos = nextpos;
            nextpos = nextpos/2;
        }
        else break;
    }
}

template <typename T>
T
heaque<T>::pop(){
    if(size() == 0){
        std::cerr <<"Can't pop a element from a empty heaque." << std::endl;
        exit(0);
    }
    else if(size() == 1){
        USED--;
        return ((Tcell*)head + 1*elemsize)->Val;
    }
    else{
        T result = ((Tcell*)head + 1*elemsize)->Val;
        memcpy((Tcell*)head + 1*elemsize, (Tcell*)head + USED*elemsize, elemsize);
        USED--;
        int curpos = 1;
        while (curpos*2 <= USED) {
            if(((Tcell*)head + (curpos*2+1)*elemsize)->key > ((Tcell*)head + curpos*2*elemsize)->key){
                if(((Tcell*)head + (curpos)*elemsize)->key > ((Tcell*)head + (curpos*2+1)*elemsize)->key) break;
                heaque<T>::exchangelem(curpos, curpos*2+1);
                curpos = curpos*2+1;
            }
            else{
                if(((Tcell*)head + (curpos)*elemsize)->key > ((Tcell*)head + curpos*2*elemsize)->key) break;
                heaque<T>::exchangelem(curpos, curpos*2);
                curpos = curpos*2;
            }
        }
        return result;
    }
}



#endif /* heaque_hpp */
