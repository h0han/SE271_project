#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <cstring>
#include <sstream>

#ifndef	SE271_PROJECT
#define SE271_PROJECT

class Student {
public:
	int id; // student number
	int gender; // represent 0(male), 1(female)
	std::string name;
	std::string password;
	std::string mail;
	std::string mbti;
	int sub_score;
	int* subject;
	std::string self_introduction;
	int match();
	double match_mbti(std::string, std::string); // return resemblance of mbti
	void csv_to_arr(std::string filename);
};

#endif