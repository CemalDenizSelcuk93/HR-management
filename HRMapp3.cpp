#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>

using std::string;
using namespace std;
	int count=0;
	int id=8901;

class person{
	
private:

	int Personalid;

public:
	
	string Firstname;
	string Lastname;
	string fn;
	string ln;
	double Workinghours;
	double Costperhour;
	double Salary;
	double wh;
	double cph;
	void set0_Fieldname() {
		fn="Deleted data";
		ln="Deleted data";
		wh=0;
		cph=0;
		in_Firstname();
		in_Lastname();
		in_Workinghour();
		in_Costperhour();
		set_salary();
	};

	void set_Fieldname(){
		cout<<"Please type the name of the employee:"<<endl;
		cin>>fn;
		in_Firstname();
		cout<<endl;
		
		cout<<"Please type the surname:"<<endl;
		cin>>ln;
		in_Lastname();
		cout<<endl;
		
		cout<<"please enter hours worked per month:"<<endl;
		cin>>wh;
		in_Workinghour();
		cout<<endl;
		
		cout<<"Please enter cost per hour:"<<endl;
		cin>>cph;
		in_Costperhour();
		cout<<endl;	
		set_salary(); 		 
		get_Fieldname();  
	}
	void set_update(){
		       
						

				int c;
				cin>>c;
				
				cout<<endl;
				if(c==1){
				cout<<"Please type the new name of the person:"<<endl;
				set_Firstname();
				cout<<"Employee has been updated, actual info are below:"<<endl;
				get_Fieldname();
				}
				else if(c==2){
				cout<<"Please type the new surname of the person:"<<endl;
				set_Lastname();
				cout<<"Employee has been updated, actual info are below:"<<endl;
				get_Fieldname();
				}
				else if(c==3){
				cout<<"Please type the new amount of working hours of the person:"<<endl;
				set_Workinghour();
				set_salary();
				cout<<"Employee has been updated, actual info are below:"<<endl;
				get_Fieldname();
				}
				else if(c==4){
				cout<<"Please type the new cost per hour for this person:"<<endl;
				set_Costperhour();
				set_salary();
				cout<<"Employee has been updated, actual info are below:"<<endl;
				get_Fieldname();
				}
				else{
					cout<<"Please type a valid digit for these four options:"<<endl;
				}				
				

	}
	
   void get_Fieldname(){
		cout<<"The persons data:"<<endl;
		cout<<"Name:"<<Firstname<<" "<<Lastname<<endl;
		cout<<"Id:"<<Personalid<<endl;
		cout<<"Salary:"<<Salary<<endl;
	}
	void set_Firstname(){
		cin>>fn;
		in_Firstname();
	}
	void set_Lastname(){
		cin>>ln;
		in_Lastname();
	}
	void set_Workinghour(){
		cin>>wh;
		in_Workinghour();
	}
	void set_Costperhour(){
		cin>>cph;
		in_Costperhour();
	}
	
   void set_employeeid(){
		this->Personalid=id;
   }
   

