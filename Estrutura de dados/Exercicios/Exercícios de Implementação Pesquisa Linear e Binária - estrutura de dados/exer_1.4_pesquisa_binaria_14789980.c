/*

codico Binario para encontrar 14789980

*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 15000000

int binary_search ( int *item , int key , int count );
struct timespec timer_start();
long timer_end(struct timespec start_time);

int main() {
	int i, *vetor;
	struct timespec initialTime;
	long time_elapsed_nanos;
	
	vetor = malloc (MAX * sizeof (int)); 
	
	for (i=0;i<MAX;i++){
		vetor [i] = i;
	}
	
	initialTime = timer_start(); 
	
	binary_search (vetor, 14789980, MAX);

	time_elapsed_nanos = timer_end(initialTime);
	
	printf("Para encontrar 14789980, levou %ld nanosegundos\n", time_elapsed_nanos);
	return 0;
}

int binary_search ( int *item , int key , int count ){
	int low ,high ,mid;
	low =0; high = count -1;
	while (low <= high ){
		mid =( low+ high )/2;
		if (key < item [mid ]){
			high =mid -1;
		} else if (key > item [mid ]){
			low =mid +1;
		} else {
			printf("Valor foi encontrado!!\n");
			return mid ;
		}
	}
return -1;
}

struct timespec timer_start(){
    struct timespec start_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
    return start_time;
}

long timer_end(struct timespec start_time){
    struct timespec end_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
    long diffInNanos = end_time.tv_nsec - start_time.tv_nsec;
    return diffInNanos;
}
