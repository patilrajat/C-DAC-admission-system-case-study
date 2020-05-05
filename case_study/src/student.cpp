#include "student.h"
#include <iostream>
using namespace std;

student::student() {
	id=0;
	name="";
	rank_a=0;
	rank_b=0;
	rank_c=0;
	degree="";
	degree_marks=0.0;
	allocated_preference=0;
	course_name="";
	center_id="";
	payment=0;
	reported=0;
	prn="";

}
student::student(int id,const string& name,int rank_a,int rank_b,int rank_c,
		const string& degree,double degree_marks,int allocated_preference,
		const string& course_name,const string& center_id,int payment,int reported,const string& prn){
	this->id=id;
	this->name=name;
	this->rank_a=rank_a;
	this->rank_b=rank_b;
	this->rank_c=rank_c;
	this->degree=degree;
	this->degree_marks=degree_marks;
	this->allocated_preference=allocated_preference;
	this->course_name=course_name;
	this->center_id=center_id;
	this->payment=payment;
	this->reported=reported;
	this->prn=prn;

}
void student::set_id(int id){
	this->id=id;
}
void student::set_name(const string& name){
	this->name=name;
}
void student::set_rank_a(int rank_a){
	this->rank_a=rank_a;
}
void student::set_rank_b(int rank_b){
	this->rank_b=rank_b;
}
void student::set_rank_c(int rank_c){
	this->rank_c=rank_c;
}
void student::set_degree(const string& degree){
	this->degree=degree;
}
void student::set_degree_marks(double degree_marks){
	this->degree_marks=degree_marks;
}
void student::set_allocated_preference(int allocated_preference){
	this->allocated_preference=allocated_preference;
}
void student::set_course_name(const string& course_name){
	this->course_name=course_name;
}
void student::set_center_id(const string& center_id){
	this->center_id=center_id;
}
void student::set_payment(int payment){
	this->payment=payment;
}
void student::set_reported(int reported){
	this->reported=reported;
}
void student::set_prn(const string& prn){
	this->prn=prn;
}

int student::get_id(){
	return this->id;
}
string& student::get_name(){
	return this->name;
}
int student::get_rank_a(){
	return this->rank_a;
}
int student::get_rank_b(){
	return this->rank_b;
}
int student::get_rank_c(){
	return this->rank_c;
}
string& student::get_degree(){
	return this->degree;
}
double student::get_degree_marks(){
	return this->degree_marks;
}
string& student::get_course_name(){
	return this->course_name;
}
int student::get_allocated_preference(){
	return this->allocated_preference;
}
string& student::get_center_id(){
	return this->center_id;
}
int student::get_payment(){
	return this->payment;
}
int student::get_reported(){
	return this->reported;
}
string& student::get_prn(){
	return this->prn;
}
void student::display_student_preferences(){
	cout<<id<<","<<name<<","<<rank_a<<","<<rank_b<<","<<rank_c<<","<<degree<<","<<degree_marks
			<<","<<allocated_preference<<","<<course_name<<","<<center_id<<","<<payment<<","<<reported<<","<<prn<<endl;
	for(unsigned i=0;i<pref.size();++i){
		pref[i].display_preferences();
	}
}
void student::display_without_preference(){
	cout<<id<<","<<name<<","<<rank_a<<","<<rank_b<<","<<rank_c<<","<<degree<<","<<degree_marks
				<<","<<allocated_preference<<","<<course_name<<","<<center_id<<","<<payment<<","<<reported<<","<<prn<<endl;
}
void student::load_student(vector<student>& s){
	ifstream ifile;
	ifile.open("students.csv");
	if(!ifile){
		cout<<"fail to open students"<<endl;
		return;
	}
	string line;
	while(getline(ifile,line)){
		stringstream ss(line);
		string tokens[13];
		for(int i=0;i<13;++i){
			getline(ss,tokens[i],',');
		}
		student obj(stoi(tokens[0]),tokens[1],stoi(tokens[2]),stoi(tokens[3]),stoi(tokens[4]),
				tokens[5],stod(tokens[6]),stoi(tokens[7]),tokens[8],tokens[9],
				stoi(tokens[10]),stoi(tokens[11]),tokens[12]);
		s.push_back(obj);
	}
}
void student::save_student(vector<student>& stud){
	ofstream ofile;
			ofile.open("students.csv");
			for(unsigned i=0;i<stud.size();++i){
				ofile<<stud[i].id<<","<<stud[i].name<<","<<stud[i].rank_a<<","<<stud[i].rank_b<<","<<stud[i].rank_c<<","<<stud[i].degree<<","<<stud[i].degree_marks
						<<","<<stud[i].allocated_preference<<","<<stud[i].course_name<<","<<stud[i].center_id<<","<<stud[i].payment<<","<<stud[i].reported<<","<<stud[i].prn<<endl;

			}
			ofile.close();
}
//void student::add_student_in_csv(){
//	ofstream ofile;
//	ofile.open("students.csv"|ios::app);
//	ofile<<id<<","<<name<<","<<rank_a<<","<<rank_b<<","<<rank_c<<","<<degree<<","<<degree_marks
//				<<","<<allocated_preference<<","<<course_name<<","<<center_id<<","<<payment<<","<<reported<<","<<prn<<endl;
//	ofile.close();
//}

student::~student() {
	// TODO Auto-generated destructor stub
}


