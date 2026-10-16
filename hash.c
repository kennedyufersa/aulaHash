#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
  int mat;
  char *nome;
  char *email;
} Aluno;

int main(int argc, char *argv[]) {
  Aluno *aluno = malloc(sizeof *aluno);
  aluno->mat = 100;
  aluno->nome = "Kennedy";
  aluno->email = "kennedy@ufersa.edu.br";
}