//
//  debug.h
//  vmlox
//
//  Created by Gino Contestabile on 15/04/22.
//

#ifndef clox_debug_h
#define clox_debug_h


#include "chunk.h"

void disassembleChunk(Chunk* chunk, char* name);
int disassembleInstruction(Chunk* chunk, int offset);
int simpleInstruction(char* name, int offset);
int constantInstruction(char* name, Chunk* chunk, int offset);
#endif /* debug_h */
