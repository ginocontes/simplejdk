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

int main(int argc, const char * argv[]) {
    
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk);
    freeChunk(&chunk);
    
}
