//
//  vm.h
//  vmlox
//
//  Created by Gino Contestabile on 16/04/22.
//

#ifndef vm_h
#define vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256


typedef struct {
    Chunk* chunk;
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value* stackTop;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult; 

void initVM(void);
void freeVM(void);

void resetStack(void);
void push(Value value);
Value pop(void); 

InterpretResult interpret(Chunk* chunk);
InterpretResult run(void);

#endif /* vm_h */
