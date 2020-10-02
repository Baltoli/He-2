#ifndef _OUTPUT_EXALGO_H
#define _OUTPUT_EXALGO_H

/* all data structures which are outputted to files should reside here for use
   of other clients or post processing passes */

#define MAX_SRCS 4
#define MAX_DSTS 4

#define REG_TYPE 0
#define MEM_STACK_TYPE 1
#define MEM_HEAP_TYPE 2
#define IMM_FLOAT_TYPE 3
#define IMM_INT_TYPE 4
#define DEFAULT_TYPE 5

typedef unsigned int uint;

typedef struct _operand_t {

  uint64 type;
  uint64 width;
  union {
    uint64 value;
    float float_value;
  };
  struct _operand_t* addr;
} operand_t;

typedef struct _output_t {

  uint64 opcode;
  uint64 num_srcs;
  uint64 num_dsts;
  operand_t srcs[MAX_SRCS];
  operand_t dsts[MAX_DSTS];
  uint64 eflags;
  uint64 pc;

} output_t;

#endif

