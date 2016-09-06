//
//  redblackTree.hpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/9.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#ifndef _redblackTree_hpp
#define _redblackTree_hpp

#include <stdio.h>
#include <iostream>
#include <string>

template <typename ValType>
class RedBlackTree {
    
    
public:
    RedBlackTree();
    ~RedBlackTree();
    
    ValType getValue(std::string key);
    
    void print();
    
    void add(std::string key, ValType value);
    
    void remove(std::string key);
    
    void test();
    
private:
    enum COLOR {RED, BLACK};
    enum POS {RIGHT, LEFT, ROOT};
    enum CASE {CASE1, CASE2, CASE3, CASE4, CASE5, CASE6};
    struct Tnode{
        std::string key;
        ValType value;
        Tnode *left;
        Tnode *right;
        Tnode *parent;
        COLOR color;
        POS position;
    };
    Tnode *root;
    Tnode *Search(Tnode *t, std::string key);
    
    void freeTree(Tnode * & t);
    void InsertKey(Tnode * & t, std::string key, ValType value);
    void Insertnode(Tnode * & t, Tnode * n);
    
    void InsertRefnode(Tnode * & t, Tnode * & n);
    void deleteTnode(Tnode * & t, std::string key);
    void printTree(Tnode * & t);

    
    void maintain(Tnode * & n);
    void rotateright(Tnode * & t, Tnode * & n);
    void rotateleft(Tnode * & t, Tnode * & n);
    void docase(CASE c, Tnode * & n);
    
    
};

template <typename ValType>
void
RedBlackTree<ValType>::test(){
    Tnode *p = RedBlackTree<ValType>::Search(root, "5");
    RedBlackTree<ValType>::rotateleft(root, p);
    //RedBlackTree<ValType>::rotateright(root, p);

}


template <typename ValType>
RedBlackTree<ValType>::RedBlackTree(){}

template <typename ValType>
RedBlackTree<ValType>::~RedBlackTree(){
    RedBlackTree<ValType>::freeTree(root);
}

template <typename ValType>
void
RedBlackTree<ValType>::add(std::string key, ValType value){
    RedBlackTree<ValType>::InsertKey(root, key, value);
    root->color = BLACK;
    root->position = ROOT;
}

template <typename ValType>
void
RedBlackTree<ValType>::maintain(Tnode * & n){
    while (n->position != ROOT && n->color == BLACK){
        if(n->parent->position == LEFT){
            Tnode *y = n->parent->parent->right;
            if(y->color == RED) RedBlackTree<ValType>::docase(CASE1, n);
            else if (n->position == RIGHT) RedBlackTree<ValType>::docase(CASE2, n);
            RedBlackTree<ValType>::docase(CASE3, n);
        }
        else{
            Tnode *y = n->parent->parent->left;
            if(y->color == RED) RedBlackTree<ValType>::docase(CASE4, n);
            else if (n->position == LEFT) RedBlackTree<ValType>::docase(CASE5, n);
            RedBlackTree<ValType>::docase(CASE6, n);

        }
    }
}

template <typename ValType>
void
RedBlackTree<ValType>::remove(std::string key){
    RedBlackTree<ValType>::deleteTnode(root, key);
}

template <typename ValType>
void
RedBlackTree<ValType>::print(){
    RedBlackTree<ValType>::printTree(root);
}

template <typename ValType>
void
RedBlackTree<ValType>::freeTree(Tnode * & t){
    if(t != NULL){
        freeTree(t->left);
        freeTree(t->right);
        delete t;
    }
}

template <typename ValType>
ValType
RedBlackTree<ValType>::getValue(std::string key){
    if(Tnode *p = RedBlackTree<ValType>::Search(root, key) != NULL)
        return p->value;
    std::cerr << "The key is not exist in the tree." << std::endl;
}


template <typename ValType>
void
RedBlackTree<ValType>::printTree(Tnode * & t){
    if(t != NULL){
        printTree(t->left);
        std::cout << t->key << std::endl;
        printTree(t->right);
    }
}

template <typename ValType>
typename RedBlackTree<ValType>::Tnode
*RedBlackTree<ValType>::Search(Tnode *t, std::string key){
    if(t == NULL) return NULL;
    if(key == t->key) return t;
    if(key < t->key) return Search(t->left, key);
    else return Search(t->right, key);
}

template <typename ValType>
void
RedBlackTree<ValType>::Insertnode(Tnode * & t, Tnode * n){
    
    if(t == NULL) {
        t = n;
    }
    else if(n->key < t->key) {
        n->parent = t;
        n->position = LEFT;
        Insertnode(t->left, n);
    }
    else {
        n->parent = t;
        n->position = RIGHT;
        Insertnode(t->right, n);
    }
    
}

