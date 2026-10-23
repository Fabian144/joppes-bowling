#ifndef SAFE_INPUT_H
#define SAFE_INPUT_H

#include <stddef.h>

/* Ready-made helpers for reading user input safely.
 * Do NOT edit these - just call them from your own code.
 * All functions re-prompt until the user enters valid input. */

/* Reads an integer between min and max (inclusive). */
int get_int(const char *prompt, int min, int max);

/* Reads a decimal number between min and max (inclusive). */
double get_double(const char *prompt, double min, double max);

/* Reads a line of text into buf (at most size-1 characters, always
 * null-terminated). Empty input is rejected. */
void get_string(const char *prompt, char *buf, size_t size);

/* Reads a single character. Returns the first non-whitespace character typed. */
char get_char(const char *prompt);

/* Asks a yes/no question. Returns 1 for yes (y/Y), 0 for no (n/N). */
int ask_yes_no(const char *prompt);

#endif