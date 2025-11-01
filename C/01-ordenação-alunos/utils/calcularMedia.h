void calcularMedia(Aluno *alunos[], int quantidadeAlunos)
{
  int i, j;
  float mediaAluno;
  float mediaGlobal = 0;
  int totalNotas = quantidadeAlunos * alunos[0]->num_notas;

  for (i = 0; i < quantidadeAlunos; i++)
  {
    mediaAluno = 0;

    for (j = 0; j < alunos[i]->num_notas; j++)
    {
      mediaAluno += alunos[i]->notas[j];
      mediaGlobal += alunos[i]->notas[j];
    }

    mediaAluno /= alunos[i]->num_notas;
    alunos[i]->media = mediaAluno;
  }

  mediaGlobal /= totalNotas;
}
