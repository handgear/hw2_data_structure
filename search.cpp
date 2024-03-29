﻿//
//  search.cpp
//  hw2_data_structure
//
//  Created by Kwon Kiyong on 4/12/17.
//  Copyright © 2017 Kwon Kiyong. All rights reserved.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "search.hpp"
#include <iostream>
#include <string>
#include "assert.h"

using namespace cv;

Search::Search(){
    // Initialize an empty list
    head = new Node;
    assert(head);
    head->next = 0;
    tail = head;
    current = 0;
}
Search::~Search(){
    while(head->next !=0)
    {
        Link delNode = head;
        head = head->next;
        delete delNode;
    }
}

void Search::insertHistory(ListElementType &newHistory){
    // precondition: list is in order
    Link addedNode(new Node);
    assert(addedNode);
    // copy struct data
    addedNode->history = newHistory;

    // find the pointer to the node that is the predecessor
    // to the new node in the in-order list
    Link pred(head);
    // assertion: pred->elem <= addedNode->elem
    while (pred->next != 0 && pred->next->history.hits >= addedNode->history.hits){
        // loop invariant: pred->next != 0 && pred->next->elem >= elem
        pred = pred->next;
        // assertion 7-1: (pred->elem <= addedNode->elem) &&
        //    (addedNode->elem >= pred->next->elem || pred->next == 0) //pred가 새로운것 보다 큰지, 까지 도달했는지
    }
    
    if(pred == tail){
        tail = addedNode;
    }
    addedNode->next = pred->next;
    pred->next = addedNode;
    // assertion: pred->elem <= pred->next->elem &&
    //    (pred->next->elem <= pred->next->next->elem || pred->next->next == 0)
    
    // postcondition: list is in order, with elem added in proper position
}

void Search::printHistory(){
    cout << "=====Print current history=====" << endl;
    cout << "-Keyword: " << current->history.keyWord \
    << "\n-Final webpage: " << current->history.finalWebPage \
    << "\n-Information: " << current->history.information \
    << "\n-Date: " << current->history.date \
    << "\n-Hits: " << current->history.hits << endl;
}

void Search::printHistory(ListElementType &history){
    cout << "=====Print one history=====" << endl;
    cout << "-Keyword: " << history.keyWord \
    << "\n-Final webpage: " << history.finalWebPage \
    << "\n-Information: " << history.information \
    << "\n-Date: " << history.date \
    << "\n-Hits: " << history.hits << endl;
}

void Search::printAllHistory(){
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

int Search::printWithImg(){
    printHistory();

    string imgPath;
	imgPath = ".\\img\\" + current->history.img;

    Mat image;
	//cout << imgPath << endl;
	//getchar();
	
    image = imread(imgPath);
	if (!image.data){ // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
    namedWindow("Display window", WINDOW_AUTOSIZE);// Create a window for display.
    imshow("Display window", image); // Show our image inside it.
    waitKey(0);

    return 0;
}

bool Search::first(ListElementType &history){
    // After calling first, current points to first item in list
    assert(head); // if no head, something is very wrong!
    
    if (head->next == 0)
        return false;
    else {
        current = head->next; // copy head->next, because this list has dummy head
        history = current->history;
        return true;
    }
}

bool Search::last(ListElementType &history){
    // After calling last, current points to last item in list
    assert(tail); // if no tail, something is very wrong!
    
    if (head->next == 0)
        return false;
    else {
        current = tail;
        history = current->history;
        return true;
    }
}

bool Search::find(string keyword){
    assert(head); // if no head, something is very wrong!
    current = head->next;
    
    if(current == 0){
//        cout << "Empty List!" << endl;
        return false;
    }
    
    while(current != 0){
        size_t found = current->history.keyWord.find(keyword);
        if(found!=string::npos){
            return true;
        }
        current = current->next;
    }
    
//    cout << "No matching history" << endl;
    // return false when current reach to end of list
    return false;
}

bool Search::deleteHistory(string keyword){
    Link nodeToDel, pred = head;
    bool findResult;
    findResult = find(keyword);
    
    if(findResult == false)
        return false;
    
    nodeToDel = current;
    while(pred->next != nodeToDel){
        pred = pred->next;
    }
    
    pred->next = nodeToDel->next;

    delete nodeToDel;
    
    return true;
}

void Search::searchThenAdd(string keyword){
    History newHistory;
    newHistory.keyWord = keyword;
    newHistory.hits = 1;
    
    bool findResult;
    
    findResult = find(keyword);
    if(findResult == true){
        // Copy found node
        newHistory = current->history;
        // Increase hits
        newHistory.hits = newHistory.hits + 1;
        // Delete found node
        deleteHistory(keyword);
        // Insert found node
        insertHistory(newHistory);
    }
    else{
        //new info
        //insert newHistory
        insertHistory(newHistory);
    }
    
}

History Search::popHistory(){
    History historyToPop;
    
    // get first history in list
    first(historyToPop);
    
    deleteHistory(historyToPop.keyWord);
    
    return historyToPop;
}

void Search::AddAll(Search listToAdd){
    
    while(listToAdd.head->next != 0){
        History historyToInsert;
        historyToInsert = listToAdd.popHistory();
        insertHistory(historyToInsert);
    }

}

bool Search::findAndShowImage(string keyword){
    if(find(keyword)){
        printWithImg();
        return true;
    }
    else{
         //cout << "No matching history" << endl;
        return false;
    }
}
