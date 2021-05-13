#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h> 
#include <iomanip>  
#include<string.h>
using namespace std;
void choice();
void opt(char ch);
void head(){
	system("CLS");
	for(int i=0;i<120;++i)
		cout<<"-*";
	cout<<"\t\t\t\t\t\t\tContacts.\n";
	for(int i=0;i<120;++i)
		cout<<"-*";
}
class contact{
	private:
	string name;
	string phone;  	
	public:
		contact* next;
		contact(){
			next=NULL;
		}
		void read(string names,string numbers){
			name=names;
			phone=numbers;
		}
		void read(){
			int cond = 1;		
			string ph="",nam="";
			while(!isalpha(nam[0])){
				head();
				cout<<"Enter the Name:\t";
				getline(cin,nam);
			}
			while((cond)||(ph.length()!=10)){
				head();
				cond = 0  ;
				cout<<"Enter the Name:\t"<<nam<<endl;
				cout<<"Enter the Number:\t";
				getline(cin,ph);
				for(int i=0;i<ph.length();++i){
					if(!isdigit(ph[i]))
						cond = 1;
				}
			}		
			read(nam,ph);
		}
		
		void display(){
			cout<<setw(30)<<">>>>>>"<<name<<"\t\t";			
			for(int i=0;i<phone.length();++i){
				if(i==3||i==6)
					cout<<"-";
				cout<<phone[i];
			}
			cout<<endl;
		}
		
		string getName(){
			return name;
		}
		
		string getNumber(){
			return phone;
		}
}*ct[26],*cn[10];

