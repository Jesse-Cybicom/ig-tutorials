#pragma once


// a type that can contain other types (types being int, string, float ...)
struct node {
	int value;
	node* next;
	node* prev;
};



// Linked-list -> Bidrectional linked-list
// first->previous should always be nullptr
// last->next should always be nullptr



// We created a structure (data)
// We created functions to work with that data



// Objects allow us to merge data and functions
struct MyType
{
	int id_; // name_
			 // Constructor - This is the default constructor
			 // MyType()
			 // {
			 //     std::cout << "MyType created\n";
			 // }



	MyType(int id)
		: id_(id)
	{
		std::cout << "MyType with value " << id_ << " created\n";
	}



	// Destructor
	~MyType()
	{
		std::cout << "MyType with value " << id_ << " destroyed\n";
	}

	
};




/*
C#



public class MyType
{
public MyType()
{
}
}




*/



// struct & class 
// In a struct everything is public by default
// In a class everything is private by default


class List
{

	node* first_;
	node* last_;
	int size_;

private:
	node* find_next(node* start, int item);

public:
	List();
	List(int first_item);
	~List();
	node* find_item(int item);
	node* find_last(int item);
	void add_item(int item);
	int get_size();
	void remove(int item);
	void print();
	node* operator[](int index);
};

