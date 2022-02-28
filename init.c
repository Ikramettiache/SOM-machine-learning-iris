#include "utils.h"

iris * reading_file(char * filename, iris * tab) {

  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  size_t read;
  size_t eof = -1;
  fp = fopen(filename, "r");
  if (fp == NULL)
    exit(1);

  int size = number_of_line_in_file(filename);
  tab = allocate_memory(size);

  int i = 0;
  while ((read = getline(&line, &len, fp)) != eof) {
    parsing_and_store_data(tab, line, i);
    ++i;
  }

  normalize_vector(tab);
  fclose(fp);

  return tab;
}

void parsing_and_store_data(iris * tab, char * data, int number) {
  const char * separator = ",";
  char * strToken = strtok(data, separator);
  char * endPtr;
  for (int i = 0; i < NUMBEROFDATA; i++) {
    double value = strtod(strToken, &endPtr);
    tab[number].vector[i] = value;
    strToken = strtok(NULL, separator);
  }
  tab[number].index = number;
  tab[number].iris_name = strdup(strToken);

}

double * calculate_average_vector(iris * tab) {
  double * average_vector = malloc(NUMBEROFDATA * sizeof(double));
  for (int j = 0; j < NUMBEROFDATA; j++) {
    double res = 0.0;
    for (int i = 0; i < 150; i++) {
      res += tab[i].vector[j];
    }
    average_vector[j] = res / 150.0;
  }

  return average_vector;
}

double * calculate_max_vector(double * vector, double value) {
  double * new_vector = malloc(NUMBEROFDATA * sizeof(double));
  for (int i = 0; i < NUMBEROFDATA; i++) {
    new_vector[i] = vector[i] + value;
  }
  return new_vector;
}

double * calculate_min_vector(double * vector, double value) {
  double * new_vector = malloc(NUMBEROFDATA * sizeof(double));
  for (int i = 0; i < NUMBEROFDATA; i++) {
    new_vector[i] = vector[i] - value;
  }
  return new_vector;
}

void normalize_vector(iris * node) {
  for (int k = 0; k < 150; k++) {
    double norm_vector = 0;

    for (int i = 0; i < NUMBEROFDATA; i++) {
      norm_vector += pow(node[k].vector[i], 2);
    }

    norm_vector = sqrt(norm_vector);
    node[k].norm = norm_vector;
    for (int j = 0; j < NUMBEROFDATA; j++) {
      node[k].vector[j] = node[k].vector[j] / norm_vector;
    }
  }
}

void print_node(iris * node, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < NUMBEROFDATA; j++) {
      printf("%lf,", node[i].vector[j]);
    }
    printf("%s", node[i].iris_name);
  }
  printf("\n");
}

void print_vector(double * vector) {
  printf("vector values -> ");
  for (int i = 0; i < NUMBEROFDATA; i++) {
    printf("%lf ", vector[i]);
  }
  printf("\n");
}