/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

#line 1 "nested5.c"
int main(void) 
{ int a ;
  int b ;
  int c ;
  int d ;
  int e ;

  {
#line 2
  a = 6;
#line 3
  b = 6;
#line 4
  c = 6;
#line 5
  d = 6;
#line 6
  e = 6;
#line 9
  a = 0;
  {
#line 9
  while (1) {
    while_0_continue: /* CIL Label */ ;
#line 9
    if (a < 6) {

    } else {
      goto while_0_break;
    }
#line 10
    b = 0;
    {
#line 10
    while (1) {
      while_1_continue: /* CIL Label */ ;
#line 10
      if (b < 6) {

      } else {
        goto while_1_break;
      }
#line 11
      c = 0;
      {
#line 11
      while (1) {
        while_2_continue: /* CIL Label */ ;
#line 11
        if (c < 6) {

        } else {
          goto while_2_break;
        }
#line 12
        d = 0;
        {
#line 12
        while (1) {
          while_3_continue: /* CIL Label */ ;
#line 12
          if (d < 6) {

          } else {
            goto while_3_break;
          }
#line 13
          e = 0;
          {
#line 13
          while (1) {
            while_4_continue: /* CIL Label */ ;
#line 13
            if (e < 6) {

            } else {
              goto while_4_break;
            }
#line 13
            e = e + 1;
          }
          while_4_break: /* CIL Label */ ;
          }
#line 12
          d = d + 1;
        }
        while_3_break: /* CIL Label */ ;
        }
#line 11
        c = c + 1;
      }
      while_2_break: /* CIL Label */ ;
      }
#line 10
      b = b + 1;
    }
    while_1_break: /* CIL Label */ ;
    }
#line 9
    a = a + 1;
  }
  while_0_break: /* CIL Label */ ;
  }
#line 20
  if (a == 6) {
#line 20
    if (b == 6) {
#line 20
      if (c == 6) {
#line 20
        if (d == 6) {
#line 20
          if (e == 6) {

          } else {
            goto ERROR;
          }
        } else {
          goto ERROR;
        }
      } else {
        goto ERROR;
      }
    } else {
      goto ERROR;
    }
  } else {
    ERROR: 
    goto ERROR;
  }
#line 23
  return (1);
}
}
