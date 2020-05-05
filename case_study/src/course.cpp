/*
 * course.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "course.h"
#include "admissionsystem.h"
course::course() {
	id=0;
		name="";
		fees=0.0;
		ccat_section="";
}
course::course(int id,const string& name,double fees,const string& ccat_section){
	this->id=id;
	this->name=name;
	this->fees=fees;
	this->ccat_section=ccat_section;
}
void course::set_id(int id){
	this->id=id;
}
void course::set_name(const string& name){
	this->name=name;
}
void course::set_fees(double fees){
	this->fees=fees;
}
void course::set_ccat_section(const string& ccat_section){
	this->ccat_section=ccat_section;
}
int course::get_id(){
	return id;
}
string& course::get_name(){
	return this->name;
}
double course::get_fees(){
	return this->fees;
}
string& course::get_ccat_section(){
	return this->ccat_section;
}
void course::display_courses(){
			cout<<id<<","<<name<<","<<fees<<","<<ccat_section<<endl;
			map<string,int>::iterator itr=coursemap.begin();
						while(itr != coursemap.end()) {
								cout << "\t-";
								sys.capa[itr->second].display_capacities();
								itr++;
							}
}
void course::display_courses_without_capacity(){
	cout<<id<<","<<name<<","<<fees<<","<<ccat_section<<endl;
}
course::~course() {
	// TODO Auto-generated destructor stub
}

