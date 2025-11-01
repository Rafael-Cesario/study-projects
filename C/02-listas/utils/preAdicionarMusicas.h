// Função para facilitar os testes
void preAdicionarMusicas(Lista *lista)
{
  Musica musicas[6] = {
      {1, "Sinfonia n5", "Ludwig van Beethoven"},
      {2, "Eine kleine Nachtmusik", "Wolfgang Amadeus Mozart"},
      {3, "Clair de Lune", "Claude Debussy"},
      {4, "O Lago dos Cisnes", "Pyotr Ilyich Tchaikovsky"},
      {5, "Canon in D", "Johann Pachelbel"},
      {6, "Primavera (As Quatro Estacoes)", "Antonio Vivaldi"}};

  for (int i = 0; i < 6; i++)
    inserirMusicaLista(lista, musicas[i]);

  printf("\n\n\x1b[31m6 musicas foram pre adicionadas\x1b[0m\n\n");
  system("pause");
}
