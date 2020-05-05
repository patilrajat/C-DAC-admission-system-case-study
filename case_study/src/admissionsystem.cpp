/*
 * admissionsystem.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "admissionsystem.h"
admission_system sys;
admission_system::admission_system() {

}

void admission_system::load_centers(){
	ifstream ifile;
	ifile.open("centers.csv");
	if(!ifile){
		cout<<"fail to open centers"<<endl;
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
		cent.push_back(obj);
	}
}

void admission_system::load_courses(){
	ifstream ifile;
	ifile.open("courses.csv");
	if(!ifile){
		cout<<"fail to open courses"<<endl;
		return;
	}
	string line;
	while(getline(ifile,line)){
		stringstream ss(line);
		string tokens[4];
		for(int i=0;i<4;++i){
			getline(ss,tokens[i],',');
		}
		course obj(stoi(tokens[0]),tokens[1],stod(tokens[2]),
				tokens[3]);
		cour.push_back(obj);
	}
}
void admission_system::load_students(){
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
		stud.push_back(obj);
	}
	ifile.close();

}

void admission_system::load_preferences(){
	ifstream ifile;
	ifile.open("preferences.csv");
	if(!ifile){
		cout<<"fail to open students"<<endl;
		return;
	}
	string line;
	while(getline(ifile,line)){
		stringstream ss(line);
		string tokens[4];
		for(int i=0;i<4;++i){
			getline(ss,tokens[i],',');
		}
		preferences obj(stoi(tokens[0]),stoi(tokens[1]),tokens[2],tokens[3]);
		student *s = find_student(obj.get_form_no());
		s->pref.push_back(obj);
	}
	ifile.close();
}
void admission_system::load_capacities(){
	ifstream ifile;
	ifile.open("capacities.csv");
	if(!ifile){
		cout<<"fail to open students"<<endl;
		return;
	}
	string line;
	while(getline(ifile,line)){
		stringstream ss(line);
		string tokens[4];
		for(int i=0;i<4;++i){
			getline(ss,tokens[i],',');
		}
		capacities obj(tokens[0],tokens[1],stoi(tokens[2]),stoi(tokens[3]));
		capa.push_back(obj);
		center *c=find_center(obj.get_center_id());
		c->centermap[obj.get_name()]=capa.size()-1;
		course *cs=find_course(obj.get_name());
		cs->coursemap[obj.get_center_id()]=capa.size()-1;

	}
	ifile.close();
}
void admission_system::load_eligibilities(){
	ifstream ifile;
	ifile.open("eligibilities.csv");
	if(!ifile){
		cout<<"fail to open students"<<endl;
		return;
	}
	string line;
	while(getline(ifile,line)){
		stringstream ss(line);
		string tokens[3];
		for(int i=0;i<3;++i){
			getline(ss,tokens[i],',');
		}
		eligibilities obj(tokens[0],tokens[1],stod(tokens[2]));
		el.push_back(obj);
		course *c=find_course(obj.get_course_name());
		c->elig.push_back(obj);

	}
	ifile.close();
}
void admission_system::load_degrees()
{
	ifstream ifile;
	ifile.open("degrees.txt");
	if(!ifile){
		cout<<"fail to open students"<<endl;
		return;
	}
	string line;

	while(getline(ifile, line))
	{
		degr.push_back(line);
	}
	ifile.close();

}

center* admission_system::find_center(const string& center_id) {
	unsigned i;
	for(i=0; i<cent.size(); i++) {
		if(cent[i].get_id() == center_id)
			return &cent[i];
	}
	return NULL;
}
course* admission_system::find_course(const string& name) {
	unsigned i;
	for(i=0; i<cour.size(); i++) {
		if(cour[i].get_name() == name)
			return &cour[i];
	}
	return NULL;
}
student* admission_system::find_student(int form_no) {
	unsigned i;
	for(i=0; i<stud.size(); i++) {
		if(stud[i].get_id() == form_no)
			return &stud[i];
	}
	return NULL;
}
void admission_system::display_centers(){
	for(unsigned i=0;i<cent.size();i++){
		cent[i].display_centers();
	}
}
void admission_system::display_courses(){
	for(unsigned i=0;i<cour.size();i++){
		cour[i].display_courses();
	}
}
void admission_system::display_students(){
	for(unsigned i=0;i<stud.size();i++){
		stud[i].display_student_preferences();
	}
}
static bool compare_by_a( student s1, student s2){
	int a=s1.get_rank_a();
	int b=s2.get_rank_a();

	return a<b;

}

void admission_system::sort_by_a(){
	sort(stud.begin(),stud.end(),::compare_by_a);
}
static bool compare_by_b( student s1, student s2){
	int a=s1.get_rank_b();
	int b=s2.get_rank_b();

	return a<b;

}

void admission_system::sort_by_b(){
	sort(stud.begin(),stud.end(),::compare_by_b);
}
static bool compare_by_c( student s1, student s2){
	int a=s1.get_rank_c();
	int b=s2.get_rank_c();

	return a<b;

}

void admission_system::sort_by_c(){
	sort(stud.begin(),stud.end(),::compare_by_c);
}
static bool compare_by_id( student s1, student s2){
	int a=s1.get_id();
	int b=s2.get_id();

	return a<b;

}
void admission_system::sort_by_id(){
	sort(stud.begin(),stud.end(),::compare_by_id);
}

void admission_system::round_1(){
	for(unsigned i=0;i<10;++i){
		sort_by_a();
		for(unsigned j=0;j<stud.size();++j){
			if(stud[j].get_payment()>=0 && stud[j].get_allocated_preference()==0)
				if(stud[j].pref.size()>i)
					if(find_section(stud[j].pref[i])=="A"){
						int index=find_capacity_index(stud[j].pref[i]);
						if(capa[index].get_filled_capacity()<capa[index].get_capacity()){
							int filled=capa[index].get_filled_capacity();
							capa[index].set_filled_capacity(filled+1);
							stud[j].set_allocated_preference(i+1);
							stud[j].set_course_name(stud[j].pref[i].get_course_name());
							stud[j].set_center_id(stud[j].pref[i].get_center_id());

						}
					}
		}
		sort_by_b();
		for(unsigned j=0;j<stud.size();++j){
			if(stud[j].get_payment()>=0 && stud[j].get_allocated_preference()==0){
				if(stud[j].pref.size()>i){
					if(find_section(stud[j].pref[i])=="B"){
						if(stud[j].get_rank_b()!=-1){
							int index=find_capacity_index(stud[j].pref[i]);
							if(capa[index].get_filled_capacity()<capa[index].get_capacity()){
								int filled=capa[index].get_filled_capacity();
								capa[index].set_filled_capacity(filled+1);
								stud[j].set_allocated_preference(i+1);
								stud[j].set_course_name(stud[j].pref[i].get_course_name());
								stud[j].set_center_id(stud[j].pref[i].get_center_id());

							}
						}
					}
				}
			}
		}
		sort_by_c();
		for(unsigned j=0;j<stud.size();++j){
			if(stud[j].get_payment()>=0 && stud[j].get_allocated_preference()==0){
				if(stud[j].pref.size()>i){
					if(find_section(stud[j].pref[i])=="C"){
						if(stud[j].get_rank_c()!=-1){
							int index=find_capacity_index(stud[j].pref[i]);
							if(capa[index].get_filled_capacity()<capa[index].get_capacity()){
								int filled=capa[index].get_filled_capacity();
								capa[index].set_filled_capacity(filled+1);
								stud[j].set_allocated_preference(i+1);
								stud[j].set_course_name(stud[j].pref[i].get_course_name());
								stud[j].set_center_id(stud[j].pref[i].get_center_id());

							}
						}
					}
				}
			}
		}
	}
}

void admission_system::round_2(){
	for(unsigned j=0;j<stud.size();++j){
		if(stud[j].get_allocated_preference()!=0){
			if(stud[j].get_payment()==0)
				stud[j].set_payment(-1);
		}
	}
	for(unsigned j=0;j<stud.size();++j){
		stud[j].set_allocated_preference(0);
		stud[j].set_course_name("NA");
		stud[j].set_center_id("NA");
	}
	for(unsigned j=0;j<capa.size();++j){
		capa[j].set_filled_capacity(0);
	}
	round_1();
}
string& admission_system::find_section(preferences& p){
	return find_course(p.get_course_name())->get_ccat_section();
}

int admission_system::find_capacity_index(preferences& p){
	int c;
	for(unsigned i=0;i<cent.size();++i){
		if(cent[i].get_id()==p.get_center_id())
			c=cent[i].centermap[p.get_course_name()];
	}
	return c;
}

int admission_system::student_menu()
{
	int choice;
	cout<<endl;
	cout<<"0.Exit"<<endl;
	cout<<"1.Register new student"<<endl;
	cout<<"2.Sign in"<<endl;
	cin>>choice;
	return choice;
}
int admission_system::student_menu2(){
	int choice;
	cout<<endl;
	cout<<"0.Exit"<<endl;
	cout<<"1.List courses (as per eligibility)"<<endl;
	cout<<"2.List centers"<<endl;
	cout<<"3.Give preferences"<<endl;
	cout<<"4.See allocated center/course"<<endl;
	cout<<"5.Update payment details"<<endl;
	cin>>choice;
	return choice;
}

int admission_system::admin_menu()
{
	int choice;
	cout<<endl;
	cout<<"0.Exit"<<endl;
	cout<<"1.List courses & eligibilities"<<endl;
	cout<<"2.List centers & capacities"<<endl;
	cout<<"3.List students"<<endl;
	cout<<"4.Update student ranks"<<endl;
	cout<<"5.Allocate centers (Round 1)"<<endl;
	cout<<"6.Allocate centers (Round 2)"<<endl;
	cout<<"7.List allocated students"<<endl;
	cout<<"8.List paid students"<<endl;
	cout<<"9.List reported (at center) students"<<endl;
	cout<<"10.Generate PRN"<<endl;
	cout<<"11.List admitted students (with PRN) for given center"<<endl;
	cin>>choice;
	return choice;
}

int admission_system::coordinator_menu()
{
	int choice;
	cout<<endl;
	cout<<"0.Exit"<<endl;
	cout<<"1.List courses (of that center)"<<endl;
	cout<<"2.List students (allocated to that center)"<<endl;
	cout<<"3.Update reported status"<<endl;
	cout<<"4.List admitted students (with PRN)"<<endl;
	cin>>choice;
	return choice;
}
int admission_system::menu_list()
{
	int choice;
	cout<<endl;
	cout<<"0.Exit"<<endl;
	cout<<"1.Student"<<endl;
	cout<<"2.Admin"<<endl;
	cout<<"3.Center Coordinator"<<endl;
	cin>>choice;
	return choice;
}
void admission_system::list_all_menus(int choice){

	switch(choice)
	{
	case 1:          //student
		int s;
		while((s=student_menu())!=0)
		{
			switch(s)
			{
			case 1: {    //register
				register_student();
				student t;
				t.save_student(stud);
				break;
			}
			case 2:      //sign in
			{
				int form_no;
				string password;
				cout<<"Enter Form Number:";
				cin>>form_no;
				cout<<endl;
				cout<<"Enter Password (name):";
				cin>>password;
				cout<<endl;
				if(student_sign_in(form_no,password)){
					cout<<"SignIn Successfully..."<<endl;
					int c;
					while((c=student_menu2())!=0){
						int id=form_no;
						switch(c)
						{
						case 1:     //1.List courses (as per eligibility)
						{
							cout<<"Eligible courses :"<<endl;
							vector<string> courses=find_eligible_courses(id);
							for(unsigned i=0;i<courses.size();++i){
								cout<<i+1<<"."<<courses[i]<<endl;
							}
							break;
						}
						case 2:      //2.List centers
						{
							display_centers();
							break;
						}
						case 3:      //3.Give Preference(append in csv)
						{
							give_preferences(id);
							break;
						}
						case 4:      //4.See allocated center/course
						{
							student *s1=find_student(id);
							int i=s1->get_allocated_preference()-1;
							if(i>=0)
								cout<<"Allocated Center And Course :"<<s1->pref[i].get_center_id()<<"-"<<s1->pref[i].get_course_name()<<endl;
							else
								cout<<"Yet not allocated/You are not eligible"<<endl;
							break;
						}
						case 5:      //5.Update payment details
						{
							student *s2=find_student(id);
							int a;
							cout<<"Press ( 1 ) if paid 11800\nPress ( 2 ) if not paid 11800"<<endl;
							cin>>a;
							if(a==1)
								s2->set_payment(11800);
							student t;
							t.save_student(stud);
							break;
						}
						default:
						{
							cout<<"enter valid choice"<<endl;
							break;
						}

						}

					}

				}
				else
				{
					cout<<"SignIn Failed...\n"<<endl;
					break;
				}
				cout<<endl;
				break;
			}
			default:
				cout<<"enter valid choice"<<endl;
				break;
			}

		}
		break;
	case 2:
	{
		string username,password;
		cout<<"Enter Username (admin):";
		cin>>username;
		cout<<endl;
		cout<<"Enter Password (admin):";
		cin>>password;
		cout<<endl;

		if(admin_sign_in(username,password)){
			cout<<"SignIn Successfully..."<<endl;
			int a;
			while((a=admin_menu())!=0)
			{
				switch(a)
				{
				case 1:{//1.List courses & eligibilities
					for(unsigned i=0;i<cour.size();i++){
						cour[i].display_courses_without_capacity();
						for(unsigned j=0;j<cour[i].elig.size();j++){
							cour[i].elig[j].display_eligibilities();
						}
					}
					break;
				}
				case 2:{//2.List centers & capacities
					display_centers();
					break;
				}
				case 3:{//3.List students
					display_students();
					break;
				}
				case 4:{//4.Update student ranks
					update_student_rank();
					break;
					student t;
					t.save_student(stud);
				}
				case 5:{//5.Allocate centers (Round 1)
					round_1();
					break;
				}
				case 6:{//6.Allocate centers (Round 2)
					round_2();
					allocated_student_vector();
					break;
				}
				case 7:{//7.List allocated students
					list_allocated();
					break;
				}
				case 8:{//8.List paid students
					list_paid();
					break;
				}
				case 9:{//9.List reported (at center) students
					list_reported();
					break;
				}
				case 10:{//10.Generate PRN
					generate_prn();
					student t;
					t.save_student(stud);
					break;
				}
				case 11:{//11.List admitted students (with PRN) for given center
					admitted_students();
					break;
				}

				}
			}
		}
		else
		{
			cout<<"SignIn Failed...\n"<<endl;
			break;
		}
		break;
	}
	case 3:
	{
		string username,password;
		cout<<"Enter Id (admin):";
		cin>>username;
		cout<<endl;
		cout<<"Enter Password (admin):";
		cin>>password;
		cout<<endl;

		if(coordinator_sign_in(username,password)){
			cout<<"SignIn Successfully..."<<endl;
			int a;
			string id=username;
			while((a=coordinator_menu())!=0)
			{
				switch(a)
				{
				case 1:{//1.List courses (of that center)
					course_of_center(id);
					break;
				}
				case 2:{//2.List students (allocated to that center)
					students_of_center(id);
					break;
				}
				case 3:{//3.Update reported status
					update_reported(id);
					student t;
					t.save_student(stud);
					break;
				}
				case 4:{//4.List admitted students (with PRN)
					students_of_center(id);
					break;
				}

				}
			}
		}
		else
		{
			cout<<"SignIn Failed...\n"<<endl;
			break;
		}

		break;
	}
	default:
	{
		cout<<"Enter valid choice"<<endl;
		break;
	}
	}
}
void admission_system::register_student(){
	int id=stud.size()+1;
	string name;
	int rank_a=0;
	int rank_b=0;
	int rank_c=0;
	string degree;
	double degree_marks;
	int allocated_preference=0;
	string course_name="NA";
	string center_id="NA";
	int payment=0;
	int reported=0;
	string prn="NA";
	cout<<endl<<"Form Number :"<<id<<endl;
	cout<<"Enter name:";
	cin>>name;
	cout<<endl;
	cout<<"Select Degree :"<<endl;
	for(unsigned i=0;i<degr.size();++i){
		cout<<i+1<<"."<<degr[i]<<endl;
	}
	cout<<"Enter choice of degree :";
	int d;
	cin>>d;
	degree=degr[d-1];
	cout<<"Degree :"<<degree<<endl;
	cout<<"Enter Degree Marks:";
	cin>>degree_marks;
	cout<<endl;
	cout<<endl<<"Go to Sign In Now"<<endl;
	student s(id,name,rank_a,rank_b,rank_c,degree,degree_marks,allocated_preference,course_name,center_id,
			payment,reported,prn);
	sys.stud.push_back(s);
}
int admission_system::student_sign_in(int id,const string& name){

	student *s=find_student(id);
	if(s!=NULL){
		if(s->get_name()==name)
			return 1;
		else
			return 0;
	}
	return 0;
}
int admission_system::admin_sign_in(const string& a,const string& b){
	if((a=="admin")&&(b=="admin"))
		return 1;
	else
		return 0;
}
int admission_system::coordinator_sign_in(const string& id,const string& pass){
	center *c=find_center(id);
	if(c!=NULL){
		if(c->get_password()==pass)
			return 1;
		else
			return 0;
	}
	return 0;
}
vector<string> admission_system::find_eligible_courses(int id){
	student *s=find_student(id);
	int count=0;
	vector<string> courses;
	for(unsigned i=0;i<el.size();++i){
		if((s->get_degree()==el[i].get_degree())&&(s->get_degree_marks()>=el[i].get_min_percentage())){
			courses.push_back(el[i].get_course_name());
			++count;
		}
	}
	if(count==0){
		cout<<"You are not eligible for any course";
	}
	return courses;
}

void admission_system::save_preference(preferences& pr){
	ofstream ofile;
	ofile.open("preferences.csv", ios::app);
	ofile<<pr.get_form_no()<<","<<pr.get_preference()<<","<<pr.get_course_name()<<","<<pr.get_center_id()<<endl;
	ofile.close();
}
void admission_system::give_preferences(int id){
	student *s=find_student(id);
	vector<string> courses=find_eligible_courses(id);
	cout<<"Eligible Centers:"<<endl;
	int count,b=0;
	vector<int> pre;
	for(unsigned i=0;i<courses.size();++i){
		for(unsigned j=0;j<capa.size();++j){
			if(courses[i]==capa[j].get_name()){
				cout<<++b<<"."<<capa[j].get_center_id()<<":"<<capa[j].get_name()<<endl;
				pre.push_back(j);
			}
		}
	}
	if(b>0){
		cout<<"Number of preferences You want to give max 10:";
		cin>>count;
		int a;
		for(int i=0;i<count;++i)
		{
			cout<<"Preference"<<i+1<<" : ";
			cin>>a;
			preferences obj(id,i+1,capa[pre[a-1]].get_name(),capa[pre[a-1]].get_center_id());
			s->pref.push_back(obj);
			save_preference(obj);
		}
	}
}
void admission_system::update_student_rank(){
	int count;
	cout<<"Number of student for Update Rank :";
	cin>>count;
	cout<<endl;
	for(int i=0;i<count;++i){
		cout<<i+1<<". Form Number to add rank :";
		int no;
		cin>>no;
		cout<<endl;
		student *s=find_student(no);
		cout<<"Enter "<<s->get_name()<<"Rank A :";
		int a;
		cin>>a;
		s->set_rank_a(a);
		cout<<endl;
		cout<<"Enter "<<s->get_name()<<"Rank B :";
		int b;
		cin>>b;
		s->set_rank_b(b);
		cout<<endl;
		cout<<"Enter "<<s->get_name()<<"Rank C :";
		int c;
		cin>>c;
		s->set_rank_c(c);
		cout<<endl;
	}
}
void admission_system::list_allocated(){
	for(unsigned i=0;i<round2.size();++i){
		cout<<round2[i].get_course_name()<<"\t"<<round2[i].get_center_id()<<"\t"<<round2[i].get_name()<<endl;
	}
}
void admission_system::list_paid(){
	for(unsigned i=0;i<round2.size();++i){
		if(round2[i].get_payment()>0){
			cout<<round2[i].get_course_name()<<"\t"<<round2[i].get_center_id()<<"\t"<<round2[i].get_name()<<"\t"<<round2[i].get_payment()<<endl;
		}
	}
}
void admission_system::admitted_students(){
	vector<string> v;
	v.push_back("PG-DAC");
	v.push_back("PG-DMC");
	v.push_back("PG-DESD");
	v.push_back("PG-DBDA");
	v.push_back("PG-DGI");
	cout<<"count"<<endl;
	cout<<"Enter course choice"<<endl;
	cout<<"1.PG-DAC"<<endl;
	cout<<"2.PG-DMC"<<endl;
	cout<<"3.PG-DESD"<<endl;
	cout<<"4.PG-DBDA"<<endl;
	cout<<"5.PG-DGI"<<endl;
	int a;
	cin>>a;
	vector<string> v2;
	v2.push_back("SIP");
	v2.push_back("SIK");
	v2.push_back("ACP");
	v2.push_back("ACN");
	cout<<"Enter course choice"<<endl;
	cout<<"1.SIP"<<endl;
	cout<<"2.SIK"<<endl;
	cout<<"3.ACP"<<endl;
	cout<<"4.ACN"<<endl;
	int b;
	cin>>b;
	int count=0;

	for(unsigned i=0;i<round2.size();++i){
		if((round2[i].get_course_name()==v[a-1]) && (round2[i].get_center_id()==v2[b-1])){
			cout<<round2[i].get_course_name()<<"\t"<<round2[i].get_center_id()<<"\t"<<round2[i].get_name()<<"\t"<<round2[i].get_prn()<<endl;
			++count;
		}
	}
	if(count==0)
		cout<<"No student with"<<v[a-1]<<" and "<<v2[b-1]<<endl;
}
void admission_system::list_reported(){
	for(unsigned i=0;i<round2.size();++i){
		if(round2[i].get_reported()>0){
			cout<<round2[i].get_course_name()<<"\t"<<round2[i].get_center_id()<<"\t"<<round2[i].get_name()<<endl;
		}
	}
}
static bool compare_by_course( student s1, student s2){
	string a=s1.get_course_name();
	string b=s2.get_course_name();

	return a<b;

}
static bool compare_by_center( student s1, student s2){
	string a=s1.get_center_id();
	string b=s2.get_center_id();

	return a<b;

}
static bool compare_by_name( student s1, student s2){
	string a=s1.get_name();
	string b=s2.get_name();

	return a<b;

}
void admission_system::allocated_student_vector(){
	for(unsigned i=0;i<stud.size();++i){
		if(stud[i].get_allocated_preference()>0)
			round2.push_back(stud[i]);
	}
	sort(round2.begin(),round2.end(),compare_by_course);
	sort(round2.begin(),round2.end(),compare_by_center);
	sort(round2.begin(),round2.end(),compare_by_name);
}
void admission_system::generate_prn(){
	for(unsigned i=0;i<round2.size();++i){
		string a=round2[i].get_course_name();
		string b=round2[i].get_center_id();
		string c=to_string(i+1);
		string d="_";
		string e=a+d+b+d+c;
		round2[i].set_prn(e);
		student *s=find_student(round2[i].get_id());
		s->set_prn(e);
	}
}
void admission_system::course_of_center(const string& id){
	for(unsigned i=0;i<capa.size();++i){
		if(capa[i].get_center_id()==id)
			cout<<capa[i].get_name()<<endl;
	}
}
void admission_system::students_of_center(const string& id){
	vector<string> v;
	v.push_back("PG-DAC");
	v.push_back("PG-DMC");
	v.push_back("PG-DESD");
	v.push_back("PG-DBDA");
	v.push_back("PG-DGI");
	cout<<"count"<<endl;
	cout<<"Enter course choice"<<endl;
	cout<<"1.PG-DAC"<<endl;
	cout<<"2.PG-DMC"<<endl;
	cout<<"3.PG-DESD"<<endl;
	cout<<"4.PG-DBDA"<<endl;
	cout<<"5.PG-DGI"<<endl;
	int a;
	cin>>a;
	int count=0;
	for(unsigned i=0;i<round2.size();++i){
		if((round2[i].get_course_name()==v[a-1]) && (round2[i].get_center_id()==id)){
			cout<<round2[i].get_course_name()<<"\t"<<round2[i].get_center_id()<<"\t"<<round2[i].get_name()<<"\t"<<round2[i].get_prn()<<endl;
			++count;
		}
	}
	if(count==0)
		cout<<"No such a student"<<endl;
}
void admission_system::update_reported(const string& id){
	cout<<"Students allocated at your center"<<endl;
	for(unsigned i=0;i<round2.size();++i){
		if(round2[i].get_center_id()==id)
			cout<<round2[i].get_id()<<"\t"<<round2[i].get_course_name()<<"\t"<<round2[i].get_center_id()<<"\t"<<round2[i].get_name()<<"\t"<<round2[i].get_prn()<<endl;
	}
	cout<<"Enter number of student reported :";
	int a;
	cin>>a;
	cout<<endl;
	for(int i=0;i<a;++i){
		cout<<i+1<<". Enter id to update :";
		int b;
		cin>>b;
		cout<<endl;
		student *s=find_student(b);
		if(s->get_center_id()==id){
			cout<<s->get_name()<<"\n press ( 1 ) if present\n press ( 2 ) if not present"<<endl;
			int c;
			cin>>c;
			cout<<endl;
			if(c==1){
				s->set_reported(1);
				for(unsigned i=0;i<round2.size();++i){
					if(round2[i].get_id()==b)
						round2[i].set_reported(1);
				}
			}
		}
		else
			cout<<"THis student not allocated at your center"<<endl;
	}
}

admission_system::~admission_system() {
	// TODO Auto-generated destructor stub
}

