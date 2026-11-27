#include <stdio.h>
#include "helpers.h"
#include "customer.h"
#include "booking.h"

bool check_id_exists(const int id, const Customer *customers, const int total)
{
	for (int i = 0; i < total; i++)
	{
		if (customers[i].id == id)
		{
			return true;
		}
	}

	return false;
}

int get_index_by_id(const int id, const Customer *customers, const int total)
{
	for (int i = 0; i < total; i++)
	{
		if (customers[i].id == id)
		{
			return i;
		}
	}

	return -1;
}

bool allocate_memory_for_customers(Customer **customers, int *limit, size_t amount)
{
	Customer *tmp = realloc(*customers, amount * sizeof(**customers));
	if (tmp == NULL)
	{
		printf("Could not allocate memory for more customers.\n");
		return false;
	}

	*customers = tmp;
	*limit = amount;
	return true;
}

bool allocate_memory_for_bookings(Booking **bookings, int *limit, size_t amount)
{
	Booking *tmp = realloc(*bookings, amount * sizeof(**bookings));
	if (tmp == NULL)
	{
		printf("Could not allocate memory for more bookings.\n");
		return false;
	}

	*bookings = tmp;
	*limit = amount;
	return true;
}
