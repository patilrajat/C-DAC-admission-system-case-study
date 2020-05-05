#include "student.h"
#include "center.h"
#include "preferences.h"
#include "course.h"
#include "eligibilities.h"
#include "admissionsystem.h"
using namespace std;
int main(void)
{
    sys.load_degrees();
	sys.load_students();
	sys.load_preferences();
	sys.load_courses();
	sys.load_centers();
	sys.load_capacities();
	sys.load_eligibilities();

	int choice;
		while((choice=sys.menu_list())!=0)
		{
			sys.list_all_menus(choice);
		}
    student s;
    s.save_student(sys.stud);
    capacities c;
    c.save_capacities(sys.capa);


	return 0;
}
