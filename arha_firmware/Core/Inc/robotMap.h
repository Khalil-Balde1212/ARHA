#ifndef ROBOT_MAP_H
#define ROBOT_MAP_H

#include "myactuator.h"

/* ── Motor CAN IDs (1-based, motor responds on 0x240 + ID) ──────────── */
#define SHOULDER_MOTOR_ID  2  
#define ELBOW_MOTOR_ID     6 

/* Total number of motors in the system */
#define NUM_MOTORS 2

/* Motor array index mapping (for the motors[] array in app.c) */
#define MOTOR_IDX_SHOULDER 0
#define MOTOR_IDX_ELBOW    1

#endif