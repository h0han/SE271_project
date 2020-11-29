#include "header.h"

int main() {

	Student students[500];
	Professor professors[120];
	MakeObject(students, "student_database.csv"); // open csv and make objects(students)
	MakeProfessor(professors); // open csv and make professors
	Menuselect(students, professors);

	return 0;
}