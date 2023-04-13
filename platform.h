#ifndef _PLATFORM_H
#define _PLATFORM_H

#define zero_init  0
#define zero       0

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;
typedef unsigned char sint8_t;
typedef unsigned short sint16_t;
typedef unsigned int sint32_t;

typedef enum return_status{
    R_NOK,
    R_OK
}return_status_t;

#endif // _STD_TYPES_H
