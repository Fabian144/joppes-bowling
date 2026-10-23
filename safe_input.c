#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "safe_input.h"

#define LINE_SIZE 256

/* Reads one line from stdin. Returns 1 on success, 0 on end of input.
 * Discards the rest of the line if it was longer than the buffer. */
static int read_line(char *buf, size_t size)
{
    if (fgets(buf, (int)size, stdin) == NULL) {
        return 0;
    }

    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            /* throw away the rest of the line */
        }
    }
    return 1;
}

/* Exits the program cleanly if stdin is closed (e.g. Ctrl+D / Ctrl+Z). */
static void read_line_or_exit(char *buf, size_t size)
{
    if (!read_line(buf, size)) {
        printf("\nEnd of input. Exiting.\n");
        exit(0);
    }
}

int get_int(const char *prompt, int min, int max)
{
    char line[LINE_SIZE];

    while (1) {
        printf("%s", prompt);
        read_line_or_exit(line, sizeof line);

        char *end;
        errno = 0;
        long value = strtol(line, &end, 10);

        if (end == line || *end != '\0' || errno == ERANGE) {
            printf("Invalid number, try again.\n");
        } else if (value < min || value > max) {
            printf("Please enter a number between %d and %d.\n", min, max);
        } else {
            return (int)value;
        }
    }
}

double get_double(const char *prompt, double min, double max)
{
    char line[LINE_SIZE];

    while (1) {
        printf("%s", prompt);
        read_line_or_exit(line, sizeof line);

        char *end;
        errno = 0;
        double value = strtod(line, &end);

        if (end == line || *end != '\0' || errno == ERANGE) {
            printf("Invalid number, try again.\n");
        } else if (value < min || value > max) {
            printf("Please enter a number between %.2f and %.2f.\n", min, max);
        } else {
            return value;
        }
    }
}

void get_string(const char *prompt, char *buf, size_t size)
{
    while (1) {
        printf("%s", prompt);
        read_line_or_exit(buf, size);

        if (buf[0] != '\0') {
            return;
        }
        printf("Input cannot be empty, try again.\n");
    }
}

char get_char(const char *prompt)
{
    char line[LINE_SIZE];

    while (1) {
        printf("%s", prompt);
        read_line_or_exit(line, sizeof line);

        for (size_t i = 0; line[i] != '\0'; i++) {
            if (!isspace((unsigned char)line[i])) {
                return line[i];
            }
        }
        printf("Please enter a character.\n");
    }
}

int ask_yes_no(const char *prompt)
{
    while (1) {
        char c = (char)tolower((unsigned char)get_char(prompt));
        if (c == 'y') {
            return 1;
        }
        if (c == 'n') {
            return 0;
        }
        printf("Please answer y or n.\n");
    }
}