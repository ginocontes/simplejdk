//
//  chunk.h
//  vmlox
//
//  Created by Gino Contestabile on 14/04/22.
//

#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"



typedef enum {
    OP_RETURN,
    OP_CONSTANT,
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    ValueArray constants; 
} Chunk;

void initChunk(Chunk* chunk);

void writeChunk(Chunk* chunk, uint8_t byte);

uint8_t addConstant(Chunk* chunk, Value value); 

void freeChunk(Chunk* chunk); 

#endif /* chunk_h */
