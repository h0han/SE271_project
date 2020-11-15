#pragma once
# include <iostream>
#include<fstream>
#include<istream>
#include<string>

class Student {
public:
	int id=0; // student number
	int gender=-1; // represent 0(male), 1(female)
	std::string password;
	std::string name;
	std::string mail;
	std::string mbti;
	int* subject = new int[100]{0};
	std::string self_introduction;
	//Student();
	//~Student();
};