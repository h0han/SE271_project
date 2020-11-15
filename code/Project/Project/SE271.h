#pragma once
# include <iostream>

class Student {
public:
	int id; // student number
	int gender; // represent 0(male), 1(female)
	std::string name;
	std::string mail;
	std::string mbti;
	int* subject;
	std::string self_introduction;

};
