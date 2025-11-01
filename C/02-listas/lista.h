typedef struct
{
  int id;
  char nome[100];
  char artista[100];
} Musica;

typedef struct Registro
{
  Musica dado;
  struct Registro *proximo;
  struct Registro *anterior;
} Registro;

typedef struct
{
  Registro *comeco;
  Registro *final;
  int tamanho;
  int proximoId;
} Lista;

int criarLista(Lista *lista);
int inserirMusicaLista(Lista *lista, Musica musica);
int removerMusicaLista(Lista *lista, int id);
int exibirPlaylist(Lista *lista);

int criarLista(Lista *lista)
{
  lista->comeco = NULL;
  lista->final = NULL;

  lista->tamanho = 0;
  lista->proximoId = 1;

  return 1;
}

int inserirMusicaLista(Lista *lista, Musica musica)
{
  Registro *novo = (Registro *)malloc(sizeof(Registro));

  if (!novo)
    return 0;

  novo->dado = musica;
  novo->proximo = NULL;
  novo->anterior = NULL;

  lista->tamanho++;
  lista->proximoId++;

  if (lista->comeco == NULL)
  {
    lista->comeco = novo;
    lista->final = novo;

    novo->proximo = lista->comeco;
    novo->anterior = lista->final;

    return 1;
  }

  lista->final->proximo = novo;
  novo->anterior = lista->final;
  novo->proximo = lista->comeco;
  lista->final = novo;
  lista->comeco->anterior = lista->final;

  return 1;
};

int removerMusicaLista(Lista *lista, int id)
{
  Registro *aux = lista->comeco;
  int encontrou = 0;

  do
  {
    if (aux->dado.id == id)
    {
      encontrou = 1;
      break;
    }

    aux = aux->proximo;
  } while (aux != lista->comeco);

  if (!encontrou)
  {
    printf("\n\x1b[31mO id que voce informou nao existe na sua playlist, verifique e tente novamente\x1b[0m\n");
    return 0;
  }

  lista->tamanho--;

  if (lista->comeco == aux)
  {

    lista->final->proximo = lista->comeco->proximo;
    lista->comeco = lista->comeco->proximo;
    lista->comeco->anterior = lista->final;

    free(aux);

    return 1;
  }

  if (lista->final == aux)
  {
    lista->final = lista->final->anterior;
    lista->final->proximo = lista->comeco;
    lista->comeco->anterior = lista->final;

    free(aux);

    return 1;
  }

  aux->anterior->proximo = aux->proximo;
  aux->proximo->anterior = aux->anterior;

  free(aux);

  return 1;
}

int exibirPlaylist(Lista *lista)
{
  if (lista->comeco == NULL)
  {
    printf("\x1b[31mSua playlist ainda esta vazia\x1b[0m\n\n");
    return 1;
  }

  Registro *aux = lista->comeco;

  printf("\n\x1b[32m===== Exibindo Playlist =====\x1b[0m\n\n");
  printf("%-5s %-40s %-30s\n", "ID", "Nome", "Artista");

  do
  {
    printf("%-5d %-40s %-30s\n", aux->dado.id, aux->dado.nome, aux->dado.artista);
    aux = aux->proximo;
  } while (aux != lista->comeco);

  printf("\n");

  return 1;
}
