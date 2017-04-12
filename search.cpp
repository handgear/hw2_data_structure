//
//  search.cpp
//  hw2_data_structure
//
//  Created by Kwon Kiyong on 4/12/17.
//  Copyright © 2017 Kwon Kiyong. All rights reserved.
//

#include "search.hpp"
#include <iostream>
#include <string>
#include "assert.h"

Search::Search()
{
    // Initialize an empty List
    head = 0;
    tail = 0;
    current = 0;
}
Search::~Search()
{
    while(head !=0)
    {
        Link delNode = head;
        head = head->next;
        delete delNode;
    }
}

void Search::insertHistory(string keyword, string webpage, string info, string date, int hits)
{
    // precondition: list is in order
    Link addedNode(new Node);
    assert(addedNode);
    addedNode->history.keyWord = keyword; //데이터 적기
    addedNode->history.finalWebPage = webpage;
    addedNode->history.information = info;
    addedNode->history.date = date;
    addedNode->history.hits = hits;
    // Special case: if the existing list is empty, or if the new data
    // is less than the smallest item in the list, the new node is added
    // to the front of the list
    if (head == 0 || hits <= head->history.hits) { //최초로 넣는 경우, 내가 가장 작을 떄
        addedNode->next = head;
        head = addedNode;
    }
    else { //중간 적당한 위치에 넣는 경우
        // find the pointer to the node that is the predecessor
        // to the new node in the in-order list
        Link pred(head);
        // assertion: pred->elem <= addedNode->elem
        while (pred->next != 0 && pred->next->history.hits <= addedNode->history.hits)
            // loop invariant: pred->next != 0 && pred->next->elem <= elem
            pred = pred->next;
        // assertion 7-1: (pred->elem <= addedNode->elem) &&
        //    (addedNode->elem <= pred->next->elem || pred->next == 0) //pred가 새로운것 보다 작은지, 끝까지 도달했는지
        addedNode->next = pred->next;
        pred->next = addedNode;
        // assertion: pred->elem <= pred->next->elem &&
        //    (pred->next->elem <= pred->next->next->elem || pred->next->next == 0)
    }
    // postcondition: list is in order, with elem added in proper position
}

void Search::printAllHistory()
{
    int index = 0;
    current = head;
    
    if(head == 0){
        cout << "No saved history" << endl;
        return;
    }
    
    while(current != 0){
        
        cout << "Index: " << index << endl;
        cout << "-Keyword: " << current->history.keyWord \
        << "\n-Final webpage: " << current->history.finalWebPage \
        << "\n-Information: " << current->history.information \
        << "\n-Date: " << current->history.date \
        << "\n-Hits: " << current->history.hits << endl;
        
        index++;
        current = current->next;
    }
}





