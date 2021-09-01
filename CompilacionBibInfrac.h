/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompilacionBibInfrac.h
 * Author: jhenn
 *
 * Created on 19 de agosto de 2021, 04:09 PM
 */



#ifndef COMPILACIONBIBINFRAC_H
#define COMPILACIONBIBINFRAC_H

#include <fstream>
using namespace std;  //sin esto no funciona el ifstream, ofstream

struct InfraccionEstabSt {
    int codigo;
    char gravedad[10];
    double multa;
};

struct FaltaSt {
    char placa[8];
    int fecha;
    int codInf;
    double multa;
    char gravedad[10];
};

struct InfraccionSt {
    int licencia;
    char placa[8];
    int codInf;
    int fecha;
};

struct ConductorSt {
    int licencia;
    char nombre[100];
    struct FaltaSt infrac[20];
    int numFaltas;
    int numFaltasLeves;
    int numFaltasGraves;
    int numFaltasMuyGraves;
    double montoFaltasLeves;
    double montoFaltasGraves;
    double montoFaltasMuyGraves;
};

bool & operator >>(ifstream &, struct ConductorSt &);
bool &operator >>(ifstream &, struct InfraccionSt &);
bool &operator >>(ifstream &, struct InfraccionEstabSt &);
void operator +(struct ConductorSt &, struct InfraccionSt const &);
void operator +(struct ConductorSt &, struct InfraccionEstabSt &) ;
void operator ++(struct ConductorSt &);
void operator *(struct ConductorSt &, int );
void fSepararFecha(int , int &, int &, int &);
void imprimirLinea(ofstream &, char , int );
ofstream &operator <<(ofstream &, struct ConductorSt &) ;


#endif /* COMPILACIONBIBINFRAC_H */

