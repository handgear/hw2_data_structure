//
//  main.cpp
//  hw2_data_structure
//
//  Created by Kwon Kiyong on 4/10/17.
//  Copyright © 2017 Kwon Kiyong. All rights reserved.
//

#include <iostream>
#include "stdio.h"
#include "search.hpp"

int main(int argc, const char * argv[])
{
   
    Search search;
    
    History data = {"gtx 750 ti benchmark", "http://www.videocardbenchmark.net/gpu.php?gpu=GeForce+GTX+750+Ti", "Average G3D Mark 3696", "20170112", 9};
    History data2 = {"오픈스택 공유 파일 시스템 (Manila)", "https://docs.openstack.org/mitaka/ko_KR/install-guide-obs/common/get_started_shared_file_systems.html", "파일 스토리지를 가상 머신에 제공합니다. 공유 파일 시스템 서비스는 파일 공유에 대한 관리 및 프로비저닝을 합니다.", "20170122", 10};
    History data3 = {"lenovo TS140 HDD 장착", "http://www.clien.net/cs2/bbs/board.php?bo_table=use&wr_id=738393", "2번 HDD 슬롯과 송풍용 프론트 팬 사이에 5번 HDD를 억지로 끼웠습니다", "20170130", 8};
    search.insertHistory(data);
    search.insertHistory(data2);
//    search.insertHistory(data3);
    
    History firstHistory, lastHistory;
    
    search.first(firstHistory);
    search.last(lastHistory);
    
    search.printAllHistory();
//    search.printHistory(firstHistory);
//    search.printHistory(lastHistory);
    
//    search.find("gtx 750");
//    
//    search.printHistory();
    cout << "==========================" << endl;
//    search.deleteHistory("gtx 750");
//    search.printAllHistory();
    
//    search.searchThenAdd("gtx");
//    search.printAllHistory();
    

//    History temp;
//    temp  = search.popHistory();
//    search.printHistory(temp);
//    cout << "==========================" << endl;
//    search.printAllHistory();
    
    
    Search searchToAdd;
    searchToAdd.insertHistory(data3);
    
    cout << "=======searchToAdd=======" << endl;
    searchToAdd.printAllHistory();
    
    search.AddAll(searchToAdd);
    cout << "=======search=======" << endl;
    search.printAllHistory();
    
	getchar();

    return 0;
}



