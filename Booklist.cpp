/*
  * @file BookList.cpp
  * Brief about this program it is an Automated library management system
  * It can add a book at the beginning of the list and
  * At the end of the list
  * It sort the list based on Title and ISBN
  * It can Traverse and Display all the books Added to the list form first to last
  * It Search a book using Title , ISBN and Author
  * It can Update the books detail
  * Delete a specific book from Booklist Using ISBN and Title
*/
#include<iostream>
#include<string>
#include<iomanip>
#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

// Define struct by the name BookList with seven data members
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
 BookList* head = NULL; // head pointer assined to NULL

COORD coord = {0, 0};
void gotoxy (int x, int y){
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// define class by the name Dlinked list
class DlinkedList{
 public: // Access specifier
 	DlinkedList(){ // data member

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
	void insert_last(){
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

 /*  void insert_middle(){
   	 int count=0,i;
   	 BookList *ptr=head;
   	 BookList *newNode=NULL;
   	 BookList *newNode2=head;

   	 if(head==NULL){
   	 	newNode = head;
   	 	newNode->next=NULL;
   	 	newNode->prev=NULL;
		}
	else{
		ptr=head->next;

		newNode->next=ptr->next;
		newNode->prev=ptr;
		ptr->next->prev=newNode;
		ptr->next=newNode;
	}
   }


// Insertion in the middle

 /* void insert_middle(Node**head,int data){
    Node* newNode = newNode ();
    newNode->data = data;

    if(*head==NULL){
    	insert(head,data);
    	return;
	}



   void insert_middle(struct Node* prev_node,int data){
   	if(prev_node == NULL){
   		return;
	   }
	   struct Node* newNode = newNode;
	   newNode->data = data;
	   newNode->next = prev_node->next;
	   prev_node->next = prev_node;
	   if(newNode->next != NULL)
	    newNode->next->prev = newNode;
   }
}*/
  // Display data
	void display_data(){
		if(head  == NULL){
		 cout<<"Sorry! Bookshelf is empty.please add Books\n"<<endl;
	}
		else{
			BookList* temp = head;
			int i=0,j;
            system("cls");
            cout<<("\t*********************************Book Data*****************************");
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
                        qtemp = temp;
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

// main function
int main(){
    DlinkedList listt;
	int option; //Declaration of variables

	while(true){
        system("Color B5");
        cout<<endl<<endl;
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\t             Wellcome To Automated Book Management System         "<<endl;
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
        system("Color E5");
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\t                    Wellcome To Search menu                       "<<endl;
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
        system("Color C5");
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\t                  Wellcome To Sorting menu                        "<<endl;
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
		 else if(option == 0){
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
		 else if (option == 0){
		 	main();//return main
		 }
	 }
	 else{
	 	cout<<"Sorry No Data To Sort"<<endl;
	 }

}

int update_menu(){
    /* this menu function has a lot of sub function to update books info
    * ->inserting at the start of the list
    * ->inserting last of the list
    * ->remove any book
    * ->update quantity of books
    */
	DlinkedList listt;//assign head pointer to temp
	int option;
		while(true){
        system("Color A5");
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\t                  Update book information                     menu"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;

		cout<<"\n1. Insert book at the start"<<endl;
		cout<<"\n2. Insert book at the middle"<<endl;
		cout<<"\n3. Insert book at the end"<<endl;
		cout<<"\n4. Remove book"<<endl;
		cout<<"\n5. Update quantity of a given book"<<endl;
		cout<<"\n6. Go back"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		system("cls");
	switch(option){
		case 1:
			listt.insert_first();//inserting first of the list
			break;
		case 2:
		//	listt.insert_middle();  //inserting at the middle
			break;
		case 3:
			listt.insert_last(); //inserting last
			break;
		case 4:
			remove_menu();//calling remove sum menu
			break;
		case 5:
			listt.quantity_update();//update quantity of book by using Isbn
			break;
		case 6:
		    main();//return to main
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}
 }
}

//////

void remove_menu(){
	DlinkedList listt;// create an object of the class
	int option;
		while(true){
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\t                       Delete book menu                           "<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
		cout<<"\n1. Delete Book By Isbn"<<endl;
		cout<<"\n2. Delete Book By Title"<<endl;
		cout<<"\n3. Go back"<<endl;
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
			update_menu();//return to upper menu
			break;
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}

}
}
void DlinkedList::delete_book(int option){
	BookList* temp = head;//assign head pointer to temp
	int i=0,value;//declaration of integers
	string title;//declaration of string
	system("Color 4");
	 if (temp == NULL){
        cout<<endl<<endl<<endl;
        cout<<"No Books to delete"<<endl;
	 }
	 else{
            cout<<"| Title |"<<setw(6);
            cout<<"| ISBN  |"<<setw(6);
            cout<<"| Index |"<<setw(6);
	 	while(temp != NULL ){
                i++;//to count to size of the list

	 			cout<<endl<<temp->Title<<setw(8);
	 			cout<<temp->Isbn<<setw(8);
	 			cout<<i<<endl;
	 			cout<<setw(8);
                temp = temp->next;
		 }
      cout<<endl;
      if(option == 1){
	  cout<<"Input Isbn of the Book: ";
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
void DlinkedList::delete_isbn(int size,int value){
    //deletes the book with a given isbn number
	int data,flag=0;
	BookList* temp = head;//assign head pointer to temp
	BookList* curr = head;//assign head pointer to curr
    for (int i = 1; temp != NULL && i <= size+1; i++){
		while (value == temp->Isbn){
			flag = 1;
			if (head->Isbn == value){
                //to delete if the value is first of the list
                BookList* first = head;//assign the head pointer to first and delete it after swapping is done
                head= head->next;
                delete first;
                break;
			}
			if (temp->next == NULL){
                //to delete if the value is last of the list
				BookList* lastnode = temp;//assign the head pointer to lastnode pointer and delete it after swapping is done
				temp = curr;
				temp->next=NULL;
				delete lastnode;//delete
				break;
				}

			if(temp->next != NULL){
                    //to delete if the value is in the middle of the list
				BookList* delete_node = temp;//assign the head pointer to delete_node pointer and delete it after swapping is done
    			temp = temp->next;
    			curr->next=temp;
                temp->prev = curr;
    			delete delete_node;//delete
    			break;
			}
		}
    	curr = temp;//saving temp to curr and
		temp = temp->next;//assign next value to temp
		}
		if(flag == 0){
			cout<<" Book not found please try again!"<<endl;
		}else if (flag == 1){
		    cout<<"book with ISBN of "<<value<<" deleted successfully"<<endl<<endl;
		}
}
void DlinkedList::delete_title(int size, string title){
    //deletes the book with a given Title of the book
	int flag=0;
	BookList* temp = head;//assign head pointer to temp
	BookList* curr = head;//assign head pointer to curr
    for (int i = 1; temp != NULL && i<= size+1; i++){
		while (title == temp->Title){
			flag = 1;
			if (head->Title == title){
                //to delete if the value is first of the list
                BookList* first = head;//assign the head pointer to first and delete it after swapping is done
                head= head->next;
                delete first;
                break;
			}
			if (temp->next == NULL){
			    //to delete if the value is last of the list
				BookList* lastnode = temp;//assign the head pointer to lastnode pointer and delete it after swapping is done
				temp = curr;
				temp->next=NULL;
				delete lastnode;//delete
				break;
				}

			if(temp->next != NULL){
                //to delete if the value is in the middle of the list
				BookList* delete_node = temp;//assign the head pointer to delete_node pointer and delete it after swapping is done
    			temp = temp->next;
    			curr->next=temp;
                temp->prev = curr;
    			delete delete_node;//delete
    			break;
			}
		}
    	curr = temp;//saving temp to curr and
		temp = temp->next;//assign next value to temp
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
	int num,amount,isbn,publising_date,option,num_of_page,flag = 0;
	string title,author,publisher,y;

    cout<<"Input Isbn to edit book data : "<<endl;
    cin>>isbn;
    i = search_by_isbn(isbn);
    if (i == NULL){
        cout<<"book not found !!"<<endl;
        flag = 5;
    }

	while(flag == 0){
            cout<<"\n1. Update Quantity of the book"<<endl;
            cout<<"\n2. Update Title of the book"<<endl;
            cout<<"\n3. Update Author of the book"<<endl;
            cout<<"\n4. Update Publisher of the book"<<endl;
            cout<<"\n5. Update Publishing date of the book"<<endl;
            cout<<"\n6. Update Number of pages of the book"<<endl;
            cout<<"\n7. Update ISBN of the book"<<endl;
            cout<<"\n8 Go back"<<endl;
            cout<<"Enter Choice:";
            cin>>option;
            system("cls");
	switch(option){
		case 1:
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
                        cout<<"How many books u want to remove: ";
                        cin>>amount;
                if(i->Total_quantity< amount){
                    cout<<"not enough books";
                }else{
                    i->Total_quantity -= amount;
                    cout<<"Number of Books updated Successfully."<<endl;
            }
        }
	    	break;
		case 2:
		    cout<<"Title of the book is -> "<<i->Title<<endl;
            cout<<"Input The New Title:"<<endl;
            cin>>title;

            i->Title = title;
            cout<<"Title of the Books updated Successfully."<<endl;
            cout<<"Press 1 : to Display the New list"<<endl;
            cout<<"press any key to continue"<<endl;
            cin>>num;
            if(num == 1){
            display_data();
            }

		    break;

		case 3:
		    cout<<"Author of the book is -> "<<i->Author<<endl;
            cout<<"Input The New Author:"<<endl;
            cin>>author;

            i->Author = author;
            cout<<"Author of the book is updated Successfully."<<endl;
            cout<<"Press 1 : to Display the New list"<<endl;
            cout<<"press any key to continue"<<endl;
            cin>>num;
            if(num == 1){display_data();}
		    break;

		case 4:
		    cout<<"Publisher of the book is -> "<<i->Publisher<<endl;
            cout<<"Input The New Publisher:"<<endl;
            cin>>publisher;

            i->Publisher = publisher;
            cout<<"Publisher of the Book is updated Successfully."<<endl;
            cout<<"Press 1 : to Display the New list"<<endl;
            cout<<"press any key to continue"<<endl;
            cin>>num;
            if(num == 1){display_data();}
		    break;

		case 5:
		    cout<<"publishing date of the book is -> "<<i->Publishing_Date<<endl;
            cout<<"Input The New Date:"<<endl;
            cin>>publising_date;

            i->Publishing_Date = publising_date;
            cout<<"Publishing date of the Book is updated Successfully."<<endl;
            cout<<"Press 1 : to Display the New list"<<endl;
            cout<<"press any key to continue"<<endl;
            cin>>num;
            if(num == 1){display_data();}
		    break;

			cout<<"Input publishing date of the book to edit: "<<endl;
            cin>>publising_date;

		case 6:
		    cout<<"Number of page of the book is -> "<<i->Num_of_page<<endl;
            cout<<"Input The New Number of page:"<<endl;
            cin>>num_of_page;

            i->Num_of_page = num_of_page;
            cout<<"Number of page of the Book is updated Successfully."<<endl;
            cout<<"Press 1 : to Display the New list"<<endl;
            cout<<"press any key to continue"<<endl;
            cin>>num;
            if(num == 1){display_data();}
		    break;

		case 8:
			update_menu();
			default:
			cout<<"..";

  }
}
}
// End of update menu
