#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdbool.h>
#include "customer.h"

bool check_id_exists(const int id, const Customer *customers, const int total);
int get_index_by_id(const int id, const Customer *customers, const int total);
#endif