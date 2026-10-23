#ifndef CUSTOMER_H
#define CUSTOMER_H
#define MAX_CUSTOMERS 100
#define MAX_CUSTOMER_NAME_LENGTH 30
#define MAX_CUSTOMER_ADDRESS_LENGTH 50

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
	int id;
	char name[MAX_CUSTOMER_NAME_LENGTH];
	char address[MAX_CUSTOMER_ADDRESS_LENGTH];
	int total_games;
	bool regular;
} Customer;

extern Customer all_customers[MAX_CUSTOMERS];
extern int total_customers;

bool load_customers(const char *filename);
bool update_customers(const char *filename);
bool add_customer(const Customer *customer, const char *filename);
bool delete_customer(const int id);
bool update_customer_name(const int id, char *new_name);
void print_customer(const Customer *customer);
void print_all_customers(void);
Customer get_customer_by_id(const int id);
#endif