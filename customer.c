#include "customer.h"
#include "helpers.h"
#include <stdio.h>
#include <string.h>

Customer all_customers[MAX_CUSTOMERS];
int total_customers = 0;
const char* scan_format =
  "ID: %d; Name: %29[^;\n]; Address: %99[^;\n]; Games: %d; Regular: %s\n";
const char* print_format =
  "ID: %d; Name: %s; Address: %s; Games: %d; Regular: %s\n";

bool
load_customers(const char* filename)
{
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Could not load customers because the file %s does not exist or "
           "could not be read.\n",
           filename);
    return false;
  }

  int count = 0;
  char regular_customer[6];
  while (count < MAX_CUSTOMERS && fscanf(file,
                                         scan_format,
                                         &all_customers[count].id,
                                         all_customers[count].name,
                                         all_customers[count].address,
                                         &all_customers[count].total_games,
                                         regular_customer) == 5) {
    if (strcmp(regular_customer, "true") == 0) {
      all_customers[count].regular = true;
    } else {
      all_customers[count].regular = false;
    }
    count++;
  }
  fclose(file);

  total_customers = count;
  return true;
}

bool
update_customers(const char* filename)
{
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    printf("Could not sync customer data because the file %s does not exist or "
           "could not be read.\n",
           filename);
    return false;
  }

  for (int i = 0; i < total_customers; i++) {
    fprintf(file,
            print_format,
            all_customers[i].id,
            all_customers[i].name,
            all_customers[i].address,
            all_customers[i].total_games,
            all_customers[i].regular ? "true" : "false");
  }
  fclose(file);

  return true;
}

bool
add_customer(const Customer* customer, const char* filename)
{
  if (total_customers == MAX_CUSTOMERS) {
    printf("Customer cap reached.\n");
    return false;
  }

  if (check_id_exists(customer->id, all_customers, total_customers)) {
    printf("Customer already exists.\n");
    return false;
  }

  FILE* file = fopen(filename, "a");
  if (file == NULL) {
    printf("Could not add customer because the file %s does not exist or could "
           "not be read.\n",
           filename);
    return false;
  }

  fprintf(file,
          print_format,
          customer->id,
          customer->name,
          customer->address,
          customer->total_games,
          customer->regular ? "true" : "false");
  fclose(file);

  printf("Customer added!\n");
  return true;
}

bool
delete_customer(int id)
{
  if (!check_id_exists(id, all_customers, total_customers)) {
    printf("Customer does not exist.\n");
    return false;
  }

  int customer_index = get_index_by_id(id, all_customers, total_customers);

  for (int i = customer_index; i < total_customers - 1; i++) {
    all_customers[i] = all_customers[i + 1];
  }

  total_customers--;

  return true;
}

bool
update_customer_name(int id, char* new_name)
{
  if (!check_id_exists(id, all_customers, total_customers)) {
    printf("Customer does not exist.\n");
    return false;
  }

  for (int i = 0; i < total_customers; i++) {
    if (all_customers[i].id == id) {
      strcpy(all_customers[i].name, new_name);
      return true;
    }
  }

  return false;
}

bool
update_customer_address(int id, char* new_address)
{
  if (!check_id_exists(id, all_customers, total_customers)) {
    printf("Customer does not exist.\n");
    return false;
  }

  for (int i = 0; i < total_customers; i++) {
    if (all_customers[i].id == id) {
      strcpy(all_customers[i].address, new_address);
      return true;
    }
  }

  return false;
}

void
print_customer(const Customer* customer)
{
  printf("\nCustomer %d:   \n", customer->id);
  printf("ID      = %d\n", customer->id);
  printf("Name    = %s\n", customer->name);
  printf("Address = %s\n", customer->address);
  printf("Games   = %d\n", customer->total_games);
  printf("Regular = %s\n\n", customer->regular == true ? "Yes" : "No");
}

void
print_all_customers(void)
{
  for (int i = 0; i < total_customers; i++) {
    print_customer(&all_customers[i]);
  }
}

Customer
get_customer_by_id(int id)
{
  for (int i = 0; i < total_customers; i++) {
    if (all_customers[i].id == id) {
      return all_customers[i];
    }
  }

  Customer c = { -1, "John Doe", "Void", -1, false };
  return c;
}