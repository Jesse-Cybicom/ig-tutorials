#include <iostream>
#include "listlib.hpp"


void print_item(node* item)
{
	if (item != nullptr)
	{
		std::cout << "\nItem " << item->value << " found";
		if (item->next != nullptr)
			std::cout << "  Next " << item->next->value;
		else
		{
			std::cout << "  Next: NULL";
		}
		if (item->prev != nullptr)
			std::cout << "  Prev " << item->prev->value;
		else
		{
			std::cout << "  Prev: NULL";
		}
	}
	else
		std::cout << "\nItem not found\n";
}



int main()
{
	{
		List my_list;
		my_list.add_item(12);
		my_list.add_item(34);
		my_list.add_item(34);
		my_list.add_item(56);
		my_list.add_item(99);
		my_list.add_item(34);
		my_list.add_item(67);
		my_list.add_item(12);
		my_list.add_item(34);
		my_list.add_item(17);


		std::cout << "my_list size is " << my_list.get_size() << "\n"; // should return 3

		my_list.print();

		my_list.remove(34);
		my_list.print();

		my_list.remove(10);
		my_list.print();

		auto item = 12;
		auto n = my_list.find_item(item);
		print_item(n);

		item = 99;
		n = my_list.find_item(item);
		print_item(n);

		item = 64;
		n = my_list.find_item(item);
		print_item(n);

		item = 12;
		n = my_list.find_last(item);
		print_item(n);

		item = 34;
		n = my_list.find_last(item);
		print_item(n);

		my_list.add_item(22);

		std::cout << "\n Exiting scope: my_list\n";
	}

	char ch;
	std::cout << "Enter any char to exit: ";
	std::cin >> ch;

	return 0;
}