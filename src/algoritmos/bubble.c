#include "bubble.h"

// Bubble Sort = ordena as notas dos alunos de maneira crescente

void bubble_sort(Aluno v[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        
        // flag para detectar se houve troca
        int trocou = 0;
        
        // percorre array comparando elementos adjacentes
        for (int j = 0; j < n - 1 - i; j++) {
            
            // se elemento atual for maior que o próximo, troca
            if (v[j].nota > v[j + 1].nota) {
                Aluno temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        
        // se não houve troca, o array já está ordenado
        if (!trocou) {
            break;
        }
    }
}
