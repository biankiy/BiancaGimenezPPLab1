/*
 * Genericas.c
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Ctype.h>


#include "funcionesAyuda.h"


/** \brief Solicita un n?mero al usuario y lo valida
 * \param pResultado Se carga el numero ingresado
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError  Es el mensaje a ser mostrado en caso de error
 * \param minimo Limite minimo a validar
 * \param maximo Limite maximo a validar
 * \return Si obtuvo el numero [0] si no [-1]
 */
int getInt(int *pResultado,
           char *pMensaje,
           char *pMensajeError,
           int minimo,
           int maximo,
           int reintentos)
{
    int retorno = ERROR;
    int buffer;

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            minimo < maximo &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%d",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = TODOK;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >= 0);

    }
    return retorno;
}


/** \brief Solicita un n?mero (flotante) al usuario y lo valida
 * \param pResultado Se carga el numero ingresado
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError  Es el mensaje a ser mostrado en caso de error
 * \param minimo Limite minimo a validar
 * \param maximo Limite maximo a validar
 * \return Si obtuvo el numero [0] si no [-1]
 */
float getFloat(float *pResultado,
               char *pMensaje,
               char *pMensajeError,
               float minimo,
               float maximo,
               int reintentos)
{
    int retorno = ERROR;
    float buffer;

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            minimo < maximo &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%f",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = TODOK;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >= 0);

    }
    return retorno;
}


/** \brief Solicita un caracter al usuario y lo valida
 * \param pResultado Se carga el caracter ingresado
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError  Es el mensaje a ser mostrado en caso de error
 * \param minimo Limite minimo a validar
 * \param maximo Limite maximo a validar
 * \return Si obtuvo el caracter [0] si no [-1]
 */
char getChar(char *pResultado,
             char *pMensaje,
             char *pMensajeError,
             char minimo,
             char maximo,
             int reintentos)
{
    int retorno = ERROR;
    char buffer;

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            minimo < maximo &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%c",&buffer)==1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = TODOK;
                    *pResultado = buffer;
                    break;
                }
            }

            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >= 0);

    }
    return retorno;
}


/** \brief Solicita una cadena de caracteres al usuario y lo valida
 * \param pResultado Se carga el string ingresado
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError  Es el mensaje a ser mostrado en caso de error
 * \param minimo longitud minimo a validar
 * \param maximo longitud maximo a validar
 * \return Si obtuvo la cadena [0] si no [-1]
 */
int getString(char *pResultado,
              char *pMensaje,
              char *pMensajeError,
              int minimo,
              int maximo,
              int reintentos)
{
    int retorno = ERROR;
    char buffer[500];

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            minimo < maximo &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            //retorna cadena si es realizada con ?xito.
            buffer[strlen(buffer)-1] = '\0';
            if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
            {
                strncpy(pResultado,buffer,maximo+1);
                retorno = TODOK;
                break;
            }

            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >=0);
    }
    return retorno;
}


/** \brief Verifica si el valor recibido es num?rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es num?rico y 0 si no lo es
 */
int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        //va a retornar 0 cuando:
        //si NO es un espacio y que no sea algo que este entra la a y z
        //y algo que no este entre la A y la Z
        if((str[i] != ' ')
                &&(str[i] < 'a' || str[i] > 'z')
                &&(str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si el valor recibido tiene letras y n?meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros . 0 si no lo es
 *
 */
int esAlfanumerico(char str[])
{

    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
                &&(str[i] < 'a' || str[i] > 'z')
                &&(str[i] < 'A' || str[i] > 'Z')
                &&(str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}


/** \brief Verifica si es valor recibido contiene solo numeros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo n?meros, espacios y UN gui?n
 */
int esTelefono(char str[])
{
    int i = 0;
    int contadorDeGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')
                &&(str[i] != '-')
                &&(str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorDeGuiones ++;
        i++;
    }
    return 1;
}

int getNombreOApellido(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
    int retorno = ERROR;
    char buffer[500];

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            minimo < maximo &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            //retorna cadena si es realizada con ?xito.
            buffer[strlen(buffer)-1] = '\0';
            if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
            {
                if(esSoloLetras(buffer)==1)
                {
                    strncpy(pResultado,buffer,maximo+1);
                    retorno = TODOK;
                    break;
                }

            }

            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >=0);
    }
    return retorno;
}

int getStringTelefono(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
    int retorno = ERROR;
    char buffer[500];

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            minimo < maximo &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            //retorna cadena si es realizada con ?xito.
            buffer[strlen(buffer)-1] = '\0';
            if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
            {
                if(esNumerico(buffer)!=1)//Si es igual a 1 es que es numerico.
                {
                    strncpy(pResultado,buffer,maximo+1);
                    retorno = TODOK;
                    break;
                }
            }

            printf("%s",pMensajeError);
            reintentos--;

        }while(reintentos >=0);
    }
    return retorno;
}

