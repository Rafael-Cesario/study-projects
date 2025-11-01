int removerMusica(Lista *lista)
{
  int id;

  if (!lista->comeco)
  {
    printf("\n\x1b[31mVoce ainda nao adicionou musicas a sua playlist\x1b[0m\n");
    return 0;
  }

  printf("Id: ");
  scanf("%d", &id);
  getchar();

  removerMusicaLista(lista, id);

  printf("\n\x1b[32mSua musica foi removida com sucesso;\x1b[0m\n");

  return 1;
}
