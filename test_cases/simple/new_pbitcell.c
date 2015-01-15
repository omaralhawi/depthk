/*
* file for bitcell.c
*/

//  P() {0==-1}


/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with the GNU C Library; if not, see
<http://www.gnu.org/licenses/>.  */




/* This header is separate from features.h so that the compiler can
include it implicitly at the start of every compilation.  It must
not itself include <features.h> or any other header that includes
<features.h> because the implicit include comes before any feature
test macros that may be defined in a source file before it first
explicitly includes a system header.  GCC knows the name of this
header in order to preinclude it.  */

/* glibc's intent is to support the IEC 559 math functionality, real
and complex.  If the GCC (4.9 and later) predefined macros
specifying compiler intent are available, use them to determine
whether the overall intent is to support these features; otherwise,
presume an older compiler has intent to support these features and
define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
Unicode 6.0.  */


/* We do not support C11 <threads.h>.  */
/*int nondet(void)
{
int x;
{
return (x);
}
}*/



//  P() {0==-1}


void error(void);


//  P() {0==-1}


int b0_val;

//  P() {0==-1}


int b0_val_t;

//  P() {0==-1}


int b0_ev;

//  P() {0==-1}


int b0_req_up;

//  P() {0==-1}


int b1_val;

//  P() {0==-1}


int b1_val_t;

//  P() {0==-1}


int b1_ev;

//  P() {0==-1}


int b1_req_up;

//  P() {0==-1}


int d0_val;

//  P() {0==-1}


int d0_val_t;

//  P() {0==-1}


int d0_ev;

//  P() {0==-1}


int d0_req_up;

//  P() {0==-1}


int d1_val;

//  P() {0==-1}


int d1_val_t;

//  P() {0==-1}


int d1_ev;

//  P() {0==-1}


int d1_req_up;

//  P() {0==-1}


int z_val;

//  P() {0==-1}


int z_val_t;

//  P() {0==-1}


int z_ev;

//  P() {0==-1}


int z_req_up;

//  P() {0==-1}


int comp_m1_st;

//  P() {0==-1}


int comp_m1_i;

//  P() {0==-1}


void method1(void);

//  P() {0==-1}


int is_method1_triggered(void);

//  P() {0==-1}


void update_b0(void);

//  P() {0==-1}


void update_b1(void);

//  P() {0==-1}


void update_d0(void);

//  P() {0==-1}


void update_d1(void);

//  P() {0==-1}


void update_z(void);

//  P() {0==-1}


void update_channels(void);

//  P() {0==-1}


void init_threads(void);

//  P() {0==-1}


int exists_runnable_thread(void);

//  P() {0==-1}


void eval(void);

//  P() {0==-1}


void fire_delta_events(void);

//  P() {0==-1}


void reset_delta_events(void);

//  P() {0==-1}


void activate_threads(void);

//  P() {0==-1}


int stop_simulation(void);

//  P() {0==-1}


void start_simulation(void);

//  P() {0==-1}


void init_model(void);

//  P() {0==-1}


int main(void);

//  P() {}


void error(void)
{


//  P() {}


ERROR:   ;

//  P() {}


return;
}

//  P() {comp_m1_st==1}


void method1(void)
{

__ESBMC_assume( comp_m1_st==1 );
int comp_m1_st_init = comp_m1_st;

//  P() {comp_m1_st==1}

__ESBMC_assume( comp_m1_st==1 );

int s1;

//  P(s1) {comp_m1_st==1}

__ESBMC_assume( comp_m1_st==1 );

int s2;

//  P(s1,s2) {comp_m1_st==1}

__ESBMC_assume( comp_m1_st==1 );

int s3;

//  P(s1,s2,s3) {comp_m1_st==1}

__ESBMC_assume( comp_m1_st==1 );

if (b0_val) {

//  P(s1,s2,s3) {comp_m1_st==1}

__ESBMC_assume( comp_m1_st==1 );

if (d1_val) {

//  P(s1,s2,s3) {comp_m1_st==1}

__ESBMC_assume( comp_m1_st==1 );

s1 = 0;
}
else {

//  P(s1,s2,s3) {comp_m1_st==1, d1_val==0}

__ESBMC_assume( comp_m1_st==1 && d1_val==0 );

s1 = 1;
}
}
else {

//  P(s1,s2,s3) {b0_val==0, comp_m1_st==1}

__ESBMC_assume( b0_val==0 && comp_m1_st==1 );

s1 = 1;
}

//  P(s1,s2,s3) {comp_m1_st==1, 0<=s1, s1<=1}

__ESBMC_assume( comp_m1_st==1 && 0<=s1 && s1<=1 );

if (d0_val) {

//  P(s1,s2,s3) {comp_m1_st==1, 0<=s1, s1<=1}

__ESBMC_assume( comp_m1_st==1 && 0<=s1 && s1<=1 );

if (b1_val) {

//  P(s1,s2,s3) {comp_m1_st==1, 0<=s1, s1<=1}

__ESBMC_assume( comp_m1_st==1 && 0<=s1 && s1<=1 );

s2 = 0;
}
else {

//  P(s1,s2,s3) {b1_val==0, comp_m1_st==1, 0<=s1, s1<=1}

__ESBMC_assume( b1_val==0 && comp_m1_st==1 && 0<=s1 && s1<=1 );

s2 = 1;
}
}
else {

//  P(s1,s2,s3) {comp_m1_st==1, d0_val==0, 0<=s1, s1<=1}

__ESBMC_assume( comp_m1_st==1 && d0_val==0 && 0<=s1 && s1<=1 );

s2 = 1;
}

//  P(s1,s2,s3) {comp_m1_st==1, 0<=s1, s1<=1, 0<=s2, s2<=1}

__ESBMC_assume( comp_m1_st==1 && 0<=s1 && s1<=1 && 0<=s2 && s2<=1 );

if (s2) {

//  P(s1,s2,s3) {comp_m1_st==1, s2==1, 0<=s1, s1<=1}

__ESBMC_assume( comp_m1_st==1 && s2==1 && 0<=s1 && s1<=1 );

s3 = 0;
}
else if (s1) {

//  P(s1,s2,s3) {comp_m1_st==1, s1==1, s2==0}

__ESBMC_assume( comp_m1_st==1 && s1==1 && s2==0 );

s3 = 0;
}
else {

//  P(s1,s2,s3) {comp_m1_st==1, s1==0, s2==0}

__ESBMC_assume( comp_m1_st==1 && s1==0 && s2==0 );

s3 = 1;
}

//  P(s1,s2,s3) {comp_m1_st==1, 1<=s1+s2+s3, s1+s3<=1, s2+s3<=1,
//    0<=s3}

__ESBMC_assume( comp_m1_st==1 && 1<=s1+s2+s3 && s1+s3<=1 && s2+s3<=1 && 0<=s3 );
if (s2) {

//  P(s1,s2,s3) {comp_m1_st==1, 1<=s1+s2+s3, s1+s3<=1, 1<=s2,
//    s2+s3<=1, 0<=s3}

__ESBMC_assume( comp_m1_st==1 && 1<=s1+s2+s3 && s1+s3<=1 && 1<=s2 && s2+s3<=1 && 0<=s3 );
if (s1) {

//  P(s1,s2,s3) {comp_m1_st==1, 1<=s1, s1+s3<=1, 1<=s2, s2+s3<=1,
//    0<=s3}

__ESBMC_assume( comp_m1_st==1 && 1<=s1 && s1+s3<=1 && 1<=s2 && s2+s3<=1 && 0<=s3 );
s2 = 1;
}
else {

//  P(s1,s2,s3) {comp_m1_st==1, s1==0, 1<=s2, s2+s3<=1, 0<=s3, s3<=1}

__ESBMC_assume( comp_m1_st==1 && s1==0 && 1<=s2 && s2+s3<=1 && 0<=s3 && s3<=1 );

s2 = 0;
}
}
else {

//  P(s1,s2,s3) {comp_m1_st==1, s1+s3==1, s2==0, 0<=s1, s1<=1}

__ESBMC_assume( comp_m1_st==1 && s1+s3==1 && s2==0 && 0<=s1 && s1<=1 );

s2 = 0;
}

//  P(s1,s2,s3) {comp_m1_st==1, s2<=s1, s1+s3<=1, 0<=s2, 0<=s3}

__ESBMC_assume( comp_m1_st==1 && s2<=s1 && s1+s3<=1 && 0<=s2 && 0<=s3 );

if (s2) {

//  P(s1,s2,s3) {comp_m1_st==1, s2<=s1, s1+s3<=1, 1<=s2, 0<=s3}

__ESBMC_assume( comp_m1_st==1 && s2<=s1 && s1+s3<=1 && 1<=s2 && 0<=s3 );

z_val_t = 0;
}
else if (s3) {

//  P(s1,s2,s3) {comp_m1_st==1, s2==0, 0<=s1, s1+s3<=1, 1<=s3}

__ESBMC_assume( comp_m1_st==1 && s2==0 && 0<=s1 && s1+s3<=1 && 1<=s3 );

z_val_t = 0;
}
else {

//  P(s1,s2,s3) {comp_m1_st==1, s2==0, s3==0, 0<=s1, s1<=1}

__ESBMC_assume( comp_m1_st==1 && s2==0 && s3==0 && 0<=s1 && s1<=1 );

z_val_t = 1;
}

//  P(s1,s2,s3,z_val_t) {comp_m1_st==1, s2+s3+z_val_t==1, s2<=s1,
//    s1+s3<=1, 0<=s2, 0<=s3}

__ESBMC_assume( comp_m1_st==1 && s2+s3+z_val_t==1 && s2<=s1 && s1+s3<=1 && 0<=s2 && 0<=s3 );
z_req_up = 1;

//  P(s1,s2,s3,z_req_up,z_val_t) {comp_m1_st==1, s2+s3+z_val_t==1,
//    z_req_up==1, s2<=s1, s1+s3<=1, 0<=s2, 0<=s3}

__ESBMC_assume( comp_m1_st==1 && s2+s3+z_val_t==1 && z_req_up==1 && s2<=s1 && s1+s3<=1 && 0<=s2 && 0<=s3 );
comp_m1_st = 2;

//  P(comp_m1_st,s1,s2,s3,z_req_up,z_val_t) {comp_m1_st==2,
//    comp_m1_st#init==1, s2+s3+z_val_t==1, z_req_up==1, s2<=s1,
//    s1+s3<=1, 0<=s2, 0<=s3}

__ESBMC_assume( comp_m1_st==2 && comp_m1_st_init==1 && s2+s3+z_val_t==1 && z_req_up==1 && s2<=s1 && s1+s3<=1 && 0<=s2 && 0<=s3 );

return;
}

