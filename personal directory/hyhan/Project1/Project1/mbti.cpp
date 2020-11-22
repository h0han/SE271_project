#include "SE271.h"

#include <iostream>
#include <string>
#include <typeinfo>
#include <stdlib.h>

std::string mbti_arr[32][32];

void csv_to_arr(std::string filename) {
    std::string str_buf;
    std::fstream fs;
    std::istringstream iss(str_buf);
    std::string token;
    int i = 0; int j = 0; // for loop

    fs.open(filename, std::ios::in);

    while (!fs.eof()) {
        i = 0;
        getline(fs, str_buf);
        std::istringstream iss(str_buf);
        while (getline(iss, token, ',')) {
            mbti_arr[j][i] = token;
            ++i;
        } ++j;
    }
    fs.close();
}

std::string upper(std::string str) {
	int i;
	for (i = 0; i < str.size(); ++i) {
		if (islower(str[i])) {
			str[i] = toupper(str[i]);
		}
	} return str;
}

double match_mbti(std::string mbti1, std::string mbti2) {
	csv_to_arr("mbti.csv");
	int i; int j; // for loop
	int idx1 = 0; int idx2 = 0; // array에서의 해당 mbti의 index
	double m_val; // 두 mbti의 매칭 정도
	std::string mbti_1 = upper(mbti1); std::string mbti_2 = upper(mbti2); // mbti가 소문자이면 대문자로 변경
	for (i = 0; i < 16; ++i) { // 16개의 mbti 성향 중 각 parameter의 index를 지정한다.
		if (mbti_arr[0][i].compare(mbti_1) == 0) { idx1 = i; }
		if (mbti_arr[0][i].compare(mbti_2) == 0) { idx2 = i; }
	}
	m_val = atof(mbti_arr[idx2][idx1].c_str());
	return m_val;
}