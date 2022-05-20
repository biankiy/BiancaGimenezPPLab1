/*
 * informes.c
 *
 *  Created on: 20 may. 2022
 *      Author: bianky
 */

#ifndef INFORMES_C_
#define INFORMES_C_

#include "informes.h"



int menu()
{
    int respuesta = ERROR;

    	printf("\n\n");
    	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    	printf("<><><>>>>>>>>>>>  ABM MOTOS UTN  <<<<<<<<<<<<><><><><<><><><><><><\n");
    	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><>\n");
    	printf("<><><| [ 1 ] <= [ ALTA DE MOTOS      ] |><><><>\n");
    	printf("<><><| [ 2 ] <= [ MODIFICAR MOTOS    ] |><><><>\n");
    	printf("<><><| [ 3 ] <= [ BAJA DE MOTO       ] |><><><>\n");
    	printf("<><><| [ 4 ] <= [ LISTADO DE MOTOS   ] |><><><>\n");
    	printf("<><><| [ 5 ] <= [ LISTAR TIPOS       ] |><><><>\n");
    	printf("<><><| [ 6 ] <= [ LISTAR COLORES     ] |><><><>\n");
    	printf("<><><| [ 7 ] <= [ LISTAR SERVICIO    ] |><><><>\n");
    	printf("<><><| [ 8 ] <= [ ALTA TRABAJO       ] |><><><>\n");
    	printf("<><><| [ 9 ] <= [ LISTAR TRABAJO     ] |><><><>\n");
    	printf("<><><| [ 10] <= [ INFORMES           ] |><><><>\n");
    	printf("<><><| [ 11] <= [ SALIR              ] |><><><>\n");
    	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
        getInt(&respuesta,"\nIngrese una opcion [1-11]: ","\nDato Invalido. Reingrese: \n",1,11,5);


    return respuesta;
}

int informes()
{
    int retorno = ERROR;

    printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\n-----------     Menu Informes         -	-------------");
    printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");
    printf("1- Mostrar las motos del color seleccionado por el usuario.\n");
    printf("2- Mostrar las motos de un tipo seleccionado.\n");
    printf("3- Informar la o las motos de mayor cilindrada.\n");
    printf("4- Mostrar un listado de las motos separadas por tipo.\n");
    printf("5- Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo.\n");
    printf("6- Mostrar el o los colores más elegidos por los clientes.\n");
    printf("7- Pedir una moto y mostrar todos los trabajos que se le hicieron a la misma.\n");
    printf("8- Pedir una moto e informar la suma de los importes de los servicios que se le hicieron a la misma.\n");
    printf("9- Pedir un servicio y mostrar las motos a las que se les realizo ese servicio y la fecha.\n");
    printf("10- Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("11- Salir.\n");
    printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");

    getInt(&retorno,"\nIngrese una opcion (/1-10/): ","\n Error !!!! Invalido. Reingrese: \n",1,11,10);

    return retorno;
}




int informarMotoPorColor(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo,eCliente listCliente[],int lenCliente)
{
    int bufferId;
	int retorno = ERROR;

    if(list != NULL && len >0 && listColor != NULL && lenColor >0 && listTipo != NULL && lenTipo >0)
    {
        mostrarListaColor(listColor,lenColor);
        getInt(&bufferId,"\nIngrese ID []: \n","\nDato Invalido.Reingrese: \n",10000,10004,5);

        if(validarIdColor(listColor,lenColor,bufferId))
        {
        	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
			printf("<><><>>>>>>>>>>>  LISTA DE MOTOS POR COLOR<<<<<<<><><><><<><><><><><><><><><><><><\n");
			printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><><\n");

			printf("| ID |     MARCA        |     TIPO   |    COLOR   |  CILINDRADA   |  CLIENTE   |\n");
			printf("|______________________________________________________________________________|\n");
        	printf("_________________________________________________________________\n");

            for(int i=0; i<len; i++)
            {
                if(list[i].idColor == bufferId)
                {
                    mostrarUnaMoto(&list[i],listTipo,lenTipo,listColor,lenColor,listCliente,lenCliente);
                }
            }
            printf("_________________________________________________________________\n\n");
            retorno = TODOK;
        }
        else
        {
            printf("\nERROR !!! No ingreso un ID valido!.\n");
        }
    }
    return retorno;
}

int informarMotoPorTipo(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo,eCliente listCliente[],int lenCliente)
{
    int bufferId;
    int retorno = ERROR;

    if(list != NULL && len >0 && listColor != NULL && lenColor >0 && listTipo != NULL && lenTipo >0)
    {
        mostrarListaTipos(listTipo,lenTipo);
        getInt(&bufferId,"\nIngrese ID []: \n","\nDato Invalido.Reingrese: \n",1000,1003,5);

        if(validarIdTipo(listTipo,lenTipo,bufferId))
        {

        	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>>><<>>\n");
			printf("<><><>>>>>>>>>>>  LISTA DE MOTOS POR TIPO<<<<<<<><><><><<><><><><><><><><><><><\n");
			printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><><><\n");
			printf("| ID |     MARCA        |     TIPO   |    COLOR   |  CILINDRADA   |  CLIENTE   |\n");
			printf("|______________________________________________________________________________|\n");
            for(int i=0; i<len; i++)
            {
                if(list[i].idTipo == bufferId)
                {
                    mostrarUnaMoto(&list[i],listTipo,lenTipo,listColor,lenColor,listCliente,lenCliente);
                }
            }
            printf("_________________________________________________________________\n\n");
            retorno = TODOK;
        }
        else
        {
            printf("\nNo ingreso un ID valido!.\n");
        }
    }
    return retorno;
}

int informarMotoMaryorCilindrada(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo,eCliente listCliente[],int lenCliente)
{
    int retorno = ERROR;

    if(list != NULL && len >0 && listColor != NULL && lenColor >0 && listTipo != NULL && lenTipo >0 && listCliente !=NULL && lenCliente >0)
    {

    	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><>>><><\n");
		printf("<><><>>>>>>>>>>>  LISTA DE MOTOS MAYOR CILINDRADA<<<<<<<><><><><<<><><><><>>><><\n");
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><>><><><><>><\n");
		printf("| ID |     MARCA        |     TIPO   |    COLOR   |  CILINDRADA   |  CLIENTE   |\n");
		printf("|______________________________________________________________________________|\n");

        for(int i=0; i<len; i++)
        {
            if(list[i].cilindrada == 750)
            {
                mostrarUnaMoto(&list[i],listTipo,lenTipo,listColor,lenColor,listCliente,lenCliente);
            }
        }
        printf("_________________________________________________________________\n\n");
        retorno = TODOK;
    }
    return retorno;
}

int informarMotoSeparadaTipo(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo,eCliente listCliente[],int lenCliente)
{
    int retorno = ERROR;
    int aux;

    if(list != NULL && len >0 && listColor != NULL && lenColor >0 && listTipo != NULL && lenTipo >0 && listCliente !=NULL && lenCliente >0)
    {

    	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("<><><>>>>>>>>>>>  LISTA DE MOTOS SEPARADA POR TIPO<<<<<><><><><<<><><\n");
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><>\n");
		printf("| ID |     MARCA        |     TIPO   |    COLOR   |  CILINDRADA   |\n");
		printf("|_________________________________________________________________|\n");

        ordenarMotoPorTipo(list,len);

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                if(aux != list[i].idTipo && i != 0)
                {
                    printf("_________________________________________________________________\n\n");
                }
                mostrarUnaMoto(&list[i],listTipo,lenTipo,listColor,lenColor,listCliente,lenCliente);
                aux = list[i].idTipo;
            }
        }

        printf("_________________________________________________________________\n\n");
        retorno = TODOK;
    }
    return retorno;
}

