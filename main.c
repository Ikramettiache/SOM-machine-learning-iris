#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {

  srand(time(NULL));

  iris * iris_tab = NULL;
  iris_tab = reading_file("iris_data.txt", iris_tab);

  double * average_vector = calculate_average_vector(iris_tab);
  double * max_vector = calculate_max_vector(average_vector, 0.05);
  double * min_vector = calculate_min_vector(average_vector, 0.02);

  map * neuron_map = init_map(min_vector, max_vector);

  neurons_learning(neuron_map, iris_tab, 3, 0.7, 500);
  neurons_learning(neuron_map, iris_tab, 3, 0.07, 1500);

  labeling(neuron_map, iris_tab);

  show_map(neuron_map);

  return 0;
}