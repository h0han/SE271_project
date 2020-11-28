#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>

#ifndef SE271_PROJECT
#define SE271_PROJECT

class Person {
public:
	std::string name;
	std::string gender; // represent 0(male), 1(female)
	std::string mail;
	std::string mbti;
	int* subject = new int[100]{ 0 };
};

class Student : public Person {
public:
	std::string id; // student number
	std::string password;
	std::string self_introduction;
	double score = 0;

	bool operator <(Student& student);
};

void open_csv_and_make_object(Student students[], std::string filename);
void Menuselect(Student students[], int& num);
int get_number_of_students();
#endif