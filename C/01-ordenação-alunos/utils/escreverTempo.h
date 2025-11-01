void escreverTempo(char nome[], double tempo, char path[], int quantidadeAlunos)
{
    FILE *arquivo = fopen(path, "a");
    fprintf(arquivo, "%s, %d, %f\n", nome, quantidadeAlunos, tempo);
    fclose(arquivo);
}
