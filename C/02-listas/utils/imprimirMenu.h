void imprimirMenu(int *opcao)
{
  system("cls");

  printf("\n\x1b[32m==== Espotefy ====\x1b[0m\n\n");
  printf("1 - Adicionar musica\n");
  printf("2 - Remover musica\n");
  printf("3 - Exibir playlist\n");
  printf("4 - Tocar playlist\n");
  printf("0 - Sair\n\n");

  scanf("%d", opcao);
  getchar();

  printf("\n");
  system("cls");
}
