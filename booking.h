#ifndef BOOKING_H
#define BOOKING_H

typedef struct
{
  int booking_id;
  int customer_id;
  int lane_number;
  char date[12];
  int time;
  int player_count;
  char status[12];
} Booking;

#endif