/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

#line 44 "../dma_example.h"
struct _control_block {
   unsigned long long in_addr ;
   unsigned long long out_addr ;
   unsigned int num_elements_per_spe ;
   unsigned int id ;
   unsigned int pad[2] ;
};
#line 44 "../dma_example.h"
typedef struct _control_block control_block_t;
#line 339 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 203 "../spu_mfcio.h"
extern void mfc_put(void volatile   *ls , unsigned int ea , unsigned int size , unsigned int tag ,
                    unsigned int tid , unsigned int rid ) ;
#line 211
extern void mfc_get(void volatile   *ls , unsigned int ea , unsigned int size , unsigned int tag ,
                    unsigned int tid , unsigned int rid ) ;
#line 252
extern void mfc_write_tag_mask(unsigned int mask ) ;
#line 270
extern void mfc_read_tag_status_all() ;
#line 28 "dma_example_spu.c"
float local_buffers[3][4096]  __attribute__((__aligned__(128)))  ;
#line 35 "dma_example_spu.c"
control_block_t control_block  __attribute__((__aligned__(128)))  ;
#line 99
extern int __VERIFIER_nondet_int() ;
#line 162
extern int ( /* missing proto */  assert)() ;
#line 70 "dma_example_spu.c"
int spu_main(unsigned long long speid  __attribute__((__unused__)) , unsigned long long argp ,
             unsigned long long envp  __attribute__((__unused__)) ) 
{ unsigned int tags[3] ;
  unsigned long long in_addr ;
  unsigned long long out_addr ;
  unsigned int i ;
  unsigned int num_chunks ;
  int cur_in_buf ;
  int next_in_buf ;
  int cur_out_buf ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  unsigned long __cil_tmp22 ;
  unsigned long __cil_tmp23 ;
  unsigned long __cil_tmp24 ;
  unsigned long __cil_tmp25 ;
  unsigned long __cil_tmp26 ;
  unsigned long __cil_tmp27 ;
  unsigned long __cil_tmp28 ;
  unsigned long __cil_tmp29 ;
  unsigned int __cil_tmp30 ;
  char const   * __restrict  __cil_tmp31 ;
  unsigned long __cil_tmp32 ;
  unsigned long __cil_tmp33 ;
  unsigned int __cil_tmp34 ;
  char const   * __restrict  __cil_tmp35 ;
  unsigned long __cil_tmp36 ;
  unsigned long __cil_tmp37 ;
  unsigned int __cil_tmp38 ;
  char const   * __restrict  __cil_tmp39 ;
  void volatile   *__cil_tmp40 ;
  unsigned int __cil_tmp41 ;
  unsigned int __cil_tmp42 ;
  unsigned long __cil_tmp43 ;
  unsigned long __cil_tmp44 ;
  unsigned int __cil_tmp45 ;
  control_block_t *__cil_tmp46 ;
  unsigned long __cil_tmp47 ;
  unsigned long __cil_tmp48 ;
  unsigned long __cil_tmp49 ;
  unsigned long __cil_tmp50 ;
  unsigned long __cil_tmp51 ;
  unsigned long __cil_tmp52 ;
  unsigned long __cil_tmp53 ;
  unsigned long __cil_tmp54 ;
  unsigned long __cil_tmp55 ;
  unsigned long __cil_tmp56 ;
  unsigned long __cil_tmp57 ;
  unsigned int __cil_tmp58 ;
  int __cil_tmp59 ;
  unsigned int __cil_tmp60 ;
  unsigned long __cil_tmp61 ;
  unsigned int __cil_tmp62 ;
  control_block_t *__cil_tmp63 ;
  unsigned long __cil_tmp64 ;
  unsigned long __cil_tmp65 ;
  unsigned long __cil_tmp66 ;
  unsigned long __cil_tmp67 ;
  unsigned long __cil_tmp68 ;
  float *__cil_tmp69 ;
  void volatile   *__cil_tmp70 ;
  unsigned int __cil_tmp71 ;
  unsigned long __cil_tmp72 ;
  unsigned int __cil_tmp73 ;
  unsigned long __cil_tmp74 ;
  unsigned long __cil_tmp75 ;
  unsigned int __cil_tmp76 ;
  unsigned long __cil_tmp77 ;
  unsigned long long __cil_tmp78 ;
  unsigned long __cil_tmp79 ;
  unsigned long __cil_tmp80 ;
  unsigned long __cil_tmp81 ;
  unsigned long __cil_tmp82 ;
  float *__cil_tmp83 ;
  void volatile   *__cil_tmp84 ;
  unsigned int __cil_tmp85 ;
  unsigned long __cil_tmp86 ;
  unsigned int __cil_tmp87 ;
  unsigned long __cil_tmp88 ;
  unsigned long __cil_tmp89 ;
  unsigned int __cil_tmp90 ;
  unsigned long __cil_tmp91 ;
  unsigned long long __cil_tmp92 ;
  unsigned long __cil_tmp93 ;
  unsigned long __cil_tmp94 ;
  unsigned int __cil_tmp95 ;
  int __cil_tmp96 ;
  unsigned int __cil_tmp97 ;
  unsigned long __cil_tmp98 ;
  unsigned long __cil_tmp99 ;
  unsigned int __cil_tmp100 ;
  int __cil_tmp101 ;
  unsigned long __cil_tmp102 ;
  unsigned long __cil_tmp103 ;
  unsigned int __cil_tmp104 ;
  int __cil_tmp105 ;
  unsigned long __cil_tmp106 ;
  unsigned long __cil_tmp107 ;
  unsigned int __cil_tmp108 ;
  int __cil_tmp109 ;
  unsigned long __cil_tmp110 ;
  unsigned long __cil_tmp111 ;
  unsigned long __cil_tmp112 ;
  unsigned long __cil_tmp113 ;
  float *__cil_tmp114 ;
  void volatile   *__cil_tmp115 ;
  unsigned int __cil_tmp116 ;
  unsigned long __cil_tmp117 ;
  unsigned int __cil_tmp118 ;
  unsigned long __cil_tmp119 ;
  unsigned long __cil_tmp120 ;
  unsigned int __cil_tmp121 ;
  unsigned long __cil_tmp122 ;
  unsigned long long __cil_tmp123 ;
  unsigned long __cil_tmp124 ;
  unsigned long __cil_tmp125 ;
  unsigned long __cil_tmp126 ;
  unsigned long __cil_tmp127 ;
  float *__cil_tmp128 ;
  void volatile   *__cil_tmp129 ;
  unsigned int __cil_tmp130 ;
  unsigned long __cil_tmp131 ;
  unsigned int __cil_tmp132 ;
  unsigned long __cil_tmp133 ;
  unsigned long __cil_tmp134 ;
  unsigned int __cil_tmp135 ;
  unsigned long __cil_tmp136 ;
  unsigned long long __cil_tmp137 ;
  unsigned long __cil_tmp138 ;
  unsigned long __cil_tmp139 ;
  unsigned int __cil_tmp140 ;
  int __cil_tmp141 ;
  unsigned int __cil_tmp142 ;
  unsigned long __cil_tmp143 ;
  unsigned long __cil_tmp144 ;
  unsigned long __cil_tmp145 ;
  unsigned long __cil_tmp146 ;
  float *__cil_tmp147 ;
  void volatile   *__cil_tmp148 ;
  unsigned int __cil_tmp149 ;
  unsigned long __cil_tmp150 ;
  unsigned int __cil_tmp151 ;
  unsigned long __cil_tmp152 ;
  unsigned long __cil_tmp153 ;
  unsigned int __cil_tmp154 ;
  unsigned long __cil_tmp155 ;
  unsigned long long __cil_tmp156 ;
  unsigned long __cil_tmp157 ;
  unsigned long __cil_tmp158 ;
  unsigned int __cil_tmp159 ;
  int __cil_tmp160 ;
  unsigned int __cil_tmp161 ;
  unsigned long __cil_tmp162 ;
  unsigned long __cil_tmp163 ;
  unsigned long __cil_tmp164 ;
  unsigned long __cil_tmp165 ;
  float *__cil_tmp166 ;
  void volatile   *__cil_tmp167 ;
  unsigned int __cil_tmp168 ;
  unsigned long __cil_tmp169 ;
  unsigned int __cil_tmp170 ;
  unsigned long __cil_tmp171 ;
  unsigned long __cil_tmp172 ;
  unsigned int __cil_tmp173 ;
  unsigned long __cil_tmp174 ;
  unsigned long __cil_tmp175 ;
  unsigned int __cil_tmp176 ;
  int __cil_tmp177 ;
  unsigned int __cil_tmp178 ;

  {
#line 88
  __cil_tmp22 = 0 * 4UL;
#line 88
  __cil_tmp23 = (unsigned long )(tags) + __cil_tmp22;
#line 88
  *((unsigned int *)__cil_tmp23) = 0U;
#line 89
  __cil_tmp24 = 1 * 4UL;
#line 89
  __cil_tmp25 = (unsigned long )(tags) + __cil_tmp24;
#line 89
  *((unsigned int *)__cil_tmp25) = 1U;
#line 90
  __cil_tmp26 = 2 * 4UL;
#line 90
  __cil_tmp27 = (unsigned long )(tags) + __cil_tmp26;
#line 90
  *((unsigned int *)__cil_tmp27) = 2U;
  {
#line 92
  __cil_tmp28 = 0 * 4UL;
#line 92
  __cil_tmp29 = (unsigned long )(tags) + __cil_tmp28;
#line 92
  __cil_tmp30 = *((unsigned int *)__cil_tmp29);
#line 92
  if (__cil_tmp30 == 4294967295U) {
    {
#line 94
    __cil_tmp31 = (char const   * __restrict  )"SPU ERROR, unable to reserve tag\n";
#line 94
    printf(__cil_tmp31);
    }
#line 95
    return (1);
  } else {
    {
#line 92
    __cil_tmp32 = 1 * 4UL;
#line 92
    __cil_tmp33 = (unsigned long )(tags) + __cil_tmp32;
#line 92
    __cil_tmp34 = *((unsigned int *)__cil_tmp33);
#line 92
    if (__cil_tmp34 == 4294967295U) {
      {
#line 94
      __cil_tmp35 = (char const   * __restrict  )"SPU ERROR, unable to reserve tag\n";
#line 94
      printf(__cil_tmp35);
      }
#line 95
      return (1);
    } else {
      {
#line 92
      __cil_tmp36 = 2 * 4UL;
#line 92
      __cil_tmp37 = (unsigned long )(tags) + __cil_tmp36;
#line 92
      __cil_tmp38 = *((unsigned int *)__cil_tmp37);
#line 92
      if (__cil_tmp38 == 4294967295U) {
        {
#line 94
        __cil_tmp39 = (char const   * __restrict  )"SPU ERROR, unable to reserve tag\n";
#line 94
        printf(__cil_tmp39);
        }
#line 95
        return (1);
      } else {

      }
      }
    }
    }
  }
  }
  {
#line 98
  __cil_tmp40 = (void volatile   *)(& control_block);
#line 98
  __cil_tmp41 = (unsigned int )argp;
#line 98
  __cil_tmp42 = (unsigned int )32UL;
#line 98
  __cil_tmp43 = 0 * 4UL;
#line 98
  __cil_tmp44 = (unsigned long )(tags) + __cil_tmp43;
#line 98
  __cil_tmp45 = *((unsigned int *)__cil_tmp44);
#line 98
  mfc_get(__cil_tmp40, __cil_tmp41, __cil_tmp42, __cil_tmp45, 0U, 0U);
#line 99
  tmp = __VERIFIER_nondet_int();
#line 99
  __cil_tmp46 = & control_block;
#line 99
  *((unsigned long long *)__cil_tmp46) = (unsigned long long )tmp;
#line 99
  tmp___0 = __VERIFIER_nondet_int();
#line 99
  __cil_tmp47 = (unsigned long )(& control_block) + 8;
#line 99
  *((unsigned long long *)__cil_tmp47) = (unsigned long long )tmp___0;
#line 99
  tmp___1 = __VERIFIER_nondet_int();
#line 99
  __cil_tmp48 = (unsigned long )(& control_block) + 16;
#line 99
  *((unsigned int *)__cil_tmp48) = (unsigned int )tmp___1;
#line 99
  tmp___2 = __VERIFIER_nondet_int();
#line 99
  __cil_tmp49 = (unsigned long )(& control_block) + 20;
#line 99
  *((unsigned int *)__cil_tmp49) = (unsigned int )tmp___2;
#line 99
  tmp___3 = __VERIFIER_nondet_int();
#line 99
  __cil_tmp50 = 0 * 4UL;
#line 99
  __cil_tmp51 = 24 + __cil_tmp50;
#line 99
  __cil_tmp52 = (unsigned long )(& control_block) + __cil_tmp51;
#line 99
  *((unsigned int *)__cil_tmp52) = (unsigned int )tmp___3;
#line 99
  tmp___4 = __VERIFIER_nondet_int();
#line 99
  __cil_tmp53 = 1 * 4UL;
#line 99
  __cil_tmp54 = 24 + __cil_tmp53;
#line 99
  __cil_tmp55 = (unsigned long )(& control_block) + __cil_tmp54;
#line 99
  *((unsigned int *)__cil_tmp55) = (unsigned int )tmp___4;
#line 102
  __cil_tmp56 = 0 * 4UL;
#line 102
  __cil_tmp57 = (unsigned long )(tags) + __cil_tmp56;
#line 102
  __cil_tmp58 = *((unsigned int *)__cil_tmp57);
#line 102
  __cil_tmp59 = 1 << __cil_tmp58;
#line 102
  __cil_tmp60 = (unsigned int )__cil_tmp59;
#line 102
  mfc_write_tag_mask(__cil_tmp60);
#line 103
  mfc_read_tag_status_all();
#line 107
  __cil_tmp61 = (unsigned long )(& control_block) + 16;
#line 107
  __cil_tmp62 = *((unsigned int *)__cil_tmp61);
#line 107
  num_chunks = __cil_tmp62 / 4096U;
#line 117
  cur_in_buf = 0;
#line 118
  next_in_buf = 1;
#line 119
  cur_out_buf = 2;
#line 123
  __cil_tmp63 = & control_block;
#line 123
  in_addr = *((unsigned long long *)__cil_tmp63);
#line 127
  __cil_tmp64 = (unsigned long )(& control_block) + 8;
#line 127
  out_addr = *((unsigned long long *)__cil_tmp64);
#line 130
  __cil_tmp65 = 0 * 4UL;
#line 130
  __cil_tmp66 = cur_in_buf * 16384UL;
#line 130
  __cil_tmp67 = __cil_tmp66 + __cil_tmp65;
#line 130
  __cil_tmp68 = (unsigned long )(local_buffers) + __cil_tmp67;
#line 130
  __cil_tmp69 = (float *)__cil_tmp68;
#line 130
  __cil_tmp70 = (void volatile   *)__cil_tmp69;
#line 130
  __cil_tmp71 = (unsigned int )in_addr;
#line 130
  __cil_tmp72 = 4096UL * 4UL;
#line 130
  __cil_tmp73 = (unsigned int )__cil_tmp72;
#line 130
  __cil_tmp74 = cur_in_buf * 4UL;
#line 130
  __cil_tmp75 = (unsigned long )(tags) + __cil_tmp74;
#line 130
  __cil_tmp76 = *((unsigned int *)__cil_tmp75);
#line 130
  mfc_get(__cil_tmp70, __cil_tmp71, __cil_tmp73, __cil_tmp76, 0U, 0U);
#line 134
  __cil_tmp77 = 4096UL * 4UL;
#line 134
  __cil_tmp78 = (unsigned long long )__cil_tmp77;
#line 134
  in_addr = in_addr + __cil_tmp78;
#line 137
  __cil_tmp79 = 0 * 4UL;
#line 137
  __cil_tmp80 = next_in_buf * 16384UL;
#line 137
  __cil_tmp81 = __cil_tmp80 + __cil_tmp79;
#line 137
  __cil_tmp82 = (unsigned long )(local_buffers) + __cil_tmp81;
#line 137
  __cil_tmp83 = (float *)__cil_tmp82;
#line 137
  __cil_tmp84 = (void volatile   *)__cil_tmp83;
#line 137
  __cil_tmp85 = (unsigned int )in_addr;
#line 137
  __cil_tmp86 = 4096UL * 4UL;
#line 137
  __cil_tmp87 = (unsigned int )__cil_tmp86;
#line 137
  __cil_tmp88 = next_in_buf * 4UL;
#line 137
  __cil_tmp89 = (unsigned long )(tags) + __cil_tmp88;
#line 137
  __cil_tmp90 = *((unsigned int *)__cil_tmp89);
#line 137
  mfc_get(__cil_tmp84, __cil_tmp85, __cil_tmp87, __cil_tmp90, 0U, 0U);
#line 141
  __cil_tmp91 = 4096UL * 4UL;
#line 141
  __cil_tmp92 = (unsigned long long )__cil_tmp91;
#line 141
  in_addr = in_addr + __cil_tmp92;
#line 144
  __cil_tmp93 = cur_in_buf * 4UL;
#line 144
  __cil_tmp94 = (unsigned long )(tags) + __cil_tmp93;
#line 144
  __cil_tmp95 = *((unsigned int *)__cil_tmp94);
#line 144
  __cil_tmp96 = 1 << __cil_tmp95;
#line 144
  __cil_tmp97 = (unsigned int )__cil_tmp96;
#line 144
  mfc_write_tag_mask(__cil_tmp97);
#line 145
  mfc_read_tag_status_all();
#line 158
  i = 2U;
  }
  {
#line 158
  while (1) {
    while_continue: /* CIL Label */ ;
#line 158
    if (i < num_chunks) {

    } else {
#line 158
      goto while_break;
    }
#line 162
    if (cur_out_buf >= 0) {
#line 162
      if (cur_out_buf < 3) {
#line 162
        tmp___6 = 1;
      } else {
#line 162
        tmp___6 = 0;
      }
    } else {
#line 162
      tmp___6 = 0;
    }
    {
#line 162
    assert(tmp___6);
    }
#line 163
    if (cur_in_buf >= 0) {
#line 163
      if (cur_in_buf < 3) {
#line 163
        tmp___7 = 1;
      } else {
#line 163
        tmp___7 = 0;
      }
    } else {
#line 163
      tmp___7 = 0;
    }
    {
#line 163
    assert(tmp___7);
    }
#line 164
    if (next_in_buf >= 0) {
#line 164
      if (next_in_buf < 3) {
#line 164
        tmp___8 = 1;
      } else {
#line 164
        tmp___8 = 0;
      }
    } else {
#line 164
      tmp___8 = 0;
    }
    {
#line 164
    assert(tmp___8);
#line 165
    __cil_tmp98 = 0 * 4UL;
#line 165
    __cil_tmp99 = (unsigned long )(tags) + __cil_tmp98;
#line 165
    __cil_tmp100 = *((unsigned int *)__cil_tmp99);
#line 165
    __cil_tmp101 = __cil_tmp100 == 0U;
#line 165
    assert(__cil_tmp101);
#line 166
    __cil_tmp102 = 1 * 4UL;
#line 166
    __cil_tmp103 = (unsigned long )(tags) + __cil_tmp102;
#line 166
    __cil_tmp104 = *((unsigned int *)__cil_tmp103);
#line 166
    __cil_tmp105 = __cil_tmp104 == 1U;
#line 166
    assert(__cil_tmp105);
#line 167
    __cil_tmp106 = 2 * 4UL;
#line 167
    __cil_tmp107 = (unsigned long )(tags) + __cil_tmp106;
#line 167
    __cil_tmp108 = *((unsigned int *)__cil_tmp107);
#line 167
    __cil_tmp109 = __cil_tmp108 == 2U;
#line 167
    assert(__cil_tmp109);
#line 172
    __cil_tmp110 = 0 * 4UL;
#line 172
    __cil_tmp111 = cur_out_buf * 16384UL;
#line 172
    __cil_tmp112 = __cil_tmp111 + __cil_tmp110;
#line 172
    __cil_tmp113 = (unsigned long )(local_buffers) + __cil_tmp112;
#line 172
    __cil_tmp114 = (float *)__cil_tmp113;
#line 172
    __cil_tmp115 = (void volatile   *)__cil_tmp114;
#line 172
    __cil_tmp116 = (unsigned int )out_addr;
#line 172
    __cil_tmp117 = 4096UL * 4UL;
#line 172
    __cil_tmp118 = (unsigned int )__cil_tmp117;
#line 172
    __cil_tmp119 = cur_out_buf * 4UL;
#line 172
    __cil_tmp120 = (unsigned long )(tags) + __cil_tmp119;
#line 172
    __cil_tmp121 = *((unsigned int *)__cil_tmp120);
#line 172
    mfc_put(__cil_tmp115, __cil_tmp116, __cil_tmp118, __cil_tmp121, 0U, 0U);
#line 176
    __cil_tmp122 = 4096UL * 4UL;
#line 176
    __cil_tmp123 = (unsigned long long )__cil_tmp122;
#line 176
    out_addr = out_addr + __cil_tmp123;
#line 179
    tmp___5 = next_in_buf;
#line 180
    next_in_buf = cur_out_buf;
#line 181
    cur_out_buf = cur_in_buf;
#line 182
    cur_in_buf = tmp___5;
#line 194
    __cil_tmp124 = 0 * 4UL;
#line 194
    __cil_tmp125 = next_in_buf * 16384UL;
#line 194
    __cil_tmp126 = __cil_tmp125 + __cil_tmp124;
#line 194
    __cil_tmp127 = (unsigned long )(local_buffers) + __cil_tmp126;
#line 194
    __cil_tmp128 = (float *)__cil_tmp127;
#line 194
    __cil_tmp129 = (void volatile   *)__cil_tmp128;
#line 194
    __cil_tmp130 = (unsigned int )in_addr;
#line 194
    __cil_tmp131 = 4096UL * 4UL;
#line 194
    __cil_tmp132 = (unsigned int )__cil_tmp131;
#line 194
    __cil_tmp133 = next_in_buf * 4UL;
#line 194
    __cil_tmp134 = (unsigned long )(tags) + __cil_tmp133;
#line 194
    __cil_tmp135 = *((unsigned int *)__cil_tmp134);
#line 194
    mfc_get(__cil_tmp129, __cil_tmp130, __cil_tmp132, __cil_tmp135, 0U, 0U);
#line 200
    __cil_tmp136 = 4096UL * 4UL;
#line 200
    __cil_tmp137 = (unsigned long long )__cil_tmp136;
#line 200
    in_addr = in_addr + __cil_tmp137;
#line 203
    __cil_tmp138 = cur_in_buf * 4UL;
#line 203
    __cil_tmp139 = (unsigned long )(tags) + __cil_tmp138;
#line 203
    __cil_tmp140 = *((unsigned int *)__cil_tmp139);
#line 203
    __cil_tmp141 = 1 << __cil_tmp140;
#line 203
    __cil_tmp142 = (unsigned int )__cil_tmp141;
#line 203
    mfc_write_tag_mask(__cil_tmp142);
#line 204
    mfc_read_tag_status_all();
#line 158
    i = i + 1U;
    }
  }
  while_break: /* CIL Label */ ;
  }
  {
#line 214
  __cil_tmp143 = 0 * 4UL;
#line 214
  __cil_tmp144 = cur_out_buf * 16384UL;
#line 214
  __cil_tmp145 = __cil_tmp144 + __cil_tmp143;
#line 214
  __cil_tmp146 = (unsigned long )(local_buffers) + __cil_tmp145;
#line 214
  __cil_tmp147 = (float *)__cil_tmp146;
#line 214
  __cil_tmp148 = (void volatile   *)__cil_tmp147;
#line 214
  __cil_tmp149 = (unsigned int )out_addr;
#line 214
  __cil_tmp150 = 4096UL * 4UL;
#line 214
  __cil_tmp151 = (unsigned int )__cil_tmp150;
#line 214
  __cil_tmp152 = cur_out_buf * 4UL;
#line 214
  __cil_tmp153 = (unsigned long )(tags) + __cil_tmp152;
#line 214
  __cil_tmp154 = *((unsigned int *)__cil_tmp153);
#line 214
  mfc_put(__cil_tmp148, __cil_tmp149, __cil_tmp151, __cil_tmp154, 0U, 0U);
#line 218
  __cil_tmp155 = 4096UL * 4UL;
#line 218
  __cil_tmp156 = (unsigned long long )__cil_tmp155;
#line 218
  out_addr = out_addr + __cil_tmp156;
#line 221
  cur_out_buf = cur_in_buf;
#line 222
  cur_in_buf = next_in_buf;
#line 225
  __cil_tmp157 = cur_in_buf * 4UL;
#line 225
  __cil_tmp158 = (unsigned long )(tags) + __cil_tmp157;
#line 225
  __cil_tmp159 = *((unsigned int *)__cil_tmp158);
#line 225
  __cil_tmp160 = 1 << __cil_tmp159;
#line 225
  __cil_tmp161 = (unsigned int )__cil_tmp160;
#line 225
  mfc_write_tag_mask(__cil_tmp161);
#line 226
  mfc_read_tag_status_all();
#line 234
  __cil_tmp162 = 0 * 4UL;
#line 234
  __cil_tmp163 = cur_out_buf * 16384UL;
#line 234
  __cil_tmp164 = __cil_tmp163 + __cil_tmp162;
#line 234
  __cil_tmp165 = (unsigned long )(local_buffers) + __cil_tmp164;
#line 234
  __cil_tmp166 = (float *)__cil_tmp165;
#line 234
  __cil_tmp167 = (void volatile   *)__cil_tmp166;
#line 234
  __cil_tmp168 = (unsigned int )out_addr;
#line 234
  __cil_tmp169 = 4096UL * 4UL;
#line 234
  __cil_tmp170 = (unsigned int )__cil_tmp169;
#line 234
  __cil_tmp171 = cur_out_buf * 4UL;
#line 234
  __cil_tmp172 = (unsigned long )(tags) + __cil_tmp171;
#line 234
  __cil_tmp173 = *((unsigned int *)__cil_tmp172);
#line 234
  mfc_put(__cil_tmp167, __cil_tmp168, __cil_tmp170, __cil_tmp173, 0U, 0U);
#line 238
  __cil_tmp174 = cur_out_buf * 4UL;
#line 238
  __cil_tmp175 = (unsigned long )(tags) + __cil_tmp174;
#line 238
  __cil_tmp176 = *((unsigned int *)__cil_tmp175);
#line 238
  __cil_tmp177 = 1 << __cil_tmp176;
#line 238
  __cil_tmp178 = (unsigned int )__cil_tmp177;
#line 238
  mfc_write_tag_mask(__cil_tmp178);
#line 239
  mfc_read_tag_status_all();
  }
#line 248
  return (0);
}
}
