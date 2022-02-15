#include <stdio.h>
#include <stdlib.h>
int main(){
	while(1==1){
		int *ptr;
		ptr = calloc(1000, sizeof(int));
		int i;
		for (i = 1; i < 200; i++){
		*ptr = 10000;
		}
	}
}
