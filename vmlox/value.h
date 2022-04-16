//
//  value.h
//  vmlox
//
//  Created by Gino Contestabile on 15/04/22.
//

#ifndef clox_value_h
#define clox_value_h

#include <stdio.h>

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);


void printValue(Value value);
#endif /* value_h */
