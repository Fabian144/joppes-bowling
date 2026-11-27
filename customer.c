#include "customer.h"
#include "helpers.h"
#include <stdio.h>
#include <string.h>

Customer* all_customers = NULL;
int total_customers = 0;
int customer_limit = 0;

const char* scan_format =
  "ID: %d; Name: %29[^;\n]; Address: %99[^;\n]; Games: %d; Regular: %s\n";
const char* print_format =
  "ID: %d; Name: %s; Address: %s; Games: %d; Regular: %s\n";

bool
load_customers_from_file(const char* filename)
{
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Could not load customers because the file %s does not exist or "
           "could not be read.\n",
           filename);
    return false;
  }

  int temp_total = 0;
  fscanf(file, "Total customers: %d\n", &temp_total);

  if (total_customers >= customer_limit &&
      !allocate_memory_for_customers(
        &all_customers, &customer_limit, total_customers * 2)) {
    return false;
  }

  total_customers = temp_total;
  int count = 0;
  char regular_customer[6];
  while (fscanf(file,
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
  return true;
}

bool
update_customers_in_file(const char* filename)
{
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    printf("Could not sync customer data because the file %s does not exist or "
           "could not be read.\n",
           filename);
    return false;
  }

  fprintf(file, "Total customers: %d\n", total_customers);
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
add_customer(const Customer* customer)
{
  if (check_id_exists(customer->id, all_customers, total_customers)) {
    printf("Customer already exists.\n");
    return false;
  }

  if (total_customers == customer_limit &&
      !allocate_memory_for_customers(
        &all_customers, &customer_limit, total_customers * 2)) {
    return false;
  }

  all_customers[total_customers].id = customer->id;
  strcpy(all_customers[total_customers].name, customer->name);
  strcpy(all_customers[total_customers].address, customer->address);
  all_customers[total_customers].total_games = customer->total_games;
  all_customers[total_customers].regular = customer->regular;

  total_customers++;
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

bool
update_customer_total_games(int id, int new_total)
{
  if (!check_id_exists(id, all_customers, total_customers)) {
    printf("Customer does not exist.\n");
    return false;
  }

  for (int i = 0; i < total_customers; i++) {
    if (all_customers[i].id == id) {
      all_customers[i].total_games = new_total;

      if (all_customers[i].total_games >= MIN_TOTAL_GAMES_OF_REGULAR) {
        all_customers[i].regular = true;
      } else {
        all_customers[i].regular = false;
      }
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