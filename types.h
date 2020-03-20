#ifndef _TYPES_H_
#define _TYPES_H_


typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;

typedef struct _thread_lock {
  uint locked;
} thread_lock;


#ifndef NULL
#define NULL (0)
#endif

#endif //_TYPES_H_