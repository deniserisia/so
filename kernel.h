#ifndef KERNEL_H_
#define KERNEL_H_

// c�digos de retorno
#define SUCCESS	0
#define FAIL	1
#define REPEAT	2

// declara��o de ponteiro de fun��o
typedef char (*ptrFunc)(void);

//defini��o da estrutura de um processo
typedef struct {
	ptrFunc func;
}process;

//prot�tipos das fun��es do kernel
char kernelInit(void);
char kernelAddProc(process* newProc);
void kernelLoop(void);// declara��o de ponteiro de fun��o

#endif