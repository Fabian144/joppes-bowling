#ifndef HELPERS_H
#define HELPERS_H

#include "customer.h"
#include <stdbool.h>
#include <stdlib.h>

bool
check_id_exists(const int id, const Customer* customers, const int total);
int
get_index_by_id(const int id, const Customer* customers, const int total);
bool
allocate_memory(Customer** customers, int* limit, size_t amount);
#endif