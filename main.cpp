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
    
    History data = {"gtx 750 ti benchmark", "http://www.videocardbenchmark.net/gpu.php?gpu=GeForce+GTX+750+Ti", "Average G3D Mark 3696", "20170112", 9, "1.jpg"};
    History data2 = {"오픈스택 공유 파일 시스템 (Manila)", "https://docs.openstack.org/mitaka/ko_KR/install-guide-obs/common/get_started_shared_file_systems.html", "파일 스토리지를 가상 머신에 제공합니다.", "20170122", 10, "1.jpg"};
    History data3 = {"lenovo TS140 HDD 장착", "http://www.clien.net/cs2/bbs/board.php?bo_table=use&wr_id=738393", "2번 HDD 슬롯과 송풍용 프론트 팬 사이에 5번 HDD를 억지로 끼웠습니다", "20170130", 8, "1.jpg"};
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


	//===============================================//
	// Mat image;

	// //image = imread("C:\\Users\\handgear\\Documents\\Visual Studio 2015\\Projects\\hw2_data_structure\\hw2_data_structure\\img\\1.jpg"); // Read the file
	// image = imread(".\\img\\1.jpg");

	// 	if (!image.data) // Check for invalid input

	// 	{

	// 		cout << "Could not open or find the image" << std::endl;

	// 		return -1;

	// 	}

	// namedWindow("Display window", WINDOW_AUTOSIZE);// Create a window for display.



	// 	imshow("Display window", image); // Show our image inside it.

	// 	waitKey(0);
	search.first(firstHistory);
    search.printWithImg();

    return 0;
}



