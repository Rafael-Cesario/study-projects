void imprimirResultados(Aluno *alunos[], int quantidadeAlunos)
{
  int i, j;

  printf("\n=== Imprimindo Resultados ===\n\n");

  printf("%-25s %6s %6s %6s %8s\n", "Nome", "N1", "N2", "N3", "Media");

    for (i = 0; i < quantidadeAlunos; i++)
    {
        printf("%-25s", alunos[i]->nome);

        for (j = 0; j < alunos[i]->num_notas; j++)
            printf(" %6.2f", alunos[i]->notas[j]);

        printf(" %8.2f\n", alunos[i]->media);
    }

  printf("\n\n");
}
