/*
 * course.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef SRC_COURSE_H_
#define SRC_COURSE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "eligibilities.h"
using namespace std;

class course {
	int id;
	string name;
	double fees;
	string ccat_section;
public:
    map<string,int> coursemap;
    vector<eligibilities> elig;
public:
	course();
	course(int id,const string& name,double fees,const string& ccat_section);
	void set_id(int id);
	void set_name(const string& name);
	void set_fees(double fees);
	void set_ccat_section(const string& ccat_section);

	int get_id();
	string& get_name();
	double get_fees();
	string& get_ccat_section();
	void display_courses();
	void display_courses_without_capacity();
	virtual ~course();
};

#endif /* SRC_COURSE_H_ */
