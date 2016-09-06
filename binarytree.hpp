//
//  binarytree.hpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/10.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#ifndef _binarytree_h
#define _binarytree_h


#include <stdio.h>
#include <iostream>
#include <string>


template <typename ValType>
class BinaryTree {
    
    
public:
    BinaryTree();
    ~BinaryTree();
    
    ValType getValue(std::string key);
    
    void print();//preorder print binary tree
    
    void add(std::string key, ValType value);
    
    void remove(std::string key);
    
private:
    struct Tnode{
        std::string key;
        ValType value;
        Tnode *left;
        Tnode *right;
    };
    Tnode *root;
    Tnode *Search(Tnode *t, std::string key);
    
    void freeTree(Tnode * & t);
    void InsertKey(Tnode * & t, std::string key, ValType value);
    void InsertTnode(Tnode * & t, Tnode * & n);
    void printTree(Tnode * & t);
    void deleteTnode(Tnode * & t, std::string key);
    
};

template <typename ValType>
BinaryTree<ValType>::BinaryTree(){}

template <typename ValType>
BinaryTree<ValType>::~BinaryTree(){
    BinaryTree<ValType>::freeTree(root);
}

template <typename ValType>
void
BinaryTree<ValType>::add(std::string key, ValType value){
    BinaryTree<ValType>::InsertKey(root, key, value);
}

template <typename ValType>
void
BinaryTree<ValType>::remove(std::string key){
    BinaryTree<ValType>::deleteTnode(root, key);
}

template <typename ValType>
void
BinaryTree<ValType>::print(){
    BinaryTree<ValType>::printTree(root);
}

template <typename ValType>
void
BinaryTree<ValType>::freeTree(Tnode * & t){
    if(t != NULL){
        freeTree(t->left);
        freeTree(t->right);
        delete t;
    }
}

template <typename ValType>
ValType
BinaryTree<ValType>::getValue(std::string key){
    if(Tnode *p = BinaryTree<ValType>::Search(root, key) != NULL)
        return p->value;
    std::cerr << "The key is not exist in the tree." << std::endl;
}


template <typename ValType>
void
BinaryTree<ValType>::printTree(Tnode * & t){
    if(t != NULL){
        printTree(t->left);
        std::cout << t->key << std::endl;
        printTree(t->right);
    }
}

template <typename ValType>
typename BinaryTree<ValType>::Tnode
*BinaryTree<ValType>::Search(Tnode *t, std::string key){
    if(t == NULL) return NULL;
    if(key == t->key) return t;
    if(key < t->key) return Search(t->left, key);
    else return Search(t->right, key);
}

template <typename ValType>
void
BinaryTree<ValType>::InsertKey(Tnode * & t, std::string key, ValType value){
    
    if(t == NULL) {
        t = new Tnode;
        t->key = key;
        t->value = value;
        t->right = NULL;
        t->left = NULL;
    }
    
    else if(key == t->key) t->value = value;
    
    else if(key < t->key) {
        InsertKey(t->left, key, value);
    }
    else {
        InsertKey(t->right, key, value);
    }
    
}

template <typename ValType>
void
BinaryTree<ValType>::InsertTnode(Tnode * & t, Tnode * & n){
    
    if(t == NULL) {
        t = n;
    }
    else if(n->key < t->key) {
        InsertTnode(t->left, n);
    }
    else {
        InsertTnode(t->right, n);
    }
    
}


template <typename ValType>
void
BinaryTree<ValType>::deleteTnode(Tnode * & t, std::string key){
    if(key == t->key){
        Tnode *old = t;
        if(t->right == NULL && t->left == NULL){
            std::cout << "The tree has been removed." << std::endl;
            t = NULL;
        }
        else if(old->right != NULL) {
            t = old->right;
            if(old->left != NULL) BinaryTree<ValType>::InsertTnode(t, old->left);
        }
        else if(old->left != NULL) {
            t = old->left;
            if(old->right != NULL) BinaryTree<ValType>::InsertTnode(t, old->right);
        }
        delete old;
        return;
    }
    else if(key < t->key){
        if(t->left == NULL){
            std::cout << "Nothing to be removed in the tree." << std::endl;
            return;
        }
        else if(key == t->left->key){
            Tnode *old = t->left;
            t->left = NULL;
            if(old->right != NULL) BinaryTree<ValType>::InsertTnode(t, old->right);
            if(old->left != NULL) BinaryTree<ValType>::InsertTnode(t, old->left);
            delete old;
            return;
        }
        deleteTnode(root->left, key);
    }
    else {
        if(t->right == NULL){
            std::cout << "Nothing to be removed in the tree." << std::endl;
            return;
        }
        else if(key == t->right->key){
            Tnode *old = t->right;
            t->right = NULL;
            if(old->right != NULL) BinaryTree<ValType>::InsertTnode(t, old->right);
            if(old->left != NULL) BinaryTree<ValType>::InsertTnode(t, old->left);
            delete old;
            return;
        }
        deleteTnode(root->right, key);
    }
}

#endif /* _binarytree_h */
