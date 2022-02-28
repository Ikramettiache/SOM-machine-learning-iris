#include "utils.h"

int number_of_line_in_file(char* filename){
    FILE*   fp;
    
    fp = fopen(filename,"r");
    if (fp == NULL)
        exit(1);

    int lines=1;
    while(!feof(fp)){
        if(fgetc(fp) == '\n'){
            lines++;
        }
    }

    return lines;
}

iris* allocate_memory(int size){

    iris* tmp;
	tmp = malloc(size * sizeof(iris));
	for(int i = 0; i < size; i++) {
		tmp[i].vector = malloc(NUMBEROFDATA * sizeof(double));
	}

    tmp->iris_name = (char*)malloc(128 * sizeof(char));
    

	return tmp;
}

double random_value(double min, double max){
	return (double)((rand() / (double)(RAND_MAX + 1.0)) * (max - min) + min); 
}

int random_int_value(int min, int max){
	return (int)((rand() / (double)(RAND_MAX + 1.0)) * (max - min) + min); 
}

double euclidean_distance(double* v1, double* v2){
	double result = 0;
	for (int i = 0; i < NUMBEROFDATA; i++){
		result += pow((v2[i] - v1[i]),2) ;
	}
	return sqrt(result);
}