void printAllNames(){
	for(int i =0;i<26;++i){
		contact* temp = ct[i];
		while(temp!=NULL){
			temp->display();
			temp=temp->next;
		}			
	}
}
void insertNumber(contact* cont){
	string number = cont->getNumber();
	int index = number[0]-'0';
	
	if(cn[index]==NULL){
		cn[index]=cont;
	}
	else{
		contact* temp = cn[index];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=cont;
	}
}
void insertName(contact* cont){
	string name = cont->getName();
	int index = tolower(name[0])-'a';
	contact* temp = ct[index];
	if(ct[index]==NULL){
		ct[index]=cont;
	}
	else{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=cont;
	}
}
contact* searchNumber(string phone){
	int index = phone[0]-'0';
	contact* temp = cn[index];
	while(temp!=NULL){
		if(temp->getNumber().compare(phone)==0){
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}
contact* searchName(string name){
	int index = tolower(name[0] )- 'a';
	contact* temp = ct[index];
	while(temp!=NULL){
		if(temp->getName().compare(name)==0){
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}
void PopAll(){
		for(int i=0;i<26;++i)
			ct[i]=NULL;
		for(int i=0;i<10;++i)
			cn[i]=NULL;
		cout<<"\t\t\t-->All Contacts have been Wiped out !!!!";
}
void search(string s){
	contact* t = new contact();
	if(isdigit(s[0])==1){
		t=searchNumber(s);		
	}		
	else{
		t=searchName(s);
	}
		
	if(t!=NULL){
		t->display();
	}	
	else{
		cout<<"Contact Doesnot Exist";
	}
}
void DeleteNumber(string number){
	if(searchNumber(number)){	
		int index = number[0]-'0';
		contact* temp = new contact();
		temp = cn[index];
		if(temp->getNumber().compare(number)==0){
			if(temp->next==NULL)
				cn[index]=NULL;
			else{
				temp=temp->next;
				cn[index]=temp;	
			}	
			return;		
		}
		else{
			while(temp->next!=NULL&&temp->next->next!=NULL){
				if(temp->next->getNumber().compare(number)==0){
					temp->next=temp->next->next;
					return;	
				}
				temp=temp->next;
			}
			
		}
		temp->next=NULL;
	}
	
}
void DeleteName(string name){
	if(searchName(name)){	
		int index = tolower(name[0])-'a';
		contact* temp = new contact();
		temp = ct[index];
		if(temp->getName().compare(name)==0){
			if(temp->next==NULL)
				ct[index]=NULL;
			else{
				temp=temp->next;
				ct[index]=temp;	
			}	
			return;		
		}
		else{
			while(temp->next!=NULL&&temp->next->next!=NULL){
				if(temp->next->getName().compare(name)==0){
					temp->next=temp->next->next;
					return;	
				}
				temp=temp->next;
			}
			
		}
		temp->next=NULL;
	}
}
void Pop(){
	string s;
	head();
	cout<<"\n>>>Enter the name or Number:";
	cin.ignore();
	getline(cin,s);
	head();
	cout<<"\n\n\n\n\n\t\t";
	contact* temp = new contact();
	if(isdigit(s[0])==1){
		
		temp = searchNumber(s);
	}
	else{
		temp = searchName(s);
	}
	if(temp!=NULL){
		DeleteNumber(temp->getNumber());
		DeleteName(temp->getName());
		cout<<"\n\t\t\tDeleted";
	}
	else{
		cout<<"Account "<<s<<"Not Found";
	}
}
void Push(string name, string phone){
	contact* a = new contact();
	contact* b = new contact();
	a->read(name,phone);
	b->read(name,phone);
	insertNumber(a);
	insertName(b);
}
void read(){
	contact* temp = new contact();
	temp->read();
	Push(temp->getName(),temp->getNumber());
	head();
	cout<<"\t\t\t\t>>>Contact Saved Successfully."<<endl;
	cout<<"\t\t\t\t>>>Press Any key to go back.\n";
}
void Modify(){
	head();
	Pop();
	cout<<"\t\t\t-->Enter the new Details";
	read();
	
}
void Dummy(){
	Push("Tony Stark","1234567890");
	Push("Alan Harper","7890654321");
	Push("Steve Rogers","0987654321");
	Push("Wade Wilson","7890987656");
	Push("Aemon Targaryan","8765456781");
}
void choice(){
	char ch;
	system("CLS");
	head();	
	cout<<"\n\n\t\t\t\t>>>Enter your Choice"<<endl;
	cout<<"\t\t\t\t>>>1-Create.\t"<<endl;
	cout<<"\t\t\t\t>>>2-Modify.\t"<<endl;
	cout<<"\t\t\t\t>>>3-Search.\t"<<endl;
	cout<<"\t\t\t\t>>>4-View.\t"<<endl;
	cout<<"\t\t\t\t>>>5-Delete.\t"<<endl;
	cout<<"\t\t\t\t>>>6-Delete ALL.\t"<<endl;
	cout<<"\t\t\t\t>>>7-Exit.\t"<<endl;
	cout<<"\t\t\t\t>>>Your Choice:";
	cin>>ch;
	opt(ch);	
}
void opt(char ch){
	head();
	switch (ch){
		case '1':{
			read();
			break;
		}
		case '2':{
			Modify();
			break;
		}
		case '3':{
			string s;
			head();
			cout<<"\n>>>Enter the name or Number:";
			cin.ignore();
			getline(cin,s);
			head();
			cout<<"\n\n\n\n\n\t\t";
			search(s);			
			break;			
		}
		case '4':{
			printAllNames();
			break;
		}
		case '5':{		
			Pop();			
			break;			
		}
		case '6':{
			PopAll();
			break;
		}
		case '7':{
			head();
			cout<<"\t\t\t\t>>>Press Any Key to Exit........";
			getch();
			exit(0);
		}
		default:{
			cout<<"\n\n\n\t\t\t\t>>>Wrong-Choice...\n";
			cout<<"\t\t\t\t>>>Try Again\n";
			cout<<"\t\t\t\t>>>Press Any Key to Continue........";
			getch();
			choice();
			break;
		}		
	}
	cout<<"\n\t\t\t>>>Press Any Key to Continue........";
	getch();
	choice();
}
int main(){
	system("CLS");
	system("COLOR 70");
	Dummy();
	choice();
	return 0;
}
