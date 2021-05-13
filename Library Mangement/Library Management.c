#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book{
	char name[20];
	char author[20];
	int copies;
	struct book* next;
}*head = NULL,*tail=NULL;
struct student{
	char name[20];
	char id[10];
	struct book Book;
	struct student* next;
}*head1=NULL,*tail2=NULL;
void displayBook(struct book* temp){
	system("CLS");
	printf("\n\n\n\n\n\n\t\t\tBook Detail.\n");
	printf("\t\t\tBook's Name:\t");
	puts(temp->name);
	printf("\t\t\tAuthor's Name:\t");
	puts(temp->author);
	printf("\t\t\tNo. of Copies:\t%d",temp->copies);
	printf("\n\n");
}
void modifyBook(struct book* newnode){
	printf("\n\n\n\n\nModifying:\n");
	printf("\n\n\n\n\n\n\t\t\tEnter the Details Below.\n");
	printf("\t\t\tEnter the Name of the Book:\t");
	scanf("%s",&newnode->name);
	printf("\t\t\tEnter the Name of the Author:\t");
	scanf("%s",&newnode->author);
	printf("\t\t\tEnter the number of copies:\t");
	scanf("%d",&newnode->copies);
	displayBook(newnode);
}
void authorBook(){
	char author[20];
	printf("Enter the name of the Author:\t");
	scanf("%s",author);
	struct book* temp;
	temp=head;
	while(temp!=NULL){
		if(strcmp(temp->author,author)==0)
			displayBook(temp);
		temp=temp->next;	
	}
}
void display(){
	struct book* temp;
	temp=head;
	system("CLS");
	printf("BOOK Details are as follow:\n\n");
	while(temp!=NULL){
		printf("Book's Name:\t");
		puts(temp->name);
		printf("Author's Name:\t");
		puts(temp->author);
		temp=temp->next;
		printf("\n\n");
	}
}
struct book* searchBook(char name[]){
	struct book* temp;
	temp=head;
	while(temp!=NULL){
	if(strcmp(temp->name,name)==0){
		printf("Book Found.\n");
		return temp;	
	}
	temp=temp->next;
	}
	printf("Book Not Found.\n");
}
void insertBook(struct book* newBook){
	newBook->next=NULL;	
	if(head==NULL){
	head=newBook;
	tail=head;
	}
	else{
	tail->next=newBook;
	tail=newBook;
	}
}
void readBook(){
	system("CLS");
	struct book* newnode=(struct book*)malloc(sizeof(struct book));
	printf("\n\n\n\n\n\n\t\t\tEnter the Details Below.\n");
	printf("\t\t\tEnter the Name of the Book:\t");
	scanf("%s",&newnode->name);
	printf("\t\t\tEnter the Name of the Author:\t");	
	scanf("%s",&newnode->author);
	printf("\t\t\tEnter the number of copies:\t");
	scanf("%d",&newnode->copies);
	insertBook(newnode);
	displayBook(newnode);
}
int libChoice(){
	system("CLS");
	printf("\n\n\n\n\n\t\t\tWelcome Admin!.\n\t\t\tEnter the pass:\t");
	system("CLS");
	int c;
	printf("\n\n\n\n\n\n");
	printf("\t\t\tLIBRARY MANAGEMENT SYSTEM:\n");
	printf("\t\t\t1. New Book Entry.\n");
	printf("\t\t\t2.Search Book.\n");
	printf("\t\t\t3.Display all Book.\n");
	printf("\t\t\t4.Display Books of Author.\n");
	printf("\t\t\t5.Exit.\n");
	printf("\t\t\t6.Main Menu.\n");
	printf("\t\t\t7.Modify Book.\n");
	printf("\t\t\tYour Choice:");	
	scanf("%d",&c);
	return c;
}
void libdir(int Choice){
	system("CLS");	
	switch(Choice){
		case 1: {
			readBook();
			break;
		}
		case 2:{		
			char name[20];
			printf("Enter the Book Name:\t");
			scanf("%s",name);
			struct book* t=searchBook(name);
			displayBook(t);
			break;
		}
		case 3:{
		display();
		break;
		}		
		case 4:{		
			authorBook();
			break;
		}
		case 5: {
			exit(0);
		}
		case 6:{
			main();
			break;
		}
		case 7:{		
			char name[20];
			printf("Enter the Book Name:\t");
			scanf("%s",name);
			struct book* t=searchBook(name);
			modifyBook(t);
			break;
		}
		default:{		
			printf("Wrong Input.\nPress any key to continue ");
			getch();
			libChoice();
		}
	}
	printf("\t\t\tRedirecting to Home Page.\n\t\t\tPress any key to continue...............");
	getch();
	libdir(libChoice());
}
int stuChoice(){
	system("CLS");
	int c;
	printf("\n\n\n\n\n\n");
	printf("\t\t\tLIBRARY MANAGEMENT SYSTEM:\n");
	printf("\t\t\t1.Search Book.\n");
	printf("\t\t\t2.Exit.\n");
	printf("\t\t\t3.Main menu\n");
	printf("\t\t\tYour Choice:");	
	scanf("%d",&c);
	return c;
}
void borrowBook(char name[]){
	struct book* temp;
	temp=head;
	while(temp!=NULL){
	if(strcmp(temp->name,name)==0)
		temp->copies=(temp->copies)-1;	
	temp=temp->next;

	}
}
void studir(int Choice){
	switch(Choice){
		case 1:{
			char name[20];
			printf("Enter the Book Name:\t");
			scanf("%s",name);
			int c;
			if(searchBook(name)==1);{
				printf("Wanna borrow(1/0)");	
				scanf("%d",&c);	
				if(c==1)
				borrowBook(name);	
			}
			break;
		}
		case 2:{
			exit(0);
			break;
		}
		case 3:{
			main();
			break;
		}
		default:{
			printf("Wrong Input.\nPress any key to continue ");	
			getch();
			main();	
		}
	}
	printf("\t\t\tRedirecting to Home Page.\n\t\t\tPress any key to continue...............");
	getch();
	studir(stuChoice());
}
int main(){
	system("CLS");
	int login;
	printf("\n\n\n\n\n\t\t\t Who are you\n");
	printf("\t\t\t1.Student.\n");
	printf("\t\t\t2.Librarian\n");
	printf("\t\t\tYour Choice:\t");
	scanf("%d",&login);
	if (login==1)
	studir(stuChoice());
	else if(login==2)
	{
		system("CLS");	
		char password[55];	
		printf("\n\n\n\n\n\n\t\t\t>>>WELCOME ADMIN:");
		printf("\n\t\t\t>>>Enter Your Password:");
		int p=0;
		do{
			password[p]=getch();
			if(password[p]!='\r'){
			printf("*");
			}
			p++;
		}while(password[p-1]!='\r');
		password[p-1]='\0';	
		if(strcmp(password,"Hello")==0){
			printf("\n\n\t\t\t>>>Password Match!!!!\n\t\t\t>>>Press any key tocontinue>>>");	
			getch();
			libdir(libChoice());	
		}
		else if(login==3)
			return 0;	
		else{
			printf("Wrong Input Redirecting.");
			main();
		}	
		return 0;
	}
}
