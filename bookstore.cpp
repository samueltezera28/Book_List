#include<iostream>
#include<string>
#include<iomanip>
#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

struct BookList{
	int Isbn;
	string Title;
	string Author;
	string Publisher;
	int Publishing_Date;
	int Num_of_page;
	int Total_quantity;

	BookList* next;
	BookList* prev;
};
 BookList* head = NULL;
COORD coord = {0, 0};
void gotoxy (int x, int y){
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class DlinkedList{
 public:
 	DlinkedList(){

	 }
	BookList* input_data(){
	    ofstream outfile;
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


		return book_data;
	}
	//inserting in the first position of the node
	void insert_first(){

		if(head == NULL){
			head = input_data();
		}
	    else {
		BookList *newNode = input_data();

		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	   }
    }
    //inserting last
	void inser_last(){
		if(head == NULL){
			head = input_data();
		}
		else{
			BookList *newNode = input_data();
			BookList* temp;
			for(temp=head; temp != NULL; temp=temp->next){
		 		if(temp->next == NULL){
                    temp->next = newNode;
                    newNode->prev = temp;
                    break;
		 		}
		    }
		}
	}

	void display_data(){
		if(head  == NULL){
		 cout<<"Sorry! Bookshelf is empty.please add Books\n"<<endl;
	}
		else{
			BookList* temp = head;
			int i=0,j;
            system("cls");
            cout<<("*********************************Book Data*****************************");
            gotoxy(2,2);
            cout<<(" Title       Isbn       AUTHOR       Publisher         Publishing Date       Total page       Qty ");
            j=4;
			while(temp != NULL){
                gotoxy(3,j);
                cout<<temp->Title;
                gotoxy(16,j);
                cout<<temp->Isbn;
                gotoxy(24,j);
                cout<<temp->Author;
                gotoxy(38,j);
                cout<<temp->Publisher;
                gotoxy(56,j);
                cout<<temp->Publishing_Date;
                gotoxy(79,j);
                cout<<temp->Num_of_page;
                gotoxy(93,j);
                cout<<temp->Total_quantity;
                cout<<("\n\n");
                j++;

				temp = temp->next;
			}
		}
	}
	BookList* search_by_isbn(int searchvalue){

            BookList* temp = head;
            BookList* qtemp;
            int i=0,value;
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
                        qtemp = temp;//hot fix needed
                        break;
                     }
                     temp = temp->next;
                 }
                 if (value == 5){
                    cout<<searchvalue<<" is found at index = "<<i<<".\n";
                 }else{
                    cout<<searchvalue<<" is not found in the list.\n";
                 }
                 return qtemp;
             }
}
	void search_by_title(string SearchTitle);
	void search_by_author(string SearchAuthor);

	void sort_by_isbn();
	void sort_by_title();

	void delete_isbn(int,int);
	void delete_title(int,string);
	void delete_book(int);
	void quantity_update();
};
//declaration of sub menu functions
int search_book_menu();
int sort_book_menu();
int update_menu();
void remove_menu();

int main(){
    DlinkedList listt;
	int option;

	while(true){
        cout<<endl<<endl;
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tWellcome To Automated Book Management System"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;

        cout<<"1. Display book\n"<<endl;
		cout<<"2. Sort books\n"<<endl;
		cout<<"3. Search books\n"<<endl;
		cout<<"4. Update book information\n"<<endl;
		cout<<"5. Exit\n"<<endl;
		cout<<"Enter your Choice:";
		cin>>option;
		system("cls");

	switch(option){
		case 1:
			listt.display_data();//function call to display data
			break;
		case 2:
			sort_book_menu();//sub menu for to apply various sorting (isbn & title)
			break;
		case 3:
		    search_book_menu();//sub menu to apply searching(title ,author, isbn)
			break;
		case 4:
			update_menu();//sub menu for (inserting ,removing,update quantity) of the book
			break;
		case 5:
		    cout<<"Bye:)";
			exit(0);//to exit and close the program
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}
}
}//end of main



