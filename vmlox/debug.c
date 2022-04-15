//
//  debug.c
//  vmlox
//
//  Created by Gino Contestabile on 15/04/22.
//

#include "debug.h"


void disassembleChunk(Chunk* chunk) {
    for(int i = 0; i< chunk->count; i++) {
        printf("%d\n", chunk->code[i]);
    }
}
