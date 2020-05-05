#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "preferences.h"

using namespace std;

class student {
	int id;
	string name;
	int rank_a;
	int rank_b;
	int rank_c;
	string degree;
	double degree_marks;
	int allocated_preference;
	string course_name;
	string center_id;
	int payment;
	int reported;
	string prn;
public:
    vector<preferences> pref;

public:
	student();
	student(int id,const string& name,int rank_a,int rank_b,int rank_c,const string& degree,
			double degree_marks,int allocated_preference,const string& course_name,const string& center_id,
			int payment,int reported,const string& prn);
	void set_id(int id);
	void set_name(const string& name);
	void set_rank_a(int rank_a);
	void set_rank_b(int rank_b);
	void set_rank_c(int rank_c);
	void set_degree(const string& degree);
	void set_degree_marks(double degree_marks);
	void set_allocated_preference(int allocated_preference);
	void set_course_name(const string& course_name);
	void set_center_id(const string& center_id);
	void set_payment(int payment);
	void set_reported(int reported);
	void set_prn(const string& prn);
	int get_id();
	string& get_name();
	int get_rank_a();
	int get_rank_b();
	int get_rank_c();
	string& get_degree();
	double get_degree_marks();
	int get_allocated_preference();
	string& get_course_name();
	string& get_center_id();
	int get_payment();
	int get_reported();
	string& get_prn();
    void save_student(vector<student>& stud);
    //void add_student_in_csv();
	void display_student_preferences();
	void display_without_preference();
	void load_student(vector<student>& s);

	virtual ~student();
};

#endif /* SRC_STUDENT_H_ */
