Aluno **copiarAlunos(Aluno **original, int quantidadeAlunos)
{
    int i, j;
    Aluno **copia = malloc(quantidadeAlunos * sizeof(Aluno *));
    if (!copia)
        return NULL;

    for (i = 0; i < quantidadeAlunos; i++)
    {
        copia[i] = malloc(sizeof(Aluno));
        if (!copia[i])
            return NULL;

        strcpy(copia[i]->nome, original[i]->nome);
        copia[i]->media = original[i]->media;
        copia[i]->num_notas = original[i]->num_notas;

        copia[i]->notas = malloc(original[i]->num_notas * sizeof(float));
        if (!copia[i]->notas)
            return NULL;

        for (j = 0; j < original[i]->num_notas; j++)
            copia[i]->notas[j] = original[i]->notas[j];
    }

    return copia;
}
