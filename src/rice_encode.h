#ifndef RICE_ENCODE
#define RICE_ENCODE

static int* signed_to_unsigned(int *signed_array, unsigned long int L);

static void put_bit(FILE *fd, char  bit);

static int get_k(int *error, int length);

void rice_code(FILE *fd, int x, int k);

void compress(FILE *fd, int *signed_array, unsigned long int L);

#endif
