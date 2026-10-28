#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "helpers.h"

Customer all_customers[MAX_CUSTOMERS];
int total_customers = 0;

bool load_customers(const char *filename)
{
	FILE *file = fopen(filename, "rb");
	if (file == NULL)
	{
		printf("Could not load customers because the file %s does not exist or could not be read.\n", filename);
		return false;
	}

	size_t count = fread(all_customers, sizeof(Customer), MAX_CUSTOMERS, file);
	fclose(file);

	total_customers = (int)count;
	return true;
}

bool update_customers(const char *filename)
{
	FILE *file = fopen(filename, "wb");
	if (file == NULL)
	{
		printf("Could not sync customer data because the file %s does not exist or could not be read.\n", filename);
		return false;
	}

	fwrite(all_customers, sizeof(Customer) * total_customers, 1, file);
	fclose(file);

	return true;
}

bool add_customer(const Customer *customer, const char *filename)
{
	if (total_customers == MAX_CUSTOMERS)
	{
		printf("Customer cap reached.\n");
		return false;
	}

	if (check_id_exists(customer->id, all_customers, total_customers))
	{
		printf("Customer already exists.\n");
		return false;
	}

	FILE *file = fopen(filename, "ab");
	if (file == NULL)
	{
		printf("Could not add customer because the file %s does not exist or could not be read.\n", filename);
		return false;
	}

	fwrite(customer, sizeof(Customer), 1, file);
	fclose(file);

	printf("Customer added!\n");
	return true;
}

bool delete_customer(int id)
{
	if (!check_id_exists(id, all_customers, total_customers))
	{
		printf("Customer does not exist.\n");
		return false;
	}

	int customer_index = get_index_by_id(id, all_customers, total_customers);

	for (int i = customer_index; i < total_customers - 1; i++)
	{
		all_customers[i] = all_customers[i + 1];
	}

	total_customers--;

	return true;
}

bool update_customer_name(int id, char *new_name)
{
	if (!check_id_exists(id, all_customers, total_customers))
	{
		printf("Customer does not exist.\n");
		return false;
	}

	for (int i = 0; i < total_customers; i++)
	{
		if (all_customers[i].id == id)
		{
			strcpy(all_customers[i].name, new_name);
			return true;
		}
	}

	return false;
}

void print_customer(const Customer *customer)
{
	printf("\nCustomer %d:   \n", customer->id);
	printf("ID      = %d\n", customer->id);
	printf("Name    = %s\n", customer->name);
	printf("Address = %s\n", customer->address);
	printf("Games   = %d\n", customer->total_games);
	printf("Regular = %s\n\n", customer->regular == true ? "Yes" : "No");
}

void print_all_customers(void)
{
	for (int i = 0; i < total_customers; i++)
	{
		print_customer(&all_customers[i]);
	}
}

Customer get_customer_by_id(int id)
{
	for (int i = 0; i < total_customers; i++)
	{
		if (all_customers[i].id == id)
		{
			return all_customers[i];
		}
	}

	Customer c = {-1, "John Doe", "Void", -1, false};
	return c;
}