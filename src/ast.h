#ifndef CODUMP_AST_
#define CODUMP_AST_
enum {
      ASSIGN
} typedef OPERATOR;

enum {
      INT,
      FLOAT,
      STRING,
      CHAR
} typedef TYPE;

struct {
  TYPE type;
  char name[50];
} typedef OBJECT;

struct {
  OBJECT* elements;
  int size;
} typedef ARRAY;

enum {
      DEFINITON,
      CONSTRUCTION,
      ASSIGNMENT
} typedef EXPRESSION_TYPE;
  
struct {
  OBJECT destination;
  ARRAY source;
  OPERATOR operation;
  EXPRESSION_TYPE type;
} typedef EXPRESSION;

struct {
  ARRAY arguments;
  EXPRESSION* expressions;
  int expression_count;
  TYPE return_type;
} typedef FUNCTION;
#endif
