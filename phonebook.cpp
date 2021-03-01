#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

string name[50];
string phoneNo[50];
string mobileNo[50];
string faxNo[50];
string email[50];
string address[50];
int counter = -1;
  
int validateContact(string tmpName){ 
	 for(int i=0; i<=counter; i++){
	 	if( name[i] == tmpName ){
	 		return 0;
	 	}
	 }
 	 return 1; 
}

void addContact(){
     string tmpName = "";
	 cout<<"Enter Name : ";
	 cin>>tmpName;
	 if( validateContact(tmpName) == 1 ){	
	     counter++;
	 	 name[counter] = tmpName;	 	
	 }else{
	 	cout<<endl<<"Contact Already Exist with this Name"<<endl;
	 	return;
	 } 
     cout<<"Enter Phone No : ";
     cin>>phoneNo[counter];
     cout<<"Enter Mobile No : ";
     cin>>mobileNo[counter];
     cout<<"Enter Fax No : ";
     cin>>faxNo[counter];
     cout<<"Enter Email No : ";
     cin>>email[counter];
     cout<<"Enter Address No : ";
     cin>>address[counter];
}
void print(int tmpCounter){
	if( name[tmpCounter] == "" )
		return;
	if( counter > -1 ){
		cout<<"Name : "<<name[tmpCounter]<<endl;	
		cout<<"Phone No : "<<phoneNo[tmpCounter]<<endl;
		cout<<"Mobile No : "<<mobileNo[tmpCounter]<<endl;
		cout<<"Fax No : "<<faxNo[tmpCounter]<<endl;
		cout<<"Email : "<<email[tmpCounter]<<endl;
		cout<<"Address : "<<address[tmpCounter]<<endl<<endl;
		cout<<"Press any key to view next / continue..."<<endl<<endl;
		getch();
	}
}
void printAll(){
	if( counter > -1 ){
		for(int i=0; i<=counter; i++){
		    print(i);
		}
	}
}

void updateContact( int tmpCounter ){	
     string tmpName = "";
	 cout<<"Enter Name : ";
	 cin>>tmpName;
	 if( validateContact(tmpName) ){
	 	 name[tmpCounter] = tmpName;	 	
	 }else{
	 	cout<<endl<<"Contact Already Exist with this Name"<<endl;
	 	return;
	 }
     cout<<"Enter Phone No : ";
     cin>>phoneNo[tmpCounter];
     cout<<"Enter Mobile No : ";
     cin>>mobileNo[tmpCounter];
     cout<<"Enter Fax No : ";
     cin>>faxNo[tmpCounter];
     cout<<"Enter Email No : ";
     cin>>email[tmpCounter];
     cout<<"Enter Address No : ";
     cin>>address[tmpCounter];
}
void deleteContact(int tmpCounter){ 
	 name[tmpCounter] = ""; 
     phoneNo[tmpCounter] = ""; 
     mobileNo[tmpCounter] = ""; 
     faxNo[tmpCounter] = "";
     email[tmpCounter] = ""; 
     address[tmpCounter] = "";
}
int findCounter(){ 
	 if( counter < 0 )
	 	 return -1;
	 	
	 string tmpName;
	 cout<<"Enter Name";
	 cin>>tmpName;
	 for(int i=0; i<=counter; i++){ 
	 	if( name[i] == tmpName ){
	 		return i;
	 	}
	 }
 	 return 1; 
}
	
int main(){
		
	char op;
	do{
		system("cls");
		cout<<"1. Add Contact"<<endl;
		cout<<"2. List Contacts"<<endl;
		cout<<"3. Search Contact"<<endl;
		cout<<"4. Update Contact"<<endl;
		cout<<"5. Delete Contact"<<endl;
		cout<<"6. Exit"<<endl<<endl;
		cout<<"Enter Option (1-6): ";
		cin>>op;
		
		switch(op){
			case '1':
			{
				 addContact();
				 cout<<"Contact added successfully..."<<endl;
				 cout<<"Press any key to continue";
				 getch();
		 		 break;
			}
			case '2':
			{
				 printAll(); 
		 		 break;
			}
			case '3':
			{
				 int tmpCounter = findCounter();
				 if( tmpCounter > -1 ){
				      print(tmpCounter);				 	
				 }
		 		 break;
			}
			case '4':
			{
				 int tmpCounter = findCounter();
				 if( tmpCounter > -1 ){
				      updateContact(tmpCounter);				 	
				 }
		 		 break;
			}
			case '5':
			{
				 int tmpCounter = findCounter();
				 if( tmpCounter > -1 ){
				      deleteContact(tmpCounter);				 	
				 }
		 		 break;
			}
			case '6':
			{
				 continue;
		 		 break; 
			}
		}
		
	}while(op != '6');
		
	return 0;

}
