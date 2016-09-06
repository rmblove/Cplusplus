//
//  TextGenerator.hpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/6.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#ifndef _textgenerator_hpp
#define _textgenerator_hpp

#include <stdio.h>
#include <string>
#include "map.h"
#include "vector.h"

class TextGenerator{
public:
    TextGenerator();
    
    TextGenerator(int odr);
    
    virtual ~TextGenerator();
    
    void start(int numch);
    
    int getOrder();
    
    void setOrder(int odr);
    
    Vector<char> getChars(std::string key); //give key which lenth is same as order and get a expect chars.
    
    
private:
    int DEFAULT_ORDER = 2;
    
    std::string SOURCE = "/Users/xiaoweibin/Desktop/C++/StanfordCPPLib/resource/A Bible Hand-Book by F. C. Holliday.txt";
    
    Map<std::string, Vector<char> > textmap ;
    
    
    
};

#endif /* _textgenerator_hpp */
