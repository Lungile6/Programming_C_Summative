#ifndef DISPATCHER_H
#define DISPATCHER_H

typedef void (*FunctionHandler)(const char*);

// Executes selected function via pointer
void dispatch(int choice, const char* filename);

#endif
