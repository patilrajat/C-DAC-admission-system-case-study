/*
 * capacities.h
 *
 *  Created on: 19-Apr-2020
 *      Author: sunbeam
 */

#ifndef SRC_CAPACITIES_H_
#define SRC_CAPACITIES_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class capacities {
	string center_id;
	string name;
	int capacity;
	int filled_capacity;

public:
	capacities();
	capacities(const string& center_id,const string& name,int capacity,int filled_capacity);
	void set_center_id(const string& center_id);
	void set_name(const string& name);
	void set_capacity(int capacity);
	void set_filled_capacity(int filled_capacity);
	string& get_center_id();
	string& get_name();
	int get_capacity();
	int get_filled_capacity();
	void display_capacities();
	void save_capacities(vector<capacities>& capa);
	virtual ~capacities();
};

#endif /* SRC_CAPACITIES_H_ */
