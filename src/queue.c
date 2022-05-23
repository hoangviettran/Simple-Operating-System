#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size == MAX_QUEUE_SIZE) return;
	uint32_t idx = q->size;
	while(idx > 0 && ((q->proc)[idx - 1])->priority <= proc->priority){
		(q->proc)[idx] = (q->proc)[idx - 1];
		idx --;
	}
	q->proc[idx] = proc;
	q->size ++;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(q->size == 0) return NULL;
	q->size--;
	struct pcb_t * curr_proc = (q->proc)[q->size];
	(q->proc)[q->size] = NULL;
	return curr_proc;
}

