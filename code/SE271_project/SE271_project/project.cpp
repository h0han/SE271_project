#include "header.h"

bool Student::operator <(Student& student) {
	return this->score < student.score;
}

std::vector<std::string> split(std::string input, char delimiter) {
	std::vector<std::string> answer;
	std::stringstream ss(input);
	std::string temp;
	while (getline(ss, temp, delimiter)) answer.push_back(temp);
	return answer;
}

int toHash(std::string id) {
	int key1 = 10 + stoi(id.substr(3, 1));
	std::string key2 = id.substr(6, 3);
	return (key1 - 18) * 200 + stoi(key2);
}

void MakeObject(Student students[], std::string filename) { 
	// Function to create objects based on user input
	std::string filePath = filename;
	std::ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		int studentNo = 0;
		std::string line;
		while (getline(openFile, line)) {
			std::vector<std::string> row = split(line, ',');
			studentNo = toHash(row[0]);
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
		}
		openFile.close();
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
	// Involve various subjects existing in DGIST major
	int idx = 0;
	int A_len = 16; // start at 0
	int B_len = 19; // start at 16
	int C_len = 12; // start at 35
	int D_len = 17; // start at 47
	int E_len = 18; // start at 64
	int F_len = 18; // start at 82
	for (int i = 0; i < 5; i++) {
		idx = std::atoi(&sub[i][1]);
		if (sub[i][0] == 'A') students[num].subject[idx - 1] = 2 * (5 - i);
		if (sub[i][0] == 'B') students[num].subject[15 + idx] = 2 * (5 - i);
		if (sub[i][0] == 'C') students[num].subject[34 + idx] = 2 * (5 - i);
		if (sub[i][0] == 'D') students[num].subject[46 + idx] = 2 * (5 - i);
		if (sub[i][0] == 'E') students[num].subject[63 + idx] = 2 * (5 - i);
		if (sub[i][0] == 'F') students[num].subject[81 + idx] = 2 * (5 - i);
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

void Signup(Student students[]) {
	int num = 0;
	std::string idd;
	std::string filePath = "student_database.csv";
	std::ofstream writeFile(filePath.data(), std::ios::app);
	if (writeFile.is_open()) {
		std::cout << "�й��� �Է����ּ���." << std::endl;
		std::cin >> idd;
		num = toHash(idd);
		students[num].id = idd;
		if (std::cin.fail())
		{
			std::cout << "error" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			Signup(students);
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

		std::cout << "�б� �̸����� �Է����ּ���.(se271@dgist.ac.kr)" << std::endl;
		std::cin >> students[num].mail;
		writeFile << students[num].mail << ",";

		std::cout << "������ mbti�� �Է����ּ���.(��, �ҹ��� ��� ���� �Է� �����մϴ�.)" << std::endl;
		std::cin >> students[num].mbti;
		writeFile << students[num].mbti << ",";

		std::cout << "�ڱ�Ұ� �� ����!" << std::endl;
		std::cin.ignore();
		getline(std::cin, students[num].self_introduction, '\n');
		writeFile << students[num].self_introduction << ",";

		open_csv("subject_code.csv");
		std::cout << "�����ϴ� ���� 5���� 1�������� 5�������� ����ּ���. (ex. A1 B5 B7 C1 D2)" << std::endl;
		std::string sub[7];
		std::cin >> sub[0] >> sub[1] >> sub[2] >> sub[3] >> sub[4];
		std::cout << "�Ⱦ��ϴ� �о� 2���� ����ּ���. (ex. E F)" << std::endl;
		std::cin >> sub[5] >> sub[6];
		Inputsubject(students, num, sub);
		for (int idx = 0; idx < 100; idx++) {
			if (idx == 99) writeFile << students[num].subject[idx] << std::endl;
			else writeFile << students[num].subject[idx] << ",";
		}

		std::cout << std::endl << "ȸ�������� �Ϸ�Ǿ����ϴ�. �α��� �� �̿����ּ���." << std::endl;
		writeFile.close();
	}
}

int Login(Student students[], std::string id, std::string password) {
	if (students[toHash(id)].id == id) {
		if (students[toHash(id)].password == password) {
			int now = toHash(id); // now is the index of the current user
			return toHash(id);
		}
		else return -1;
	}
	return -1;
}

std::string mbti_arr[32][32];

void MbtiToArr(std::string filename) {
	std::string str_buf;
	std::fstream fs;
	std::istringstream iss(str_buf);
	std::string token;
	int i = 0; int j = 0;
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

std::string upper(std::string str) {
	// converting lowercase letters into uppercase letters
	int i;
	for (i = 0; i < str.size(); ++i) {
		if (islower(str[i])) {
			str[i] = toupper(str[i]);
		}
	} return str;
}

double MbtiMatch(std::string mbti1, std::string mbti2) {
	MbtiToArr("mbti.csv");
	int i;  // for loop
	int idx1 = 0; int idx2 = 0; // index of corresponding mbti in array
	double m_val; // degree of matching of two mbti
	std::string mbti_1 = upper(mbti1); std::string mbti_2 = upper(mbti2); // Change mbti to uppercase if lowercase
	for (i = 0; i < 16; ++i) { // Specifies the index of each parameter among 16 mbti propensity
		if (mbti_arr[0][i].compare(mbti_1) == 0) { idx1 = i; }
		if (mbti_arr[0][i].compare(mbti_2) == 0) { idx2 = i; }
	}
	m_val = atof(mbti_arr[idx2][idx1].c_str());
	return m_val;
}

void Match(Student students[], int now) {
	// Subject Matching
	students[now].score = -10000;
	for (int no = 0; no < 500; no++) {
		if (no == now || students[no].id == "0") continue;
		for (int i = 0; i < 100; i++) {
			students[no].score = students[no].score + pow(students[now].subject[i] - students[no].subject[i], 2);
		}
	}

	// MBTI Matching
	for (int no = 0; no < 500; no++) {
		if (students[no].id == "0") continue;
		students[no].score = students[no].score - 5 * MbtiMatch(students[no].mbti, students[now].mbti);
	}

	std::cout << "============================================================================================================" << std::endl;
	std::cout << students[now].name << "�԰� UGRP ��Ī ������ ���� �л������ �����մϴ�." << std::endl;
	std::cout << "�����ϴ� ����� �Ⱦ��ϴ� ����, MBTI ���⿡ ���� ������ �ο��˴ϴ�." << std::endl;
	std::cout << "������ �������� ���� �� �´� �л��Դϴ�." << std::endl;
	std::cout << "������ 0�̸� ����, 1�̸� �����Դϴ�." << std::endl;
	std::cout << "============================================================================================================" << std::endl;
	std::cout.width(7);
	std::cout << std::left << "�̸�" << ": ";
	std::cout.width(5);
	std::cout << std::left << "����" << ": ";
	std::cout.width(10);
	std::cout << std::left << "�й�" << ": ";
	std::cout.width(25);
	std::cout << std::left << "�̸���" << ": ";
	std::cout.width(5);
	std::cout << std::left << "����" << ": ";
	std::cout << std::left << "�� �� �ڱ�Ұ�" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
	std::sort(students, students + 500);
	for (int i = 1; i < 500; i++) {
		if (students[i].id == "0") continue;
		std::cout.width(7);
		std::cout << std::left << students[i].name << ": ";
		std::cout.width(5);
		std::cout << std::left << students[i].score << ": ";
		std::cout.width(10);
		std::cout << std::left << students[i].id << ": ";
		std::cout.width(25);
		std::cout << std::left << students[i].mail << ": ";
		std::cout.width(5);
		std::cout << std::left << students[i].gender << ": ";
		std::cout << std::left << students[i].self_introduction << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Showprofessor(Professor professors[], Student student) { 
	// Show a professor who fits user
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (professors[i].subject[j] == 1 && student.subject[j] == 10) {
				std::cout << "============================================================================================================" << std::endl;
				std::cout << "1���� ������!" << std::endl;
				std::cout << "���� : " << professors[i].name << std::endl;
				std::cout << "�̸��� : " << professors[i].mail << std::endl;
				std::cout << "���ǽ� ��ġ : " << professors[i].officeloc << std::endl;
			}
		}
	}
}
void MakeProfessor(Professor professors[]) {
	// Create objects based on existing professors' information
	std::string filePath = "professor_database.csv";
	std::ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		int professorNo = 0;
		std::string line;
		while (getline(openFile, line)) {
			std::vector<std::string> row = split(line, ',');
			professors[professorNo].name = row[0];
			professors[professorNo].gender = row[1];
			professors[professorNo].mail = row[2];

			for (int idx = 0; idx < 100; idx++) {
				professors[professorNo].subject[idx] = std::atoi((row[3 + idx]).c_str());
			}
			professors[professorNo].officeloc = row[103];
			professorNo++;
		}
		openFile.close();
	}
}

void Menuselect(Student students[], Professor professors[]) {
	int menuchoice = 0;
	std::string id;
	std::string password;
	std::cout << "ȯ���մϴ�. �� ���α׷��� ����� ������ UGRP ������ �������� ��Ī���ִ� ���α׷��Դϴ�." << std::endl;
	std::cout << "�ܼ� â�� �ִ�ȭ�� �� ������ּ���." << std::endl;
	std::cout << "============================================================================================================" << std::endl;
	std::cout << "1.ȸ������ 2.�α��� 3.����" << std::endl;
	std::cout << "============================================================================================================" << std::endl;
	std::cin >> menuchoice;
	if (menuchoice != 1 && menuchoice != 2 && menuchoice != 3) {
		std::cout << "�ٽ� �������ּ���" << std::endl;
		Menuselect(students, professors);
	}
	if (menuchoice == 1) {
		Signup(students);
		Menuselect(students, professors);
	}
	if (menuchoice == 2) {
		std::cout << "ID(�й�): ";
		std::cin >> id;
		std::cout << "Password: ";
		std::cin >> password;
		int now = Login(students, id, password);
		if (now != -1) {
			std::cout << "�α��� ����" << std::endl;
			Showprofessor(professors, students[toHash(id)]);
			Match(students, now);
			Menuselect(students, professors);
		}
		else {
			std::cout << "�߸��� ��й�ȣ�̰ų� �������� �ʴ� ID�Դϴ�." << std::endl;
			Menuselect(students, professors);
		}
	}
	if (menuchoice == 3) {
		std::cout << "���α׷��� �����մϴ�." << std::endl;
	}
}