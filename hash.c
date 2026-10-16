#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
typedef struct aluno {
  int mat;
  char *nome;
  char *email;
} Aluno;

typedef struct No {
  struct No *prox;
  Aluno aluno;
} No;

typedef struct tabela {
  No *baldes[TAM];
  int quantidade;
} tabela;

int funcHash(Aluno *);
tabela *criarTabela();
Aluno *criarAluno(int, const char *, const char *);
void show(tabela *);

int inserirAluno(tabela *, Aluno *novo);
int main(int argc, char *argv[]) {
  tabela *hashTable = criarTabela();
  Aluno *aluno1, *aluno2;
  aluno1 = criarAluno(53192120, "Kennedy", "kennedy@ufersa.edu.br");
  aluno2 = criarAluno(53792120, "Lopes", "lopes@ufersa.edu.br");
  inserirAluno(hashTable, aluno1);
  inserirAluno(hashTable, aluno2);
  show(hashTable);
}
void show(tabela *hash) {
  Aluno *aux;
  for (size_t i = 0; i < TAM; i++) {
    aux = &(hash->baldes[i]->aluno);
    if (hash->baldes[i] != NULL) {
      printf("Balde[%lu]: ", i);
      No* aux2 = &(hash->baldes[i]);
      while (aux2 != NULL) {
        printf("Matrícula: %d\n", aux2->aluno->mat);
        printf("Nome: %s\n", aux2->aluno->nome);
        printf("Email: %s\n", aux2->aluno->email);
        
      }
    }
  }
}
int inserirAluno(tabela *hashTable, Aluno *novo) {
  int indice = funcHash(novo);
  // hashTable->baldes[indice]
  No *no = malloc(sizeof *no);
  no->aluno = *novo;
  no->prox = hashTable->baldes[indice];
  hashTable->baldes[indice] = no;
  return 0;
}

tabela *criarTabela() {
  tabela *res = malloc(sizeof *res);
  for (size_t i = 0; i < TAM; i++) {
    res->baldes[i] = NULL;
  }
  res->quantidade = 0;
  return res;
}

int funcHash(Aluno *aluno) { return aluno->mat % TAM; }
Aluno *criarAluno(int m, const char *nome, const char *email) {
  Aluno *novo = malloc(sizeof *novo);
  novo->mat = m;
  novo->nome = strdup(nome);
  novo->email = strdup(email);
  return novo;
}
// Veja se chegou essa comentário
// https://github.com/kennedyufersa/aulaHash