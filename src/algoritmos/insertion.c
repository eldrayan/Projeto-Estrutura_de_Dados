#include "insertion.h"

//Insertion Sort = ordena as notas dos alunos de maneira crescente

void insertion_sort(Aluno v[], int n) {

    for (int i = 1; i < n; i++) {

        Aluno chave = v[i];
        int j = i - 1;

        // desloca elementos maiores que a chave
        while (j >= 0 && v[j].nota > chave.nota) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}
