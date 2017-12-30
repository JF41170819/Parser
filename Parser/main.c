#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    ArrayList* listaPersonas = al_newArrayList();
    leerTexto("fetchcsv.txt", listaPersonas);
    return 0;
}
