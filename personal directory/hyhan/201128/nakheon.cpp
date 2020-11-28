#include "nakon_header.h"

bool Student::operator <(Student& student) {
	return this->score > student.score;
}

std::vector<std::string> split(std::string input, char delimiter) { // .csv ���� �ҷ��ͼ� vector�� ��ȯ
    std::vector<std::string> answer;
    std::stringstream ss(input);
    std::string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

void MakeObject(Student students[], std::string filename) {
    std::string filePath = filename;
    std::ifstream openFile(filePath.data());
    if (openFile.is_open()) {
        int studentNo = 0;
        std::string line;
        while (getline(openFile, line)) {
            std::vector<std::string> row = split(line, ',');

            students[studentNo].id = row[0];
            students[studentNo].password = row[1];
            students[studentNo].name = row[2];
            students[studentNo].gender = row[3];
            students[studentNo].mail = row[4];
            students[studentNo].mbti = row[5];
            students[studentNo].self_introduction = row[6];
            for (int idx = 0; idx < 100; idx++) {
                students[studentNo].subject[idx] = std::atoi((row[7 + idx]).c_str());
            }
            
            studentNo++;
        }
        openFile.close();
    }
}

int get_number_of_students() {
	int num = 0;
	std::string filePath = "number_of_students.txt";
	std::ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		std::string line;
		while (getline(openFile, line)) {
			num = std::atoi(line.c_str());
		}
		openFile.close();
	}
	return num;
}

void write_number_of_students(int num) {
	std::string filePath = "number_of_students.txt";
	std::ofstream writeFile(filePath.data());
	if (writeFile.is_open()) {
		writeFile << num;
		writeFile.close();
	}
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
			std::cout.width(35);
			std::cout << std::left << token;
		}
		std::cout << std::endl;
	}
	fs.close();
}

void Inputsubject(Student students[], int& num, std::string sub[]) {
	int idx = 0;
	int A_len = 16; // start at 0
	int B_len = 19; // start at 16
	int C_len = 12; // start at 35
	int D_len = 17; // start at 47
	int E_len = 18; // start at 64
	int F_len = 18; // start at 82
	for (int i = 0; i < 5; i++) {
		idx = std::atoi(&sub[i][1]);
		if (sub[i][0] == 'A') students[num].subject[idx - 1] = 1;
		if (sub[i][0] == 'B') students[num].subject[15 + idx] = 1;
		if (sub[i][0] == 'C') students[num].subject[34 + idx] = 1;
		if (sub[i][0] == 'D') students[num].subject[46 + idx] = 1;
		if (sub[i][0] == 'E') students[num].subject[63 + idx] = 1;
		if (sub[i][0] == 'F') students[num].subject[81 + idx] = 1;
	}
	for (int i = 5; i < 7; i++) {
		if (sub[i] == "A") for (int j = 0; j < A_len; j++) students[num].subject[j] = -1;
		if (sub[i] == "B") for (int j = 0; j < B_len; j++) students[num].subject[16 + j] = -1;
		if (sub[i] == "C") for (int j = 0; j < C_len; j++) students[num].subject[35 + j] = -1;
		if (sub[i] == "D") for (int j = 0; j < D_len; j++) students[num].subject[47 + j] = -1;
		if (sub[i] == "E") for (int j = 0; j < E_len; j++) students[num].subject[64 + j] = -1;
		if (sub[i] == "F") for (int j = 0; j < F_len; j++) students[num].subject[82 + j] = -1;
	}
}

void Signup(Student students[], int& num) {
	std::string filePath = "student_database.csv";
	std::ofstream writeFile(filePath.data(), std::ios::app);
	if (writeFile.is_open()) {
		std::cout << "�й��� �Է����ּ���." << std::endl;
		std::cin >> students[num].id;
		if (std::cin.fail())
		{
			std::cout << "error" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			Signup(students, num);
		}
		writeFile << students[num].id << ",";

		std::cout << "��й�ȣ�� �Է����ּ���." << std::endl;
		std::cin >> students[num].password;
		writeFile << students[num].password << ",";

		std::cout << "�̸��� �Է����ּ���." << std::endl;
		std::cin >> students[num].name;
		writeFile << students[num].name << ",";

		while (students[num].gender != "1" && students[num].gender != "0") {
			std::cout << "������ �Է����ּ���.(���ڴ� 0, ���ڴ� 1)" << std::endl;
			std::cin >> students[num].gender;
			writeFile << students[num].gender << ",";
		}

		std::cout << "�б� �̸����� �Է����ּ���." << std::endl;
		std::cin >> students[num].mail;
		writeFile << students[num].mail << ",";

		std::cout << "������ mbti�� �Է����ּ���." << std::endl;
		std::cin >> students[num].mbti;
		writeFile << students[num].mbti << ",";

		std::cout << "�ڱ�Ұ� �� ����!" << std::endl;
		std::cin.ignore();
		getline(std::cin, students[num].self_introduction, '\n');
		writeFile << students[num].self_introduction << ",";

		open_csv("subject_code.csv");
		std::cout << "�����ϴ� ���� 5���� ����ּ���. (ex. A1 B5 B7 C1 D2)" << std::endl;
		std::string sub[7];
		std::cin >> sub[0] >> sub[1] >> sub[2] >> sub[3] >> sub[4];
		std::cout << "�Ⱦ��ϴ� �о� 2���� ����ּ���. (ex. E F)" << std::endl;
		std::cin >> sub[5] >> sub[6];
		Inputsubject(students, num, sub);
		for (int idx = 0; idx < 100; idx++) {
			if (idx == 99) writeFile << students[num].subject[idx] << std::endl;
			else writeFile << students[num].subject[idx] << ",";
		}

		num++;
		write_number_of_students(num);
		std::cout << std::endl << "ȸ�������� �Ϸ�Ǿ����ϴ�. �α��� �� �̿����ּ���." << std::endl;

		writeFile.close();
	}
}

