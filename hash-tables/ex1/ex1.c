#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *returnAnswer = malloc(sizeof(Answer));
  // YOUR CODE HERE
if(length < 2) {
  return NULL;
}

for (int i = 0; i < length; i++) {
  hash_table_insert(ht, weights[i], i);
}

for(int a = 0; a < length; a++) {
  int match = hash_table_retrieve(ht, limit - weights[a]);
  if(match != -1) {
    if(a > match) {
      returnAnswer->index_1 = a;
      returnAnswer->index_2 = match;
    } else{
      returnAnswer->index_1 = match;
      returnAnswer->index_2 = a;
    }
    destroy_hash_table(ht);
    return returnAnswer;
  }
}
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};

  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);

  if (answer_4->index_1 != 6)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  if (answer_4->index_2 != 2)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");

  return 0;
}
#endif