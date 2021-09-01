/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 15 de agosto de 2021, 09:23 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>   
#include <fstream>   
#include "CompilacionBibInfrac.h"
#define MAX 100

using namespace std;

/*
 * 
 */

void leerDatosConductores(struct ConductorSt conductor[MAX], int & numCond) {

    ifstream archCond("Conductores.txt", ios::in);
    if(!archCond){
        cout<<"No se pudo abrir Conductores"<<endl;
        exit(1);
    }
  
    numCond = 0;
    while (1) {
        if ((archCond>>conductor[numCond]) == false)
            break; 
        cout << conductor[numCond].licencia;
        numCond ++;       
    }

}

int buscarCond(struct ConductorSt *conductor, int numCond, int lic) {

    for (int i = 0; i < numCond; i++) {
        if (conductor[i].licencia == lic) return i;
    }
    return -1;
}

void anadirFaltasCometidasAConductores(struct ConductorSt *conductor, int numCond) {

    ifstream archInfrac("RegistroDeFallas.txt", ios::in);
    if(!archInfrac){
        cout<<"No se pudo abrir RegistroDeFallas"<<endl;
        exit(1);
    }
    struct InfraccionSt infraccion;

    while (1) {
        if (archInfrac >> infraccion == false) break;
        int pos = buscarCond(conductor, numCond, infraccion.licencia);
        if (pos != -1) {
            conductor[pos] + infraccion;
        }
    }

}

void calcularMontosYCantidadesInfraccionesAConductor( struct ConductorSt *conductor, 
                                                    int numCond){
      
    for(int i=0; i<numCond ; i++){
        ++(conductor[i]) ;
    }
    
}

void emitirReporte(struct ConductorSt *conductor, int numCond){
    
    ofstream archRep("ReporteCond.txt", ios::out);
    
    for(int i=0; i<numCond; i++){
        archRep<<conductor[i];
    }
    
}

void completarMultasYGravedadAConductor(struct ConductorSt *conductor, int numCond) {

    ifstream archFaltas("Infracciones.txt", ios::in);
    struct InfraccionEstabSt infrEsta;
    
    if(!archFaltas){
        cout<<"No se pudo abrir Infracciones"<<endl;
        exit(1);
    }
    while (1) {
        if (archFaltas >> infrEsta == false) break;
        
        for(int i=0; i<numCond; i++){
            conductor[i] + infrEsta;
        }
    }

}

int main(int argc, char** argv) {

    struct ConductorSt conductor[MAX];

    int numCond;

    leerDatosConductores(conductor, numCond);
    //anadirFaltasCometidasAConductores(conductor, numCond);
    //completarMultasYGravedadAConductor(conductor, numCond);
    //calcularMontosYCantidadesInfraccionesAConductor(conductor,numCond);
    //emitirReporte(conductor, numCond);

    return 0;
}

