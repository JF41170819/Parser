#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Funciones.h"

ePersona* new_persona(void)
{
    ePersona* returnAux;

    returnAux = (ePersona*)malloc(sizeof(ePersona));

    if(returnAux != NULL)
    {
        strcpy(returnAux->domain, "");
        strcpy(returnAux->ip, "");
        strcpy(returnAux->userName, "");
        strcpy(returnAux->email, "");
        strcpy(returnAux->startDate, "");
        strcpy(returnAux->diskPartition, "");
        returnAux->quota = 0;
        returnAux->diskSpaceUsed = 0;
        strcpy(returnAux->package, "");
        strcpy(returnAux->theme, "");
        strcpy(returnAux->owner, "");
        strcpy(returnAux->server, "");
        strcpy(returnAux->unixStartDate, "");
        returnAux->diskSpaceUsedBytes = 0;
        returnAux->quotaBytes = 0;
        returnAux->isSuspended = 0;
        strcpy(returnAux->suspensionDate, "");
        strcpy(returnAux->suspensionLocked, "");
        strcpy(returnAux->suspensionReason, "");
    }

    return returnAux;
}

/** ARCHIVO BINARIO **/
/*
int guardarEnArchivo(ePendrive* pendrive, char* path)
{
    FILE* archivoBinario;

    if((archivoBinario = fopen(path, "rb+"))== NULL)
    {
        if((archivoBinario = fopen(path, "wb+"))== NULL)
        {
            return -1;
        }
    }

    fseek(archivoBinario, 0L, SEEK_END);
    fwrite(pendrive, sizeof(ePendrive), 1, archivoBinario);
    fclose(archivoBinario);

    return 1;
}

ePendrive* leerDesdeArchivo(char* path)
{
    FILE* archivoBinario;

    ePendrive* returnAux = new_pendrive();

    if((archivoBinario = fopen(path, "rb+"))== NULL)
    {
        return NULL;
    }

    rewind(archivoBinario);
    fread(returnAux, sizeof(ePendrive), 1, archivoBinario);
    return returnAux;
}
*/
/** ARCHIVO DE TEXTO **/
/*
int guardarEnArchivoDeTexto(ePendrive* pendrive, char* path)
{
    FILE* archivoTexto;

    if((archivoTexto = fopen(path, "r+"))== NULL)
    {
        if((archivoTexto = fopen(path, "w+"))== NULL)
        {
            return -1;
        }
    }

    fseek(archivoTexto, 0L, SEEK_END);
    fprintf(archivoTexto, "%d %s %s %d",pendrive->codigo,pendrive->marca,pendrive->modelo,pendrive->capacidad);
    fclose(archivoTexto);
    return 1;
}
*/
int leerTexto(char* path, ArrayList* listaPersonas)
{
    int returnAux = -1;

    char domain[500];
    char ip[250];
    char userName[500];
    char email[500];
    char startDate[250];
    char diskPartition[250];
    char quota[250];
    char diskSpaceUsed[250];
    char package[500];
    char theme[500];
    char owner[250];
    char server[500];
    char unixStartDate[500]; //int
    char diskSpaceUsedBytes[250];
    char quotaBytes[250];
    char isSuspended[250];
    char suspensionDate[250];
    char suspensionLocked[250];
    char suspensionReason[250];

    FILE* archivoTexto;

    if((archivoTexto = fopen(path, "r+"))== NULL)
    {
        return -1;
    }

    ePersona* aux;

    if(archivoTexto != NULL)
    {
        while(!feof(archivoTexto))
        {
            //4
            fscanf(archivoTexto, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d\n", domain, ip, userName, email, startDate, diskPartition, quota, diskSpaceUsed, package, theme, owner, server, unixStartDate, diskSpaceUsedBytes, quotaBytes, isSuspended, suspensionDate, suspensionLocked, suspensionReason);

            printf("%s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s -- %s\n", domain, ip, userName, email, startDate, diskPartition, quota, diskSpaceUsed, package, theme, owner, server, unixStartDate, diskSpaceUsedBytes, quotaBytes, isSuspended, suspensionDate, suspensionLocked, suspensionReason);

            system("pause");

            aux = new_persona();

            /*int quota;
            int diskSpaceUsed;
            long long int diskSpaceUsedBytes;
            long long int quotaBytes;
            int isSuspended;*/

            if(aux != NULL)
            {
                strcpy(aux->domain, domain);
                strcpy(aux->ip, ip);
                strcpy(aux->userName, userName);
                strcpy(aux->email, email);
                strcpy(aux->startDate, startDate);
                strcpy(aux->diskPartition, diskPartition);
                aux->quota = atoi(quota);
                aux->diskSpaceUsed = atoi(diskSpaceUsed);
                strcpy(aux->package, package);
                strcpy(aux->theme, theme);
                strcpy(aux->owner, owner);
                strcpy(aux->server, server);
                strcpy(aux->unixStartDate, unixStartDate);
                aux->diskSpaceUsedBytes = atoll(diskSpaceUsedBytes);
                aux->quotaBytes = atoll(quotaBytes);
                aux->isSuspended = atoi(isSuspended);
                strcpy(aux->suspensionDate, suspensionDate);
                strcpy(aux->suspensionLocked, suspensionLocked);
                strcpy(aux->suspensionReason, suspensionReason);
            }

            listaPersonas->add(listaPersonas, aux);
        }

        fclose(archivoTexto);

        returnAux = 0;
    }

    return returnAux;
}
