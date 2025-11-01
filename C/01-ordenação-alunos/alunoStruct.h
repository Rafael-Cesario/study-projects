// Defina a struct Aluno
typedef struct
{
  char nome[50];
  int num_notas; // Quantidade de notas do aluno
  float *notas;  // Vetor de notas alocado dinamicamente
  float media;
} Aluno;
