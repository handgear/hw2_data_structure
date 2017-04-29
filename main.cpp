//
//  main.cpp
//  hw2_data_structure
//
//  Created by Kwon Kiyong on 4/10/17.
//  Copyright © 2017 Kwon Kiyong. All rights reserved.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "stdio.h"
#include "search.hpp"

using namespace cv;

int main(int argc, const char * argv[])
{
   
    Search search;
    
    History data = {"gtx 750 ti benchmark", "http://www.videocardbenchmark.net/gpu.php?gpu=GeForce+GTX+750+Ti", "Average G3D Mark 3696", "20170112", 9, "gtx750.jpg"};
    History data2 = {"오픈스택 공유 파일 시스템 (Manila)", "https://docs.openstack.org/mitaka/ko_KR/install-guide-obs/common/get_started_shared_file_systems.html", "파일 스토리지를 가상 머신에 제공합니다.", "20170122", 14, "manila.png"};
    History data3 = {"lenovo TS140 HDD 장착", "http://www.clien.net/cs2/bbs/board.php?bo_table=use&wr_id=738393", "2번 HDD 슬롯과 송풍용 프론트 팬 사이에 5번 HDD를 억지로 끼웠습니다", "20170130", 28, "ts140.jpg"};
    History data4 = {"바흐솔리스텐서울 음반", "http://blog.naver.com/audioguy1/220970898652", "오디오가이의 새로운 클래식 음악 신보", "20170216", 2, "bach.jpg"};

    search.insertHistory(data);
    search.insertHistory(data2);
    search.insertHistory(data3);
    search.insertHistory(data4);

	search.printAllHistory();

    cout << "click any key for continue" << endl;
    getchar();
    // problem 1
    cout << "======Problem 1. Inserting below history" << endl;
    History data5 = {"b85m", "http://www.asrock.com/mb/intel/b85m/", "Supports New 4th and 4th Generation Intel® Core™ Socket 1150", "20170226", 41, "b85m.jpg"};
    search.insertHistory(data5);
    search.printHistory(data5);

    cout << "======print all history with inserted data" << endl;
    search.printAllHistory();

    cout << "click any key for continue" << endl;
    getchar();
    // problem 2 (last)
    History firstHistory, lastHistory;
    
    search.first(firstHistory);
    search.last(lastHistory);  
    cout << "======Problem 2. print last history" << endl;
    search.printHistory(lastHistory);

    cout << "click any key for continue" << endl;
    getchar();
    // problem 3 (find)
    cout << "======Problem 3. find by keyword (ex: 'gtx')" << endl; 
    search.find("gtx");
    cout << "ptint current node(finded node)" << endl;
    search.printHistory();

    cout << "click any key for continue" << endl;
    getchar();
    // problem 4 (delete)
    cout << "======Problem 4. delete history (ex: delete 'gtx 750' history)" << endl;
    search.deleteHistory("gtx 750");
    cout << "print all after delete 'gtx 750' history" << endl;
    search.printAllHistory();
    
    cout << "click any key for continue" << endl;
    getchar();
    // problem 5 (delete)
    cout << "======Problem 5-1. search existing history (ex: search 'lenovo')" << endl;
    cout << "======before search" << endl;
    search.printAllHistory();
    cout << "======after search" << endl;
    search.searchThenAdd("lenovo");
    search.printAllHistory();

    cout << "click any key for continue" << endl;
    getchar();
    // Problem 5-2. 
    cout << "======Problem 5-1. search new keyword & add (ex: search 'github')" << endl;
    cout << "======before search" << endl;
    search.printAllHistory();
    cout << "======after search" << endl;
    search.searchThenAdd("github");
    search.printAllHistory();
    
    cout << "click any key for continue" << endl;
    getchar();
    // Problem 6. 
    cout << "======Problem 6. AddAll" << endl;

    // Make new list
    Search searchToAdd;
    History newData1 = {"e3-1231v3 benchmark", "https://cpubenchmark.net/cpu", "Average CPU Mark 9629", "20170330", 3, "e3-1231.jpg"};
    History newData2 = {"Xcode wakatime", "https://wakatime.com/help/plugins/xcode", "Run this Terminal command:", "20170401", 1, "wakatime.png"};

    searchToAdd.insertHistory(newData1);
    searchToAdd.insertHistory(newData2);

    cout << "======new list with 2 history" << endl;
    searchToAdd.printAllHistory();

    cout << "======after AddAll new list to original list" << endl;
    search.AddAll(searchToAdd);
    search.printAllHistory();

    cout << "click any key for continue" << endl;
    getchar();
    // Problem 6. 
    cout << "======Problem 7. findAndShowImage by opencv" << endl;
    cout << "======search 'e3-1231'" << endl;
    search.findAndShowImage("e3-1231");
    cout << "click any key for continue" << endl;
    getchar();

    cout << "======search 'Manila'" << endl;
    search.findAndShowImage("Manila");
    cout << "click any key for continue" << endl;
    getchar();

    cout << "======search 'HDD'" << endl;
    search.findAndShowImage("HDD");
    cout << "click any key for continue" << endl;   
    getchar();


    cout << "======Problem 8. INCOMPLETE / NOTHING TO SHOW" << endl;
    cout << "END OF THE PROJECT \n THANK YOU" << endl;
    cout << "click any key for termination" << endl;
    getchar();

    return 0;
}