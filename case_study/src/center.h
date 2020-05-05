/*
 * center.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#ifndef SRC_CENTER_H_
#define SRC_CENTER_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

#include "course.h"
using namespace std;

class center {
	string id;
	string name;
	string address;
	string coordinator;
	string password;
public:
     map<string,int> centermap;
public:
	center();
	center(const string& id,const string& name,const string& address,
			const string& coordinator,const string& password);
	void set_id(const string& id);
	void set_name(const string& name);
	void set_address(const string& address);
	void set_coordinator(const string& coordinator);
	void set_password(const string& password);

	string& get_id();
	string& get_name();
	string& get_address();
	string& get_coordinator();
	string& get_password();

	void display_centers();
	void display_centers_without_capacity();
    void load_center(vector<center>& s);
	virtual ~center();
};

#endif /* SRC_CENTER_H_ */
