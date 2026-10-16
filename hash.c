#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
typedef struct aluno {
  int mat;
  char *nome;
  char *email;
} Aluno;

int funcHash(Aluno*);

Aluno *criarAluno(int, const char *, const char *);
int main(int argc, char *argv[]) {
  Aluno *aluno;
  aluno = criarAluno(53192120, "Kennedy", "kennedy@ufersa.edu.br");
  int res = funcHash(aluno);
  printf("Aluno %s\nHash -> %d\n", aluno->nome, funcHash(aluno));
}

int funcHash(Aluno* aluno){
    return aluno->mat % TAM;
}

Aluno *criarAluno(int m, const char *nome, const char *email) {
  Aluno *novo = malloc(sizeof *novo);
  novo->mat = m;
  novo->nome = strdup(nome);
  novo->email = strdup(email);
  return novo;
}
// Veja se chegou essa comentário
// https://github.com/kennedyufersa/aulaHash