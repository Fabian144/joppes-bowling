#ifndef LANE_H
#define LANE_H

#include "booking.h"
#include <stdbool.h>

typedef struct
{
  int lane_number;
  Booking latest_booking;
} Lane;

#endif