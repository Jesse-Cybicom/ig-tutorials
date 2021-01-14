#include <iostream>
#include "listlib.hpp"

// DO NOT REPEAT YOURSELF!

// Jesse: Jerry you're rewriting your class here. This is wrong. You've already defined the class in the header
// All you should be adding to your .cpp file is the implementation.
// It can be written like this:
// <return type> <class-name>::<method-name>(<parameters>)
// e.g.
// node* List::find_next(node* start, int item)
class List
{
	node* first_;
	node* last_;
	int size_;


private:
	node* find_next(node* start, int item)
	{
		node* current_node = start;

		while (current_node != nullptr)
		{
			if (current_node->value == item) return current_node;
			current_node = current_node->next;
		}

		return nullptr; //not found
	}


public:
	List()
		: first_(nullptr),
		last_(nullptr),
		size_(0)
	{
	}


	List(int first_item)
		: List()
	{
		add_item(first_item);
	}


	~List()
	{
		while (first_ != nullptr) {
			auto next_node = first_->next;
			std::cout << "Deleting node with value " << first_->value << "\n";
			delete first_;
			first_ = next_node;
		}
	}

	node* find_item(int item)
	{
		return find_next(first_, item);
	}

	node* find_last(int item)
	{
		auto curr = first_;
		auto last = first_;

		curr = find_next(first_, item);
		while (curr != nullptr)
		{
			last = curr;
			curr = find_next(last->next, item);
		}

		return last;
	}


	void add_item(int item)
	{
		node* new_node = new node();
		new_node->value = item;
		new_node->next = nullptr; // Nothing after the last item
		new_node->prev = nullptr;

		if (first_ == nullptr) { // nothing in list yet
			first_ = new_node;
		}
		else {
			last_->next = new_node;
			new_node->prev = last_;
		}
		last_ = new_node;
		++size_;
	}

	int get_size()
	{
		return size_;
	}

	void remove(int item)
	{
		auto kill_node = find_item(item);

		if (kill_node != nullptr)
		{
			kill_node->prev->next = kill_node->next;
			kill_node->next->prev = kill_node->prev;
			delete kill_node;
			--size_;
			std::cout << "\nItem " << item << " deleted.\n";
		}
		else
		{
			std::cout << "\nDelete item " << item << " not found!\n";
		}
	}

	void print()
	{
		auto curr = first_;
		std::cout << "Size: " << size_;
		std::cout << "  Items: ";
		while (curr != nullptr)
		{
			std::cout << curr->value << " ";
			curr = curr->next;
		}
	}

	
};