char getSexo(char *pResultado,char *pMensaje,char *pMensajeError,int reintentos)
{
    int retorno = ERROR;//DEVUELVE -1 SI ES ERROR
    char buffer;

    if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);

            if(scanf("%c",&buffer)==1)
            {
                if(buffer == 'f' || buffer == 'm')
                {
                    retorno = TODOK;
                    *pResultado = buffer;
                    break;
                }
            }

            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >= 0);

    }
    return retorno;
}

int isValidNombre(char* cadena,int longitud)
{
    int retorno = ERROR;
    if(cadena != NULL && longitud >0)
    {
        for(int i=0; cadena[i] != '0' && i<longitud; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z') &&(cadena[i] < 'a' || cadena[i] > 'z'))
            {
                retorno = TODOK;
                break;
            }
        }
    }
    return retorno;
}

void convertirMayuscula(char* cadena)
{
    for (int indice = 0; cadena[indice] != '\0'; ++indice)
    {
        cadena[indice] = toupper(cadena[indice]);
    }
}

void convertirMinuscula(char* cadena)
{
    for (int indice = 0; cadena[indice] != '\0'; ++indice)
    {
        cadena[indice] = tolower(cadena[indice]);
    }
}

char validarSioNo(char *pResultado,char *pMensaje,char *pMensajeError,int reintentos)
{
    int retorno = ERROR;
    char buffer;

    if(pResultado != NULL &&
            pMensaje != NULL &&
            pMensajeError != NULL &&
            reintentos >=0)
    {
        do
        {
            printf("%s",pMensaje);
            fflush(stdin);


            if(scanf("%c",&buffer)==1)
            {
                convertirMinuscula(&buffer);
                if( buffer == 's' || buffer == 'n')
                {
                    retorno = TODOK;
                    *pResultado = buffer;
                    break;
                }
            }

            printf("%s",pMensajeError);
            reintentos--;

        }
        while(reintentos >= 0);

    }
    return retorno;
}

int valFecha(int dd,int mm, int yy)
{
    int retorno = ERROR;

    if(yy>=2014 && yy<=2050)
    {
//check month
        if(mm>=1 && mm<=12)
        {
//check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
            {
                retorno = TODOK;
            }

            else
            {
                if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                {
                    retorno = TODOK;
                }

                else
                {
                    if((dd>=1 && dd<=28) && (mm==2))
                    {
                        retorno = TODOK;
                    }

                    else
                    {
                        if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                        {
                            retorno = TODOK;
                        }

                        else
                            printf("Dia no valido!.\n");
                    }
                }
            }
        }
        else
        {
            printf("Mes no valido!.\n");
        }
    }
    else
    {
        printf("Fecha no valida!.\n");
    }

    return retorno;
}

int intercambiar(int *list, int i, int j)
{
    int ret = -1;
    int aux;
    if(list != NULL)
    {
        aux = list[i];
        list[i] = list[j];
        list[j] = aux;
        ret = 1;
    }
    return ret;
}

int ordenacion_seleccion(int *list, int len)
{
    int i, j, k, ret = -1;

    if(list != NULL)
    {
        for (i=0; i<len-1; i++)
        {
            for (k=i, j=i+1; j<len; j++)
            {
                if (list[j] <list[k])
                {
                    k = j;
                }
                if (k != i)
                {
                    intercambiar (list, i, k);
                }
            }
        }
        ret = 1;
    }
    return ret;
}

int ordenarArrayInt(int list[],int len)
{
    int ret = ERROR;
    int aux;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(list[i] < list[j])
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
        ret = TODOK;
    }
    return ret;
}

