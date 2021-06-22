/*****************************************/
/*author:khaled mahrous
/*date:23/05/2021
/*version:1.0.0
/*description:
/*****************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define setbit(reg,bit_num) reg|=(1<<bit_num)
#define clrbit(reg,bit_num) reg&=~(1<<bit_num)
#define togbit(reg,bit_num) reg^=(1<<bit_num)
#define getbit(reg,bit_num) ((reg>>bit_num)&1)

#endif