int informarCantColorYTipo(eMoto list[],int len,eColor listColor[],int lenColor,eTipo listTipo[],int lenTipo)
{
    int contador = 0,idTipo,idColor,ret = ERROR;

    if(list != NULL && len >0 && listColor != NULL && lenColor >0 && listTipo != NULL && lenTipo >0)
    {
        mostrarListaTipos(listTipo,lenTipo);
        getInt(&idTipo,"\nIngrese un ID [1000/1003]: \n","\nErrror.",1000,1003,5);
        if(validarIdTipo(listTipo,lenTipo,idTipo))
        {
            mostrarListaColor(listColor,lenColor);
            getInt(&idColor,"\nIngrese un ID [10000/10004]: \n","\nErrror.",10000,10004,5);
            if(validarIdColor(listColor,lenColor,idColor))
            {
                for(int i=0; i<len; i++)
                {
                    if(list[i].isEmpty == 0 && list[i].idColor == idColor && list[i].idTipo == idTipo)
                    {
                        contador++;
                    }
                }

                printf("\nLa cantidad de ese color y tipo ingresado es : %d\n\n",contador);
                ret = TODOK;
            }
        }
    }

    return ret;
}

int informarColorMasElegido(eMoto list[],int len,eColor listColor[],int lenColor)
{
    int mayor;
	int retorno = ERROR;
    eColor arrayAuxColor[lenColor];

    if(list != NULL && len >0 && listColor != NULL && lenColor >0)
    {
        for(int y=0; y<lenColor; y++)
        {
            if(listColor[y].isEmpty == 0)
            {
                arrayAuxColor[y].isEmpty = 0;
                arrayAuxColor[y].id = listColor[y].id;
                strcpy(arrayAuxColor[y].nombreColor,listColor[y].nombreColor);
            }
        }

        for(int i=0; i<lenColor; i++)
        {
            if(listColor[i].isEmpty == 0)
            {
                for(int j=0; j<len; j++)
                {
                    if(list[j].isEmpty == 0)
                    {
                        if(list[j].idColor == listColor[i].id)
                        {
                            arrayAuxColor[i].isEmpty++;
                        }
                    }
                }
            }
        }

        ordenarListaColoresAux(arrayAuxColor,lenColor);
        mayor = arrayAuxColor[0].isEmpty;


        printf("\nEl o los color/es mas elegido o elegidos es/son :\n");

        for(int k=0; k<lenColor; k++)
        {
            if(arrayAuxColor[k].isEmpty == mayor)
            {
                printf("\n-%s",arrayAuxColor[k].nombreColor);
            }
        }
        printf("\n\n");
        retorno = TODOK;
    }
    return retorno;
}

