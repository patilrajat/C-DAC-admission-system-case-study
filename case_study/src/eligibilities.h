/*
 * eligibilities.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef SRC_ELIGIBILITIES_H_
#define SRC_ELIGIBILITIES_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class eligibilities {
	string course_name;
	string degree;
	double min_percentage;

public:
	eligibilities();
	eligibilities(const string& course_name,const string& degree,double min_percentage);
	void set_course_name(const string& course_name);
	void set_course_degree(const string& degree);
	void set_min_percentage(double min_percentage);

	string& get_course_name();
	string& get_degree();
	double get_min_percentage();
	void display_eligibilities();
	virtual ~eligibilities();
};

#endif /* SRC_ELIGIBILITIES_H_ */
