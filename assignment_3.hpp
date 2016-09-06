//
//  assignment_3.hpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/7.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#ifndef assignment_3_hpp
#define assignment_3_hpp

#include <stdio.h>
#include "vector.h"

/*prints the binary representation for a given integer*/
void PrintInBinary(int num);

/* Given a set of integers and a target number, your goal is to find a subset of those numbers that sum to that target number.*/
bool CanMakeSum(Vector<int> & nums, int targetSum);

/*justlikeabrovesay*/
void WhatMakeSum(Vector<int> nums, int targetSum);


/*takes a positive numStairs value and returns the number of different ways to climb a staircase of that height taking strides of one or two stairs at a time.*/
int CountWays(int numStairs);

bool Solvable(int start, Vector<int> & squares);

/*given a vector of the lengths needed and the stock pipe length.*/
int CutStock(Vector<int> & requests, int stockLength);



/*print vector with loop*/
template <typename T>
void printVector(Vector<T> & v){
    std::cout << " { ";
    for(auto p = v.begin(); p!=v.end(); ++p){
        std::cout << *p << ", ";
    }
    std::cout << "} " << std::endl;
}
#endif /* assignment_3_hpp */