//  P() {}


int is_method1_triggered(void)
{


//  P() {}


int __retres1;

//  P(__retres1) {}


if (b0_ev==1) goto l99999;

//  P(__retres1) {}


if (b1_ev==1) goto l99998;

//  P(__retres1) {}


if (d0_ev==1) goto l99997;

//  P(__retres1) {}


if (d1_ev==1) goto l99996;

//  P(__retres1) {}


__retres1 = 0;
goto return_label;
l99996:   ;

//  P(__retres1) {d1_ev==1}

__ESBMC_assume( d1_ev==1 );

__retres1 = 1;
goto return_label;
l99997:   ;

//  P(__retres1) {d0_ev==1}

__ESBMC_assume( d0_ev==1 );

__retres1 = 1;
goto return_label;
l99998:   ;

//  P(__retres1) {b1_ev==1}

__ESBMC_assume( b1_ev==1 );

__retres1 = 1;
goto return_label;
l99999:   ;

//  P(__retres1) {b0_ev==1}

__ESBMC_assume( b0_ev==1 );

__retres1 = 1;

//  P(__retres1) {0<=__retres1, __retres1<=1}

__ESBMC_assume( 0<=__retres1 && __retres1<=1 );

/* CIL Label */
return_label:   return __retres1;
}

//  P() {b0_req_up==1}


void update_b0(void)
{

__ESBMC_assume( b0_req_up==1 );
int b0_req_up_init = b0_req_up;

//  P() {b0_req_up==1}

__ESBMC_assume( b0_req_up==1 );

if (b0_val!=1) {

//  P() {b0_req_up==1}

__ESBMC_assume( b0_req_up==1 );

b0_val = 1;

//  P(b0_val) {b0_req_up==1, b0_val==1}

__ESBMC_assume( b0_req_up==1 && b0_val==1 );

b0_ev = 0;
}

//  P(b0_ev,b0_val) {b0_req_up==1, b0_val==1}

__ESBMC_assume( b0_req_up==1 && b0_val==1 );

b0_req_up = 0;

//  P(b0_ev,b0_req_up,b0_val) {b0_req_up==0, b0_req_up#init==1,
//    b0_val==1}

__ESBMC_assume( b0_req_up==0 && b0_req_up_init==1 && b0_val==1 );

return;
}

//  P() {b1_req_up==1}


void update_b1(void)
{

__ESBMC_assume( b1_req_up==1 );
int b1_req_up_init = b1_req_up;

//  P() {b1_req_up==1}

__ESBMC_assume( b1_req_up==1 );

if (b1_val!=1) {

//  P() {b1_req_up==1}

__ESBMC_assume( b1_req_up==1 );

b1_val = 1;

//  P(b1_val) {b1_req_up==1, b1_val==1}

__ESBMC_assume( b1_req_up==1 && b1_val==1 );

b1_ev = 0;
}

//  P(b1_ev,b1_val) {b1_req_up==1, b1_val==1}

__ESBMC_assume( b1_req_up==1 && b1_val==1 );

b1_req_up = 0;

//  P(b1_ev,b1_req_up,b1_val) {b1_req_up==0, b1_req_up#init==1,
//    b1_val==1}

__ESBMC_assume( b1_req_up==0 && b1_req_up_init==1 && b1_val==1 );

return;
}

//  P() {d0_req_up==1}


