#include<iostream>
#include<string>
using namespace std;
struct BookList{
	int Isbn;
	char Title[30];
	char Author[30];
	char Publisher[30];
	int Publishing_Date;
	int Num_of_page;
	int Total_quantity;
	
	BookList* next;
	BookList* prev;
};
BookList* head = NULL;


class DlinkedList{
 	
 public:
 	DlinkedList(){ 
	
	 }
	BookList* input_data(){
		BookList* book_data = new BookList;
		cout<<"\n enter Isbn: ";cin>>book_data->Isbn;
		cout<<"\n enter Title of the book: ";cin>>book_data->Title;
		cout<<"\n enter Author: ";cin>>book_data->Author;
		cout<<"\n enter Publisher: ";cin>>book_data->Publisher;
		cout<<"\n enter Publishing_Date: ";cin>>book_data->Publishing_Date;
		cout<<"\n enter Number of Pages: ";cin>>book_data->Num_of_page;
		cout<<"\n enter Total_quantity: ";cin>>book_data->Total_quantity;
		
		book_data->next = NULL;
		book_data->prev = NULL;
		
		if(head == NULL){
			head = book_data;
		}
		
		return book_data;
	}
	void insert_first(){
		if(head == NULL){
			head = input_data();
		}
	    else {
		BookList *temp = input_data();
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}
	void inser_last(){
		if(head == NULL){
			head = input_data();
		}
		else{
			BookList *temp = input_data();
			while(head){
				if (head->next == NULL){
					head->next == temp->prev;   
				}
				head = head->next;
				
			}
			
		}
	}

	
	void display_data(){
		if(head  == NULL){
		 cout<<"no data";
	}
		else{
			BookList* temp = head;
			while(temp != NULL){
				cout<<"\n Title of the book:"<<temp->Title;
				cout<<"\n Author of the book:"<<temp->Author;
				cout<<"\n Publisher of the book:"<<temp->Publisher;
				cout<<"\n publishing date of the book:"<<temp->Publishing_Date;
				cout<<"\n Total page:"<<temp->Num_of_page;
				cout<<"\n Quantity of the book:"<<temp->Total_quantity;
				cout<<"\n International standard book number:"<<temp->Isbn<<endl<<endl;
				temp = temp->next;
			}
		} 
	}
	void search_by_isbn(int searchvalue);
	void search_by_title(string SearchTitle);
	void search_by_author(string SearchAuthor);
};
int search_book_menu();
int sort_book_menu();
int update_menu();

int main(){
	int option;
	
	while(true){		
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tWellcome To Automated book managment system"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
	
		cout<<"enter 1 to Search the book"<<endl;
		cout<<"enter 2 to Sort the book"<<endl;
		cout<<"enter 3 to Update book information"<<endl;
		cout<<"enter 4)Exit"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		//system("cls");
		
	switch(option){
		case 1:
			search_book_menu();
			break;
		case 2:
			sort_book_menu();
			break;
		case 3:
			update_menu();
			break;
		case 4:
			exit(0);
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}
	if(option == 4){
		cout<<"Bye:)";
		return 0;
	}
	
			
}
	
	
}//end of main



int search_book_menu(){
	string SearchTitle, SearchAuthor;
	int option, SearchIsbn;
	DlinkedList list;
	
	while(true){		
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tWellcome To Search menu"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
	
		cout<<"enter 1 to Search by ISBN"<<endl;
		cout<<"enter 2 to Search by Title"<<endl;
		cout<<"enter 3 to Search by Author"<<endl;
		cout<<"enter 4 to Go back"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		//system("cls");
		
	switch(option){
		case 1:
			cout<<"Input Isbn of the book: ";
			cin>>SearchIsbn;
			list.search_by_isbn(SearchIsbn);
			break;
		case 2:
			cout<<"Input Title of the book: ";
			cin>>SearchTitle;
			list.search_by_title(SearchTitle);
			break;
		case 3:
			cout<<"Input Author of the book: ";
			cin>>SearchAuthor;
			list.search_by_author(SearchAuthor);
			break;
		case 4:
			main();
			break;
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}	
}
}

void DlinkedList::search_by_isbn(int searchvalue){
		
	BookList* temp = head;
	int i,value;
	 if (temp != NULL){
	 	while(temp != NULL ){
	 		i++;
	 		if (temp->Isbn == searchvalue){
	 			value = 5;
	 			cout<<"\n Title of the book:"<<temp->Title;
				cout<<"\n Author of the book:"<<temp->Author;
				cout<<"\n Publisher of the book:"<<temp->Publisher;
				cout<<"\n publishing date of the book:"<<temp->Publishing_Date;
				cout<<"\n Total page:"<<temp->Num_of_page;
				cout<<"\n Quantity of the book:"<<temp->Total_quantity;
				cout<<"\n International standard book number:"<<temp->Isbn<<endl<<endl;
	 			break;
			 }
			 temp = temp->next;
		 }
		 if (value == 5){
		 	cout<<searchvalue<<" is found at index = "<<i<<".\n";
		 }else{
		 	cout<<searchvalue<<" is not found in the list.\n";
		 }
	 }
}

void DlinkedList::search_by_title(string SearchTitle){
	BookList* temp = head;
	int i,value;
	 if (temp != NULL){
	 	while(temp != NULL ){
	 		i++;
	 		if (temp->Title == SearchTitle){
	 			value = 5;
	 			cout<<"\n Title of the book:"<<temp->Title;
				cout<<"\n Author of the book:"<<temp->Author;
				cout<<"\n Publisher of the book:"<<temp->Publisher;
				cout<<"\n publishing date of the book:"<<temp->Publishing_Date;
				cout<<"\n Total page:"<<temp->Num_of_page;
				cout<<"\n Quantity of the book:"<<temp->Total_quantity;
				cout<<"\n International standard book number:"<<temp->Isbn<<endl<<endl;
	 			break;
			 }
			 temp = temp->next;
		 }
		 if (value == 5){
		 	cout<<SearchTitle<<" is found at index = "<<i<<".\n";
		 }else{
		 	cout<<SearchTitle<<" is not found in the list.\n";
		 }
	 }
	
}
void DlinkedList::search_by_author(string SearchAuthor){
	BookList* temp = head;
	int i,value;
	 if (temp != NULL){
	 	while(temp != NULL ){
	 		i++;
	 		if (temp->Author == SearchAuthor){
	 			value = 5;
	 			cout<<"\n Title of the book:"<<temp->Title;
				cout<<"\n Author of the book:"<<temp->Author;
				cout<<"\n Publisher of the book:"<<temp->Publisher;
				cout<<"\n publishing date of the book:"<<temp->Publishing_Date;
				cout<<"\n Total page:"<<temp->Num_of_page;
				cout<<"\n Quantity of the book:"<<temp->Total_quantity;
				cout<<"\n International standard book number:"<<temp->Isbn<<endl<<endl;
	 			break;
			 }
			 temp = temp->next;
		 }
		 if (value == 5){
		 	cout<<SearchAuthor<<" is found at index = "<<i<<".\n";
		 }else{
		 	cout<<SearchAuthor<<" is not found in the list.\n";
		 }
	 }
	
}
int sort_book_menu(){
	int option,SortIsbn,SortTitle;
	
	while(true){		
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tWellcome To Sorting menu"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
	
		cout<<"enter 1 to Sort by ISBN"<<endl;
		cout<<"enter 2 to Sort by Title"<<endl;
		cout<<"enter 3 to Go back"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		//system("cls");
		
	switch(option){
		case 1:
			cout<<"Input Isbn of the book";
			cin>>SortIsbn;
			//sort_by_isbn(SortIsbn);
			break;
		case 2:
			cout<<"Input Title of the book";
			cin>>SortTitle;
			//sort_by_title(SortTitle);
			break;
		case 3:
			main();
			break;
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}	
}
}//end of sort menu

int update_menu(){
	DlinkedList listt;
	int option;
		while(true){		
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tUpdate book information menu"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
	
		cout<<"enter 1 to add new book"<<endl;
		cout<<"enter 2 to display book"<<endl;
		cout<<"enter 3 to remove book"<<endl;
		cout<<"enter 4 update quantity of a given book"<<endl;
		cout<<"enter 5 to Go back"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		//system("cls");
	switch(option){
		case 1:
			listt.insert_first();
			break;
		case 2:
			listt.display_data();
			break;
		case 3:
			main();
			break;
		case 4:
			main();
			break;
		case 5:
			main();
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}	
}
	
}
