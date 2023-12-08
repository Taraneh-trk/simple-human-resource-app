//                            Taraneh kordi
#include <iostream>
#include <sstream>
#include <conio.h>
#include <fstream>
#include <cstdlib>
using namespace std;

bool flaglogin = false;
bool flagcreataccount = true;
bool flagsearchperson = false;
bool flagadmin = false;  
enum TeamLevel { junior = 0 , intermed = 1 , senior = 2 };
enum Level { admin = -1 , ordinary = -2 };
struct personinformation{
	string name;
	string lastname;
	string position;
	float workexperience;
	long long int salary;
	TeamLevel teamlevel;
	Level level;
	int membernuminfile;
}prsn1;
class Person;
class Admin;
class OrdinaryStaff;
class guardian;
class DatabaseTeam;
class ProgrammingTeam;
class Tester;

class Login{
	private:
		string username;
		long password;
	public:
		Login(int n)
		{
			if(n==0){
				LOGIN();
			}else{
				creataccount();
			}
		}
		void LOGIN()
		{
			char ch;
			cout<<"\ndo you remember your username & password (y/n) ? ";
			cin>>ch;
			if(ch=='y'){
				cout<<"\nenter username (string) : ";
				getline(cin>>std::ws,username);
				cout<<"\nenter password (int) : ";
				cin>>password;
				fstream f1;
				f1.open("login.txt",ios::in | ios::out);
				if(!f1){
					cout<<"\nerror in openning file . \n";
					exit(0);
				}
				string start;
				getline(f1,start);
				string usercheck;
				string pass;
				int counter=0;
				while(!f1.eof())
				{
					getline(f1,usercheck);
					getline(f1,pass);
					long passcheck = atol(pass.c_str());
					if(usercheck == username && passcheck == password){
						counter++;
						break;
					}	
				}
				if(counter==1)
				{
					cout<<"\nlogin succesfully . \n";
					flaglogin = true;
				}else{
					cout<<"\nusername & password are wrong . \nplease try again . \n";
					LOGIN();
				}
				f1.close();	
			}else{
				cout<<"\nso creat a account . \n";
				creataccount();
			}
		}
		void creataccount()
		{
			cout<<"\nenter username (string) : ";
			getline(cin>>std::ws,username);
			cout<<"\nenter password (int) : ";
			cin>>password;
			fstream f2;
			string usercheck;
			string pass;
			int counter=0;
			int num = 0;
			f2.open("login.txt",ios::in | ios::out);
			if(!f2){
				cout<<"\nerror in openning file . \n";
				exit(0);
			}
			string start;
			getline(f2,start);
			while(!f2.eof())
			{
				getline(f2,usercheck);
				getline(f2,pass);
				long passcheck = atol(pass.c_str());
				if(usercheck == username && passcheck == password){
					counter++;
					break;
				}
				num++;
			}
			if(counter==0){
				f2.close();
				fstream f3;
				f3.open("login.txt",ios::app);
				if(!f3){
				cout<<"\nerror in openning file . \n";
				return ;
				}
				if(num == 0){
					f3<<"start";
					f3<<'\n'<<username<<'\n'<<password;
				}else{
					f3<<'\n'<<username<<'\n'<<password;
				}
				f3.close();
				cout<<"\naccount created . and all files are deleted too . \n";
				fstream finfo;
				finfo.open("DatabaseTeam info.txt",ios::trunc | ios::in | ios::out);
				finfo<<"start";
				finfo.close();
				finfo.open("ProgrammingTeam info.txt",ios::trunc | ios::in | ios::out);
				finfo<<"start";
				finfo.close();
				finfo.open("Testers info.txt",ios::trunc | ios::in | ios::out);
				finfo<<"start";
				finfo.close();
				finfo.open("guardians info.txt",ios::trunc | ios::in | ios::out);
				finfo<<"start";
				finfo.close();
			}else{
				cout<<"\nusername & password are before used . \nplease try again . \n";
				creataccount();
			}
		}
		
