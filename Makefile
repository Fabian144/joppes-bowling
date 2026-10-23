CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -MMD -MP
DIRECTORY = build
PROGRAM = bowling

OBJS = $(DIRECTORY)/main.o $(DIRECTORY)/customer.o $(DIRECTORY)/helpers.o $(DIRECTORY)/safe_input.o 

$(DIRECTORY)/$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(DIRECTORY)/%.o: %.c | $(DIRECTORY)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

$(DIRECTORY):
	mkdir -p $(DIRECTORY)

clean:
	rm -rf $(DIRECTORY)

run:
	$(DIRECTORY)/$(PROGRAM)

.PHONY: clean run

bowling: $(DIRECTORY)/$(PROGRAM)