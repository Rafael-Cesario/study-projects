void bubbleSort(Aluno **alunos, int quantidadeAlunos)
{
    int i, j;
    Aluno *alunoTemp;

    for (i = 0; i < quantidadeAlunos - 1; i++)
        for (j = 0; j < quantidadeAlunos - i - 1; j++)
            if (alunos[j]->media < alunos[j + 1]->media)
            {
                alunoTemp = alunos[j + 1];
                alunos[j + 1] = alunos[j];
                alunos[j] = alunoTemp;
                Sleep(0.4);
            }
}