template <typename ValType>
void
RedBlackTree<ValType>::InsertKey(Tnode * & t, std::string key, ValType value){
    typename RedBlackTree<ValType>::Tnode *n;
    n = new Tnode;
    n->key = key;
    n->value = value;
    n->color = RED;
    n->right = NULL;
    n->left = NULL;
    RedBlackTree<ValType>::Insertnode(root, n);
    RedBlackTree<ValType>::maintain(n);
}

template <typename ValType>
void
RedBlackTree<ValType>::rotateright(Tnode *&t, Tnode *&n){
    if(n->position == ROOT){
        t = n->left;
        n->left = t->right;
        if(n->right != NULL){
            t->right->parent = n;
            t->right->position = LEFT;
        }
        t->right = n;
        n->parent = t;
        n->position = RIGHT;
        
        t->parent = NULL;
        t->position = ROOT;
    }
    else{
        Tnode *m = n->left;
        n->left = m->right;
        if(m->right != NULL){
            m->right->parent = n;
            m->right->position = LEFT;
        }
        m->right = n;
        n->parent = m;
        n->position = RIGHT;
        
    }
}

template <typename ValType>
void
RedBlackTree<ValType>::rotateleft(Tnode *&t, Tnode *&n){
    if(n->position == ROOT){
        t = n->right;
        n->right = t->left;
        if(n->left != NULL){
            t->left->parent = n;
            t->left->position = RIGHT;
        }
        t->left = n;
        n->parent = t;
        n->position = LEFT;
        
        t->parent = NULL;
        t->position = ROOT;
    }
    else{
        Tnode *m = n->right;
        n->right = m->left;
        if(m->left != NULL){
            m->left->parent = n;
            m->left->position = RIGHT;
        }
        m->left = n;
        n->parent = m;
        n->position = LEFT;
        
    }
}

template <typename ValType>
void
RedBlackTree<ValType>::docase(CASE c, Tnode * & n){
    if(c == CASE1){
        n = n->parent->parent;
        n->color = RED;
        n->left->color = BLACK;
        n->right->color = BLACK;
    }
    else if (c == CASE2){
        RedBlackTree<ValType>::rotateleft(root, n->parent);
    }
    else if (c == CASE3){
        RedBlackTree<ValType>::rotateright(root, n->parent->parent);
        n->color = BLACK;
        n->left->color = RED;
        n->right->color = RED;
    }
    else if(c == CASE4){
        n = n->parent->parent;
        n->color = RED;
        n->right->color = BLACK;
        n->left->color = BLACK;
    }
    else if (c == CASE5){
        RedBlackTree<ValType>::rotateright(root, n->parent);
    }
    else if (c == CASE6){
        RedBlackTree<ValType>::rotateleft(root, n->parent->parent);
        n->color = BLACK;
        n->left->color = RED;
        n->right->color = RED;
    }
    
}



template <typename ValType>
void
RedBlackTree<ValType>::InsertRefnode(Tnode * & t, Tnode * & n){
    
    if(t == NULL) {
        t = n;
    }
    else if(n->key < t->key) {
        n->parent = t;
        n->position = LEFT;
        InsertRefnode(t->left, n);
    }
    else {
        n->parent = t;
        n->position = RIGHT;
        InsertRefnode(t->right, n);
    }
    
}




template <typename ValType>
void
RedBlackTree<ValType>::deleteTnode(Tnode * & t, std::string key){
    if(key == t->key){
        Tnode *old = t;
        if(t->right == NULL && t->left == NULL){
            std::cout << "The tree has been removed." << std::endl;
            t = NULL;
        }
        else if(old->right != NULL) {
            t = old->right;
            if(old->left != NULL) RedBlackTree<ValType>::InsertRefnode(t, old->left);
        }
        else if(old->left != NULL) {
            t = old->left;
            if(old->right != NULL) RedBlackTree<ValType>::InsertRefnode(t, old->right);
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
            if(old->right != NULL) RedBlackTree<ValType>::InsertRefnode(t, old->right);
            if(old->left != NULL) RedBlackTree<ValType>::InsertRefnode(t, old->left);
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
            if(old->right != NULL) RedBlackTree<ValType>::InsertRefnode(t, old->right);
            if(old->left != NULL) RedBlackTree<ValType>::InsertRefnode(t, old->left);
            delete old;
            return;
        }
        deleteTnode(root->right, key);
    }
}




#endif /* _redblackTree_hpp */
