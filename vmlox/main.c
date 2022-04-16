//
//  main.c
//  vmlox
//
//  Created by Gino Contestabile on 14/04/22.
//

#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

#define DEBUG_TRACE_EXECUTION
#undef DEBUG_TRACE_EXECUTION

int main(int argc, const char * argv[]) {
    
    
    Chunk chunk;
    initVM();
    initChunk(&chunk);
    printf("chunk count: %d, chunk cap: %d\n", chunk.count, chunk.capacity);
    printf("chunk count: %d, chunk cap: %d\n", chunk.count, chunk.capacity);
    uint8_t constant = addConstant(&chunk, 13);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);
    
    uint8_t secondconst = addConstant(&chunk, 10);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, secondconst);
    writeChunk(&chunk ,OP_NEGATE);
    writeChunk(&chunk, OP_RETURN);
    printf("chunk count: %d, chunk cap: %d\n", chunk.count, chunk.capacity);
    printf("chunk code %d at index %d\n", chunk.code[2], 1);
    
    //disassembleChunk(&chunk, "First Chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    
}

//3 months to finish compilers book and theory
//project -- write a self-hosting compiler and interpreter and assembler. Write all kinds of low-level stuff.
//project -- 
