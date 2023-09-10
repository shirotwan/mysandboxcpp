#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <locale>
using namespace std;
template <class T> class Fichero{
private:
    unsigned fil,col = 0; // VARIABLES DE TAMAÑO
    T** tb = NULL; // FICHERO
    virtual void initT(){ // GENERADOR DE MATRIZ
        tb = new T*[fil];
        for(int i = 0; i < fil; i++){tb[i] = new T[col];}}
public:
    Fichero(unsigned fil,unsigned col):fil(fil),col(col){initT();} // CONSTRUCTOR
    Fichero(T** tb):tb(tb){this->tb = tb;}
    Fichero(T** tb,unsigned fil,unsigned col):fil(fil),col(col){initT();this->tb = tb;}
    ~Fichero(){delete tb; fil = col = 0;} // DESTRUCTOR
    virtual void setFval(unsigned posf,unsigned posc,T val){tb[posf][posc] = val;} // SET POR ELEMENTO
    T getFval(unsigned posf,unsigned posc){return tb[posf][posc];} // GET POR ELEMENTO
    T** getFichero(){return tb;} // GET TODO EL HORARIO
    virtual void displayFichero(){ //MOSTRAR EN PANTALLA
    cout << endl;for(int i = 0;i < fil;i++){for(int j = 0;j < col;j++){cout << tb[i][j] << " ";}cout << endl;}}
};