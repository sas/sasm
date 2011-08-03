#ifndef PERVASIVE_H_
# define PERVASIVE_H_

typedef   unsigned char           byte;
typedef   unsigned int            uint;

/*
** Sized types, should only used when size really matters.
** ANSI-C only specifies minimum sizes of each integer type so we rely on the
** compiler for the correctness of these typedefs.
*/
typedef   unsigned char           uint8;
typedef   char                    sint8;
typedef   unsigned short int      uint16;
typedef   short int               sint16;
typedef   unsigned int            uint32;
typedef   int                     sint32;
typedef   unsigned long long int  uint64;
typedef   long long int           sint64;

#endif /* !PERVASIVE_H_ */
