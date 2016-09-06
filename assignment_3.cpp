//
//  assignment_3.cpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/7.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#include "assignment_3.hpp"
#include <iostream>
#include "set.h"

void
printVector(Vector<int> & v){
    std::cout << " { ";
    for(auto p = v.begin(); p!=v.end(); ++p){
        std::cout << *p << ", ";
    }
    std::cout << "} " << std::endl;
}

int sumVector(Vector<int> & v){
    int sum = 0;
    for(auto p = v.begin(); p!=v.end(); ++p){
        sum += *p;
    }
    return sum;
}

void
printInBinary(int num){       //num should be over than zero.
    if(num == 0) return;
    else{
        printInBinary(num/2);
        std::cout << num%2;
    }
}

void
PrintInBinary(int num){
    if(num < 0) std::cerr << "Num should be over than zero:"<<std::endl;
    printInBinary(num);
    std::cout << std::endl;
}

bool
recSubsets(Vector<int> & nums, int targetSum, int sum)
{
    if (sum == targetSum) return true;
    for(int i = 0; i < nums.size(); i++){
        int n = nums[i];
        sum += n;
        nums.remove(i);
        if (recSubsets(nums, targetSum, sum)) {
            //printVector(nums);
            return true;
        }
        nums.insert(i, n);
        sum -= n;
        
    }
    //if (sum == targetSum) return true;
    return false;
}

bool
CanMakeSum(Vector<int> & nums, int targetSum){
    int sum = 0;
    return recSubsets(nums, targetSum, sum);
}

void Subsets(Vector<int> soFar, Vector<int> nums, int targetSum)
{
    if (nums.isEmpty()){
        if(sumVector(soFar) ==targetSum) printVector(soFar);
    }
    else {
        // add to subset, remove from rest, recur
        Vector<int> soFarplusnums_1 = soFar;
        soFarplusnums_1.add(nums[0]);
        nums.remove(0);
        Subsets(soFarplusnums_1, nums, targetSum);
        // don't add to subset, remove from rest,recur
        Subsets(soFar, nums, targetSum);
    }
}

void
WhatMakeSum(Vector<int> nums, int targetSum){
    Vector<int> sf;
    Subsets(sf, nums, targetSum);
}


int
CountWays(int numStairs){
    if(numStairs ==1 ) return 1;
    if(numStairs ==2 ) return 2;
    return CountWays(numStairs - 1) + CountWays(numStairs-2);
}

bool
Solvable_Inner(int start, Vector<int> & squares, Set<int> & INDEXSET){
    if(start == squares.size()-1) return true;
    if(INDEXSET.contains(start)) return false;
    INDEXSET.add(start);
    int *move = new int[2];
    move[0] = squares[start];
    move[1] = -squares[start];
    for(int i = 0; i < 2 ; i++){
        start += move[i];
        if(start >= 0 && start < squares.size()) return Solvable_Inner(start, squares, INDEXSET);
        start -= move[i];
    }
    delete[] move;
    return false;
}

bool
Solvable(int start, Vector<int> & squares){
    Set<int> INDEX_SET;
    return Solvable_Inner(start, squares, INDEX_SET);
}

void
CutStock_Inner(Vector<int> & requests, int &remindLength, int &count, int Length){
    if(requests.isEmpty()){
        if(remindLength > 0) count++;
        return;
    }
    int max = 0;
    int index = 0;
    for(int i = 0; i < requests.size(); i++){
        if(remindLength >= requests[i] && requests[i]> max) {
            max = requests[i];
            index = i;
        }
    }
    remindLength -= max;
    if(remindLength >= 0) requests.remove(index);
    if(remindLength <= 0){
        count++;
        remindLength = Length;
    }
    CutStock_Inner(requests, remindLength, count, Length);
}

int
CutStock(Vector<int> & requests, int stockLength){
    int count = 0;
    int remindLength = stockLength;
    int Length = stockLength;
    Vector<int> request = *&requests;
    CutStock_Inner(request, remindLength, count, Length);
    return count;
}
