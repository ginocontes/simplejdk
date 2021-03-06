//
//  chunk.c
//  vmlox
//
//  Created by Gino Contestabile on 14/04/22.
//

#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    initValueArray(&chunk->constants);
}


void writeChunk(Chunk* chunk, uint8_t byte) {
    if(chunk->capacity < chunk->count + 1)  {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t,
                                 chunk->code,
                                 oldCapacity,
                                 chunk->capacity
                                 );
    }
    chunk->code[chunk->count] = byte;
    chunk->count++;
}


uint8_t addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1; // return the index where the constant was allocated
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t,chunk->code, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

