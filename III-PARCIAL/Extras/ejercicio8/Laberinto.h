#pragma once
#pragma warning(disable:4996)

int m[100][100];
int f, c;
int fp, cp;
int fs, cs;
const int ARRIBA = 0, DERECHA = 1, IZQUIERDA = 2, ABAJO = 3;
int direccion = ARRIBA;
int arriba, abajo, izquierda, derecha;

void leerArchivo() {
    int maxCol;
    FILE* archivo;
    char caracter;
    int codigo;
    bool flag = true;

    archivo = fopen("laberinto.txt", "rt");
    if (archivo == NULL) {
        printf("Error en lectura de archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    while (!feof(archivo)) {
        caracter = fgetc(archivo);
        codigo = caracter;

        if (codigo == 10) {
            f++;
            if (flag) { maxCol = c; flag = false; }
            c = 0;
        }
        else {
            m[f][c] = codigo - 48;
            if (m[f][c] == 2) { fp = f; cp = c; }
            if (m[f][c] == 3) { fs = f; cs = c; }
            c++;
        }
    }
    c = maxCol;
    fclose(archivo);

}

void verLaberinto() {

    system("cls");
    for (int i = 0; i<f; i++) {
        for (int ii = 0; ii<c; ii++) {
            if (m[i][ii] == 1) printf("|");
            else if (i == fs && ii == cs) printf("A");
            else if (i == fp && ii == cp) printf("B");
            else printf(" ");
        }
        printf("\n");
    }

}

void recorrer() {
    int old_fp, old_cp;

    old_fp = fp; old_cp = cp;

    arriba = m[fp - 1][cp];
    abajo = m[fp + 1][cp];
    derecha = m[fp][cp + 1];
    izquierda = m[fp][cp - 1];


    if (derecha == 3) direccion = DERECHA;
    else if (izquierda == 3) direccion = IZQUIERDA;
    else if (arriba == 3) direccion = ARRIBA;
    else if (abajo == 3) direccion = ABAJO;


    else if (direccion == ARRIBA) {
        if (derecha == 1 && arriba == 0) {}
        else if (derecha == 0) direccion = DERECHA;
        else if (izquierda == 0) direccion = IZQUIERDA;
        else direccion = ABAJO;
    }
    else if (direccion == 1) {
        if (abajo == 1 && derecha == 0) {}
        else if (abajo == 0) direccion = ABAJO;
        else if (arriba == 0) direccion = ARRIBA;
        else direccion = IZQUIERDA;
    }
    else if (direccion == 3) {
        if (abajo == 0 && izquierda == 1) {}
        else if (izquierda == 0) direccion = IZQUIERDA;
        else if (derecha == 0) direccion = DERECHA;
        else direccion = ARRIBA;
    }
    else if (direccion == 2) {
        if (izquierda == 0 && arriba == 1) {}
        else if (arriba == 0) direccion = ARRIBA;
        else if (abajo == 0) direccion = ABAJO;
        else direccion = DERECHA;
    }

    m[old_fp][old_cp] = 0;

    switch (direccion) {
    case 0:
        m[fp - 1][cp] = 2;
        fp--;
        break;
    case 1:
        m[fp][cp + 1] = 2;
        cp++;
        break;
    case 2:
        m[fp][cp - 1] = 2;
        cp--;
        break;
    case 3:
        m[fp + 1][cp] = 2;
        fp++;
        break;
    }
}
