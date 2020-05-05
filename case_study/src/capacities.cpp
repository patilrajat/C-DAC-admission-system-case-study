/*
 * capacities.cpp
 *
 *  Created on: 19-Apr-2020
 *      Author: sunbeam
 */

#include "capacities.h"

capacities::capacities() {
	center_id="";
	name="";
	capacity=0;
	filled_capacity=0;
}
capacities::capacities(const string& center_id,const string& name,int capacity,int filled_capacity){
	this->center_id=center_id;
	this->name=name;
	this->capacity=capacity;
	this->filled_capacity=filled_capacity;
}
	void capacities::set_center_id(const string& center_id){
		this->center_id=center_id;
	}
	void capacities::set_name(const string& name){
		this->name=name;
	}
	void capacities::set_capacity(int capacity){
		this->capacity=capacity;
	}
	void capacities::set_filled_capacity(int filled_capacity){
		this->filled_capacity=filled_capacity;
	}
	string& capacities::get_center_id(){
		return this->center_id;
	}
	string& capacities::get_name(){
        return this->name;
	}
	int capacities::get_capacity(){
		return this->capacity;
	}
	int capacities::get_filled_capacity(){
		return this->filled_capacity;
	}
	void capacities::display_capacities(){
		cout<<"--"<<center_id<<","<<name<<","<<capacity<<","<<filled_capacity<<endl;
	}
	void capacities::save_capacities(vector<capacities>& capa){
		ofstream ofile;
			ofile.open("capacities.csv");
			for(unsigned i=0;i<capa.size();++i){
				ofile<<capa[i].get_center_id()<<","<<capa[i].get_name()<<","<<capa[i].get_capacity()<<","<<capa[i].get_filled_capacity()<<endl;
			}

	}

capacities::~capacities() {
	// TODO Auto-generated destructor stub
}

