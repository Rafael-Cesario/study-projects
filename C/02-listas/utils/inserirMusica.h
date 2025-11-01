int inserirMusica(Lista *lista)
{
  Musica musica;
  int opcao;

  do
  {
    system("cls");

    printf("\nNome: ");
    fgets(musica.nome, sizeof(musica.nome), stdin);
    musica.nome[strcspn(musica.nome, "\n")] = '\0';

    printf("Artista: ");
    fgets(musica.artista, sizeof(musica.artista), stdin);
    musica.artista[strcspn(musica.artista, "\n")] = '\0';

    printf("\nOs valores digitados estao corretos?\n");
    printf("\x1b[33m%s, %s\x1b[0m\n\n", musica.nome, musica.artista);
    printf("0 Digitar novamente - 1 Confirmar\n");
    scanf("%d", &opcao);
    getchar();
  } while (opcao != 1);

  musica.id = lista->proximoId;

  inserirMusicaLista(lista, musica);

  printf("\n\x1b[32mSua nova musica foi adicionada com sucesso\x1b[0m\n\n");

  return 1;
}
