double quickSortRelatorio(Aluno **alunos, int quantidadeAlunos)
{
    Aluno **alunosCopia;
    clock_t inicio, fim;
    double tempo;
    int i;

    printf("\nTestando QuickSort\n");
    alunosCopia = copiarAlunos(alunos, quantidadeAlunos);
    if (!alunosCopia)
        printf("Erro ao copiar alunos\n");

    inicio = clock();
    quickSort(alunosCopia, quantidadeAlunos);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    imprimirResultados(alunosCopia, quantidadeAlunos);

    for (i = 0; i < quantidadeAlunos; i++) {
        free(alunosCopia[i]->notas);
        free(alunosCopia[i]);
    }

    free(alunosCopia);

    for (i = 0; i < quantidadeAlunos; i++)
    {
        free(alunos[i]->notas);
        free(alunos[i]);
    }

    free(alunos);

    return tempo;
}
