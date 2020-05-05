/*
 * admissionsystem.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef SRC_ADMISSIONSYSTEM_H_
#define SRC_ADMISSIONSYSTEM_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "course.h"
#include "student.h"
#include "preferences.h"
#include "eligibilities.h"
#include "capacities.h"
#include "center.h"
using namespace std;

class admission_system {
public:
	vector<student> stud;
	vector<center> cent;
	vector<course> cour;
	vector<capacities> capa;
	vector<string> degr;
	vector<eligibilities> el;
	vector<student> round2;

public:
	admission_system();
	void load_centers();
	void load_courses();
	void load_students();
	void load_capacities();
	void load_degrees();
	void load_eligibilities();

	center* find_center(const string&);
	course* find_course(const string& name);
	void load_preferences();
	void save_preference(preferences& pr);
	void display_centers();
	void display_courses();
	void display_students();
	void sort_by_a();
	void sort_by_b();
	void sort_by_c();
	void sort_by_id();
	void round_1();
	void round_2();
	string& find_section(preferences& p);
	int find_capacity_index(preferences& p);
	student* find_student(int form_no);
	int student_menu();
	int student_menu2();
	int admin_menu();
	int coordinator_menu();
	int menu_list();
	void list_all_menus(int choice);
	void register_student();
	int student_sign_in(int id,const string& name);
	vector<string> find_eligible_courses(int id);
	void find_eligible_centers(int id);
	void give_preferences(int id);
	int admin_sign_in(const string& a,const string& b);
	void update_student_rank();
	void list_allocated();
	void list_paid();
	void list_reported();
	void allocated_student_vector();
	void generate_prn();
	void admitted_students();
	int coordinator_sign_in(const string& id,const string& pass);
	void course_of_center(const string& id);
	void students_of_center(const string& id);
	void update_reported(const string& id);
	void students_of_center_with_pnr(const string& id);
	virtual ~admission_system();
};
extern admission_system sys;
#endif /* SRC_ADMISSIONSYSTEM_H_ */
