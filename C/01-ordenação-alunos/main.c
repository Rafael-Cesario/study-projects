#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "alunoStruct.h"
#include "./utils/contarLinhas.h"
#include "./utils/pegarDadosAlunos.h"
#include "./utils/calcularMedia.h"
#include "./utils/imprimirResultados.h"
#include "./algoritmos/bubbleSort.h"
#include "./algoritmos/mergeSort.h"
#include "./algoritmos/quickSort.h"
#include "./utils/copiarAlunos.h"
#include "./relatoriosAlgoritmos/bubbleSortRelatorio.h"
#include "./relatoriosAlgoritmos/mergeSortRelatorio.h"
#include "./relatoriosAlgoritmos/quickSortRelatorio.h"
#include "./utils/escreverTempo.h"
#include "./utils/gerarRelatorios.h"
#include "./utils/calcularMediaAlgoritmos.h"

int main()
{
    gerarRelatorios(5);
    calcularMediaAlgoritmos();

    return 0;
}
