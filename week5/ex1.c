#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadTask(void *vargp) {
	int* thisId = (int*) vargp;
	printf("My id is %u and I love it\n", *thisId);
	int ret = 100;
	pthread_exit(&ret);
	}

int main() {
	int n;
	pthread_t id;	
	scanf("%d", &n);
	pthread_t ids[n];
	//sequential
	for (int i = 0; i < n; i++) {
		printf("Thread number %d is created\n", i);
		pthread_create(&id, NULL, threadTask, (void*) &id);
		pthread_join(id, NULL);	
	}

	//parallel
	for (int i = 0; i < n; i++){
		printf("Thread number %d is created\n", i);
		pthread_create(&ids[i], NULL, threadTask, (void*) &ids[i]);
	}
	for (int i = 0; i < n; i ++){
		pthread_join(ids[i], NULL);
	}
	return 0;
}
