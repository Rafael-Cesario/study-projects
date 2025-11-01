void quickSort(Aluno **alunos, int quantidadeAlunos);
void q_sort(Aluno **alunos, int esq, int dir);

void quickSort(Aluno **alunos, int quantidadeAlunos)
{
    q_sort(alunos, 0, quantidadeAlunos - 1);
}

void q_sort(Aluno **alunos, int esq, int dir)
{
    if (esq >= dir)
        return;

    int i, j;
    Aluno *alunoTemp, *pivot;

    pivot = alunos[dir];
    i = esq - 1;

    for (j = esq; j < dir; j++)
        if (alunos[j]->media > pivot->media)
        {
            i++;
            alunoTemp = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = alunoTemp;
            Sleep(0.4);
        }

    alunoTemp = alunos[i + 1];
    alunos[i + 1] = pivot;
    alunos[dir] = alunoTemp;

    q_sort(alunos, esq, i);
    q_sort(alunos, i + 2, dir);
}
