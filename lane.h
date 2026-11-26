#ifndef LANE_H
#define LANE_H

#include <stdbool.h>

typedef struct
{
  int booking_id;
  int customer_id;
  int lane_number;
  char date[11];
  int time;
  int player_count;
  bool status;
} Lane;

#endif