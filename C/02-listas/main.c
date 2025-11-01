#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "./utils/imprimirMenu.h"
#include "./utils/inserirMusica.h"
#include "./utils/removerMusica.h"
#include "./utils/reproduzir.h"
#include "./utils/preAdicionarMusicas.h"

int main()
{
  Lista lista;
  int opcao;

  criarLista(&lista);

  preAdicionarMusicas(&lista);

  do
  {
    imprimirMenu(&opcao);

    switch (opcao)
    {
    case 1:
      inserirMusica(&lista);
      break;
    case 2:
      removerMusica(&lista);
      break;
    case 3:
      exibirPlaylist(&lista);
      break;
    case 4:
      reproduzir(&lista);
      break;
    case 0:
      printf("\x1b[31mFinalizando...\x1b[0m\n\n");
      break;
    case 99:
      printf("\x1b[34mRafael de Oliveira Cesario da Silva - Data de Entrega: 22.10.2025\x1b[0m\n\n");
      break;
    default:
      printf("Opcao Invalida\n\n");
      break;
    }

    system("pause");
  } while (opcao != 0);

  return 0;
}
