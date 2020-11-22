#include "SE271.h"
#include <sstream>

void open_csv(std::string filename) {
    std::string str_buf;
    std::fstream fs;
    std::istringstream iss(str_buf);
    std::string token;
    std::string mbti_arr[32][32];
    int i = 0; int j = 0; // for loop

    fs.open(filename, std::ios::in);

    while (!fs.eof()) {
        getline(fs, str_buf);
        std::istringstream iss(str_buf);
        while (getline(iss, token, ',')) {
            std::cout << token << std::endl;
            mbti_arr[j][i] = token;
            ++i;
        } ++j;
    }
    for (int k = 0; k < 16; ++k) {
        for (int l = 0; l < 16; ++l) {
            std::cout << mbti_arr[k][l] << '\n';
        }
    } // 공백 발생하는 문제
    fs.close();
}