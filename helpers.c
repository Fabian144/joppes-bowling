#include "helpers.h"
#include "customer.h"
#include <stdio.h>

bool
check_id_exists(const int id, const Customer* customers, const int total)
{
  for (int i = 0; i < total; i++) {
    if (customers[i].id == id) {
      return true;
    }
  }

  return false;
}

int
get_index_by_id(const int id, const Customer* customers, const int total)
{
  for (int i = 0; i < total; i++) {
    if (customers[i].id == id) {
      return i;
    }
  }

  return -1;
}

bool
allocate_memory(Customer** customers, int* limit, size_t amount)
{
  Customer* tmp = realloc(*customers, amount * sizeof(**customers));
  if (tmp == NULL) {
    printf("Could not allocate memory for more customers.\n");
    return false;
  }

  *customers = tmp;
  *limit = amount;
  return true;
}
