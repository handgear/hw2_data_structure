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
    // Initialize an empty list
    head = new Node;
    assert(head);
    head->next = 0;
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

void Search::insertHistory(ListElementType &newHistory)
{
    // precondition: list is in order
    Link addedNode(new Node);
    assert(addedNode);
    // copy struct data
    addedNode->history = newHistory;

    // find the pointer to the node that is the predecessor
    // to the new node in the in-order list
    Link pred(head);
    // assertion: pred->elem <= addedNode->elem
    while (pred->next != 0 && pred->next->history.hits <= addedNode->history.hits)
        // loop invariant: pred->next != 0 && pred->next->elem <= elem
        pred = pred->next;
    // assertion 7-1: (pred->elem <= addedNode->elem) &&
    //    (addedNode->elem <= pred->next->elem || pred->next == 0) //pred가 새로운것 보다 작은지, 까지 도달했는지
    addedNode->next = pred->next;
    pred->next = addedNode;
    // assertion: pred->elem <= pred->next->elem &&
    //    (pred->next->elem <= pred->next->next->elem || pred->next->next == 0)
    
    // postcondition: list is in order, with elem added in proper position
}

void Search::printHistory(ListElementType &history){
    cout << "=====Print one history=====" << endl;
    cout << "-Keyword: " << history.keyWord \
    << "\n-Final webpage: " << history.finalWebPage \
    << "\n-Information: " << history.information \
    << "\n-Date: " << history.date \
    << "\n-Hits: " << history.hits << endl;
}

void Search::printAllHistory()
{
    assert(head); // if no head, something is very wrong!
    int index = 0;
    current = head->next;
    
    if(head->next == 0){
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

bool Search::first(ListElementType &history)
{
    // After calling first, current points to first item in list
    assert(head); // if no head, something is very wrong!
    
    if (head->next == 0)
        return false;
    else {
        current = head->next;
        history = current->history;
        return true;
    }
}