int Login(Student students[], std::string id, std::string password, int& num) {
	for (int i = 0; i < num; i++) {
		if (students[i].id == id) {
			if (students[i].password == password) {
				int now = i; //now�� ���� �������� index
				return now;
			}
			else return -1;
		}
	}
	return -1;
}

std::string mbti_arr[32][32]; // mbti�� ���� array

void csv_to_arr(std::string filename) {
	std::string str_buf;
	std::fstream fs;
	std::istringstream iss(str_buf);
	std::string token;
	int i = 0; int j = 0; // for loop
	fs.open(filename, std::ios::in);
	while (!fs.eof()) {
		i = 0;
		getline(fs, str_buf);
		std::istringstream iss(str_buf);
		while (getline(iss, token, ',')) {
			mbti_arr[j][i] = token;
			++i;
		} ++j;
	}
	fs.close();
}

std::string upper(std::string str) { // �ҹ��� --> �빮�ڷ� ��ȯ�ϴ� �Լ�
	int i;
	for (i = 0; i < str.size(); ++i) {
		if (islower(str[i])) {
			str[i] = toupper(str[i]);
		}
	} return str;
}

double match_mbti(std::string mbti1, std::string mbti2) {
	csv_to_arr("mbti.csv");
	int i; int j; // for loop
	int idx1 = 0; int idx2 = 0; // array������ �ش� mbti�� index
	double m_val; // �� mbti�� ��Ī ����
	std::string mbti_1 = upper(mbti1); std::string mbti_2 = upper(mbti2); // mbti�� �ҹ����̸� �빮�ڷ� ����
	for (i = 0; i < 16; ++i) { // 16���� mbti ���� �� �� parameter�� index�� �����Ѵ�.
		if (mbti_arr[0][i].compare(mbti_1) == 0) { idx1 = i; }
		if (mbti_arr[0][i].compare(mbti_2) == 0) { idx2 = i; }
	}
	m_val = atof(mbti_arr[idx2][idx1].c_str());
	return m_val;
}

void Match(Student students[], int& num, int now) {
	// Subject Matching
	for (int i = 0; i < 100; i++) {
		if (students[now].subject[i] == 1) {
			for (int no = 0; no < num; no++) {
				if (no == now) students[no].score = 1000;
				if (students[no].subject[i] == 1) students[no].score = students[no].score + 3;
				else if (students[no].subject[i] == -1) students[no].score = students[no].score - 5;
			}
		}	
	}

	// MBTI Matching
	for (int no = 0; no < num; no++) {
		students[no].score = students[no].score + match_mbti(students[no].mbti, students[now].mbti);
	}

	std::cout << "======================================================" << std::endl;
	std::cout << students[now].name << "�԰� UGRP ��Ī ������ ���� �л������ �����մϴ�." << std::endl;
	std::cout << "�����ϴ� ������ ��ġ�� 3�� �߰�, ���� �����ϴ� ������ ������ �Ⱦ��ϸ� -5��, MBTI ���⿡ ���� 0~1������ �ο��˴ϴ�." << std::endl;
	std::cout << "======================================================" << std::endl;
	std::sort(students, students + num);
	for (int i = 1; i < num; i++) {
		std::cout << students[i].name << ":" << students[i].score << std::endl;
	}
}

void Menuselect(Student students[], int& num) {
	int menuchoice = 0;
	std::string id;
	std::string password;
		std::cout << "1.ȸ������ 2.�α��� 3.����" << std::endl;
		std::cin >> menuchoice;
		if (menuchoice != 1 && menuchoice != 2  && menuchoice != 3) {
			std::cout << "�ٽ� �������ּ���" << std::endl;
			Menuselect(students, num);
		}
		if (menuchoice == 1) {
			Signup(students, num);
			Menuselect(students, num);
		}
		if (menuchoice == 2) {
			std::cout << "ID(�й�): ";
			std::cin >> id;
			std::cout << "Password: ";
			std::cin >> password;
			int now = Login(students, id, password, num);
			if (now != -1) {
				std::cout << "�α��� ����" << std::endl;
				std::cout << "1. �ڽŰ� �´� UGRP ��� ���� 2. �Խ���" << std::endl;
				std::cin >> menuchoice;
				if (menuchoice != 1 && menuchoice != 2) {
					std::cout << "�ٽ� �������ּ���" << std::endl;
					Menuselect(students, num);
					if (menuchoice == 1) {
						Match(students, num, now);
					}
					else if (menuchoice == 2) {
						// �Խ��� �����ִ� �Լ�
					}
				}
			}
			else {
				std::cout << "�߸��� ��й�ȣ�̰ų� �������� �ʴ� ID�Դϴ�." << std::endl;
				Menuselect(students, num);
			}
		}
		if (menuchoice == 3) {
			std::cout << "���α׷��� �����մϴ�." << std::endl;
		}
	}