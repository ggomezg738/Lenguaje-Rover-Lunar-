#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//Valida si un caracter  es una letra valida.
bool letraValida(char ch) {
  if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch<= 'z'){
    return true;
  }
  return false;
}

int main() {
	
	//tipo de dato estados
    enum TEstado {q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12,q13,q14,q15,q16,q17,q18,q19,q20,q21,q22,q23,q24,q25,q26,q27,q28,q29,q30,q31,qe};

    //vaiable estados
    TEstado Estado = q0;
    
	//Guarda una palabra de varios caracteres concatenados.
    string palabra = "";
    
    //Contadores
	int identificadores = 0;
	
	int operadoresSuma = 0;
	int operadoresResta = 0;
	int operadoresMultiplicacion = 0;
	int operadoresDivision = 0;
	
    int llavesAbiertas = 0;
    int llavesCerradas = 0;
    int parentesisAbiertos = 0;
    int parentesisCerrados = 0;
    
    
    //Lectura del archivo
	fstream archivoEntrada;
	archivoEntrada.open("programa.txt", ios::in);
	if (!archivoEntrada) {
		cout << "No se encontro el archivo";
	} else {
		char ch; //Contiene el caracter actual.

		while (1) {
			archivoEntrada >> ch;
			
			if (archivoEntrada.eof())
				break;
			
			
			
			//Estados	
			switch (Estado){
            case q0:
                //si es un caracter valido
                if (letraValida(ch)){
                    Estado = q1;
					palabra += ch;
                }else{
					Estado = qe;
                	cout << "q0 -> Se esperaba una letra." << endl;
				}
                break;
            case q1:
                //si es un caracter valido
                if (letraValida(ch)){
                    Estado = q1;
					palabra += ch;
                } else if (ch == '{') { //si inicia el bloque.
                    Estado = q2;
					cout << "identificador primario: "<< palabra <<endl;
					palabra = ""; //vacia la palabra.
					
					llavesAbiertas++;	
                } else {
                	cout << "q1 -> Se esperaba una letra o {." << endl;
				}
                break;
			case q2:
				if (palabra.compare("var") == 0){ //Creacion de variable
					Estado = q3;
					cout<<palabra<<endl;
					palabra = "";
					palabra +=ch;
				} else if (letraValida(ch)){
                    Estado = q2;
					palabra += ch;
                }else{
					Estado = qe;
                	cout << "q2 -> Se esperaba una letra." << endl;
				}
                break;
            case q3:
				if (letraValida(ch)){
                    Estado = q3;
					palabra += ch;
				}else if(ch == '='){
					Estado = q4;
					identificadores++;
					cout<<palabra<<endl;
                }else{
					Estado = qe;
                	cout << "q3 -> Se esperaba una letra o =." << endl;
				}
            	break;
			}
			
			
		}

	}
	
	cout<< "Total llaves abiertas: " <<llavesAbiertas<<endl;
	archivoEntrada.close();
	return 0;
}