int search_book_menu(){
    /* search book menu
    * while loop to display the menu of different searching method
    * search_by_isbn to search by isbn of the book
    * search_by_title to search by title of the book
    * search_by_author to search by the name of the author
    * main() to return
    */
	string SearchTitle, SearchAuthor;
	int option, SearchIsbn;
	DlinkedList list; // create an object of the class

	while(true){
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tWellcome To Search menu"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;

		cout<<"1. Search by ISBN"<<endl;
		cout<<"2. Search by Title"<<endl;
		cout<<"3. Search by Author"<<endl;
		cout<<"4. Go back"<<endl;
		cout<<"Enter Choice:";
		cin>>option;

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


void DlinkedList::search_by_title(string SearchTitle){
    //linear search is used to find the value.

	BookList* temp = head;// assigning head pointer to temp
	int i=0,value;
	 if (temp != NULL){
	 	while(temp != NULL ){
	 		i++;
	 		if (temp->Title == SearchTitle){
                    //value must be found to display the book
	 			value = 5;
	 			cout<<"\n Title: "<<temp->Title;
				cout<<"\n Author: "<<temp->Author;
				cout<<"\n Publisher: "<<temp->Publisher;
				cout<<"\n publishing date: "<<temp->Publishing_Date;
				cout<<"\n Total page: "<<temp->Num_of_page;
				cout<<"\n Quantity: "<<temp->Total_quantity;
				cout<<"\n ISBN: "<<temp->Isbn<<endl<<endl;
	 			break;
			 }
			 temp = temp->next;//assign next pointer to temp
		 }
		 if (value == 5){
		 	cout<<SearchTitle<<" is found at index = "<<i<<".\n";
		 }else{
		 	cout<<SearchTitle<<" is not found in the list.\n";
		 }
	 }

}
void DlinkedList::search_by_author(string SearchAuthor){
    //linear search is used to find the value.
	BookList* temp = head;// assigning head pointer to temp
	int i,value;
	 if (temp != NULL){
	 	while(temp != NULL ){
	 		i++;
	 		if (temp->Author == SearchAuthor){
                //value must be found to display the book
	 			value = 5;
	 			cout<<"\n Title: "<<temp->Title;
				cout<<"\n Author: "<<temp->Author;
				cout<<"\n Publisher: "<<temp->Publisher;
				cout<<"\n publishing date :"<<temp->Publishing_Date;
				cout<<"\n Total page: "<<temp->Num_of_page;
				cout<<"\n Quantity: "<<temp->Total_quantity;
				cout<<"\n International standard book number:"<<temp->Isbn<<endl<<endl;
	 			break;
			 }
			 temp = temp->next;//assign next pointer to temp
		 }
		 if (value == 5){
		 	cout<<SearchAuthor<<" is found at index = "<<i<<".\n";
		 }else{
		 	cout<<SearchAuthor<<" is not found in the list.\n";
		 }
	 }

}//end of function
int sort_book_menu(){
	int option,SortIsbn,SortTitle;//declaration of integer variables
	DlinkedList listt;// create an object of the class

	while(true){
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tWellcome To Sorting menu"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;

		cout<<"1. Sort by ISBN"<<endl;
		cout<<"2. Sort by Title"<<endl;
		cout<<"3. Go back"<<endl;
		cout<<"Enter Choice:";
		cin>>option;

	switch(option){
		case 1:
			listt.sort_by_isbn();//sorting by isbn
			break;
		case 2:
			listt.sort_by_title();//sorting by title
			break;
		case 3:
			main();//return to main
			break;
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}
}
}//end of sort menu

void DlinkedList::sort_by_isbn(){
    // sotrting by isbn in ascending  order
    // it uses Bubble sort algorithm
 	BookList *i, *j; //declaration of pointer i & j that points to BookList structure
    BookList* temp = head; //assign head pointer to temp
	int num,option;//declaration of integer varaiables
	string y;//declaration of string variables

     for(i = temp; i->next != NULL; i=i->next)
     {
         for(j=i->next; j != NULL; j=j->next)
         {
             if(i->Isbn > j->Isbn)//bubble sort swap starts if this condition is true
             {
                 num = j->Isbn;
                 j->Isbn = i->Isbn;
                 i->Isbn= num;
                 //swap isbn
                 y = j->Author;
                 j->Author = i->Author;
                 i->Author = y;
                //swap author
                 num = j->Num_of_page;
                 j->Num_of_page = i->Num_of_page;
                 i->Num_of_page = num;
                 //swap number of page
                 num = j->Publishing_Date;
                 j->Publishing_Date = i->Publishing_Date;
                 i->Publishing_Date = num;
                 // swap publishing date
                 num = j->Total_quantity;
                 j->Total_quantity = i->Total_quantity;
                 i->Total_quantity = num;
                 //swap total quantity
                 y = j->Title;
                 j->Title = i->Title;
                 i->Title = y;
                 //swap title
                  y = j->Publisher;
                 j->Publisher = i->Publisher;
                 i->Publisher = y;
                 //swap publisher
             }
         }
     }
     if (temp!=NULL){
     	cout<<"\t the books are sorted successfully by Isbn"<<endl;
     	cout<<"press 1 to display the sorted books by ISBN"<<endl;
     	cout<<"press 0 to go back to menu"<<endl;
     	cin>>option;
     	if(option == 1){
     		display_data();//display daata
		 }
		 else{
		 	main();//return to main
		 }
	 }
	 else{
	 	cout<<"Sorry No Data To Sort"<<endl;
	 }
}

void DlinkedList::sort_by_title(){
    // sotrting by title in ascending  order
    // it uses Bubble sort algorithm
 	BookList *i, *j;//declaration of pointer i & j that points to BookList structure
    BookList* temp = head;//assign head pointer to temp
	int num,option;//declaration of integer varaiables
	string y;//declaration of string variables

     for(i = temp; i->next != NULL; i=i->next)
     {
         for(j=i->next; j != NULL; j=j->next)
         {
             if(i->Title > j->Title)
             {
             	 y = j->Title;
                 j->Title = i->Title;
                 i->Title = y;
                 //swap title
                 y = j->Author;
                 j->Author = i->Author;
                 i->Author = y;
                //swap author
                 num = j->Num_of_page;
                 j->Num_of_page = i->Num_of_page;
                 i->Num_of_page = num;
                 //swap num of page
                 num = j->Publishing_Date;
                 j->Publishing_Date = i->Publishing_Date;
                 i->Publishing_Date = num;
                 //swap publishing date
                 num = j->Total_quantity;
                 j->Total_quantity = i->Total_quantity;
                 i->Total_quantity = num;
                 //swap total quantity
                 num = j->Isbn;
                 j->Isbn = i->Isbn;
                 i->Isbn= num;
                 //swap isbn
                  y = j->Publisher;
                 j->Publisher = i->Publisher;
                 i->Publisher = y;
                 //swap publisher
             }
         }
     }
     if (temp!=NULL){
     	cout<<"\t the books are sorted successfully by Isbn"<<endl;
     	cout<<"press 1 to display the sorted books by ISBN"<<endl;
     	cout<<"press 0 to go back to menu"<<endl;
     	cout<<"->";
     	cin>>option;
     	if(option == 1){
     		display_data();//display the sorted data
		 }
		 else{
		 	main();//return main
		 }
	 }
	 else{
	 	cout<<"no data"<<endl;
	 }

}

int update_menu(){
	DlinkedList listt;
	int option;
		while(true){
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tUpdate book information menu"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;

		cout<<"enter 1 to Insert book at the start"<<endl;
		cout<<"enter 2 to Insert book at the end"<<endl;
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
			listt.inser_last();
			break;
		case 3:
			remove_menu();
			break;
		case 4:
			listt.quantity_update();
			break;
		case 5:
			main();
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}
}
}

void remove_menu(){
	DlinkedList listt;
	int option;
		while(true){
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tDelete book menu"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
		cout<<"enter 1 to delete book using Isbn number"<<endl;
		cout<<"enter 2 to delete book using title"<<endl;
		cout<<"enter 3 to Go back"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		//system("cls");
	switch(option){
		case 1:
            listt.delete_book(option);
			break;
		case 2:
			listt.delete_book(option);
			break;
		case 3:
			update_menu();
			break;
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}

}
}
void DlinkedList::delete_isbn(int size,int value){
	int data,flag=0;
	BookList* temp = head;
	BookList* curr = head;
    for (int i = 1; temp != NULL && i <= size+1; i++){
		while (value == temp->Isbn){
			flag = 1;
			if (head->Isbn == value){
                BookList* first = head;
                head= head->next;
                cout<<"first";
                delete first;
                break;
			}
			if (temp->next == NULL){
				BookList* lastnode = temp;
				temp = curr;
				temp->next=NULL;
				cout<<"sd"<<endl;
				delete lastnode;
				break;
				}

			if(temp->next != NULL){
				BookList* delete_node = temp;

    			temp = temp->next;
    			curr->next=temp;
                temp->prev = curr;
    			cout<<"fuck"<<endl;
    			delete delete_node;
    			break;
			}
		}
    	curr = temp;
		temp = temp->next;
		}
		if(flag == 0){
			cout<<" Book not found please try again!"<<endl;
		}else{
		    cout<<"book with ISBN of "<<value<<" deleted successfully"<<endl<<endl;
		}
}
void DlinkedList::delete_book(int option){
	BookList* temp = head;
	int i=0,value;
	string title;

	cout<<"| Title |"<<setw(6);
	cout<<"| ISBN  |"<<setw(6);
	cout<<"| Index |"<<setw(6);
	 if (temp == NULL){
        cout<<endl<<endl<<endl;
        cout<<"No Books to delete"<<endl;
	 }
	 else{
	 	while(temp != NULL ){
	 		i++;

	 			cout<<endl<<temp->Title<<setw(8);
	 			cout<<temp->Isbn<<setw(8);
	 			cout<<i<<endl;
	 			cout<<setw(8);
			 temp = temp->next;
		 }
      cout<<endl;
      if(option == 1){
	  cout<<"input Isbn of the Book: ";
	  cin>>value;
	  delete_isbn(i,value);
      }
      if(option == 2){
        cout<<"Input Title of the book: ";
        cin>>title;
        delete_title(i,title);
      }
	 }
}
void DlinkedList::delete_title(int size, string title){
	int flag=0;
	BookList* temp = head;
	BookList* curr = head;
    for (int i = 1; temp != NULL && i<= size+1; i++){
		while (title == temp->Title){
			flag = 1;
			if (head->Title == title){
                BookList* first = head;
                head= head->next;
                cout<<"first";
                delete first;
                break;
			}
			if (temp->next == NULL){
				BookList* lastnode = temp;
				temp = curr;
				temp->next=NULL;
				cout<<"sd"<<endl;
				delete lastnode;
				break;
				}

			if(temp->next != NULL){
				BookList* delete_node = temp;

    			temp = temp->next;
    			curr->next=temp;
                temp->prev = curr;
    			cout<<"fuck"<<endl;
    			delete delete_node;
    			break;
			}
		}
    	curr = temp;
		temp = temp->next;
		}
		if(flag == 0){
			cout<<" Book not found please try again!"<<endl;
		}else{
		    cout<<"book with Title of "<<title<<" deleted successfully"<<endl<<endl;
		}
}
void DlinkedList::quantity_update(){
    BookList* i, *j;
    BookList* temp = head;
	int num,amount,isbn;
	string y;
    cout<<"input isbn of the book to edit its quantites"<<endl;
    cin>>isbn;
    i = search_by_isbn(isbn);
    if (i == NULL){
    	cout<<"book not found !!"<<endl;
	}else{

    cout<<"there are "<< i->Total_quantity<<" of books found in the library "<<endl;
    cout<<"to increase the book quantity press 1:"<<endl;
    cout<<"to decrease the book quantity press 2:"<<endl;
    cin>>num;
    if(num == 1){
        cout<<"how many books u want to add ";
        cin>>amount;
        i->Total_quantity += amount;
        cout<<"Number of Books updated Successfully."<<endl;
    }
    if(num == 2){
        cout<<"how many books u want to remove ";
        cin>>amount;
        if(i->Total_quantity< amount){
            cout<<"not enough books";

        }else{
            i->Total_quantity -= amount;
            cout<<"Number of Books updated Successfully."<<endl;
            }
}
}
}