void update_d0(void)
{

__ESBMC_assume( d0_req_up==1 );
int d0_req_up_init = d0_req_up;

//  P() {d0_req_up==1}

__ESBMC_assume( d0_req_up==1 );

if (d0_val!=1) {

//  P() {d0_req_up==1}

__ESBMC_assume( d0_req_up==1 );

d0_val = 1;

//  P(d0_val) {d0_req_up==1, d0_val==1}

__ESBMC_assume( d0_req_up==1 && d0_val==1 );

d0_ev = 0;
}

//  P(d0_ev,d0_val) {d0_req_up==1, d0_val==1}

__ESBMC_assume( d0_req_up==1 && d0_val==1 );

d0_req_up = 0;

//  P(d0_ev,d0_req_up,d0_val) {d0_req_up==0, d0_req_up#init==1,
//    d0_val==1}

__ESBMC_assume( d0_req_up==0 && d0_req_up_init==1 && d0_val==1 );

return;
}

//  P() {d1_req_up==1}


void update_d1(void)
{

__ESBMC_assume( d1_req_up==1 );
int d1_req_up_init = d1_req_up;

//  P() {d1_req_up==1}

__ESBMC_assume( d1_req_up==1 );

if (d1_val!=1) {

//  P() {d1_req_up==1}

__ESBMC_assume( d1_req_up==1 );

d1_val = 1;

//  P(d1_val) {d1_req_up==1, d1_val==1}

__ESBMC_assume( d1_req_up==1 && d1_val==1 );

d1_ev = 0;
}

//  P(d1_ev,d1_val) {d1_req_up==1, d1_val==1}

__ESBMC_assume( d1_req_up==1 && d1_val==1 );

d1_req_up = 0;

//  P(d1_ev,d1_req_up,d1_val) {d1_req_up==0, d1_req_up#init==1,
//    d1_val==1}

__ESBMC_assume( d1_req_up==0 && d1_req_up_init==1 && d1_val==1 );

return;
}

//  P() {z_req_up==1}


void update_z(void)
{

__ESBMC_assume( z_req_up==1 );
int z_req_up_init = z_req_up;

//  P() {z_req_up==1}

__ESBMC_assume( z_req_up==1 );

if (z_val!=z_val_t) {

//  P() {z_req_up==1}

__ESBMC_assume( z_req_up==1 );

z_val = z_val_t;

//  P(z_val) {z_req_up==1, z_val==z_val_t}

__ESBMC_assume( z_req_up==1 && z_val==z_val_t );

z_ev = 0;
}

//  P(z_ev,z_val) {z_req_up==1, z_val==z_val_t}

__ESBMC_assume( z_req_up==1 && z_val==z_val_t );

z_req_up = 0;

//  P(z_ev,z_req_up,z_val) {z_req_up==0, z_req_up#init==1,
//    z_val==z_val_t}

__ESBMC_assume( z_req_up==0 && z_req_up_init==1 && z_val==z_val_t );

return;
}

//  P() {b0_req_up<=1, b1_req_up<=1, d0_req_up<=1, d1_req_up<=1}


