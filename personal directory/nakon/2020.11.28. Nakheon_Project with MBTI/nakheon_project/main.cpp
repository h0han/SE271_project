#include "nakon_header.h"

int main() {
	
	Student students[800];
	Professor professors[120];
	open_csv_and_make_object(students, "student_database.csv");
	open_csv_and_make_professor(professors);
	Menuselect(students, professors);
	
	//std::cout<<toHash("")
	return 0;
}