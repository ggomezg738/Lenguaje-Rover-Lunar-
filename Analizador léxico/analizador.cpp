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

//Valida si el caracter es un digito valido.
bool digitoValido(char ch){
	if (ch >= '0' && ch <= '9'){
    	return true; 
	}
	return false;
}

int palabraReservadaBool(string tabla[2][30],string palabra,char ch){
	palabra += ch;
	if (palabra.compare(tabla[0][11])==0){ //Si es true
		return 1;
	}
	
	if (palabra.compare(tabla[0][12])==0){ //Si es false
		return 0;
	}
	
	return -1; // Si no es true ni false.
}

int compararPalabra(string enTabla,string palabra, char ch){
	palabra += ch;
	return palabra.compare(enTabla);
}



int main() {
	
	//tipo de dato estados
    enum TEstado {q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12,q13,q14,q15,q16,q17,q18,q19,q20,q21,q22,q23,q24,q25,q26,q27,q28,q29,q30,q31,qe};

    //vaiable estados
    TEstado Estado = q0;
    
    //Tabla de símbolos con las palabras reservadas y los identificadores
    //Donde los valores de tabla[0] serán las palabras reservadas y los de tabla[1]
    //serán los identificadores.
    string tabla[2][30]; 
    tabla [0][0] = "var";
    tabla [0][1] = "girar";
    tabla [0][2] = "tomarCaptura";
    tabla [0][3] = "retraer";
    tabla [0][4] = "extender";
    tabla [0][5] = "inclinar";
    tabla [0][6] = "girar";
	tabla [0][7] = "desplazar";
	tabla [0][8] = "repetirmientras";
	tabla [0][9] = "si";
	tabla [0][10] = "entonces";
	tabla [0][11] = "true";
	tabla [0][12] = "false";
	tabla [0][13] = "camara";
	tabla [0][14] = "pedestal";
	tabla [0][15] = "ruedaA";
	tabla [0][16] = "ruedaB";
	tabla [0][17] = "ruedaC";
	tabla [0][18] = "ruedaD";
	tabla [0][19] = "ruedaE";
	tabla [0][20] = "ruedaF";
	tabla [0][21] = "brazoA";
	tabla [0][22] = "brazoB";
	tabla [0][23] = "adelante";
	tabla [0][24] = "atras";
	tabla [0][25] = "derecha";
	tabla [0][26] = "izquierda";
    
	//Guarda una palabra de varios caracteres concatenados.
    string palabra = "";
    
    //Contadores
	int identificadores = 0;
	
	int palabrasReservadasVar = 0;
	int palabrasReservadasTrue = 0;
	int palabrasReservadasFalse = 0;
	
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
			
			if (archivoEntrada.eof()) //Llega al final del archivo
				break;
			
			
			//Estados	
			switch (Estado){
            case q0:
                //si es un caracter valido
                if (letraValida(ch)){
                    Estado = q1;
					palabra += ch;
					cout<<"q0->q1 "<<ch<<endl;
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
					cout<<"q1->q1 "<<ch<<endl;
                } else if (ch == '{') { //si inicia el bloque.
                    Estado = q2;
					cout << "identificador primario: "<< palabra <<endl;
					palabra = ""; //Limpia la palabra.
					cout<<"q1->q2 "<<ch<<endl;
					llavesAbiertas++;	
                } else {
                	cout << "q1 -> Se esperaba una letra o {." << endl;
				}
                break;
			case q2:
				if (letraValida(ch)){ //Creacion de variable
					Estado = q3;
					palabra +=ch;
					cout<<"q2->q3 "<<ch<<endl;
				} else if (ch == '}'){
                    //Estado = q61;
                }else{
					Estado = qe;
                	cout << "q2 -> Se esperaba una letra o }." << endl;
				}
                break;
            case q3:
            	if (compararPalabra(tabla[0][0],palabra,ch)==0){ // si se completa la palabra reservada var
            		Estado = q4;
            		palabra += ch;
            		cout<<"q3->q4 "<<ch<<endl;
            		cout<<"Declaracion de variable: "<<palabra<<endl;
					palabrasReservadasVar++;
					palabra = "";
				}else if(letraValida(ch)){
                    Estado = q3;
                    cout<<"q3->q3 "<<ch<<endl;
					palabra += ch;
				}else if(ch == '='){
					Estado = q6;
					cout<<"q3->q6 "<<ch<<endl;
					identificadores++;
					cout<< "Asignando valor a identificador: "<<palabra<<endl;
					palabra= "";
                }else{
					Estado = qe;
                	cout << "q3 -> Se esperaba una letra o =." << endl;
				}
            	break;
            case q4:
    			if (letraValida(ch)){
    				Estado = q5;
    				cout<<"q4->q5 "<<ch<<endl;
    				palabra += ch;
				}else{
					Estado = qe;
                	cout << "q4 -> Se esperaba una letra." << endl;
				}
            	break;
            case q5:
            	if (letraValida(ch)){
    				Estado = q5;
    				cout<<"q5->q5 "<<ch<<endl;
    				palabra += ch;	
				} else if(ch == '='){
					Estado = q6;
					cout<<"q5->q6 "<<ch<<endl;
					cout<< "Identificador creado: "<<palabra<<endl;
					palabra = "";
				} else if(ch == ';'){
					Estado = q2;
					cout << "Fin de linea."<<endl;
					palabra = "";
				} else {
					Estado = qe;
					cout << "q5 -> Se esperaba una letra o =." << endl;
				}
				break;
			case q6:
				if (digitoValido(ch)){
					Estado = q7;
					palabra += ch;
					cout<<"q6->q7 "<<ch<<endl;
				}else if(ch=='+'){
					Estado = q7;
					palabra += ch;
					operadoresSuma++;
				}else if(ch=='-'){
					Estado = q7;
					palabra += ch;
					operadoresResta++;
				}else if(letraValida(ch)){
					Estado = q10;
					palabra += ch;
					cout<<"q6->q10 "<<ch<<endl;
				}else{
					Estado = qe;
					cout << "q6 -> Se esperaba [<digito>,+,-,<letra>]" << endl;
				}
				break;
			case q7:
				if(digitoValido(ch)){
					Estado = q7;
					palabra += ch;
				} else if (ch == '.'){
					Estado = q8;
					palabra += ch;
					cout << "Numero decimal." << endl;
				} else if (ch == '+'){
					Estado = q6;
					cout << "Operación de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q6;
					cout << "Operación de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q6;
					cout << "Operación de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q6;
					cout << "Operación de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ';'){
					Estado = q2;
					cout << "Fin de linea, valor asignado: "<<palabra<<endl;
					palabra = "";
				} else {
					cout << "q7 -> Se esperaba [<digito>,+,-,*,/,;]" << endl;
				}
				break;
			case q8:
				if(digitoValido(ch)){
					Estado = q9;
					palabra += ch;
				} else {
					Estado = q3;
					cout << "q8 -> Se esperaba <digito>" << endl;
				}
				break;
			case q9:
				if(digitoValido(ch)){
					Estado = q9;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q6;
					cout << "Operación de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q6;
					cout << "Operación de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q6;
					cout << "Operación de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q6;
					cout << "Operación de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ';'){
					Estado = q2;
					cout << "q9 Fin de linea."<<palabra<<endl;
					palabra = "";
				} else {
					cout << "q9 -> Se esperaba [<digito>,+,-,*,/,;,.]" << endl;
				}
				break;
			case q10:
				if(palabraReservadaBool(tabla,palabra,ch)==1){ //Si es la palabra true
            		Estado = q11;
            		palabra += ch;
            		cout<<"q10->q11 Palabra reservada: "<<palabra<<endl;
					palabrasReservadasTrue++;
					palabra = "";	
				} else if(palabraReservadaBool(tabla,palabra,ch)==0){ //Si es la palbra false
					Estado = q11;
            		palabra += ch;
            		cout<<"q10->q11 Palabra reservada: "<<palabra<<endl;
					palabrasReservadasTrue++;
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q10;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q6;
					cout << "Operación de suma al identificador: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q6;
					cout << "Operación de resta al identificador: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q6;
					cout << "Operación de multiplicacion al identificador: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q6;
					cout << "Operación de division al identificador: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ';'){
					Estado = q2;
					cout << "Fin de linea."<<palabra<<endl;
					palabra = "";
				} else {
					cout << "q10 -> Se esperaba [<letra>,+,-,*,/,;]" << endl;
				}
				break;
			case q11:
				if (ch == ';'){
					Estado = q2;
					cout << "Fin de linea."<<endl;
					palabra = "";
				} else {
					cout << "q11 -> Se esperaba [;]" << endl;
				}
				break;
			case q12:
				if (ch == ';'){
					Estado = q2;
					cout << "Fin de linea."<<endl;
					palabra = "";
				} else {
					cout << "q12 -> Se esperaba [;]" << endl;
				}
				break;
			case q13:
				if (ch == '('){
					Estado = q14;
					cout << "Parentesis abierto."<<endl;
					parentesisAbiertos++;
					palabra = "";
				} else {
					cout << "q13 -> Se esperaba [(]" << endl;
				}
				break;
			case q14:
				if (digitoValido(ch)){
					Estado = q15;
					palabra += ch;
				}else if(ch=='+'){
					Estado = q15;
					palabra += ch;
					operadoresSuma++;
				}else if(ch=='-'){
					Estado = q15;
					palabra += ch;
					operadoresResta++;
				}else if(letraValida(ch)){
					Estado = q24;
					palabra += ch;
				}else{
					Estado = qe;
					cout << "q14 -> Se esperaba [<digito>,+,-,<letra>]" << endl;
				}
				break;								
			}	
		}

	}
	
	cout<< "Total llaves abiertas: " <<llavesAbiertas<<endl;
	cout<< "Total identificadores: " <<llavesAbiertas<<endl;
	
	archivoEntrada.close();
	return 0;
}



