//
//  vm.c
//  vmlox
//
//  Created by Gino Contestabile on 16/04/22.
//

#include "vm.h"
#include "value.h"


VM vm;


void initVM() {
    resetStack();
}

void freeVM() {
    return ;
}

void resetStack() {
    vm.stackTop = vm.stack; 
}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}

InterpretResult run() {
    for(;;) {
#ifdef DEBUG_TRACE_EXECUTION
#include "debug.h"
        for(Value* slot = vm.stack; slot <vm.stackTop; slot++) {
            printf("[ ");
            printValue(*slot);
            printf(" ]");
        }
        printf("\n");
        disassembleInstruction(vm.chunk, (int) (vm.ip - vm.chunk->code) );
#endif
        uint8_t instruction;
        switch(instruction = *vm.ip++) {
            case OP_RETURN: {
                printValue(pop());
                printf("\n"); 
                return INTERPRET_OK;
            }
            case OP_CONSTANT: {
                Value constant = vm.chunk->constants.values[*vm.ip++];
                push(constant);
                printf("\n");
                break;
            }
            case OP_NEGATE: {
                push(-pop());
                break;
            }
            case OP_ADD: {
                push(pop() + pop());
                break;
            }
            case OP_SUBTRACT: {
                push(pop() - pop());
                break;
            }
            case OP_MULTIPLY: {
                push(pop() * pop());
                break;
            }
            case OP_DIVIDE: {
                push(pop() / pop());
                break;
            }

                
                
        }
    }
    return  INTERPRET_RUNTIME_ERROR;
}
