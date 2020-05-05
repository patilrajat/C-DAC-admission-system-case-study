/*
 * preferences.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#ifndef SRC_PREFERENCES_H_
#define SRC_PREFERENCES_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class preferences {
	int form_no;
	int preference;
	string course_name;
	string center_id;

public:
	preferences();
	preferences(int form_no,int preference,const string& course_name,const string& center_id);

	void set_form_no(int form_no);
	void set_preference(int preference);
	void set_course_name(const string& course_name);
	void set_center_id(const string& center_id);

	int get_form_no();
	int get_preference();
	string& get_course_name();
	string& get_center_id();
	void display_preferences();
	virtual ~preferences();
};

#endif /* SRC_PREFERENCES_H_ */
