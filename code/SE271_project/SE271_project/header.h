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
	int* subject = new int[100]{ 0 };
};

class Student : public Person {
public:
	std::string id = "0"; // student number
	std::string password;
	std::string mbti;
	std::string self_introduction;
	double score = 0;
	bool operator <(Student& student);
};

class Professor : public Person {
public:
	std::string officeloc;
};

void MakeObject(Student students[], std::string filename);
void MakeProfessor(Professor[]);
void Menuselect(Student students[], Professor[]);
int toHash(std::string);
#endif