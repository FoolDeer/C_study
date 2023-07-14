// #include <stdio.h>
// #include <stdlib.h>

// #define INIT_SIZE 5

// int main(void) { 
//   char* a;
//   int i, c, size=INIT_SIZE;
//     a = (char *) malloc(size * sizeof(char));
//   for (i=0; ((c=getchar()) != '#'); i++) {
//     if (i >= size) {
//     size *= 2;
//     a = (char *) realloc(a, size * sizeof(char));
//     }
//   a[i] = c;
//   }
//   while (i > 0)
//     putchar(a[--i]);
//   free(a);
//   return 0;
// }

// #define INIT_SIZE 15

// int main(void) { 
//   char* a;
//   int i, c, size=INIT_SIZE;
//   a = (char *) malloc(size * sizeof(char));
//   for (i=0; ((c=getchar()) != '#'); i++) {
//     if (i >= size) {
//     size *= 4;
//     a = (char *) realloc(a, size * sizeof(char));
//     }
//     a[i] = c;
//   }
//   while (i > 0)
//     putchar(a[--i]);
//   free(a);
//   return 0;
// }