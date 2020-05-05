/*
 * eligibilities.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "eligibilities.h"

eligibilities::eligibilities() {
	course_name="";
	degree="";
	min_percentage=0.0;
}
eligibilities::eligibilities(const string& course_name,const string& degree,double min_percentage){
	this->course_name=course_name;
	this->degree=degree;
	this->min_percentage=min_percentage;
}
	void eligibilities::set_course_name(const string& course_name){
		this->course_name=course_name;
	}
	void eligibilities::set_course_degree(const string& degree){
		this->degree=degree;
	}
	void eligibilities::set_min_percentage(double min_percentage){
		this->min_percentage=min_percentage;
	}

	string& eligibilities::get_course_name(){
		return this->course_name;
	}
	string& eligibilities::get_degree(){
		return this->degree;
	}
	double eligibilities::get_min_percentage(){
		return this->min_percentage;

	}
	void eligibilities::display_eligibilities(){
		cout<<course_name<<","<<degree<<","<<min_percentage<<endl;
	}

eligibilities::~eligibilities() {
	// TODO Auto-generated destructor stub
}

