#pragma once
# include <iostream>
#include<fstream>
#include<istream>
#include<string>

class Person {
public:
	std::string name;
	std::string mail;
	std::string gender = "-1"; // represent 0(male), 1(female)
	int* subject = new int[100]{ 0 };
};

class Student : public Person{
public:
	std::string id=0; // student number
	std::string password;
	std::string self_introduction;
	std::string mbti;
	//Student();
	//~Student();
};

class Professor : public Person {
public:
	std::string officeloc;
};
