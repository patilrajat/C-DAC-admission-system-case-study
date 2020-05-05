/*
 * preferences.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "preferences.h"

preferences::preferences() {
	form_no=0;
	preference=0;
	course_name="";
	center_id="";

}
preferences::preferences(int form_no,int preference,const string& course_name,const string& center_id){
	this->form_no=form_no;
	this->preference=preference;
	this->course_name=course_name;
	this->center_id=center_id;
}

void preferences::set_form_no(int form_no){
	this->form_no=form_no;
}
void preferences::set_preference(int preference){
	this->preference=preference;
}
void preferences::set_course_name(const string& course_name){
	this->course_name=course_name;
}
void preferences::set_center_id(const string& center_id){
	this->center_id=center_id;
}

int preferences::get_form_no(){
	return this->form_no;
}
int preferences::get_preference(){
	return this->preference;
}
string& preferences::get_course_name(){
	return this->course_name;
}
string& preferences::get_center_id(){
	return this->center_id;
}
void preferences::display_preferences(){
	cout<<"\t-"<<form_no<<","<<preference<<","<<course_name<<","<<center_id<<endl;
}
preferences::~preferences() {
	// TODO Auto-generated destructor stub
}