		friend class Menu;
};
class Person{
	protected:
		personinformation personionfo;
	public:
		Person() { }
		void setperson(personinformation personionfo)
		{
			this->personionfo.name = personionfo.name;
			this->personionfo.lastname = personionfo.lastname;
			this->personionfo.position = personionfo.position;
			this->personionfo.level = personionfo.level;
			this->personionfo.teamlevel = personionfo.teamlevel;
			this->personionfo.workexperience = personionfo.workexperience;
			this->personionfo.salary = personionfo.salary;
		}
		virtual string tostring()   // hint : to_string() is not work on my IDE
		{
			stringstream str;
			str<<'\n'<<personionfo.name<<'\n'<<personionfo.lastname;
			str<<'\n'<<personionfo.level<<'\n'<<personionfo.teamlevel;
			str<<'\n'<<personionfo.salary;
			str<<'\n'<<personionfo.workexperience;
			string strResult = str.str();
			return strResult;
		}
		friend class Menu;
};
class Admin : public Person
{
	public:
		Admin() : Person() { }
		void setadmin(personinformation personionfo)
		{
			personionfo.level = admin;
			Person::setperson(personionfo);
		}
		string tostring()   // hint : to_string() is not work on my IDE
		{
			stringstream str;
			str<<'\n'<<personionfo.name<<'\n'<<personionfo.lastname;
			str<<'\n'<<admin<<'\n'<<personionfo.teamlevel;
			str<<'\n'<<personionfo.salary;
			str<<'\n'<<personionfo.workexperience;
			string strResult = str.str();
			return strResult;
		}
};
class OrdinaryStaff : public Person
{
	public:
		OrdinaryStaff() : Person() { }
		void setOrdinaryStaff(personinformation personionfo)
		{
			personionfo.level = ordinary;
			Person::setperson(personionfo);
		}
		string tostring()   // hint : to_string() is not work on my IDE
		{
			stringstream str;
			str<<'\n'<<personionfo.name<<'\n'<<personionfo.lastname;
			str<<'\n'<<ordinary<<'\n'<<personionfo.teamlevel;
			str<<'\n'<<personionfo.salary;
			str<<'\n'<<personionfo.workexperience;
			string strResult = str.str();
			return strResult;
		}
};
class guardian : public OrdinaryStaff
{
	public:
		Admin admin;
		guardian() : OrdinaryStaff() { }
		void setguardian(personinformation personionfo)
		{
			OrdinaryStaff::setOrdinaryStaff(personionfo);
		}
	
};
class DatabaseTeam : public OrdinaryStaff
{
	public:
		Admin admin;
		DatabaseTeam() : OrdinaryStaff() { }
		void setDatabaseTeammember(personinformation personionfo)
		{
			OrdinaryStaff::setOrdinaryStaff(personionfo);
		}
};
class ProgrammingTeam : public OrdinaryStaff
{
	public:
		 Admin admin;
		 ProgrammingTeam() : OrdinaryStaff() { }
		 void setProgrammingTeammember(personinformation personionfo)
		 {
		 	OrdinaryStaff::setOrdinaryStaff(personionfo);
		 }
		
};
class Tester : public OrdinaryStaff
{
	public:
		Admin admin;
		Tester() : OrdinaryStaff() { }
		void setTestermember(personinformation personionfo)
		{
			OrdinaryStaff::setOrdinaryStaff(personionfo);
		}
};
string getchar(int n)
{
	switch(n)
	{
		case -1:
			return "admin";
			break;
		case -2:
			return "ordinary";
			break;
		case 0:
			return "junior";
			break;
		case 1:
			return "intermed";
			break;
		case 2:
			return "senior";
			break;
	}
}
Level getnum(int in,int pos)
{
	switch(in)
	{
		case -1:
			return admin;
			break;
		case -2:
			return ordinary;
			break;
	}
}
TeamLevel getnum(int in)
{
	switch(in)
	{
		case 0:
			return junior;
			break;
		case 1:
			return intermed;
			break;
		case 2:
			return senior;
			break;
	}
}
ostream &operator<< (ostream &output,personinformation personionfo)
{
	output<<"\nname : "<<personionfo.name;
	output<<"\nlastname : "<<personionfo.lastname;
	output<<"\nlevel (admin or ordinary) : "<<getchar(personionfo.level);
	output<<"\nteam level (junior or intermed or senior) : "<<getchar(personionfo.teamlevel);
	output<<"\nsalary : "<<personionfo.salary;
	output<<"\nworkexperience : "<<personionfo.workexperience;
	return output;
}
istream &operator>> (istream &input,personinformation &personionfo)
{
	int in;
	cout<<"\nenter member's name : ";
	input>>personionfo.name;
	cout<<"\nenter member's lastname : ";
	input>>personionfo.lastname;
	cout<<"\nenter member's level (admin -> (-1) or ordinary -> (-2)) : ";
	input>>in;
	personionfo.level = getnum(in,0);
	if(personionfo.level == admin)
		flagadmin = true;
	cout<<"\nenter member's team level (junior -> (0) or intermed -> (1) or senior -> (2)) : ";
	input>>in;
	personionfo.teamlevel = getnum(in);
	cout<<"\nenter member's salary : ";
	input>>personionfo.salary;
	cout<<"\nenter member's workexperience : ";
	input>>personionfo.workexperience;
	return input;
}
personinformation readfromfile(fstream *finfo)
{
	personinformation prsn;
	
	string strtemp;
	getline(*finfo,prsn.name);
	getline(*finfo,prsn.lastname);
	getline(*finfo,strtemp);
	prsn.level = getnum(atoi(strtemp.c_str()),0);
	getline(*finfo,strtemp);
	prsn.teamlevel = getnum(atoi(strtemp.c_str()));
	getline(*finfo,strtemp);
	prsn.salary = atoi(strtemp.c_str());
	getline(*finfo,strtemp);
	prsn.workexperience = atof(strtemp.c_str());
	
	return prsn;
}
class Menu{
	private:
		char ch;
	public:
		Menu(){
			if(flagcreataccount == true){
				cout<<"do you have an account ? ";
				cin>>ch;
			}else{
				ch='y';
			}
			if(ch=='y'){
				while(1)
				{
					int n;
					if(flaglogin){
						cout<<"\n1- show";
						cout<<"\n2- add";
						cout<<"\n3- delete";
						cout<<"\n4- search";
						cout<<"\n5- edit";
						cout<<"\n6- total number";
						cout<<"\n7- exit";
						cout<<"\n\nenter your choose : ";
					}else{
						cout<<"\n0- login";
						cout<<"\n\nenter your choose : ";
					}
					cin>>n;
					switch(n)
					{
						case 0:
							logintoprofile();
							break;
						case 1:
							show();
							break;
						case 2:
							add();
							break;
						case 3:
							Delete();
							break;
						case 4:
							search();
							break;
						case 5:
							edit();
							break;
						case 6:
							totalnumber();
							break;
						case 7:
							return ;
						//use return instead of exit(0) for exicuting destructer
					}
				}
		}else{
			cout<<"\ncreat your account : ";
			Login log1(1);
			flagcreataccount = false;
			Menu();
		}
		}
		long long int teamnum(string position)
		{
			fstream finfo;
				if(position == "DatabaseTeam")
					finfo.open("DatabaseTeam info.txt",ios::in | ios::out);
				else if(position == "ProgrammingTeam")
						finfo.open("ProgrammingTeam info.txt",ios::in | ios::out);
					else if(position == "Testers")
							finfo.open("Testers info.txt",ios::in | ios::out);
						else if(position == "guardians")
								finfo.open("guardians info.txt",ios::in | ios::out);
			if(!finfo){
				cout<<"\nerror in openning file . \n";
				exit(0);
			}
			personinformation prsn;
			string start;
			getline(finfo,start);
			int num = 0;
			while(!finfo.eof())
			{
				readfromfile(&finfo);
				num++;
			}
			finfo.close();
			return num;
		}
		void totalnumber()
		{
			while(1)
			{
				int choose;
				cout<<"\ntotal number of which team ? ";
				cout<<"\n1- DatabaseTeam";
				cout<<"\n2- ProgrammingTeam";
				cout<<"\n3- Testers";
				cout<<"\n4- guardians";
				cout<<"\n5- whole";
				cout<<"\n6- finish";
				cout<<"\nenter your choose : ";
				cin>>choose;
				switch(choose)
				{
					case 1:
						cout<<"\ntotal number of DatabaseTeam : ";
						cout<<teamnum("DatabaseTeam")<<" member";
						cout<<endl;
						break;
					case 2:
						cout<<"\ntotal number of ProgrammingTeam : ";
						cout<<teamnum("ProgrammingTeam")<<" member";
						cout<<endl;
						break;
					case 3:
						cout<<"\ntotal number of Testers : ";
						cout<<teamnum("Testers")<<" member";
						cout<<endl;
						break;
					case 4:
						cout<<"\ntotal number of guardians : ";
						cout<<teamnum("guardians")<<" member";
						cout<<endl;
						break;
					case 5:
						cout<<"\ntotal number of whole : ";
						cout<<teamnum("DatabaseTeam") + teamnum("ProgrammingTeam") + teamnum("Testers") + teamnum("guardians")<<" member";
						cout<<endl;
						break;
					case 6:
						return ;
						break;
				}
				char ch;
				cout<<"\ndo you want to continue ? (y/n) : ";
				cin>>ch;
				if(ch == 'n')
					break;
			}
		}
		void logintoprofile()
		{
			Login log1(0);
		}
		void show()
		{
			while(1)
			{
				int choose;
				cout<<"\nwhat to show ? ";
				cout<<"\n1- DatabaseTeam";
				cout<<"\n2- ProgrammingTeam";
				cout<<"\n3- Testers";
				cout<<"\n4- guardians";
				cout<<"\n5- whole";
				cout<<"\n6- finish to show";
				cout<<"\nenter your choose : ";
				cin>>choose;
				DatabaseTeam database;
				ProgrammingTeam program;
				Tester tester;
				guardian guard;
				switch(choose){
					case 1:
						show(database,1);
						break;
					case 2:
						show(program,2);
						break;
					case 3:
						show(tester,3);
						break;
					case 4:
						show(guard,4);
						break;
					case 5:
						show(database,1);
						show(program,2);
						show(tester,3);
						show(guard,4);
						break;
					default:
						return ;
				}
			}
		}
		template<class t>
		void show(t team,int teampos)
		{
			fstream finfo;
			string position;
			switch(teampos)
			{
				case 1:
					finfo.open("DatabaseTeam info.txt",ios::in | ios::out);
					position = "DatabaseTeam";
					break;
				case 2:
					finfo.open("ProgrammingTeam info.txt",ios::in | ios::out);
					position = "ProgrammingTeam";
					break;
				case 3:
					finfo.open("Testers info.txt",ios::in | ios::out);
					position = "Testers";
					break;
				case 4:
					finfo.open("guardians info.txt",ios::in | ios::out);
					position = "guardians";
					break;
			}
			if(!finfo){
				cout<<"\nerror in openning file . \n";
				exit(0);
			}
			int i=1;
			string strtemp;
			string start;
			getline(finfo,start);
			int membernum = teamnum(position);
			cout<<'\n'<<position<<" are as follows: ";
			if(membernum == 0)
			{
				cout<<"\nno member existed . \n";
			}
			while(!finfo.eof())
			{
				cout<<'\n';
				cout<<"\nmember number "<<i<<" : ";
				team.personionfo = readfromfile(&finfo);
				cout<<team.personionfo;
				i++;
				cout<<'\n';
			}
			finfo.close();
		}
		void add()
		{
			while(1)
			{
				int choose;
				cout<<"\nwhere to add ? ";
				cout<<"\n1- DatabaseTeam";
				cout<<"\n2- ProgrammingTeam";
				cout<<"\n3- Testers";
				cout<<"\n4- guardians";
				cout<<"\n5- finish to add";
				cout<<"\nenter your choose : ";
				cin>>choose;
				DatabaseTeam database;
				ProgrammingTeam program;
				Tester tester;
				guardian guard;
				int numbertoadd;
				int i=1;
				if(choose!=5){
					cout<<"\nhow many member you want to add ? ";
					cin>>numbertoadd;
				}
				switch(choose){
					case 1:
						while(numbertoadd!=0)
						{
							add(database,1,i);
							numbertoadd--;
							i++;
						}
						break;
					case 2:
						while(numbertoadd!=0)
						{
							add(program,2,i);
							numbertoadd--;
							i++;
						}
						break;
					case 3:
						while(numbertoadd!=0)
						{
							add(tester,3,i);
							numbertoadd--;
							i++;
						}
						break;
					case 4:
						while(numbertoadd!=0)
						{
							add(guard,4,i);
							numbertoadd--;
							i++;
						}
						break;
					default:
						return ;
				}
			}
		}
		template<class t>
		void add(t team,int teampos,int num)
		{
			fstream finfo;
			string position;
			switch(teampos)
			{
				case 1:
					finfo.open("DatabaseTeam info.txt",ios::app);
					position = "DatabaseTeam";
					break;
				case 2:
					finfo.open("ProgrammingTeam info.txt",ios::app);
					position = "ProgrammingTeam";
					break;
				case 3:
					finfo.open("Testers info.txt",ios::app);
					position = "Testers";
					break;
				case 4:
					finfo.open("guardians info.txt",ios::app);
					position = "guardians";
					break;
			}
			if(!finfo){
				cout<<"\nerror in openning file . \n";
				exit(0);
			}
			cout<<"\nmember number "<<num;
			cin>>team.personionfo;
			if(flagadmin){
				team.admin.personionfo = team.personionfo;
				finfo<<team.admin.tostring();
			}else 
				finfo<<team.tostring();
			finfo.close();
			cout<<"\naddad succesfully . \n";
			flagadmin = false;
		}
		void Delete()
		{
			while(1)
			{
				cout<<"\nfind who do you want to delete by searching it : ";
				search(-1);  //glabal variable to save  prsn1
				// number of person  prsn1.membernuminfile
				if(flagsearchperson)
				{
					fstream finfo;
					if(prsn1.position == "DatabaseTeam")
						finfo.open("DatabaseTeam info.txt",ios::in | ios::out);
					else if(prsn1.position == "ProgrammingTeam")
							finfo.open("ProgrammingTeam info.txt",ios::in | ios::out);
						else if(prsn1.position == "Testers")
								finfo.open("Testers info.txt",ios::in | ios::out);
							else if(prsn1.position == "guardians")
									finfo.open("guardians info.txt",ios::in | ios::out);
					if(!finfo){
						cout<<"\nerror in openning file . \n";
						exit(0);
					}
					string start;
					getline(finfo,start);
					int membernum = teamnum(prsn1.position);
					Person prsns[membernum],prsntemp;
					int num = 1;
					int i=0;
					for(int j=0;j<membernum;j++)
					{
						if(num != prsn1.membernuminfile)
						{
							prsns[i].personionfo = readfromfile(&finfo);
							i++;
						}else{
							prsntemp.personionfo = readfromfile(&finfo);
						}
						num++;
					}
					finfo.close();
					
					fstream finfo1;
					if(prsn1.position == "DatabaseTeam")
						finfo1.open("DatabaseTeam info.txt",ios::trunc | ios::in | ios::out);
					else if(prsn1.position == "ProgrammingTeam")
							finfo1.open("ProgrammingTeam info.txt",ios::trunc | ios::in | ios::out);
						else if(prsn1.position == "Testers")
								finfo1.open("Testers info.txt",ios::trunc | ios::in | ios::out);
							else if(prsn1.position == "guardians")
									finfo1.open("guardians info.txt",ios::trunc |ios::in | ios::out );
					if(!finfo){
						cout<<"\nerror in openning file . \n";
						exit(0);
					}
					finfo1<<start;
					for(int i=0;i<membernum-1;i++)
					{
						finfo1<<prsns[i].tostring();
					}
					finfo1.close();
					
					cout<<"\ndeleted succesfully . \n";
				}else
					cout<<"\nnoting deleted . \n";
				char ch;
				cout<<"\ndo you want to delete more people ? (y/n) : ";
				cin>>ch;
				if(ch == 'n')
					break;
			}
		}
		void search(int pass = 0)
		{
			while(1)
			{
				int choose;
				cout<<"\nwhere to search ? ";
				cout<<"\n1- DatabaseTeam";
				cout<<"\n2- ProgrammingTeam";
				cout<<"\n3- Testers";
				cout<<"\n4- guardians";
				cout<<"\n5- whole(if you don't know where he/she work)";
				cout<<"\n6- finish to search";
				cout<<"\nenter your choose : ";
				cin>>choose;
				DatabaseTeam database;
				ProgrammingTeam program;
				Tester tester;
				guardian guard;
				switch(choose){
					case 1:
						flagsearchperson = false;
						search(database,1);
						break;
					case 2:
						flagsearchperson = false;
						search(program,2);
						break;
					case 3:
						flagsearchperson = false;
						search(tester,3);
						break;
					case 4:
						flagsearchperson = false;
						search(guard,4);
						break;
					case 5:
						flagsearchperson = false;
						search(database,1,5);
						if(flagsearchperson == false)
						{
							search(program,2,4);
							if(flagsearchperson == false)
							{
								search(tester,3,3);
								if(flagsearchperson == false)
								{
									search(guard,4,2);
								}
							}
						}	
						break;
					default:
						return ;
				}
				if(pass == -1 || pass == -2)
					break;
			}
		}
		template<class t>
		void search(t team,int teampos,int whole = 0)
		{
			fstream finfo;
			string position;
			switch(teampos)
			{
				case 1:
					finfo.open("DatabaseTeam info.txt",ios::in | ios::out);
					position = "DatabaseTeam";
					break;
				case 2:
					finfo.open("ProgrammingTeam info.txt",ios::in | ios::out);
					position = "ProgrammingTeam";
					break;
				case 3:
					finfo.open("Testers info.txt",ios::in | ios::out);
					position = "Testers";
					break;
				case 4:
					finfo.open("guardians info.txt",ios::in | ios::out);
					position = "guardians";
					break;
			}
			if(!finfo){
				cout<<"\nerror in openning file . \n";
				exit(0);
			}
			//prsn1
			string start;
			getline(finfo,start);
			int num = 1;
			if(whole == 0 || whole == 5)
			{
				cout<<"\nenter person's name whom you search for : ";
				cin>>prsn1.name;
				cout<<"\nenter person's lastname whom you search for : ";
				cin>>prsn1.lastname;
			}
			while(!finfo.eof())
			{
				team.personionfo = readfromfile(&finfo);
				if(prsn1.name == team.personionfo.name && prsn1.lastname == team.personionfo.lastname)
				{
					flagsearchperson = true;
					break;
				}
				num++;
			}
			if(flagsearchperson)
			{
				cout<<"\ninformation about "<<prsn1.name<<" "<<prsn1.lastname<<" who work in "<<position<<" : ";
				cout<<team.personionfo<<'\n';
				prsn1.position = position;
				prsn1.level = team.personionfo.level;
				prsn1.teamlevel = team.personionfo.teamlevel;
				prsn1.salary = team.personionfo.salary;
				prsn1.workexperience = team.personionfo.workexperience;
				prsn1.membernuminfile = num;
			}else{
				if(whole == 0 || whole == 2)
				{
					cout<<"\nsuch person was not found . \nplease try again . \n";
					flagsearchperson = false;
				}
			}
			finfo.close();
		}
		void edit()
		{
			while(1)
			{
				cout<<"\nfind who do you want to edit by searching it : ";
				search(-2);  //glabal variable to save prsn1
				if(flagsearchperson)
				{
					fstream finfo;
					if(prsn1.position == "DatabaseTeam")
						finfo.open("DatabaseTeam info.txt",ios::in | ios::out);
					else if(prsn1.position == "ProgrammingTeam")
							finfo.open("ProgrammingTeam info.txt",ios::in | ios::out);
						else if(prsn1.position == "Testers")
								finfo.open("Testers info.txt",ios::in | ios::out);
							else if(prsn1.position == "guardians")
									finfo.open("guardians info.txt",ios::in | ios::out);
					if(!finfo){
						cout<<"\nerror in openning file . \n";
						exit(0);
					}
					string start;
					getline(finfo,start);
					int membernum = teamnum(prsn1.position);
					Person prsns[membernum],prsntemp;
					int num = 1;
					int i=0;
					for(int j=0;j<membernum;j++)
					{
						if(num != prsn1.membernuminfile)
						{
							prsns[j].personionfo = readfromfile(&finfo);
						}else{
							prsns[j].personionfo = readfromfile(&finfo);
							cout<<"\nenter information by what you want to edit : ";
							cin>>prsns[j].personionfo;
						}
						num++;
					}
					finfo.close();
					
					fstream finfo1;
					if(prsn1.position == "DatabaseTeam")
						finfo1.open("DatabaseTeam info.txt",ios::trunc | ios::in | ios::out);
					else if(prsn1.position == "ProgrammingTeam")
							finfo1.open("ProgrammingTeam info.txt",ios::trunc | ios::in | ios::out);
						else if(prsn1.position == "Testers")
								finfo1.open("Testers info.txt",ios::trunc | ios::in | ios::out);
							else if(prsn1.position == "guardians")
									finfo1.open("guardians info.txt",ios::trunc |ios::in | ios::out );
					if(!finfo){
						cout<<"\nerror in openning file . \n";
						exit(0);
					}
					finfo1<<start;
					for(int i=0;i<membernum;i++)
					{
						finfo1<<prsns[i].Person::tostring();
					}
					finfo1.close();
					
					cout<<"\nedited succesfully . \n";
				}else
					cout<<"\nnothing edited . \n";
				char ch;
				cout<<"\ndo you want to edit more people ? (y/n) : ";
				cin>>ch;
				if(ch == 'n')
					break;
			}
		}
		~Menu()
		{
			cout<<"\n\nthe end ...................\n";
		}
		friend class Login;
		friend class Person;
};
int main()
{
	Menu menu1;
	
	return 0;
}
