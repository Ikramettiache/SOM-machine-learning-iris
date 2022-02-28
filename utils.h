#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define NUMBEROFDATA 4
#define NUMBEROFLINE 150
#define SIZEOFNAMES 100
#define NEIGHBORHOOD 3
#define ITERATION 2000
#define ALPHA 0.7
#define LINE 10
#define COLUMN 6

typedef struct iris iris;
typedef struct neurons neurons;
typedef struct map map;

struct iris {
  int index;
  double * vector;
  char * iris_name;
  double norm;
};

struct neurons {
  char * label;
  double * data;
};

struct map {
  int line;
  int column;
  double alpha;
  int neighborhood_radius;
  neurons ** table;
};

iris * allocate_memory(int size);
iris * reading_file(char * filename, iris * tab);
map * init_map(double * min_vector, double * max_vector);
void parsing_and_store_data(iris * head, char * data, int number);
void store_to_struct(double * values, char * name);
void print_node(iris * node, int size);
void normalize_vector(iris * node);
void print_vector(double * vector);
void neurons_learning(map * neurons_map, iris * iris_tab, int neighbor, double alpha, int iteration);
void neurons_learning2(map * neurons_map, iris * iris_tab, int neighbor, double alpha, int iteration);
void apprentissage(map * neurons_map, iris * iris_tab, int voisin, int alpha, int iteration);
void labeling(map * neurons_map, iris * iris_tab);
void show_map(map * neurons_map);
void print_map(map * print_map);
int number_of_line_in_file(char * filename);
int random_int_value(int min, int max);
void grid_limitation(int * coord, int i, int j, int neighbor);
double random_value(double min, double max);
double euclidean_distance(double * v1, double * v2);
double * calculate_average_vector(iris * tab);
double * calculate_max_vector(double * vector, double value);
double * calculate_min_vector(double * vector, double value);