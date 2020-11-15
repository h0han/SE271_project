#pragma once
#include<iostream>
#include<fstream>
#include<istream>
#include<string>

#ifndef SE271_PROJECT
#define SE271_PROJECT

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

void open_csv(std::string filename);

#endif