/*
 * center.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include "center.h"
#include "admissionsystem.h"
center::center() {
	id="";
	name="";
	address="";
	coordinator="";
	password="";
}
center::center(const string& id,const string& name,const string& address,
		const string& coordinator,const string& password){
	this->id=id;
	this->name=name;
	this->address=address;
	this->coordinator=coordinator;
	this->password=password;

}
void center::set_id(const string& id){
	this->id=id;
}
void center::set_name(const string& name){
	this->name=name;
}
void center::set_address(const string& address){
	this->address=address;
}
void center::set_coordinator(const string& coordinator){
	this->coordinator=coordinator;
}
void center::set_password(const string& password){
	this->password=password;
}


string& center::get_id(){
	return id;
}
string& center::get_name(){
	return this->name;
}
string& center::get_address(){
	return this->address;
}
string& center::get_coordinator(){
	return this->coordinator;
}
string& center::get_password(){
	return this->password;
}

void center::load_center(vector<center>& s){
	ifstream ifile;
			ifile.open("centers.csv");
			if(!ifile){
				cout<<"fail to open students"<<endl;
				return;
			}
			string line;
		while(getline(ifile,line)){
			stringstream ss(line);
			string tokens[5];
			for(int i=0;i<5;++i){
				getline(ss,tokens[i],',');
			}
			center obj(tokens[0],tokens[1],tokens[2],
					   tokens[3],tokens[4]);
			s.push_back(obj);
		}
}
void center::display_centers(){
	cout<<id<<","<<name<<","<<address<<","<<coordinator<<endl;
	map<string,int>::iterator itr=centermap.begin();
			while(itr != centermap.end()) {
					cout << "\t-";
					sys.capa[itr->second].display_capacities();
					itr++;
				}
}
void center::display_centers_without_capacity(){
	cout<<id<<","<<name<<","<<address<<","<<coordinator<<endl;
}

center::~center() {
	// TODO Auto-generated destructor stub
}


