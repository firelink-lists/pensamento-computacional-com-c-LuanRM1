#include <iostream>
using namespace std;

void troca(int v[], int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void copiar_array(const int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

bool arrays_iguais(const int a[], const int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void imprimir_array(const int v[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}

// Alternativa 1
void selection_sort_alt1(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = 0;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        troca(v, i, min_idx);
    }
}

// Alternativa 2
void selection_sort_alt2(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        troca(v, i, min_idx);
    }
}

// Alternativa 3
void selection_sort_alt3(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        troca(v, i, i + 1);
    }
}

// Alternativa 4
bool selection_sort_alt4_invalida() {
    return false;
}

// Alternativa 5 (correta)
void selection_sort_alt5(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        troca(v, i, min_idx);
    }
}

bool testar_funcao(void (*func)(int[], int), const int entrada[], const int esperado[], int n) {
    int teste[100];
    copiar_array(entrada, teste, n);
    func(teste, n);
    return arrays_iguais(teste, esperado, n);
}

void rodar_testes(const char* nome, void (*func)(int[], int)) {
    const int n1 = 5;
    int entrada1[n1]  = {5, 3, 8, 1, 2};
    int esperado1[n1] = {1, 2, 3, 5, 8};

    const int n2 = 6;
    int entrada2[n2]  = {10, 9, 8, 7, 6, 5};
    int esperado2[n2] = {5, 6, 7, 8, 9, 10};

    const int n3 = 7;
    int entrada3[n3]  = {4, 4, 2, 9, 1, 1, 7};
    int esperado3[n3] = {1, 1, 2, 4, 4, 7, 9};

    bool ok1 = testar_funcao(func, entrada1, esperado1, n1);
    bool ok2 = testar_funcao(func, entrada2, esperado2, n2);
    bool ok3 = testar_funcao(func, entrada3, esperado3, n3);

    cout << nome << " -> ";
    if (ok1 && ok2 && ok3) {
        cout << "deu certo" << endl;
    } else {
        cout << "deu ruim" << endl;
        cout << "  Teste 1: " << (ok1 ? "OK" : "ERRO") << endl;
        cout << "  Teste 2: " << (ok2 ? "OK" : "ERRO") << endl;
        cout << "  Teste 3: " << (ok3 ? "OK" : "ERRO") << endl;
    }
}

int main() {
    cout << "Testando todas as alternativas do selection sort:\n\n";

    rodar_testes("Alternativa 1", selection_sort_alt1);
    rodar_testes("Alternativa 2", selection_sort_alt2);
    rodar_testes("Alternativa 3", selection_sort_alt3);
    rodar_testes("Alternativa 5", selection_sort_alt5);

    return 0;
}