   void in_Firstname(){
		this->Firstname=fn;
   }			
   void in_Lastname(){
		this->Lastname=ln;
   }
   void in_Workinghour(){
		this->Workinghours=wh;
   }
   void in_Costperhour(){
		this->Costperhour=cph;
   }
   void set_salary(){
		this->Salary=Costperhour*Workinghours;
   }        
   void get_bye(){
   	cout<<endl;
   	cout<<"You are being directed to the main menu..."<<endl<<endl;
   }
};
class HRM{
	private:
		person temp[100];
	person arrayemp[100];
	person key[100];

	
	public:
	void addperson(){
		char preference;
		do{
			arrayemp[count].set_employeeid();
			arrayemp[count].set_Fieldname();
			id++;
			count++;
			cout<<"would you like to keep adding employees?(y/n):"<<endl;
			cin>>preference;
			cout<<endl;
		} while(preference=='y'||preference=='Y');
		arrayemp[count].get_bye();
	}
	void deleteperson(){
		char answer, preference;
		int i;
		string a, b;
		
		cout<<"please type the name of the person you would like to erase data of:"<<endl;
		
		cout<<"Name: ";
		cin>>a;
		cout<<endl;
		cout<<"Surname: ";
		cin>>b;
		cout<<endl;	
		
		do{
		
	    for(i=0;i<count;i++)
		{
	    	if(arrayemp[i].Firstname==a&&arrayemp[i].Lastname==b)
			{
	    		cout<<"are you sure about unemploying this poor guy?(y/n)";
	    		cin>>answer;
				cout<<endl;
	    		if(answer=='y'||answer=='Y')
				{
	    			arrayemp[i].set0_Fieldname();
	    			arrayemp[i].get_Fieldname();
	    			cout<<endl<<endl;
				}
				else{cout<<"You are directed to main menu.."<<endl<<endl;
				
				}
	    	}
			}
			cout<<"would you like to delete another employee?(y/n)"<<endl;
			cin>>preference;
		}while(preference=='y'||preference=='Y');
			arrayemp[i].get_bye();
		
	}


   
	void updateperson(){
		    int i;
		    string a, b;
		    char preference;
		    do{
			cout<<"Please type the first name:"<<endl;
			cin>>a;
			cout<<endl<<"please type the last name:"<<endl;
			cin>>b;
			cout<<endl;
			
			
		for(i=0;i<100;i++){

			if(arrayemp[i].Firstname==a&&arrayemp[i].Lastname==b){
				cout<<"please choose the field which will be updated;"<<endl;
				cout<<"1)Name"<<endl;
				cout<<"2)Surname"<<endl;
				cout<<"3)Working hours"<<endl;
				cout<<"4)Cost per hour"<<endl;
				cout<<"You should type corresponding digit of your choice"<<endl;
				arrayemp[i].set_update();
				}
			}
			cout<<"would you like to update info of another employee?(y/n)"<<endl;
			cin>>preference;
			
			
		}while(preference=='y'||preference=='Y');
		arrayemp[i].get_bye();
	}
	   	   void WorkinghoursortList(){
   	
   	int i, j;

   	for(i=1;i<100;i++){
   		j=i-1;
   		key[i]=temp[i];
   		while(key[i].Workinghours<temp[j].Workinghours&&temp[j].Workinghours>=0){
		   
		temp[j+1]=temp[j];
		j--;

   	}
   	temp[j+1]=key[i];
   		
   		
	   }

   }
		   void SalarysortList(){
   	
   	int i, j;
   	
   	for(i=1;i<100;i++){
   		j=i-1;
   		key[i]=temp[i];
   		while(key[i].Salary<temp[j].Salary&&temp[j].Salary>=0){
		   
		temp[j+1]=temp[j];
		j--;

   	}
   	temp[j+1]=key[i];
   		
   		
	   }

   }
	void reportlist(){
		int i;
		char a, b;
		memcpy(temp, arrayemp, sizeof(arrayemp));

			cout<<"Please choose based on which field you want to list employee?"<<endl;
			cout<<"1)Personal Id"<<endl;
			cout<<"2)Salary(ascending order)"<<endl;
			cout<<"3)Working hours(ascending order)"<<endl;
			cout<<"Please type corresponding digit of your choice:"<<endl;
			cin>>b;
			cout<<endl;
			if(b=='1'){
			
		for(i=0;i<100;i++){
			cout<<endl;
			arrayemp[i].get_Fieldname();
			cout<<endl;
		}
		cout<<"Please type a char to get to the main menu:"<<endl;
		cin>>a;
		
	}
	        else if(b=='2'){
	        	SalarysortList();
	        	for(i=0;i<100;i++){
	        		temp[i].get_Fieldname();
			
				}
				cout<<"Please type a char to get to the main menu:"<<endl;
		        cin>>a;
			}
			else if(b=='3'){
				WorkinghoursortList();
				for(i=0;i<100;i++){
	        	temp[i].get_Fieldname();
				}
				cout<<"Please type a char to get to the main menu:"<<endl;
		        cin>>a;
			}
		}
	void searchperson(){
		int i;
		char preference, choice;
		string a, b;
		double c, d;
		do{
			cout<<"Please choose based on which field you want to search employee?"<<endl;
			cout<<"1)Name and surname"<<endl;
			cout<<"2)Salary"<<endl;
			cout<<"Please type corresponding digit of your choice:"<<endl;
			cin>>choice;
			if(choice=='1'){
			
			for(i=0;i<100;i++){
				cout<<"Please type the name:"<<endl;
				cin>>a;
				cout<<endl<<"please type the surname:"<<endl;
				cin>>b;
				cout<<endl;
				if(arrayemp[i].Firstname==a&&arrayemp[i].Lastname==b){
					arrayemp[i].get_Fieldname();
					cout<<endl<<endl;
				}
			}
		}
		    else if(choice=='2'){
		    	cout<<"Please type the interval of salary that you want to search for."<<endl;
		    	cout<<"Min:"<<endl;
		    	cin>>c;
		    	cout<<endl<<"Max:"<<endl;
		    	cin>>d;
		    	cout<<endl;
		    	for(i=0;i<100,i++;){
		    		if(arrayemp[i].Salary>=c&&arrayemp[i].Salary<=d){
		    			cout<<endl;
		    			arrayemp[i].get_Fieldname();
		    			cout<<endl;
					}
				}
				
			}
			else{
				cout<<endl;
				cout<<"You have to type 1 or 2 to select one of these options."<<endl;
			}
			cout<<endl;
			cout<<"would you like to keep searching employees from the list?(y/n)"<<endl;
			cin>>preference;
			cout<<endl<<endl;
		}while(preference=='y'||preference=='Y');
		
	}
};
	
	int mainmenu(){
		char preference;
		HRM Info;
		do{
			
			cout<<"1)Add a new joiner"<<endl;
			cout<<"2)Delete an existing employee from the list"<<endl;
			cout<<"3)Update information of an existing employee"<<endl;
			cout<<"4)List of employees sorted by any field that you prefer"<<endl;
			cout<<"5)Search an employee on the list by any field according to your preferance"<<endl;
			cout<<"6)Quit"<<endl;
			cout<<"Please choose one"<<endl;
			cin>>preference;
			if(preference=='1'){
				Info.addperson();
			}
			if(preference=='2'){
				Info.deleteperson();
			}
			if(preference=='3'){
				Info.updateperson();
			}
			if(preference=='4'){
			Info.reportlist();
			}
			if(preference=='5'){
				Info.searchperson();
			}
			if(preference=='6'){
				cout<<endl;
				cout<<"Goodbye.. :)";
			}
	    }while(preference != '6');
	    return 0;
	} // noktali virgul olmamali, bu bir bildirim (decleration) degil, tanim (definition).

int main()
{
	cout<<"Hello, our program consists of 5 options which appear on the menu below;"<<endl;

	mainmenu();
	
    return 0;
};
