int reproduzir(Lista *lista)
{
  Registro *aux = lista->comeco;
  char opcao;

  if (!aux)
  {
    printf("\n\x1b[31mVoce nao tem musicas na sua playlist\x1b[0m\n");
    return 0;
  }

  printf("\n\x1b[34mProxima (p) - Anterior (a) - Sair (s)\x1b[0m\n");

  do
  {
    printf("\nTocando agora: \x1b[34m%s \x1b[33m%s\n\x1b[0m", aux->dado.nome, aux->dado.artista);

    scanf(" %c", &opcao);
    getchar();

    switch (opcao)
    {
    case 'p':
      aux = aux->proximo;
      break;
    case 'a':
      aux = aux->anterior;
      break;
    case 's':
      printf("\n\x1b[31mEncerrando tocar musica\x1b[0m\n");
      break;
    default:
      printf("\n\x1b[31mOpcao invalida\x1b[0m\n");
      break;
    }
  } while (opcao != 's');

  return 1;
}
