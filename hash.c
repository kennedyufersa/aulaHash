#include <stdio.h>
#include <stdlib.h>
typedef struct aluno {
    int mat;
    char *nome;
    char *email;
} Aluno;
Aluno* criarAluno(int, const char*, const char*);
int main(int argc, char *argv[]) {
    Aluno *aluno;
    aluno = criarAluno(100, "Kennedy", "kennedy@ufersa.edu.br");
}
Aluno* criarAluno(int m, const char* nome, const char*email){
    Aluno* novo = malloc(sizeof *novo);
    novo->mat = m;
    novo->nome = nome;
    novo->email = email;
    return novo;
}
// https://github.com/kennedyufersa/aulaHash