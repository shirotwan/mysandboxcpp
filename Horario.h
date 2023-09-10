#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <locale>
using namespace std;
template <class T> class Horario{
private:
    unsigned fil,col,sp = 0; // VARIABLES DE TAMAÑO
    T*** lst =  NULL; // EL HORARIO
    virtual void initH(){ // GENERADOR DE MATRIZ 3X
        lst = new T**[fil];
        for(int i = 0; i < fil; i++){lst[i] = new T*[col]; for(int j = 0;j < col;j++)lst[i][j] = new T[sp];}}
public:
    Horario(unsigned fil,unsigned col,unsigned sp):fil(fil),col(col),sp(sp){initH();} // CONSTRUCTOR
    ~Horario(){delete lst; fil = col = sp = 0;} // DESTRUCTOR
    virtual void setHval(unsigned posf,unsigned posc,unsigned poss,T val){lst[posf][posc][poss] = val;} // SET POR ELEMENTO
    T getHval(unsigned posf,unsigned posc,unsigned poss){return lst[posf][posc][poss];} // GET POR ELEMENTO
    T*** getHorario(){return lst;} // GET TODO EL HORARIO
    virtual void displayHorario(){ //MOSTRAR EN PANTALLA
    cout << endl;for(int i = 0;i < fil;i++){for(int j = 0;j < col;j++){for(int k = 0;k < sp;k++){cout << lst[i][j][k] << " ";}cout << endl;}cout << endl;}}
};