int informarTrabajosSeleccionados(eMoto list[],int len,eTrabajo listJob[],int lenJob,eServicio listServ[],int lenServ)
{
    int bufferID;
    int retorno = -1;

    if(list != NULL && len >0)
    {
        getInt(&bufferID,"\nIngrese ID moto: \n","\nDato Invalido.Reingrese:\n",1000,1100,5);
        if(validarIdMoto(list,len,bufferID)==1)
        {
        	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
			printf("<><><>>>>>>>>>  LISTA DE TRABAJOS<<<<<><><><><<><><\n");
			printf("<><>><><><><><><><><><><><><><><><><><><><><><><><<\n");

            printf("\n|ID       Moto      Servicio    Fecha             | \n");
            printf("____________________________________________________\n\n");

            for(int i=0; i<lenJob; i++)
            {
                if(listJob[i].idMoto == bufferID && listJob[i].isEmpty == 0)
                {
                    mostrarUnTrabajo(&listJob[i],listServ,lenServ,list,len);
                }
            }
            printf("____________________________________________________\n\n");
        }
        else
        {
            printf("\nNo se encontro ninguna moto con el ID ingresado!.\n");
        }
        retorno = 1;
    }
    return retorno;
}

int informarSumarValores(eMoto list[],int len,eTrabajo listJob[],int lenJob,eServicio listServ[],int lenServ)
{
    int monto;
    int acu=0;
    int bufferIdMoto;
    int retorno = ERROR;

    if(list != NULL && len >0)
    {
        getInt(&bufferIdMoto,"\nIngrese ID moto: \n","\nDato Invalido.Reingrese:\n",1000,1100,5);
        if(validarIdMoto(list,len,bufferIdMoto)==TODOK)
        {
            for(int i=0; i<lenJob; i++)
            {
                if(listJob[i].idMoto == bufferIdMoto)
                {
                    get_MontoServicio(listServ,lenServ,&monto,listJob[i].idServicio);
                    acu += monto;
                }
            }
            printf("\nLa suma de los Valores es: $%d\n\n",acu);
        }
        else
        {
            printf("\nNo se encontro ninguna moto con el ID ingresado:\n");
        }
        retorno = TODOK;
    }
    return retorno;
}

int informarServiciosPorMoto(eTrabajo listJob[],int lenJob,eServicio listServ[],int lenServ,eMoto listMoto[],int lenMoto)
{
    int bufferIdServ, ret = ERROR;
    char marcaAux[24];

    if(listJob != NULL && lenJob >0 && listServ != NULL && lenServ >0)
    {
        getInt(&bufferIdServ,"\nIngrese ID servicio: \n","\nDato Invalido.Reingrese:\n",20000,20003,5);
        if(validarServicio(listServ,lenServ,bufferIdServ)==TODOK)
        {
        	printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("\n      [Marca]      [Fecha]\n");
            printf("_______________________________\n\n");

            for(int i=0; i<lenJob; i++)
            {
                if(listJob[i].idServicio == bufferIdServ)
                {
                    if(cargarDescripcionMarca(listMoto,lenMoto,listJob[i].idMoto,marcaAux)==TODOK)
                    {
                        printf("\%12s      ",marcaAux);
                        printf("%02d/",listJob[i].fecha.dia);
                        printf("%02d/",listJob[i].fecha.mes);
                        printf("%4d\n",listJob[i].fecha.anio);
                    }
                }
            }
            printf("\n\n");
        }
        ret = TODOK;
    }
    return ret;
}

int informarServicioPorFecha(eServicio listServ[],int lenServ,eTrabajo listJob[],int lenJob)
{
    int diaAux, mesAux, anioAux, ret=ERROR;
    char servAux[24];

    if(listServ != NULL && lenServ >0 && listJob != NULL && lenJob >0)
    {
        getInt(&diaAux,"\nIngrese dia [1-31]: \n","\nError.",1,31,3);
        getInt(&mesAux,"\nIngrese mes [1-12]: \n","\nError.",1,12,3);
        getInt(&anioAux,"\nIngrese año [2014-2050]: \n","\nError.",2014,2050,3);

        if(valFecha(diaAux,mesAux,anioAux)==TODOK)
        {
        	printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("\nServicios realizados en la fecha\n");
            printf("_______________________________\n\n");
            for(int i=0; i<lenJob; i++)
            {
                if(listJob[i].fecha.dia == diaAux && listJob[i].fecha.mes == mesAux && listJob[i].fecha.anio == anioAux )
                {
                    cargarDescServ(listServ,lenServ,listJob[i].idServicio,servAux);
                    printf("%s\n",servAux);
                }
            }
            ret = TODOK; printf("\n\n");
        }
    }
    return ret;
}
#endif /* INFORMES_C_ */
