void merge(Aluno **vetor, int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Aluno **Esq = malloc(n1 * sizeof(Aluno *));
    Aluno **Dir = malloc(n2 * sizeof(Aluno *));

    for (i = 0; i < n1; i++)
        Esq[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        Dir[j] = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2)
    {
        if (Esq[i]->media >= Dir[j]->media)
        {
            vetor[k++] = Esq[i++];
            Sleep(0.4);
        }
        else
        {
            vetor[k++] = Dir[j++];
            Sleep(0.4);
        }
    }

    while (i < n1)
        vetor[k++] = Esq[i++];

    while (j < n2)
        vetor[k++] = Dir[j++];

    free(Esq);
    free(Dir);
}

void mergeSort(Aluno **vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
