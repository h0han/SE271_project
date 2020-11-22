#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <sstream>

#ifndef SE271_PROJECT
#define SE271_PROJECT

class Student {
public:
	std::string id; // student number
	std::string password;
	std::string name;
	std::string gender; // represent 0(male), 1(female)
	std::string mail;
	std::string mbti;
	std::string self_introduction;
	int* subject = new int[100]{ 0 };
};

void open_csv_and_make_object(Student students[], std::string filename);
void Menuselect(Student students[], int& num);
int get_number_of_students();
#endif