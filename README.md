# Joppe's Bowling 🎳

### A Bowling Alley Booking System Written in C

## Project Overview

Joppe's Bowling needs a reliable booking system to replace its notebook and sticky notes. This project aims to simplify customer management, lane reservations, and booking administration.

**Status:** Work in Progress 🚧

## Features

### Customer Management

- [x] Register a new customer.
- [x] Display all registered customers.
- [x] Search for a customer by their unique customer ID.
- [x] Update a customer's name.
- [ ] Update a customer's address.
- [ ] Update the number of times a customer has bowled.
- [ ] Identify regular customers who have bowled at least 10 times.

### Booking Management

- [ ] Create and view bookings.
- [ ] Search bookings by customer, lane, or date.
- [ ] Cancel bookings.
- [ ] Check lane availability.
- [ ] Prevent overlapping bookings for the same lane.
- [ ] Track completed bookings and update customer visit counts.

### Data Storage

- [x] Save customer information to files.
- [ ] Save booking information to files.
- [x] Load previously saved information when the program starts.
- [x] Preserve all saved data when the program exits.
- [x] Handle missing or unreadable data files gracefully.

### Validation

- [x] Validate user input and handle errors.
- [ ] Prevent duplicate IDs and invalid bookings.
- [x] Display clear error messages.

## Technical Requirements

- **Language:** C
- **Data structures:** `struct` types for customers, lanes, and bookings.
- **Storage:** File handling.
- **Interface:** Menu-driven command-line application.
- **Reliability:** Input validation and booking conflict detection.

Each customer has a unique ID, name, address, and bowling visit count. Each booking contains a booking ID, customer ID, lane number, date, time slot, number of players, and status.

## Development Roadmap

- [x] Define data structure for customers.
- [ ] Define data structure for lanes.
- [ ] Define data structure for bookings.
- [x] Implement customer management.
- [ ] Implement booking and lane management.
- [ ] Add booking conflict detection.
- [x] Implement file storage.
- [x] Add input validation and error handling.
- [ ] Test and finalize the program.

## Building and Running

Compile using GCC through Make:

```bash
make bowling
```

Run the program:

```bash
make run
```