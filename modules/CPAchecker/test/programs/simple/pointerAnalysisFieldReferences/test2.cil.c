/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

#line 211 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h"
typedef unsigned int size_t;
#line 8 "test2.c"
struct str {
   int a ;
   struct str *pstr ;
};
#line 471 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *malloc(size_t __size )  __attribute__((__malloc__)) ;
#line 488
extern  __attribute__((__nothrow__)) void free(void *__ptr ) ;
#line 13 "test2.c"
int main(void) 
{ struct str *pstruct ;
  void *tmp ;
  void *tmp___0 ;
  unsigned int __cil_tmp4 ;
  void *__cil_tmp5 ;
  unsigned int __cil_tmp6 ;
  unsigned int __cil_tmp7 ;
  unsigned int __cil_tmp8 ;
  unsigned int __cil_tmp9 ;
  unsigned int __cil_tmp10 ;
  struct str *__cil_tmp11 ;
  unsigned int __cil_tmp12 ;
  void *__cil_tmp13 ;
  unsigned int __cil_tmp14 ;
  unsigned int __cil_tmp15 ;
  unsigned int __cil_tmp16 ;
  struct str *__cil_tmp17 ;
  void *__cil_tmp18 ;
  unsigned int __cil_tmp19 ;
  unsigned int __cil_tmp20 ;
  struct str *__cil_tmp21 ;
  void *__cil_tmp22 ;
  struct str **mem_23 ;
  struct str **mem_24 ;
  struct str **mem_25 ;
  struct str **mem_26 ;

  {
  {
#line 16
  tmp = malloc(8U);
#line 16
  pstruct = (struct str *)tmp;
  }
  {
#line 17
  __cil_tmp4 = (unsigned int )pstruct;
#line 17
  __cil_tmp5 = (void *)0;
#line 17
  __cil_tmp6 = (unsigned int )__cil_tmp5;
#line 17
  if (__cil_tmp6 == __cil_tmp4) {
#line 18
    return (1);
  } else {

  }
  }
  {
#line 21
  tmp___0 = malloc(8U);
#line 21
  __cil_tmp7 = (unsigned int )pstruct;
#line 21
  __cil_tmp8 = __cil_tmp7 + 4;
#line 21
  mem_23 = (struct str **)__cil_tmp8;
#line 21
  *mem_23 = (struct str *)tmp___0;
  }
  {
#line 22
  __cil_tmp9 = (unsigned int )pstruct;
#line 22
  __cil_tmp10 = __cil_tmp9 + 4;
#line 22
  mem_24 = (struct str **)__cil_tmp10;
#line 22
  __cil_tmp11 = *mem_24;
#line 22
  __cil_tmp12 = (unsigned int )__cil_tmp11;
#line 22
  __cil_tmp13 = (void *)0;
#line 22
  __cil_tmp14 = (unsigned int )__cil_tmp13;
#line 22
  if (__cil_tmp14 == __cil_tmp12) {
#line 23
    return (2);
  } else {

  }
  }
  {
#line 26
  __cil_tmp15 = (unsigned int )pstruct;
#line 26
  __cil_tmp16 = __cil_tmp15 + 4;
#line 26
  mem_25 = (struct str **)__cil_tmp16;
#line 26
  __cil_tmp17 = *mem_25;
#line 26
  __cil_tmp18 = (void *)__cil_tmp17;
#line 26
  free(__cil_tmp18);
#line 27
  __cil_tmp19 = (unsigned int )pstruct;
#line 27
  __cil_tmp20 = __cil_tmp19 + 4;
#line 27
  mem_26 = (struct str **)__cil_tmp20;
#line 27
  __cil_tmp21 = *mem_26;
#line 27
  __cil_tmp22 = (void *)__cil_tmp21;
#line 27
  free(__cil_tmp22);
  }
#line 29
  return (0);
}
}
