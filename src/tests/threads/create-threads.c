#include <threads/thread.h>
#include <stddef.h>
#include <stdio.h>
#include "devices/timer.h"
#include "threads/interrupt.h"

static void thread_test (void *);

void
test_create_threads(void)
{
	int i;
	int thread_cnt = 5;
	int priorities[] = {32, 38, 33, 34, 35};

	msg ("Thread \"%s\" begins creating %d threads", thread_current()->name, thread_cnt);
	for (i=0; i<thread_cnt; i++){
		char name[16];
		snprintf (name, sizeof name, "my_thread %d", i);
		printf("Creating thread: %s\n", name);
		thread_create (name, priorities[i], thread_test, NULL);
	}
	msg ("Thread \"%s\" finished creating %d threads", thread_current()->name, thread_cnt);

	/* Wait for the previously created threads to finish their execution */
	timer_sleep (1000 + 100);

	msg ("Thread \"%s\" exits its function", thread_current()->name);
}

static void print_thread_info(struct thread* t, void* aux)
{
	printf("Thread \"%s\" info: [name=%s, tid=%d, status=%s priority=%d]\n", t->name, t->name, t->tid, thread_status(t->status), t->priority);
}

static void thread_test (void *argv UNUSED){
	msg ("Thread \"%s\" is running.", thread_current()->name);
	thread_yield();
	print_thread_info(thread_current(), NULL);
	msg ("Thread \"%s\" is ending.", thread_current()->name);
}
