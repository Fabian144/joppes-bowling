#include "customer.h"
#include "helpers.h"

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