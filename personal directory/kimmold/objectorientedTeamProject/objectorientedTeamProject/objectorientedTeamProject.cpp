// objectorientedTeamProject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ootp.h"
#include <sstream>
#include <fstream>
#include <istream>
#include <vector>

int professroNo;

int HashFunc(int n) {
	int year, last3;
	year = (n / 100000) % 100;
	last3 = n % 1000;
	return (year - 18) * 300 + last3;
}
std::vector<std::string> split(std::string input, char delimiter) {
	std::vector<std::string> answer;
	std::stringstream ss(input);
	std::string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}

void open_csv(std::string filename) {
	std::string str_buf;
	std::fstream fs;
	std::istringstream iss(str_buf);
	std::string token;

	fs.open(filename, std::ios::in);

	while (!fs.eof()) {
		getline(fs, str_buf);
		std::istringstream iss(str_buf);
		while (getline(iss, token, ',')) {
			std::cout.width(30);
			std::cout <<std::left<< token;
		}
		std::cout<< std::endl;
	}
	fs.close();
}
//void Getstudents(Student studnets[]) {
//}

void Inputsubject(Student students[], int& num, std::string sub[]) {
	int idx = 0;
	for (int i = 0; i <= 4; i++) {
		idx = std::atoi(&sub[i][1]);
		if (sub[i][0] == 'A') students[num].subject[idx - 1]=1;
		if (sub[i][0] == 'B') students[num].subject[15 + idx]=1;
		if (sub[i][0] == 'C') students[num].subject[34 + idx]=1;
		if (sub[i][0] == 'D') students[num].subject[46 + idx]=1;
		if (sub[i][0] == 'E') students[num].subject[63 + idx]=1;
		if (sub[i][0] == 'F') students[num].subject[81 + idx]=1;
	}
}

void Inputsubject2(Student students[], int& num, char sub) {
	for (int i = 0; i <= 4; i++) {
		if (sub == 'A') for (int i = 0; i <= 15;i++) students[num].subject[i] = -1;
		if (sub == 'B') for (int i = 16; i <= 34; i++) students[num].subject[i] = -1;
		if (sub == 'C') for (int i = 35; i <= 46; i++) students[num].subject[i] = -1;
		if (sub == 'D') for (int i = 47; i <= 63; i++) students[num].subject[i] = -1;
		if (sub == 'E') for (int i = 64; i <= 81; i++) students[num].subject[i] = -1;
		if (sub == 'F') for (int i = 82; i <= 99; i++) students[num].subject[i] = -1;
	}
}


void Signup(Student students[], int& num) {
	std::string sub[7];
	char hate;
	std::cout << "학번을 입력해주세요." << std::endl;
	std::cin >> students[0].id;
	if (std::cin.fail())
	{
		std::cout << "error" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		Signup(students, num);
	}
	std::cout << "비밀번호를 입력해주세요." << std::endl;
	std::cin >> students[num].password;
	std::cout << "이름을 입력해주세요." << std::endl;
	std::cin >> students[num].name;
	while (students[num].gender != 1 && students[num].gender != 0) {
		std::cout << "성별를 입력해주세요.(남자는 0, 여자는 1)" << std::endl;
		std::cin >> students[num].gender;
	}
	std::cout << "학교 이메일을 입력해주세요." << std::endl;
	std::cin >> students[num].mail;
	std::cout << "본인의 mbti을 입력해주세요." << std::endl;
	std::cin >> students[num].mbti;
	open_csv("subject_code.csv");
	std::cout << "좋아하는 과목 5개를 골라주세요." << std::endl;
	std::cin >> sub[0] >> sub[1] >> sub[2] >> sub[3] >> sub[4];
	Inputsubject(students, num, sub);
	
	std::cout << "싫어하는 분야 1개를 골라주세요." << std::endl;
	std::cin >> hate;
	Inputsubject2(students, num, hate);

	std::cout << "자기소개한말씀!" << std::endl;
	std::cin >> students[num].self_introduction;
	num++;
	std::cout <<std::endl<<"회원가입이 완료되었습니다. 로그인 후 이용해주세요." << std::endl;
}

bool Login(Student students[], int id, std::string password, int& num) {
	for (int i = 0; i < num; i++) {
		if (students[i].id == id) {
			if (students[i].password == password) {
				for (int j = 0; j < 99; j++)std::cout << students[i].subject[j] << ' ';
				return true;
			}
			else return false;
		}
	}
	return false;
}

void open_csv_and_make_object(Professor professors[]) {
	std::string filePath = "professor_database.csv";
	std::ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		professroNo = 0;
		std::string line;
		while (getline(openFile, line)) {
			std::vector<std::string> row = split(line, ',');
			professors[professroNo].name = row[0];
			professors[professroNo].gender = row[1];
			professors[professroNo].mail = row[2];

			for (int idx = 0; idx < 100; idx++) {
				professors[professroNo].subject[idx] = std::atoi((row[3 + idx]).c_str());
			}
			professors[professroNo].officeloc = row[103];
			professroNo++;
		}
		openFile.close();
	}
}

void Showprofessor(Professor professors[],Student student ){

	for (int i = 0; i < professroNo; i++) {
		for (int j = 0; j < 100; j++) {
			if (professors[i].subject[j] == 1 && student.subject[j] >= 1) {
				std::cout << "매칭된 교수님!" << std::endl;
				std::cout << "성함 : " << professors[i].name << std::endl;
				std::cout << "이메일 : " << professors[i].mail << std::endl;
				std::cout << "오피스 위치 : " << professors[i].officeloc << std::endl;
			}
		}
	}
}



void Menuselect(Student students[], int& num) {
	int menuchoice = 0;
	int id;
	std::string password;
	while (menuchoice != 4) {
		std::cout << "1.회원가입 2.로그인 3.사람 찾기 4.교수 찾기 5.종료" << std::endl;
		std::cin >> menuchoice;
		if (menuchoice != 1 && menuchoice != 2 && menuchoice != 3 && menuchoice != 4) {
			std::cout << "다시 선택해주세요" << std::endl;
			Menuselect(students, num);
		}
		if (menuchoice == 1) {
			Signup(students, num);
		}
		if (menuchoice == 2) {
			std::cout << "ID(학번): ";
			std::cin >> id;
			std::cout << "Password: ";
			std::cin >> password;
			if (Login(students, id, password, num)) {
				std::cout << "로그인 성공" << std::endl;
			}
			else std::cout << "잘못된 비밀번호이거나 존재하지 않는 ID입니다." << std::endl;
		}
		if (menuchoice == 3) {

		}
		if (menuchoice == 4) {
			break;
		}
	}
}


int main(){
	int num = 0;
	Student students[200];
	Professor professors[50];
	//Getstudents(students);
	Menuselect(students, num);

}