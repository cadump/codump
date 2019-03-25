#include <stdio.h>
#include <string.h>

#include "ast.h"

FUNCTION MAIN;

int main(int argc, char* argv[]) {
  FILE* input;
  FILE* output;

  // Parse command line arguments
  if (argc > 0) {
    for(int i = 0; i < argc; i++) {
      if(strcmp(argv[i],  "-r")) {
	input = stdin;
      } else if(strcmp(argv[i], "-i")) {
	i++;
	input = fopen(argv[i], "r");
	output = fopen("main.c", "w+");
      } else if(strcmp(argv[i], "-o")) {
	  i++;
	  output = fopen(argv[i], "w+");
      }
    }
  } else return 1;

  int c;
  int previous = '\0';
  char expr[0];

  while(c != EOF) {
    while((c = fgetc(input)) != EOF && c != '\n' && previous != '(') {      
      strcat(expr, (const char*)c);
    }
  }
  // Spawn new codump instance for every function block
  // because everything in codump behaves like a function
  /* int c; */
  /* int level = 0; */
  /* while((c = fgetc(input)) != EOF) { */
  /*   if (c == '(') { */
  /*     level++; */
  /*     FILE* child = popen("codump -r", "w+"); */
  /*     while((c = fgetc(input)) != EOF || (level != 0 && c != ')' )) { */
  /* 	if(c == ')') level--; */
  /* 	else if(c == '(') level++; */
  /* 	putc(c, child); */
  /*     } */
  /*   } */
  /* } */
}
