int contarLinhas(char path[])
{
  FILE *arquivo = fopen(path, "r");
  char texto[100];
  int quantidadeLinhas = 0;

  if (!arquivo)
  {
    printf("Erro ao ler o arquivo");
    return -1;
  }

  while (fgets(texto, sizeof(texto), arquivo))
    quantidadeLinhas++;

  fclose(arquivo);
  return quantidadeLinhas;
}
