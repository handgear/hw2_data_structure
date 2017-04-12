//
//  search.hpp
//  hw2_data_structure
//
//  Created by Kwon Kiyong on 4/12/17.
//  Copyright © 2017 Kwon Kiyong. All rights reserved.
//

#ifndef search_hpp
#define search_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct History{
    string keyWord;
    string finalWebPage;
    string information;
    string date;
    int hits;
    
    History& operator=(const History& a)
    {
        keyWord = a.keyWord;
        finalWebPage = a.finalWebPage;
        information = a.information;
        date = a.date;
        hits = a.hits;
        return *this;
    }
};
typedef History ListElementType;

class Search{
private:
    struct Node; // declaration without definition
    typedef Node *Link; // use declaration of Node
    struct Node { // now we define Node
        ListElementType history;
        Link next;
    };
    Link head;
    Link tail;
    Link current;

public:
    Search();
    ~Search();
    void insertHistory(string keyword, string webpage, string info, string date, int hits);
//    void printHistory(int index);
    void printAllHistory();
//    int searchKeyInfoField(string hintWord);
    //int search
    
    
};

#endif /* search_hpp */
