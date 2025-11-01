void calcularMediaAlgoritmos()
{
    int numRelatorio;
    int quantidadeLinhas;
    int *quantidadeAlunos;
    char **nomes;
    char path[50];

    double *tempos;
    double tempo;
    char texto[50], *token;
    int linhaAtual;
    int totalExecucoes = 5;

    FILE *arquivo;

    quantidadeLinhas = contarLinhas("./relatorios/relatorio_01.csv");
    tempos = calloc(quantidadeLinhas, sizeof(double));
    quantidadeAlunos = malloc(quantidadeLinhas * sizeof(int));
    nomes = malloc(quantidadeLinhas * sizeof(char*));

    for (linhaAtual = 0; linhaAtual < quantidadeLinhas; linhaAtual++)
        nomes[linhaAtual] = malloc(10);

    printf("\nCalculando medias...\n");
    for (numRelatorio = 1; numRelatorio <= totalExecucoes; numRelatorio++)
    {
        sprintf(path, "./relatorios/relatorio_0%d.csv", numRelatorio);

        arquivo = fopen(path, "r");

        if (!arquivo)
        {
            printf("Erro ao ler o arquivo: %s\n", path);
        }

        linhaAtual = 0;
        while(fgets(texto, sizeof(texto), arquivo) )
        {
            token = strtok(texto, ",");
            strcpy(nomes[linhaAtual], token);

            token = strtok(NULL, ",");
            quantidadeAlunos[linhaAtual] = atoi(token);

            token = strtok(NULL, ",");
            tempo = atof(token);

            tempos[linhaAtual] += tempo;
            linhaAtual++;
        }

        fclose(arquivo);
    }

    arquivo = fopen("./relatorios/medias.csv", "w");

    for (linhaAtual = 0; linhaAtual < quantidadeLinhas; linhaAtual++)
    {
        tempos[linhaAtual] /= totalExecucoes;
        fprintf(arquivo, "%s, %d, %f\n", nomes[linhaAtual], quantidadeAlunos[linhaAtual], tempos[linhaAtual]);
    }

    for (linhaAtual = 0; linhaAtual < quantidadeLinhas; linhaAtual++)
        free(nomes[linhaAtual]);
    free(nomes);
    free(tempos);
    free(quantidadeAlunos);

    fclose(arquivo);

    printf("Medias calculadas com sucesso. ./relatorios/medias.csv\n\n");
}
