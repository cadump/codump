#ifndef CODUMP_AST_
#define CODUMP_AST_
enum {
      ASSIGN,
      APPEND,
      ADD,
      SUBSTRACT,
      MULTIPLY,
      DIVIDE,
      POWER
} typedef OPERATOR;

enum {
      INT,
      FLOAT,
      STRING,
      CHAR,
      COMPLEX
} typedef TYPE;

struct {
  TYPE type;
  ARRAY complex_children;
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
