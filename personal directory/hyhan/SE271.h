#pragma once
# include <iostream>

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
	int match_mbti(); // return resemblance of mbti
};

#endif