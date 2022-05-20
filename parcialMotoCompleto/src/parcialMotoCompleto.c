#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "moto.h"
#include "servicios.h"
#include "tipos.h"
#include "color.h"
#include "fecha.h"
#include "hardcodeo.h"
#include "funcionesAyuda.h"
#include "informes.h"
#include "trabajo.h"
#include "cliente.h"

#define TAM_TIPO 4
#define TAM_SERV 4
#define TAM_COLOR 5
#define TAM_MOTO 20
#define TAM_TRABAJO 20
#define TAM_Clientes 50


int main()
{
	setbuf(stdout,NULL);

    eMoto listaMotos[TAM_MOTO];
    eTrabajo listaTrabajos[TAM_TRABAJO];
    eCliente listaClientes[TAM_Clientes];

    eTipo listaTipo[TAM_TIPO] =
    {
        {1000,"Enduro",0},
        {1001,"Chopera",0},
        {1002,"Scooter",0},
        {1003,"Ciclomotor",0}

    };

    eServicio listaServicios[TAM_SERV]=
    {
        {20000,"Limpieza",450,0},
        {20001,"Ajuste",300,0},
        {20002,"Balanceo",150,0},
        {20003,"Cadena",390,0}
    };

    eColor listColor[TAM_COLOR] =
    {
        {10000,"Gris",0},
        {10001,"Negro",0},
        {10002,"Blanco",0},
        {10003,"Azul",0},
        {10004,"Rojo",0}
    };

    inicializarArrayMoto(listaMotos,TAM_MOTO);
    inicializarArrayTrabajo(listaTrabajos,TAM_TRABAJO);
    inicializarArrayClientes(listaClientes,TAM_Clientes);

    int flagMoto = 0;
    int flagJob = 0;
    int idMoto = 1000;
    int idJobs = 1;
    int idCliente = 1;
    char salir = 'n';

    flagMoto = hardcodearMotos(listaMotos,TAM_MOTO,&idMoto,15);
    flagJob = hardcodearTrabajos(listaTrabajos,TAM_TRABAJO,&idJobs,15);
    hardcodearClientes(listaClientes,TAM_Clientes,&idCliente,10);

    do
    {
        switch(menu())
        {
        case 1:
            if(altaMoto(listaMotos,TAM_MOTO,&idMoto,listaTipo,TAM_TIPO,listColor,TAM_COLOR))
            {
                printf("\nAlta realizada Con Exito!.\n\n");
                flagMoto = 1;
            }
            else
            {
                printf("\nOpps ! Ocurrio un error!.\n\n");
            }
            break;

        case 2:
            if(flagMoto)
            {
                mostrarListaMotos(listaMotos,TAM_MOTO,listaTipo,TAM_TIPO,listColor,TAM_COLOR,listaClientes,TAM_Clientes);
                modificarMoto(listaMotos,TAM_MOTO,listColor,TAM_COLOR);
            }
            else
            {
                printf("\n--Primero debe dar de alta una moto--.\n\n");
            }

            break;

        case 3:
            if(flagMoto)
            {
                mostrarListaMotos(listaMotos,TAM_MOTO,listaTipo,TAM_TIPO,listColor,TAM_COLOR,listaClientes,TAM_Clientes);
                bajaMoto(listaMotos,TAM_MOTO);
            }
            else
            {
                printf("\n--Primero debe dar de alta una moto--.\n\n");
            }

            break;

        case 4:
            ordenarMotosPorTipoEId(listaMotos,TAM_MOTO);
            mostrarListaMotos(listaMotos,TAM_MOTO,listaTipo,TAM_TIPO,listColor,TAM_COLOR,listaClientes,TAM_Clientes);
            break;

        case 5:
            mostrarListaTipos(listaTipo,TAM_TIPO);
            break;

        case 6:
            mostrarListaColor(listColor,TAM_COLOR);
            break;

        case 7:
            mostrarListaServicios(listaServicios,TAM_SERV);
            break;

        case 8:
            mostrarListaMotos(listaMotos,TAM_MOTO,listaTipo,TAM_TIPO,listColor,TAM_COLOR,listaClientes,TAM_Clientes);
            if(altaTrabajo(listaTrabajos,TAM_TRABAJO,&idJobs,listaServicios,TAM_SERV,listaMotos,TAM_MOTO))
            {
                printf("\nAlta Exitosa!.\n");
            }
            else
            {
                printf("\nOpps, Ocurrio un error!.\n\n");
            }
            break;

        case 9:
            if(flagJob)
            {
                mostrarListaTrabajos(listaTrabajos,TAM_TRABAJO,listaServicios,TAM_SERV,listaMotos,TAM_MOTO);
            }
            else
            {
                printf("\n--Primero debe dar de alta un Trabajo--.\n\n");
            }

            break;

        case 10:
            switch(informes())
            {
                case 1:
                    informarMotoPorColor(listaMotos,TAM_MOTO,listColor,TAM_COLOR,listaTipo,TAM_TIPO,listaClientes,TAM_Clientes);
                    break;

                case 2:
                    informarMotoPorTipo(listaMotos,TAM_MOTO,listColor,TAM_COLOR,listaTipo,TAM_TIPO,listaClientes,TAM_Clientes);
                    break;

                case 3:
                    informarMotoMaryorCilindrada(listaMotos,TAM_MOTO,listColor,TAM_COLOR,listaTipo,TAM_TIPO,listaClientes,TAM_Clientes);
                    break;

                case 4:
                    informarMotoSeparadaTipo(listaMotos,TAM_MOTO,listColor,TAM_COLOR,listaTipo,TAM_TIPO,listaClientes,TAM_Clientes);
                    break;

                case 5:
                    informarCantColorYTipo(listaMotos,TAM_MOTO,listColor,TAM_COLOR,listaTipo,TAM_TIPO);
                    break;

                case 6:
                   informarColorMasElegido(listaMotos,TAM_MOTO,listColor,TAM_COLOR);
                    break;

                case 7:
                   mostrarListaMotos(listaMotos,TAM_MOTO,listaTipo,TAM_TIPO,listColor,TAM_COLOR,listaClientes,TAM_Clientes);
                   informarTrabajosSeleccionados(listaMotos,TAM_MOTO,listaTrabajos,TAM_TRABAJO,listaServicios,TAM_SERV);
                    break;

                case 8:
                    mostrarListaMotos(listaMotos,TAM_MOTO,listaTipo,TAM_TIPO,listColor,TAM_COLOR,listaClientes,TAM_Clientes);
                    informarSumarValores(listaMotos,TAM_MOTO,listaTrabajos,TAM_TRABAJO,listaServicios,TAM_SERV);
                    break;

                case 9:
                    mostrarListaServicios(listaServicios,TAM_SERV);
                    informarServiciosPorMoto(listaTrabajos,TAM_TRABAJO,listaServicios,TAM_SERV,listaMotos,TAM_MOTO);
                    break;

                case 10:
                    informarServicioPorFecha(listaServicios,TAM_SERV,listaTrabajos,TAM_TRABAJO);
                    break;

                case 11:
                    break;
            }
            break;

        case 11:
            validarSioNo(&salir,"\nConfirma Salida [s/n]: \n","\nERROR!!!! Dato Invalido.Reingrese: \n",10);
            break;
        }



    }
    while(salir == 'n');

    return 0;
}