void update_channels(void)
{

__ESBMC_assume( b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
int b0_req_up_init = b0_req_up;
int d1_req_up_init = d1_req_up;
int b1_req_up_init = b1_req_up;
int z_req_up_init = z_req_up;
int d0_req_up_init = d0_req_up;

//  P() {b0_req_up<=1, b1_req_up<=1, d0_req_up<=1, d1_req_up<=1}

__ESBMC_assume( b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );

if (b0_req_up==1) {

//  P() {b0_req_up==1, b1_req_up<=1, d0_req_up<=1, d1_req_up<=1}

__ESBMC_assume( b0_req_up==1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );

update_b0();
}

//  P(b0_ev,b0_req_up,b0_val) {b0_req_up<=0,
//    b0_req_up<=b0_req_up#init, b0_req_up#init<=b0_req_up+1,
//    b1_req_up<=1, d0_req_up<=1, d1_req_up<=1}

__ESBMC_assume( b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
if (b1_req_up==1) {

//  P(b0_ev,b0_req_up,b0_val) {b1_req_up==1, b0_req_up<=0,
//    b0_req_up<=b0_req_up#init, b0_req_up#init<=b0_req_up+1,
//    d0_req_up<=1, d1_req_up<=1}

__ESBMC_assume( b1_req_up==1 && b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && d0_req_up<=1 && d1_req_up<=1 );
update_b1();
}

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val) {b0_req_up<=0,
//    b0_req_up<=b0_req_up#init, b0_req_up#init<=b0_req_up+1,
//    b1_req_up<=0, b1_req_up<=b1_req_up#init,
//    b1_req_up#init<=b1_req_up+1, d0_req_up<=1, d1_req_up<=1}

__ESBMC_assume( b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && b1_req_up<=0 && b1_req_up<=b1_req_up_init && b1_req_up_init<=b1_req_up+1 && d0_req_up<=1 && d1_req_up<=1 );
if (d0_req_up==1) {

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val) {d0_req_up==1,
//    b0_req_up<=0, b0_req_up<=b0_req_up#init,
//    b0_req_up#init<=b0_req_up+1, b1_req_up<=0,
//    b1_req_up<=b1_req_up#init, b1_req_up#init<=b1_req_up+1,
//    d1_req_up<=1}

__ESBMC_assume( d0_req_up==1 && b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && b1_req_up<=0 && b1_req_up<=b1_req_up_init && b1_req_up_init<=b1_req_up+1 && d1_req_up<=1 );
update_d0();
}

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val) {b0_req_up<=0, b0_req_up<=b0_req_up#init,
//    b0_req_up#init<=b0_req_up+1, b1_req_up<=0,
//    b1_req_up<=b1_req_up#init, b1_req_up#init<=b1_req_up+1,
//    d0_req_up<=0, d0_req_up<=d0_req_up#init,
//    d0_req_up#init<=d0_req_up+1, d1_req_up<=1}

__ESBMC_assume( b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && b1_req_up<=0 && b1_req_up<=b1_req_up_init && b1_req_up_init<=b1_req_up+1 && d0_req_up<=0 && d0_req_up<=d0_req_up_init && d0_req_up_init<=d0_req_up+1 && d1_req_up<=1 );
if (d1_req_up==1) {

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val) {d1_req_up==1, b0_req_up<=0, b0_req_up<=b0_req_up#init,
//    b0_req_up#init<=b0_req_up+1, b1_req_up<=0,
//    b1_req_up<=b1_req_up#init, b1_req_up#init<=b1_req_up+1,
//    d0_req_up<=0, d0_req_up<=d0_req_up#init,
//    d0_req_up#init<=d0_req_up+1}

__ESBMC_assume( d1_req_up==1 && b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && b1_req_up<=0 && b1_req_up<=b1_req_up_init && b1_req_up_init<=b1_req_up+1 && d0_req_up<=0 && d0_req_up<=d0_req_up_init && d0_req_up_init<=d0_req_up+1 );
update_d1();
}

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_req_up,d1_val) {b0_req_up<=0,
//    b0_req_up<=b0_req_up#init, b0_req_up#init<=b0_req_up+1,
//    b1_req_up<=0, b1_req_up<=b1_req_up#init,
//    b1_req_up#init<=b1_req_up+1, d0_req_up<=0,
//    d0_req_up<=d0_req_up#init, d0_req_up#init<=d0_req_up+1,
//    d1_req_up<=0, d1_req_up<=d1_req_up#init,
//    d1_req_up#init<=d1_req_up+1}

__ESBMC_assume( b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && b1_req_up<=0 && b1_req_up<=b1_req_up_init && b1_req_up_init<=b1_req_up+1 && d0_req_up<=0 && d0_req_up<=d0_req_up_init && d0_req_up_init<=d0_req_up+1 && d1_req_up<=0 && d1_req_up<=d1_req_up_init && d1_req_up_init<=d1_req_up+1 );
if (z_req_up==1) {

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_req_up,d1_val) {z_req_up==1, b0_req_up<=0,
//    b0_req_up<=b0_req_up#init, b0_req_up#init<=b0_req_up+1,
//    b1_req_up<=0, b1_req_up<=b1_req_up#init,
//    b1_req_up#init<=b1_req_up+1, d0_req_up<=0,
//    d0_req_up<=d0_req_up#init, d0_req_up#init<=d0_req_up+1,
//    d1_req_up<=0, d1_req_up<=d1_req_up#init,
//    d1_req_up#init<=d1_req_up+1}

__ESBMC_assume( z_req_up==1 && b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && b1_req_up<=0 && b1_req_up<=b1_req_up_init && b1_req_up_init<=b1_req_up+1 && d0_req_up<=0 && d0_req_up<=d0_req_up_init && d0_req_up_init<=d0_req_up+1 && d1_req_up<=0 && d1_req_up<=d1_req_up_init && d1_req_up_init<=d1_req_up+1 );
update_z();
}

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_req_up,d1_val,z_ev,z_req_up,z_val)
//    {b0_req_up<=0, b0_req_up<=b0_req_up#init,
//    b0_req_up#init<=b0_req_up+1, b1_req_up<=0,
//    b1_req_up<=b1_req_up#init, b1_req_up#init<=b1_req_up+1,
//    d0_req_up<=0, d0_req_up<=d0_req_up#init,
//    d0_req_up#init<=d0_req_up+1, d1_req_up<=0,
//    d1_req_up<=d1_req_up#init, d1_req_up#init<=d1_req_up+1,
//    z_req_up<=z_req_up#init, z_req_up#init<=z_req_up+1}

__ESBMC_assume( b0_req_up<=0 && b0_req_up<=b0_req_up_init && b0_req_up_init<=b0_req_up+1 && b1_req_up<=0 && b1_req_up<=b1_req_up_init && b1_req_up_init<=b1_req_up+1 && d0_req_up<=0 && d0_req_up<=d0_req_up_init && d0_req_up_init<=d0_req_up+1 && d1_req_up<=0 && d1_req_up<=d1_req_up_init && d1_req_up_init<=d1_req_up+1 && z_req_up<=z_req_up_init && z_req_up_init<=z_req_up+1 );

return;
}

//  P() {}


void init_threads(void)
{


//  P() {}


if (0==1) {

//  P() {0==-1}


comp_m1_st = 0;
}
else {

//  P() {}


comp_m1_st = 2;
}

//  P(comp_m1_st) {comp_m1_st==2}

__ESBMC_assume( comp_m1_st==2 );


return;
}

//  P() {}


int exists_runnable_thread(void)
{


//  P() {}


int __retres1;

//  P(__retres1) {}


if (comp_m1_st==0) goto l99999;

//  P(__retres1) {}


__retres1 = 0;
goto return_label;
l99999:   ;

//  P(__retres1) {comp_m1_st==0}

__ESBMC_assume( comp_m1_st==0 );

__retres1 = 1;

//  P(__retres1) {0<=__retres1, __retres1<=1}

__ESBMC_assume( 0<=__retres1 && __retres1<=1 );

/* CIL Label */
return_label:   return __retres1;
}

//  P() {}


void eval(void)
{


//  P() {}


int tmp;

//  P(tmp) {}


int tmp___0;
l99999:   ;

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {}


if (!1) goto while_0_break;

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {}


/* CIL Label */
while_0_continue:   ;

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {}


tmp___0 = exists_runnable_thread();

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {0<=tmp___0,
//    tmp___0<=1}

__ESBMC_assume( 0<=tmp___0 && tmp___0<=1 );
if (tmp___0) {
}
else {
goto while_0_break;
}

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {tmp___0==1}

__ESBMC_assume( tmp___0==1 );

if (comp_m1_st==0) {

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {comp_m1_st==0,
//    tmp___0==1}

__ESBMC_assume( comp_m1_st==0 && tmp___0==1 );
tmp = __VERIFIER_nondet_int();

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {comp_m1_st==0,
//    tmp___0==1}

__ESBMC_assume( comp_m1_st==0 && tmp___0==1 );
if (tmp) {

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {comp_m1_st==0,
//    tmp___0==1}

__ESBMC_assume( comp_m1_st==0 && tmp___0==1 );
comp_m1_st = 1;

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {comp_m1_st==1,
//    tmp___0==1}

__ESBMC_assume( comp_m1_st==1 && tmp___0==1 );
method1();
}
}
goto l99999;

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {tmp___0==0}

__ESBMC_assume( tmp___0==0 );

/* CIL Label */
while_0_break:   ;

//  P(comp_m1_st,tmp,tmp___0,z_req_up,z_val_t) {tmp___0==0}

__ESBMC_assume( tmp___0==0 );


return;
}

//  P() {}


void fire_delta_events(void)
{

int z_ev_init = z_ev;
int b1_ev_init = b1_ev;
int d1_ev_init = d1_ev;
int b0_ev_init = b0_ev;
int d0_ev_init = d0_ev;

//  P() {}


if (b0_ev==0) {

//  P() {b0_ev==0}

__ESBMC_assume( b0_ev==0 );

b0_ev = 1;
}

//  P(b0_ev) {b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 );

if (b1_ev==0) {

//  P(b0_ev) {b1_ev==0, b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1}

__ESBMC_assume( b1_ev==0 && b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 );

b1_ev = 1;
}

//  P(b0_ev,b1_ev) {b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1,
//    b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 );
if (d0_ev==0) {

//  P(b0_ev,b1_ev) {d0_ev==0, b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1,
//    b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1}

__ESBMC_assume( d0_ev==0 && b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 );
d0_ev = 1;
}

//  P(b0_ev,b1_ev,d0_ev) {b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1,
//    b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1, d0_ev#init<=d0_ev,
//    d0_ev<=d0_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 );
if (d1_ev==0) {

//  P(b0_ev,b1_ev,d0_ev) {d1_ev==0, b0_ev#init<=b0_ev,
//    b0_ev<=b0_ev#init+1, b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1,
//    d0_ev#init<=d0_ev, d0_ev<=d0_ev#init+1}

__ESBMC_assume( d1_ev==0 && b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 );
d1_ev = 1;
}

//  P(b0_ev,b1_ev,d0_ev,d1_ev) {b0_ev#init<=b0_ev,
//    b0_ev<=b0_ev#init+1, b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1,
//    d0_ev#init<=d0_ev, d0_ev<=d0_ev#init+1, d1_ev#init<=d1_ev,
//    d1_ev<=d1_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 && d1_ev_init<=d1_ev && d1_ev<=d1_ev_init+1 );
if (z_ev==0) {

//  P(b0_ev,b1_ev,d0_ev,d1_ev) {z_ev==0, b0_ev#init<=b0_ev,
//    b0_ev<=b0_ev#init+1, b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1,
//    d0_ev#init<=d0_ev, d0_ev<=d0_ev#init+1, d1_ev#init<=d1_ev,
//    d1_ev<=d1_ev#init+1}

__ESBMC_assume( z_ev==0 && b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 && d1_ev_init<=d1_ev && d1_ev<=d1_ev_init+1 );
z_ev = 1;
}

//  P(b0_ev,b1_ev,d0_ev,d1_ev,z_ev) {b0_ev#init<=b0_ev,
//    b0_ev<=b0_ev#init+1, b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1,
//    d0_ev#init<=d0_ev, d0_ev<=d0_ev#init+1, d1_ev#init<=d1_ev,
//    d1_ev<=d1_ev#init+1, z_ev#init<=z_ev, z_ev<=z_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 && d1_ev_init<=d1_ev && d1_ev<=d1_ev_init+1 && z_ev_init<=z_ev && z_ev<=z_ev_init+1 );

return;
}

//  P() {}


void reset_delta_events(void)
{

int z_ev_init = z_ev;
int b1_ev_init = b1_ev;
int d1_ev_init = d1_ev;
int b0_ev_init = b0_ev;
int d0_ev_init = d0_ev;

//  P() {}


if (b0_ev==1) {

//  P() {b0_ev==1}

__ESBMC_assume( b0_ev==1 );

b0_ev = 2;
}

//  P(b0_ev) {b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 );

if (b1_ev==1) {

//  P(b0_ev) {b1_ev==1, b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1}

__ESBMC_assume( b1_ev==1 && b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 );

b1_ev = 2;
}

//  P(b0_ev,b1_ev) {b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1,
//    b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 );
if (d0_ev==1) {

//  P(b0_ev,b1_ev) {d0_ev==1, b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1,
//    b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1}

__ESBMC_assume( d0_ev==1 && b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 );
d0_ev = 2;
}

//  P(b0_ev,b1_ev,d0_ev) {b0_ev#init<=b0_ev, b0_ev<=b0_ev#init+1,
//    b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1, d0_ev#init<=d0_ev,
//    d0_ev<=d0_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 );
if (d1_ev==1) {

//  P(b0_ev,b1_ev,d0_ev) {d1_ev==1, b0_ev#init<=b0_ev,
//    b0_ev<=b0_ev#init+1, b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1,
//    d0_ev#init<=d0_ev, d0_ev<=d0_ev#init+1}

__ESBMC_assume( d1_ev==1 && b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 );
d1_ev = 2;
}

//  P(b0_ev,b1_ev,d0_ev,d1_ev) {b0_ev#init<=b0_ev,
//    b0_ev<=b0_ev#init+1, b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1,
//    d0_ev#init<=d0_ev, d0_ev<=d0_ev#init+1, d1_ev#init<=d1_ev,
//    d1_ev<=d1_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 && d1_ev_init<=d1_ev && d1_ev<=d1_ev_init+1 );
if (z_ev==1) {

//  P(b0_ev,b1_ev,d0_ev,d1_ev) {z_ev==1, b0_ev#init<=b0_ev,
//    b0_ev<=b0_ev#init+1, b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1,
//    d0_ev#init<=d0_ev, d0_ev<=d0_ev#init+1, d1_ev#init<=d1_ev,
//    d1_ev<=d1_ev#init+1}

__ESBMC_assume( z_ev==1 && b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 && d1_ev_init<=d1_ev && d1_ev<=d1_ev_init+1 );
z_ev = 2;
}

//  P(b0_ev,b1_ev,d0_ev,d1_ev,z_ev) {b0_ev#init<=b0_ev,
//    b0_ev<=b0_ev#init+1, b1_ev#init<=b1_ev, b1_ev<=b1_ev#init+1,
//    d0_ev#init<=d0_ev, d0_ev<=d0_ev#init+1, d1_ev#init<=d1_ev,
//    d1_ev<=d1_ev#init+1, z_ev#init<=z_ev, z_ev<=z_ev#init+1}

__ESBMC_assume( b0_ev_init<=b0_ev && b0_ev<=b0_ev_init+1 && b1_ev_init<=b1_ev && b1_ev<=b1_ev_init+1 && d0_ev_init<=d0_ev && d0_ev<=d0_ev_init+1 && d1_ev_init<=d1_ev && d1_ev<=d1_ev_init+1 && z_ev_init<=z_ev && z_ev<=z_ev_init+1 );

return;
}

//  P() {}


void activate_threads(void)
{


//  P() {}


int tmp;

//  P(tmp) {}


tmp = is_method1_triggered();

//  P(tmp) {0<=tmp, tmp<=1}

__ESBMC_assume( 0<=tmp && tmp<=1 );

if (tmp) {

//  P(tmp) {tmp==1}

__ESBMC_assume( tmp==1 );

comp_m1_st = 0;
}

//  P(comp_m1_st,tmp) {0<=tmp, tmp<=1}

__ESBMC_assume( 0<=tmp && tmp<=1 );


return;
}

//  P() {}


int stop_simulation(void)
{


//  P() {}


int tmp;

//  P(tmp) {}


int __retres2;

//  P(__retres2,tmp) {}


tmp = exists_runnable_thread();

//  P(__retres2,tmp) {0<=tmp, tmp<=1}

__ESBMC_assume( 0<=tmp && tmp<=1 );

if (tmp) goto l99999;

//  P(__retres2,tmp) {tmp==0}

__ESBMC_assume( tmp==0 );

__retres2 = 1;
goto return_label;
l99999:   ;

//  P(__retres2,tmp) {tmp==1}

__ESBMC_assume( tmp==1 );

__retres2 = 0;

//  P(__retres2,tmp) {__retres2+tmp==1, 0<=__retres2, __retres2<=1}

__ESBMC_assume( __retres2+tmp==1 && 0<=__retres2 && __retres2<=1 );

/* CIL Label */
return_label:   return __retres2;
}

//  P() {b0_ev==2, b0_req_up==1, b0_val==0, b1_ev==2, b1_req_up==1,
//    b1_val==0, d0_ev==2, d0_req_up==1, d0_val==0, d1_ev==2,
//    d1_req_up==1, d1_val==0, z_ev==2, z_req_up==0, z_val==0}

void start_simulation(void)
{

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b1_ev==2 && b1_req_up==1 && b1_val==0 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d1_ev==2 && d1_req_up==1 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
int d1_req_up_init = d1_req_up;
int b1_req_up_init = b1_req_up;
int d1_ev_init = d1_ev;
int b0_ev_init = b0_ev;
int d0_val_init = d0_val;
int d1_val_init = d1_val;
int b0_val_init = b0_val;
int z_ev_init = z_ev;
int b1_val_init = b1_val;
int b1_ev_init = b1_ev;
int b0_req_up_init = b0_req_up;
int z_val_init = z_val;
int d0_req_up_init = d0_req_up;
int z_req_up_init = z_req_up;
int d0_ev_init = d0_ev;

//  P() {b0_ev==2, b0_req_up==1, b0_val==0, b1_ev==2, b1_req_up==1,
//    b1_val==0, d0_ev==2, d0_req_up==1, d0_val==0, d1_ev==2,
//    d1_req_up==1, d1_val==0, z_ev==2, z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b1_ev==2 && b1_req_up==1 && b1_val==0 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d1_ev==2 && d1_req_up==1 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
int kernel_st;

//  P(kernel_st) {b0_ev==2, b0_req_up==1, b0_val==0, b1_ev==2,
//    b1_req_up==1, b1_val==0, d0_ev==2, d0_req_up==1, d0_val==0,
//    d1_ev==2, d1_req_up==1, d1_val==0, z_ev==2, z_req_up==0,
//    z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b1_ev==2 && b1_req_up==1 && b1_val==0 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d1_ev==2 && d1_req_up==1 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
int tmp;

//  P(kernel_st,tmp) {b0_ev==2, b0_req_up==1, b0_val==0, b1_ev==2,
//    b1_req_up==1, b1_val==0, d0_ev==2, d0_req_up==1, d0_val==0,
//    d1_ev==2, d1_req_up==1, d1_val==0, z_ev==2, z_req_up==0,
//    z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b1_ev==2 && b1_req_up==1 && b1_val==0 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d1_ev==2 && d1_req_up==1 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
kernel_st = 0;

//  P(kernel_st,tmp) {b0_ev==2, b0_req_up==1, b0_val==0, b1_ev==2,
//    b1_req_up==1, b1_val==0, d0_ev==2, d0_req_up==1, d0_val==0,
//    d1_ev==2, d1_req_up==1, d1_val==0, kernel_st==0, z_ev==2,
//    z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b1_ev==2 && b1_req_up==1 && b1_val==0 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d1_ev==2 && d1_req_up==1 && d1_val==0 && kernel_st==0 && z_ev==2 && z_req_up==0 && z_val==0 );
update_channels();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,z_req_up,z_val)
//    {b0_ev#init==2, b0_req_up#init==1, b0_val#init==0,
//    b1_ev#init==2, b1_req_up#init==1, b1_val#init==0, d0_ev#init==2,
//    d0_req_up#init==1, d0_val#init==0, d1_ev#init==2,
//    d1_req_up#init==1, d1_val#init==0, kernel_st==0, z_ev#init==2,
//    z_req_up#init==0, z_val#init==0, 0<=b0_req_up, b0_req_up<=1,
//    0<=b1_req_up, b1_req_up<=1, 0<=d0_req_up, d0_req_up<=1,
//    0<=d1_req_up, d1_req_up<=1, z_req_up<=0, 0<=z_req_up+1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==0 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && 0<=b0_req_up && b0_req_up<=1 && 0<=b1_req_up && b1_req_up<=1 && 0<=d0_req_up && d0_req_up<=1 && 0<=d1_req_up && d1_req_up<=1 && z_req_up<=0 && 0<=z_req_up+1 );
init_threads();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, comp_m1_st==2, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==0, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, 0<=b0_req_up, b0_req_up<=1, 0<=b1_req_up,
//    b1_req_up<=1, 0<=d0_req_up, d0_req_up<=1, 0<=d1_req_up,
//    d1_req_up<=1, z_req_up<=0, 0<=z_req_up+1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && comp_m1_st==2 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==0 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && 0<=b0_req_up && b0_req_up<=1 && 0<=b1_req_up && b1_req_up<=1 && 0<=d0_req_up && d0_req_up<=1 && 0<=d1_req_up && d1_req_up<=1 && z_req_up<=0 && 0<=z_req_up+1 );
fire_delta_events();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, comp_m1_st==2, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==0, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, 0<=b0_req_up, b0_req_up<=1, 0<=b1_req_up,
//    b1_req_up<=1, 0<=d0_req_up, d0_req_up<=1, 0<=d1_req_up,
//    d1_req_up<=1, z_req_up<=0, 0<=z_req_up+1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && comp_m1_st==2 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==0 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && 0<=b0_req_up && b0_req_up<=1 && 0<=b1_req_up && b1_req_up<=1 && 0<=d0_req_up && d0_req_up<=1 && 0<=d1_req_up && d1_req_up<=1 && z_req_up<=0 && 0<=z_req_up+1 );
activate_threads();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==0, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, 0<=b0_req_up, b0_req_up<=1, 0<=b1_req_up,
//    b1_req_up<=1, 0<=d0_req_up, d0_req_up<=1, 0<=d1_req_up,
//    d1_req_up<=1, z_req_up<=0, 0<=z_req_up+1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==0 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && 0<=b0_req_up && b0_req_up<=1 && 0<=b1_req_up && b1_req_up<=1 && 0<=d0_req_up && d0_req_up<=1 && 0<=d1_req_up && d1_req_up<=1 && z_req_up<=0 && 0<=z_req_up+1 );
reset_delta_events();
l99999:   ;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, z_ev#init==2, z_req_up#init==0, z_val#init==0,
//    b0_req_up<=1, b1_req_up<=1, d0_req_up<=1, d1_req_up<=1,
//    0<=kernel_st, kernel_st<=3}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 && 0<=kernel_st && kernel_st<=3 );
if (!1) goto while_1_break;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, z_ev#init==2, z_req_up#init==0, z_val#init==0,
//    b0_req_up<=1, b1_req_up<=1, d0_req_up<=1, d1_req_up<=1,
//    0<=kernel_st, kernel_st<=3}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 && 0<=kernel_st && kernel_st<=3 );
/* CIL Label */
while_1_continue:   ;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, z_ev#init==2, z_req_up#init==0, z_val#init==0,
//    b0_req_up<=1, b1_req_up<=1, d0_req_up<=1, d1_req_up<=1,
//    0<=kernel_st, kernel_st<=3}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 && 0<=kernel_st && kernel_st<=3 );
kernel_st = 1;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==1, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==1 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
eval();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==1, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==1 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
kernel_st = 2;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==2, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==2 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
update_channels();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==2, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==2 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
kernel_st = 3;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==3, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==3 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
fire_delta_events();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==3, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==3 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
activate_threads();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==3, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==3 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
reset_delta_events();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==3, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==3 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
tmp = stop_simulation();

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==3, z_ev#init==2, z_req_up#init==0,
//    z_val#init==0, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1, 0<=tmp, tmp<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==3 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 && 0<=tmp && tmp<=1 );
if (tmp) {
}
else {
goto l99999;
}

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==3, tmp==1, z_ev#init==2,
//    z_req_up#init==0, z_val#init==0, b0_req_up<=1, b1_req_up<=1,
//    d0_req_up<=1, d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==3 && tmp==1 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
/* CIL Label */
while_1_break:   ;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,comp_m1_st,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,kernel_st,tmp,z_ev,
//    z_req_up,z_val,z_val_t) {b0_ev#init==2, b0_req_up#init==1,
//    b0_val#init==0, b1_ev#init==2, b1_req_up#init==1,
//    b1_val#init==0, d0_ev#init==2, d0_req_up#init==1,
//    d0_val#init==0, d1_ev#init==2, d1_req_up#init==1,
//    d1_val#init==0, kernel_st==3, tmp==1, z_ev#init==2,
//    z_req_up#init==0, z_val#init==0, b0_req_up<=1, b1_req_up<=1,
//    d0_req_up<=1, d1_req_up<=1}

__ESBMC_assume( b0_ev_init==2 && b0_req_up_init==1 && b0_val_init==0 && b1_ev_init==2 && b1_req_up_init==1 && b1_val_init==0 && d0_ev_init==2 && d0_req_up_init==1 && d0_val_init==0 && d1_ev_init==2 && d1_req_up_init==1 && d1_val_init==0 && kernel_st==3 && tmp==1 && z_ev_init==2 && z_req_up_init==0 && z_val_init==0 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );

return;
}

//  P() {}


void init_model(void)
{


//  P() {}


b0_val = 0;

//  P(b0_val) {b0_val==0}

__ESBMC_assume( b0_val==0 );

b0_ev = 2;

//  P(b0_ev,b0_val) {b0_ev==2, b0_val==0}

__ESBMC_assume( b0_ev==2 && b0_val==0 );

b0_req_up = 0;

//  P(b0_ev,b0_req_up,b0_val) {b0_ev==2, b0_req_up==0, b0_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 );

b1_val = 0;

//  P(b0_ev,b0_req_up,b0_val,b1_val) {b0_ev==2, b0_req_up==0,
//    b0_val==0, b1_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_val==0 );
b1_ev = 2;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_val) {b0_ev==2, b0_req_up==0,
//    b0_val==0, b1_ev==2, b1_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_val==0 );
b1_req_up = 0;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val) {b0_ev==2,
//    b0_req_up==0, b0_val==0, b1_ev==2, b1_req_up==0, b1_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 );
d0_val = 0;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_val) {b0_ev==2,
//    b0_req_up==0, b0_val==0, b1_ev==2, b1_req_up==0, b1_val==0,
//    d0_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_val==0 );
d0_ev = 2;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_val)
//    {b0_ev==2, b0_req_up==0, b0_val==0, b1_ev==2, b1_req_up==0,
//    b1_val==0, d0_ev==2, d0_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_val==0 );
d0_req_up = 0;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val) {b0_ev==2, b0_req_up==0, b0_val==0, b1_ev==2,
//    b1_req_up==0, b1_val==0, d0_ev==2, d0_req_up==0, d0_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 );
d1_val = 0;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_val) {b0_ev==2, b0_req_up==0, b0_val==0, b1_ev==2,
//    b1_req_up==0, b1_val==0, d0_ev==2, d0_req_up==0, d0_val==0,
//    d1_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_val==0 );
d1_ev = 2;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_val) {b0_ev==2, b0_req_up==0, b0_val==0,
//    b1_ev==2, b1_req_up==0, b1_val==0, d0_ev==2, d0_req_up==0,
//    d0_val==0, d1_ev==2, d1_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_val==0 );
d1_req_up = 0;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_req_up,d1_val) {b0_ev==2, b0_req_up==0,
//    b0_val==0, b1_ev==2, b1_req_up==0, b1_val==0, d0_ev==2,
//    d0_req_up==0, d0_val==0, d1_ev==2, d1_req_up==0, d1_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_req_up==0 && d1_val==0 );
z_val = 0;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_req_up,d1_val,z_val) {b0_ev==2, b0_req_up==0,
//    b0_val==0, b1_ev==2, b1_req_up==0, b1_val==0, d0_ev==2,
//    d0_req_up==0, d0_val==0, d1_ev==2, d1_req_up==0, d1_val==0,
//    z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_val==0 );
z_ev = 2;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_req_up,d1_val,z_ev,z_val) {b0_ev==2,
//    b0_req_up==0, b0_val==0, b1_ev==2, b1_req_up==0, b1_val==0,
//    d0_ev==2, d0_req_up==0, d0_val==0, d1_ev==2, d1_req_up==0,
//    d1_val==0, z_ev==2, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_ev==2 && z_val==0 );
z_req_up = 0;

//  P(b0_ev,b0_req_up,b0_val,b1_ev,b1_req_up,b1_val,d0_ev,d0_req_up,
//    d0_val,d1_ev,d1_req_up,d1_val,z_ev,z_req_up,z_val) {b0_ev==2,
//    b0_req_up==0, b0_val==0, b1_ev==2, b1_req_up==0, b1_val==0,
//    d0_ev==2, d0_req_up==0, d0_val==0, d1_ev==2, d1_req_up==0,
//    d1_val==0, z_ev==2, z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
b0_val_t = 1;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,z_ev,z_req_up,z_val)
//    {b0_ev==2, b0_req_up==0, b0_val==0, b0_val_t==1, b1_ev==2,
//    b1_req_up==0, b1_val==0, d0_ev==2, d0_req_up==0, d0_val==0,
//    d1_ev==2, d1_req_up==0, d1_val==0, z_ev==2, z_req_up==0,
//    z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==0 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
b0_req_up = 1;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,d0_ev,
//    d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,z_ev,z_req_up,z_val)
//    {b0_ev==2, b0_req_up==1, b0_val==0, b0_val_t==1, b1_ev==2,
//    b1_req_up==0, b1_val==0, d0_ev==2, d0_req_up==0, d0_val==0,
//    d1_ev==2, d1_req_up==0, d1_val==0, z_ev==2, z_req_up==0,
//    z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==0 && b1_val==0 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
b1_val_t = 1;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,b1_val_t,
//    d0_ev,d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,z_ev,z_req_up,
//    z_val) {b0_ev==2, b0_req_up==1, b0_val==0, b0_val_t==1,
//    b1_ev==2, b1_req_up==0, b1_val==0, b1_val_t==1, d0_ev==2,
//    d0_req_up==0, d0_val==0, d1_ev==2, d1_req_up==0, d1_val==0,
//    z_ev==2, z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==0 && b1_val==0 && b1_val_t==1 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
b1_req_up = 1;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,b1_val_t,
//    d0_ev,d0_req_up,d0_val,d1_ev,d1_req_up,d1_val,z_ev,z_req_up,
//    z_val) {b0_ev==2, b0_req_up==1, b0_val==0, b0_val_t==1,
//    b1_ev==2, b1_req_up==1, b1_val==0, b1_val_t==1, d0_ev==2,
//    d0_req_up==0, d0_val==0, d1_ev==2, d1_req_up==0, d1_val==0,
//    z_ev==2, z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==1 && b1_val==0 && b1_val_t==1 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
d0_val_t = 1;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,b1_val_t,
//    d0_ev,d0_req_up,d0_val,d0_val_t,d1_ev,d1_req_up,d1_val,z_ev,
//    z_req_up,z_val) {b0_ev==2, b0_req_up==1, b0_val==0, b0_val_t==1,
//    b1_ev==2, b1_req_up==1, b1_val==0, b1_val_t==1, d0_ev==2,
//    d0_req_up==0, d0_val==0, d0_val_t==1, d1_ev==2, d1_req_up==0,
//    d1_val==0, z_ev==2, z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==1 && b1_val==0 && b1_val_t==1 && d0_ev==2 && d0_req_up==0 && d0_val==0 && d0_val_t==1 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
d0_req_up = 1;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,b1_val_t,
//    d0_ev,d0_req_up,d0_val,d0_val_t,d1_ev,d1_req_up,d1_val,z_ev,
//    z_req_up,z_val) {b0_ev==2, b0_req_up==1, b0_val==0, b0_val_t==1,
//    b1_ev==2, b1_req_up==1, b1_val==0, b1_val_t==1, d0_ev==2,
//    d0_req_up==1, d0_val==0, d0_val_t==1, d1_ev==2, d1_req_up==0,
//    d1_val==0, z_ev==2, z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==1 && b1_val==0 && b1_val_t==1 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d0_val_t==1 && d1_ev==2 && d1_req_up==0 && d1_val==0 && z_ev==2 && z_req_up==0 && z_val==0 );
d1_val_t = 1;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,b1_val_t,
//    d0_ev,d0_req_up,d0_val,d0_val_t,d1_ev,d1_req_up,d1_val,d1_val_t,
//    z_ev,z_req_up,z_val) {b0_ev==2, b0_req_up==1, b0_val==0,
//    b0_val_t==1, b1_ev==2, b1_req_up==1, b1_val==0, b1_val_t==1,
//    d0_ev==2, d0_req_up==1, d0_val==0, d0_val_t==1, d1_ev==2,
//    d1_req_up==0, d1_val==0, d1_val_t==1, z_ev==2, z_req_up==0,
//    z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==1 && b1_val==0 && b1_val_t==1 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d0_val_t==1 && d1_ev==2 && d1_req_up==0 && d1_val==0 && d1_val_t==1 && z_ev==2 && z_req_up==0 && z_val==0 );
d1_req_up = 1;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,b1_val_t,
//    d0_ev,d0_req_up,d0_val,d0_val_t,d1_ev,d1_req_up,d1_val,d1_val_t,
//    z_ev,z_req_up,z_val) {b0_ev==2, b0_req_up==1, b0_val==0,
//    b0_val_t==1, b1_ev==2, b1_req_up==1, b1_val==0, b1_val_t==1,
//    d0_ev==2, d0_req_up==1, d0_val==0, d0_val_t==1, d1_ev==2,
//    d1_req_up==1, d1_val==0, d1_val_t==1, z_ev==2, z_req_up==0,
//    z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==1 && b1_val==0 && b1_val_t==1 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d0_val_t==1 && d1_ev==2 && d1_req_up==1 && d1_val==0 && d1_val_t==1 && z_ev==2 && z_req_up==0 && z_val==0 );
comp_m1_i = 0;

//  P(b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,b1_val,b1_val_t,
//    comp_m1_i,d0_ev,d0_req_up,d0_val,d0_val_t,d1_ev,d1_req_up,
//    d1_val,d1_val_t,z_ev,z_req_up,z_val) {b0_ev==2, b0_req_up==1,
//    b0_val==0, b0_val_t==1, b1_ev==2, b1_req_up==1, b1_val==0,
//    b1_val_t==1, comp_m1_i==0, d0_ev==2, d0_req_up==1, d0_val==0,
//    d0_val_t==1, d1_ev==2, d1_req_up==1, d1_val==0, d1_val_t==1,
//    z_ev==2, z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==1 && b1_val==0 && b1_val_t==1 && comp_m1_i==0 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d0_val_t==1 && d1_ev==2 && d1_req_up==1 && d1_val==0 && d1_val_t==1 && z_ev==2 && z_req_up==0 && z_val==0 );

return;
}

//  P() {}


int main(void)
{


//  P() {}


int __retres1;

//  P(__retres1) {}


init_model();

//  P(__retres1,b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,
//    b1_val,b1_val_t,comp_m1_i,d0_ev,d0_req_up,d0_val,d0_val_t,d1_ev,
//    d1_req_up,d1_val,d1_val_t,z_ev,z_req_up,z_val) {b0_ev==2,
//    b0_req_up==1, b0_val==0, b0_val_t==1, b1_ev==2, b1_req_up==1,
//    b1_val==0, b1_val_t==1, comp_m1_i==0, d0_ev==2, d0_req_up==1,
//    d0_val==0, d0_val_t==1, d1_ev==2, d1_req_up==1, d1_val==0,
//    d1_val_t==1, z_ev==2, z_req_up==0, z_val==0}

__ESBMC_assume( b0_ev==2 && b0_req_up==1 && b0_val==0 && b0_val_t==1 && b1_ev==2 && b1_req_up==1 && b1_val==0 && b1_val_t==1 && comp_m1_i==0 && d0_ev==2 && d0_req_up==1 && d0_val==0 && d0_val_t==1 && d1_ev==2 && d1_req_up==1 && d1_val==0 && d1_val_t==1 && z_ev==2 && z_req_up==0 && z_val==0 );
start_simulation();

//  P(__retres1,b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,
//    b1_val,b1_val_t,comp_m1_i,comp_m1_st,d0_ev,d0_req_up,d0_val,
//    d0_val_t,d1_ev,d1_req_up,d1_val,d1_val_t,z_ev,z_req_up,z_val,
//    z_val_t) {b0_val_t==1, b1_val_t==1, comp_m1_i==0, d0_val_t==1,
//    d1_val_t==1, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_val_t==1 && b1_val_t==1 && comp_m1_i==0 && d0_val_t==1 && d1_val_t==1 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
if (!(z_val==0)) {

//  P(__retres1,b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,
//    b1_val,b1_val_t,comp_m1_i,comp_m1_st,d0_ev,d0_req_up,d0_val,
//    d0_val_t,d1_ev,d1_req_up,d1_val,d1_val_t,z_ev,z_req_up,z_val,
//    z_val_t) {b0_val_t==1, b1_val_t==1, comp_m1_i==0, d0_val_t==1,
//    d1_val_t==1, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_val_t==1 && b1_val_t==1 && comp_m1_i==0 && d0_val_t==1 && d1_val_t==1 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
error();
}

//  P(__retres1,b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,
//    b1_val,b1_val_t,comp_m1_i,comp_m1_st,d0_ev,d0_req_up,d0_val,
//    d0_val_t,d1_ev,d1_req_up,d1_val,d1_val_t,z_ev,z_req_up,z_val,
//    z_val_t) {b0_val_t==1, b1_val_t==1, comp_m1_i==0, d0_val_t==1,
//    d1_val_t==1, b0_req_up<=1, b1_req_up<=1, d0_req_up<=1,
//    d1_req_up<=1}

__ESBMC_assume( b0_val_t==1 && b1_val_t==1 && comp_m1_i==0 && d0_val_t==1 && d1_val_t==1 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
__retres1 = 0;

//  P(__retres1,b0_ev,b0_req_up,b0_val,b0_val_t,b1_ev,b1_req_up,
//    b1_val,b1_val_t,comp_m1_i,comp_m1_st,d0_ev,d0_req_up,d0_val,
//    d0_val_t,d1_ev,d1_req_up,d1_val,d1_val_t,z_ev,z_req_up,z_val,
//    z_val_t) {__retres1==0, b0_val_t==1, b1_val_t==1, comp_m1_i==0,
//    d0_val_t==1, d1_val_t==1, b0_req_up<=1, b1_req_up<=1,
//    d0_req_up<=1, d1_req_up<=1}

__ESBMC_assume( __retres1==0 && b0_val_t==1 && b1_val_t==1 && comp_m1_i==0 && d0_val_t==1 && d1_val_t==1 && b0_req_up<=1 && b1_req_up<=1 && d0_req_up<=1 && d1_req_up<=1 );
return 0;
}