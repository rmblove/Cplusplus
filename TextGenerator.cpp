//
//  TextGenerator.cpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/6.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#include "TextGenerator.hpp"
#include <fstream>
#include <string>
#include "random.h"
#include "strlib.h"

TextGenerator::TextGenerator(){
    TextGenerator(DEFAULT_ORDER);
}

TextGenerator::TextGenerator(int odr){
    DEFAULT_ORDER = odr;
    std::ifstream in(SOURCE);
    char c;
    std::string s;
    s.resize(DEFAULT_ORDER);
    while (in.get(c)) {
        textmap[s].add(c);
        //std::cout << c;
        s = s.substr(1) + c;
    }
    in.close();
}

TextGenerator::~TextGenerator(){}



void
TextGenerator::start(int numch){
    std::string key = randomElement(textmap.keys());
    for(int i = 0; i < numch; i++){
        char c = randomElement(textmap[key]);
        std::cout << c;
        key = key.substr(1) + c;
    }
    
}

int
TextGenerator::getOrder(){
    return DEFAULT_ORDER;
}

void
TextGenerator::setOrder(int odr){
    textmap.clear();
    DEFAULT_ORDER = odr;
    TextGenerator();    
}

Vector<char>
TextGenerator::getChars(std::string key){
    if(key.length() != DEFAULT_ORDER){
        std::cerr << "You should type a key length :" << DEFAULT_ORDER;
    }
    return textmap[key];
}