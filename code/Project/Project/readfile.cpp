//#include "SE271.h"
//#include <sstream>
//
//void csv_to_arr(std::string filename) {
//    std::string str_buf;
//    std::fstream fs;
//    std::istringstream iss(str_buf);
//    std::string token;
//    std::string mbti_arr[20][20];
//    int i = 0; int j = 0; // for loop
//
//    fs.open(filename, std::ios::in);
//
//    while (!fs.eof()) {
//        i = 0;
//        getline(fs, str_buf);
//        std::istringstream iss(str_buf);
//        while (getline(iss, token, ',')) {
//            mbti_arr[j][i] = token;
//            ++i;
//        } ++j;
//    }
//    fs.close();
//}