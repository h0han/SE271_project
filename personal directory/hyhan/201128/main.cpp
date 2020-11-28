#include "nakon_header.h"

int main() {
	Student students[200];
	MakeObject(students, "student_database.csv");
    int num = get_number_of_students();
	Menuselect(students, num);
	return 0;
}