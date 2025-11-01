void gerarRelatorios()
{
    int numRelatorio;
    char path[50];
    char caminho[50];
    int quantidadeAlunos;
    int totalExecucoes = 5;
    int i, entradaAtual;
    double tempo;

    Aluno **alunos, **alunosCopia;
    clock_t inicio, fim;

    int quantidadeEntradas = 14;
    char * entradas[] =
    {
        "./entradas/alunos_1024.csv",
        "./entradas/alunos_128.csv",
        "./entradas/alunos_16.csv",
        "./entradas/alunos_16384.csv",
        "./entradas/alunos_2048.csv",
        "./entradas/alunos_256.csv",
        "./entradas/alunos_32.csv",
        "./entradas/alunos_32768.csv",
        "./entradas/alunos_4.csv",
        "./entradas/alunos_4096.csv",
        "./entradas/alunos_512.csv",
        "./entradas/alunos_64.csv",
        "./entradas/alunos_8.csv",
        "./entradas/alunos_8192.csv",
    };

    for (numRelatorio = 1; numRelatorio <= totalExecucoes; numRelatorio++)
    {
        sprintf(path, "./relatorios/relatorio_0%d.csv", numRelatorio);

        FILE *arquivo = fopen(path, "w");
        fclose(arquivo);

        for (entradaAtual = 0; entradaAtual < quantidadeEntradas; entradaAtual++)
        {
            strcpy(caminho, entradas[entradaAtual]);

            quantidadeAlunos = contarLinhas(caminho);

            printf("\nQuantidade de alunos: %d\n", quantidadeAlunos);

            alunos = malloc(quantidadeAlunos * sizeof(Aluno *));
            for (i = 0; i < quantidadeAlunos; i++)
                alunos[i] = malloc(sizeof(Aluno));

            if (!alunos)
                printf("Erro ao alocar memoria para alunos");

            pegarDadosAlunos(caminho, alunos);
            calcularMedia(alunos, quantidadeAlunos);

            tempo = bubbleSortRelatorio(alunos, quantidadeAlunos);
            escreverTempo("Bubble", tempo, path, quantidadeAlunos);

            tempo = mergeSortRelatorio(alunos, quantidadeAlunos);
            escreverTempo("Merge", tempo, path, quantidadeAlunos);

            tempo = quickSortRelatorio(alunos, quantidadeAlunos);
            escreverTempo("Quick", tempo, path, quantidadeAlunos);
        }
    }
}
