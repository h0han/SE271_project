#include "nakon_header.h"

std::vector<std::string> split(std::string input, char delimiter) {
    std::vector<std::string> answer;
    std::stringstream ss(input);
    std::string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

void open_csv_and_make_object(Student students[], std::string filename) {
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
	for (int i = 0; i < 5; i++) {
		idx = std::atoi(&sub[i][1]);
		if (sub[i][0] == 'A') students[num].subject[idx - 1] = 1;
		if (sub[i][0] == 'B') students[num].subject[15 + idx] = 1;
		if (sub[i][0] == 'C') students[num].subject[34 + idx] = 1;
		if (sub[i][0] == 'D') students[num].subject[46 + idx] = 1;
		if (sub[i][0] == 'E') students[num].subject[63 + idx] = 1;
		if (sub[i][0] == 'F') students[num].subject[81 + idx] = 1;
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
		std::string sub[5];
		std::cin >> sub[0] >> sub[1] >> sub[2] >> sub[3] >> sub[4];
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

bool Login(Student students[], std::string id, std::string password, int& num) {
	for (int i = 0; i < num; i++) {
		//std::cout << students[i].id << std::endl;
		if (students[i].id == id) {
			if (students[i].password == password) {
				//for (int j = 0; j < 99; j++)std::cout << students[i].subject[j] << ' ';
				return true;
			}
			else return false;
		}
	}
	return false;
}

void Menuselect(Student students[], int& num) {
	int menuchoice = 0;
	std::string id;
	std::string password;
	//while (menuchoice != 4) {
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
			if (Login(students, id, password, num)) {
				std::cout << "�α��� ����" << std::endl;
			}
			else std::cout << "�߸��� ��й�ȣ�̰ų� �������� �ʴ� ID�Դϴ�." << std::endl;
			Menuselect(students, num);
		}
		
		if (menuchoice == 3) {
			//return;
		}
	}
//}
