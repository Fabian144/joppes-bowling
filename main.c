#include <stdio.h>
#include "customer.h"
#include "helpers.h"
#include "safe_input.h"

void print_menu();

int main(void)
{
	printf("Welcome to Joppes Bowling\n");

	const char *filename = "customers.dat";

	load_customers(filename);

	int user_choice;
	int run_program = true;

	while (run_program)
	{
		print_menu();
		user_choice = get_int("Enter choice: ", 0, 5);

		switch (user_choice)
		{
		case 1:
		{
			Customer new_customer;

			new_customer.id = total_customers + 1;
			get_string("Enter name: ", new_customer.name, sizeof(new_customer.name));
			get_string("Enter address: ", new_customer.address, sizeof(new_customer.address));
			new_customer.total_games = 0;
			new_customer.regular = false;

			if (add_customer(&new_customer, filename))
			{
				load_customers(filename);
				print_customer(&new_customer);
			}
			break;
		}
		case 2:
		{
			int id = get_int("Enter the id of the customer you want to delete: ", 1, 10000);
			int customer_index = get_index_by_id(id, all_customers, total_customers);

			delete_customer(id);

			if (!update_customers(filename))
			{
				printf("The customer %s has not been deleted", all_customers[customer_index].name);
				load_customers(filename);
			}
			else
			{
				printf("The customer %s has been deleted!\n", all_customers[customer_index].name);
			}
			break;
		}
		case 3:
			print_all_customers();
			break;
		case 4:
		{
			int search_id = get_int("Enter customer id: ", 1, 10000);
			Customer customer = get_customer_by_id(search_id);

			if (customer.id == search_id)
			{
				printf("We found the customer!\n");
				print_customer(&customer);
			}
			else
			{
				printf("We did not find the magic customer!\n");
			}
			break;
		}
		case 5:
		{
			char new_name[MAX_CUSTOMER_NAME_LENGTH];

			int id = get_int("Enter customer id: ", 1, 10000);
			int customer_index = get_index_by_id(id, all_customers, total_customers);

			get_string("Enter new name: ", new_name, MAX_CUSTOMER_NAME_LENGTH - 1);

			if (!update_customer_name(id, new_name) || !update_customers(filename))
			{
				printf("The customers name has not been changed.\n");
				load_customers(filename);
			}
			else
			{
				printf("The customers name has been changed!\n");
				print_customer(&all_customers[customer_index]);
			}
			break;
		}
		case 0:
			run_program = false;
			break;
		default:
			printf("Invalid choice! Try again!\n");
			break;
		}
	}

	return 0;
}

void print_menu()
{
	printf("\n1. Create a new customer\n");
	printf("2. Delete a customer\n");
	printf("3. Show all customers\n");
	printf("4. Search for a customer\n");
	printf("5. Update a customers name\n");
	printf("0. Quit\n");
}