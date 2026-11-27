#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>
#include <stdlib.h>
#include "customer.h"

bool check_id_exists(const int id, const Customer *customers, const int total);
int get_index_by_id(const int id, const Customer *customers, const int total);
bool allocate_memory_for_customers(Customer **customers, int *limit, size_t amount);
#endif