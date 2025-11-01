void pegarDadosAlunos(char path[], Aluno **alunos)
{
  FILE *arquivo = fopen(path, "r");
  char texto[100], copyTexto[100];
  char *token;
  int alunoAtual;
  int notaAtual;

  if (!arquivo)
    printf("Erro ao ler o arquivo");

  alunoAtual = 0;
  while (fgets(texto, sizeof(texto), arquivo))
  {
    strcpy(copyTexto, texto);
    token = strtok(copyTexto, ",");
    strcpy(alunos[alunoAtual]->nome, token);
    alunos[alunoAtual]->num_notas = 0;

    token = strtok(NULL, ",");

    while (token)
    {
      alunos[alunoAtual]->num_notas++;
      token = strtok(NULL, ",");
    }

    alunos[alunoAtual]->notas = malloc(alunos[alunoAtual]->num_notas * sizeof(float));

    if (!alunos[alunoAtual]->notas)
      printf("Erro ao alocar memoria para notas");

    token = strtok(texto, ",");
    token = strtok(NULL, ",");

    notaAtual = 0;
    while (token)
    {
      token[strcspn(token, "\n")] = 0;
      alunos[alunoAtual]->notas[notaAtual] = atof(token);
      token = strtok(NULL, ",");
      notaAtual++;
    }

    alunoAtual++;
  }

  fclose(arquivo);
}
