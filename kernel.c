#include "kernel.h"

#define POOL_SIZE 10

process* pool[POOL_SIZE]; 
int start, end;


char kernelAddProc(process* newProc) {
    if(((end + 1 ) % POOL_SIZE) != start) {
        pool[end] = newProc;
        end = (end + 1) % POOL_SIZE;

        return SUCCESS;
    }

    return FAIL;
}

char kernelInit(void) {
    start = 0, end = 0;
            

    return SUCCESS;
}


// verifica se tem processo no buffer circular
void kernelLoop(void) {

    // algoritmo do kernelLoop
	while(1) {
        if(start != end) {
            if(pool[start]->func() == REPEAT) {
                kernelAddProc(  pool[start]);
            }
            start = (start + 1) % POOL_SIZE;
        }
    }
}