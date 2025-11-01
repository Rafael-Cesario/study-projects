double bubbleSortRelatorio(Aluno **alunos, int quantidadeAlunos)
{
    Aluno **alunosCopia;
    clock_t inicio, fim;
    double tempo;
    int i;

    printf("\nTestando BubbleSort\n");
    alunosCopia = copiarAlunos(alunos, quantidadeAlunos);

    if (!alunosCopia)
        printf("Erro ao copiar alunos\n");

    inicio = clock();
    bubbleSort(alunosCopia, quantidadeAlunos);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    imprimirResultados(alunosCopia, quantidadeAlunos);

    for (i = 0; i < quantidadeAlunos; i++)
    {
        free(alunosCopia[i]->notas);
        free(alunosCopia[i]);
    }

    free(alunosCopia);

    return tempo;
}
