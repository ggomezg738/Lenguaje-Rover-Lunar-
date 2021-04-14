#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

	string lista[50][2];

	int n=1;
	int m=0;

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

//Verifica si la siguiente palabra será de tipo booleano (true o false)
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

//Compara la siguiente palabra con otra.
int compararPalabra(string enTabla,string palabra, char ch){
	palabra += ch;
	return palabra.compare(enTabla);
}

//Verifica si la siguiente palabra es una palabra reservada.
int esReservada(string tabla[2][30],string palabra,char ch){
	palabra += ch;
	int result = -1;
	for (int i = 0; i <=30; i++){
		result = tabla[0][i].compare(palabra);
		if (result == 0){
			return 0;
		}
	}
	return -1;
}
//Verifica si una palabra es una palabra reservada.
int esReservada(string tabla[2][30],string palabra){
	int result = -1;
	for (int i = 0; i <=30; i++){
		result = tabla[0][i].compare(palabra);
		if (result == 0){
			return 0;
		}
	}
	return -1;
}
//Verifica si la siguiente palabra es un identificador ya creado.
int esIdentificador(string tabla[2][30],string palabra,char ch){
	palabra += ch;
	int result = -1;
	for (int i = 0; i <=30; i++){
		result = tabla[1][i].compare(palabra);
		if (result == 0){
			return 0;
		}
	}
	return -1;
}
//Verifica si una palabra es un identificador ya creado.
int esIdentificador(string tabla[2][30],string palabra){
	int result = -1;
	for (int i = 0; i <=30; i++){
		result = tabla[1][i].compare(palabra);
		if (result == 0){
			return 0;
		}
	}
	return -1;
}

int esDireccion(string tabla[2][30],string palabra,char ch){
	palabra += ch;
	int result = -1;
	for (int i = 23; i <=26; i++){
		result = tabla[0][i].compare(palabra);
		if (result == 0){
			return 0;
		}
	}
	return -1;
}

int esParte(string tabla[2][30],string palabra,char ch){
	palabra += ch;
	int result = -1;
	for (int i = 13; i <=22; i++){
		result = tabla[0][i].compare(palabra);
		if (result == 0){
			return 0;
		}
	}
	return -1;
}

int esParteMovimiento(string tabla[2][30],string palabra,char ch){
	palabra += ch;
	int result = -1;
	for (int i = 15; i <=22; i++){
		result = tabla[0][i].compare(palabra);
		if (result == 0){
			return 0;
		}
	}
	return -1;
}


		
	void IngresoIdentificador(string palabra){
		if(n>=49){
			cout<<"Sin espacio.";
		} else{
			lista[n][0]=palabra;
			n++;
		}
	}
	
	void IngresoTipo(string palabra){
		lista[n][1]=palabra;
	}
	
	void IngresoPalabraReservada(string palabra){
		IngresoIdentificador(palabra);
		palabra="Palabra reservada";
		IngresoTipo(palabra);
	}
	
	void MostrarLista(){
		for(int i=0; i<50; i++){
			cout<<endl;
			for(int j=0; j<2; j++){
				cout<<"      "<<lista[i][j]<<"     ";
			}
		}
	}	
	
		
		
	




int main() {
	
	//Tipo de dato estados.
	//El estado qe significa que resivio un caracter incorrecto y paso a estado de error.
	//El estado q70 es el estado final.
    enum TEstado {q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12,q13,q14,q15,q16,q17,q18,q19,q20,q21,q22,q23,q24,q25,q26,q27,q28,q29,q30,q31,q32,q33,q34,q35,q36,q37,q38a,q38b,q39,q40,q41,q42,q43,q44,q45,q46,q47,q48,q49,q50,q51,q52,q53,q54,q55,q56,q57a,q57b,q58,q59,q60,q61,q62,q63,q64,q65,q66,q67,q68,q69,q70,qe};

    //vaiable estados
    TEstado Estado = q0;
    
    lista[0][0]="Identificadores";
	lista[0][1]="Tipo";
    
    //Tabla de s�mbolos con las palabras reservadas y los identificadores
    //Donde los valores de tabla[0] ser�n las palabras reservadas y los de tabla[1]
    //ser�n los identificadores.
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
	int identificadores = 0; //Para las variables definidas.
	
	//int palabrasReservadasVar = 0;
	//int palabrasReservadasTrue = 0;
	//int palabrasReservadasFalse = 0;
	
	int operadoresSuma = 0;
	int operadoresResta = 0;
	int operadoresMultiplicacion = 0;
	int operadoresDivision = 0;
	
	int signoMenor = 0;
	int signoMayor = 0;
	int signoIgual = 0;

	int signoAdmiracion = 0;

	int punto = 0;
	int puntoComa = 0;
	int coma = 0;
	
    int llavesAbiertas = 0;
    int llavesCerradas = 0;
    int parentesisAbiertos = 0;
    int parentesisCerrados = 0;
    
    
    
    //Lectura del archivo
	fstream archivoEntrada;
	archivoEntrada.open("entrada.txt", ios::in);
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
					cout<<"q0->q1: "<<ch<<endl;
                }else{
					Estado = qe;
                	cout << "q0 ->qe: " <<ch<< endl;
				}
                break;
            case q1:
                //si es un caracter valido
                if (letraValida(ch)){
                    Estado = q1;
					palabra += ch;
                } else if (ch == '{' && esReservada(tabla, palabra) != 0) { //si inicia el bloque.
                    Estado = q2;
					cout << "identificador primario: "<< palabra <<endl;
					tabla[1][identificadores] = palabra;
					IngresoIdentificador(palabra);
					identificadores++;
					palabra = ""; //Limpia la palabra.
					cout<<"q1->q2: "<<ch<<endl;
					llavesAbiertas++;	
                } else {
                	Estado = qe;
                	cout << "q1 ->qe: " <<ch<< endl;
				}
                break;
			case q2:
				if (letraValida(ch)){ //Creacion de variable
					Estado = q3;
					palabra +=ch;
					cout<<"q2->q3: "<<ch<<endl;
				} else if (ch == '}'){
                    Estado = q69;
					cout<<"q2->q69: "<<ch<<endl;
					llavesCerradas++;
                }else{
					Estado = qe;
                	cout << "q2 -> qe Se esperaba una letra o }." << endl;
				}
                break;
            case q3:
            	if (compararPalabra(tabla[0][0],palabra,ch)==0){ // si se completa la palabra reservada var
            		Estado = q4;
            		palabra += ch;
            		cout<<"q3->q4: "<<palabra<<" Declaracion de variable."<<endl;
					IngresoTipo(palabra);
					palabra = "";
				}else if(compararPalabra(tabla[0][1],palabra,ch)==0){ // girar
					Estado = q59;
            		palabra += ch;
            		cout<<"q3->q59: "<<palabra<<" Palabra reservada."<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				}else if(compararPalabra(tabla[0][2],palabra,ch)==0){ // tomarCaptura
					Estado = q12;
            		palabra += ch;
            		cout<<"q3->q12: "<<palabra<<" Palabra reservada."<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				}else if(compararPalabra(tabla[0][3],palabra,ch)==0 || compararPalabra(tabla[0][4],palabra,ch)==0){ //retraer o extender
					Estado = q43;
            		palabra += ch;
            		cout<<"q3->q43: "<<palabra<<" Palabra reservada."<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				}else if(compararPalabra(tabla[0][5],palabra,ch)==0){ // inclinar
					Estado = q53;
            		palabra += ch;
            		cout<<"q3->q53: "<<palabra<<" Palabra reservada."<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				}else if(compararPalabra(tabla[0][6],palabra,ch)==0){ // girar
					Estado = q59;
            		palabra += ch;
            		cout<<"q3->q59: "<<palabra<<" Palabra reservada."<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				}else if(compararPalabra(tabla[0][7],palabra,ch)==0){ // desplazar
					Estado = q63;
            		palabra += ch;
            		cout<<"q3->q63: "<<palabra<<" Palabra reservada."<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				}else if(compararPalabra(tabla[0][8],palabra,ch)==0){ // repetirmientras
					Estado = q13;
            		palabra += ch;
            		cout<<"q3->q13: "<<palabra<<" Palabra reservada."<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				}else if(compararPalabra(tabla[0][9],palabra,ch)==0){ // si
					Estado = q28;
            		palabra += ch;
            		cout<<"q3->q28: "<<palabra<<" Palabra reservada."<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";																
				}else if(letraValida(ch)){
                    Estado = q3;
					palabra += ch;
				}else if(ch == '='){
					if(esIdentificador(tabla,palabra)==0){ //Si es un identificador valido.
						Estado = q6;
						cout<<"q3->q6: "<<ch<<endl;
						cout<<"Asignando valor al identificador: "<<palabra<<endl;
						signoIgual++;
					} else {
						Estado = qe;
                		cout << "q3 -> qe: "<<palabra<<" No esta definido." <<endl;
					}
					palabra= "";
                }else{
					Estado = qe;
                	cout << "q3 -> qe Se esperaba una letra o =. "<<ch<< endl;
				}
            	break;
            case q4:
    			if (letraValida(ch)){
    				Estado = q5;
    				cout<<"q4->q5: "<<ch<<endl;
    				palabra += ch;
				}else{
					Estado = qe;
                	cout << "q4 -> qe Se esperaba una letra." <<ch<< endl;
				}
            	break;
            case q5:
            	if (letraValida(ch)){
    				Estado = q5;
    				palabra += ch;	
				} else if(ch == '='){
					if (esIdentificador(tabla,palabra)!=0 && esReservada(tabla,palabra)==-1){
						Estado = q6;
						cout<<"q5->q6 Identificador creado:"<<palabra<<endl;
						tabla[1][identificadores] = palabra;
						IngresoIdentificador(palabra);
						identificadores++;
						signoIgual++;
					} else {
						Estado = qe;
						cout << "q5 ->qe ya existe un identificador: "<<palabra<< endl;
					}
					palabra = "";
				} else if(ch == ';'){
					if (esIdentificador(tabla,palabra)!=0 && esReservada(tabla,palabra)==-1){
						Estado = q2;
						cout<<"q5->q6 Identificador creado:"<<palabra<<endl;
						cout << "Fin de linea."<<endl;
						tabla[1][identificadores] = palabra;
						identificadores++;
						puntoComa++;
					} else {
						Estado = qe;
						cout << "q5 ->qe ya existe un identificador: "<<palabra<< endl;
					}
					palabra = "";
				} else {
					Estado = qe;
					cout << "q5 -> qe Se esperaba una letra o =. " <<ch << endl;
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
					cout << "q6 -> qe Se esperaba [<digito>,+,-,<letra>] "<<ch << endl;
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
					punto++;
				} else if (ch == '+'){
					Estado = q6;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q6;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q6;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q6;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ';'){
					Estado = q2;
					cout << "Fin de linea, valor asignado: "<<palabra<<endl;
					palabra = "";
					puntoComa++;
				} else {
					Estado = qe;
					cout << "q7 -> qe Se esperaba [<digito>,+,-,*,/,;]"<<ch << endl;
				}
				break;
			case q8:
				if(digitoValido(ch)){
					Estado = q9;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q8 -> qe Se esperaba <digito>" <<ch<< endl;
				}
				break;
			case q9:
				if(digitoValido(ch)){
					Estado = q9;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q6;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q6;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q6;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q6;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ';'){
					Estado = q2;
					cout << "q9 Fin de linea. "<<palabra<<endl;
					palabra = "";
					puntoComa++;
				} else {
					Estado = qe;
					cout << "q9 -> qe Se esperaba [<digito>,+,-,*,/,;,.] "<<ch << endl;
				}
				break;
			case q10:
				if(palabraReservadaBool(tabla,palabra,ch)==1){ //Si es la palabra true
            		Estado = q11;
            		palabra += ch;
            		cout<<"q10->q11 Palabra reservada: "<<palabra<<endl;
					IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(palabraReservadaBool(tabla,palabra,ch)==0){ //Si es la palbra false
					Estado = q11;
            		palabra += ch;
            		cout<<"q10->q11 Palabra reservada: "<<palabra<<endl;
					IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q10;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q6;
					cout << "Operacion de suma al identificador: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q6;
					cout << "Operacion de resta al identificador: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q6;
					cout << "Operacion de multiplicacion al identificador: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q6;
					cout << "Operacion de division al identificador: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ';'){
					if(esReservada(tabla,palabra)!=0){
						Estado = q2;
						cout << "q10 Fin de linea. "<<palabra<<endl;
						puntoComa++;
					}else{
						Estado  = qe;
						cout<< "q10 -> qe: "<<palabra<<" Es una palabra reservada."<<endl;
					}
					
					palabra = "";
				} else {
					Estado = qe;
					cout << "q10 ->qe Se esperaba [<letra>,+,-,*,/,;]" <<ch<< endl;
				}
				break;
			case q11:
				if (ch == ';'){
					Estado = q2;
					cout << "q11 Fin de linea."<<endl;
					palabra = "";
					puntoComa++;
				} else {
					Estado = qe;
					cout << "q11 -> qe Se esperaba [;]" <<ch<< endl;
				}
				break;
			case q12:
				if (ch == ';'){
					Estado = q2;
					cout << "q12 Fin de linea."<<endl;
					palabra = "";
					puntoComa++;
				} else {
					Estado = qe;
					cout << "q12 -> qe Se esperaba [;]" <<ch<< endl;
				}
				break;
			case q13:
				if (ch == '('){
					Estado = q14;
					cout << "q13 -> q14 Parentesis abierto."<<endl;
					parentesisAbiertos++;
					palabra = "";
				} else {
					Estado = qe;
					cout << "q13 -> qe Se esperaba [(]" <<ch<< endl;
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
			case q15:
				if(digitoValido(ch)){
					Estado = q15;
					palabra += ch;
				} else if (ch == '.'){
					Estado = q16;
					palabra += ch;
					cout << "Numero decimal." << endl;
					punto++;
				} else if (ch == '+'){
					Estado = q14;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q14;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q14;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q14;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == '=' || ch == '!'){
					Estado = q18;
					cout << "q15 Inicio de operador booleano despues de: "<<palabra<<endl;
					palabra = "";
					palabra += ch;
					if (ch == '='){
						signoIgual++;
					} else {
						signoAdmiracion++;
					}
					
				} else if (ch == '<' || ch == '>'){
					Estado = q25;
					cout << "q15 Inicio de operador booleano despues de: "<<palabra<<endl;
					palabra = "";
					palabra += ch;
					if (ch == '<'){
						signoMenor++;
					} else {
						signoMayor++;
					}
				} else {
					Estado = qe;
					cout << "q15 -> qe: "<<ch<<endl;
				}
				break;
			case q16:
				if(digitoValido(ch)){
					Estado = q17;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q16 -> qe Se esperaba <digito>" <<ch<< endl;
				}				
				break;
			case q17:
				if(digitoValido(ch)){
					Estado = q17;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q14;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q14;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q14;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q14;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == '=' || ch == '!'){
					Estado = q18;
					cout << "q17 Inicio de operador booleano despues de: "<<palabra<<endl;
					palabra = "";
					palabra += ch;
					if (ch == '='){
						signoIgual++;
					} else {
						signoAdmiracion++;
					}
				} else if (ch == '<' || ch == '>'){
					Estado = q25;
					cout << "q17 Inicio de operador booleano despues de: "<<palabra<<endl;
					palabra = "";
					palabra += ch;
					if (ch == '<'){
						signoMenor++;
					} else {
						signoMayor++;
					}
				} else {
					Estado = qe;
					cout << "q17 -> qe: "<<ch<<endl;
				}				
				break;
			case q18:
				if (ch == '='){
					Estado = q19;
					palabra += ch;
					cout << "q18 -> q19 Operador booleano: "<<palabra<<endl;
					palabra = "";
					signoIgual++;
				}else{
					Estado = qe;
					cout << "q18 -> qe: "<<ch<<endl;
				}
				break;
			case q19:
				if (digitoValido(ch)){
					Estado = q20;
					palabra += ch;
				}else if(ch=='+'){
					Estado = q20;
					palabra += ch;
					operadoresSuma++;
				}else if(ch=='-'){
					Estado = q20;
					palabra += ch;
					operadoresResta++;
				}else if(letraValida(ch)){
					Estado = q26;
					palabra += ch;
				}else{
					Estado = qe;
					cout << "q19 -> qe: " <<ch<< endl;
				}
				break;
			case q20:
				if(digitoValido(ch)){
					Estado = q20;
					palabra += ch;
				} else if (ch == '.'){
					Estado = q21;
					palabra += ch;
					cout << "Numero decimal." << endl;
					punto++;
				} else if (ch == '+'){
					Estado = q19;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q19;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q19;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q19;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ')'){
					Estado = q23;
					cout << "q20 -> q23 Cierre de parentesis: "<<palabra<<endl;
					palabra = "";
					parentesisCerrados++;
				} else {
					Estado = qe;
					cout << "q20 -> qe: "<<ch<<endl;
				}
				break;
			case q21:
				if(digitoValido(ch)){
					Estado = q22;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q21 -> qe: "<<ch<<endl;
				}	
				break;
			case q22:
				if(digitoValido(ch)){
					Estado = q22;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q19;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q19;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q19;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q19;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ')'){
					Estado = q23;
					cout << "q22 -> q23 Cierre de parentesis: "<<ch<<endl;
					palabra = "";
					parentesisCerrados++;
				} else {
					Estado = qe;
					cout << "q22 -> qe: "<<ch<<endl;
				}
				break;
			case q23:
				if(ch=='{'){
					Estado = q2;
					cout<< "q23 -> q2: inicio de bloque: "<<ch<<endl;
					palabra = "";
					llavesAbiertas++;  
				}else {
					Estado = qe;
					cout << "q23 -> qe: "<<ch<<endl;
				}
				break;
			case q24:
				if(palabraReservadaBool(tabla,palabra,ch)==1){ //Si es la palabra true
            		Estado = q27;
            		palabra += ch;
            		cout<<"q24->q27 Palabra reservada: "<<palabra<<endl;
					IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(palabraReservadaBool(tabla,palabra,ch)==0){ //Si es la palbra false
					Estado = q27;
            		palabra += ch;
            		cout<<"q10->q11 Palabra reservada: "<<palabra<<endl;
					IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q24;
					palabra += ch;
				} else if (esReservada(tabla,palabra) != 0){
					if (ch == '+'){
						Estado = q14;
						cout << "Operacion de suma a: "<<palabra<<endl;
						palabra = "";
						operadoresSuma++;
					} else if (ch == '-'){
						Estado = q14;
						cout << "Operacion de resta a: "<<palabra<<endl;
						palabra = "";
						operadoresResta++;
					} else if (ch == '*'){
						Estado = q14;
						cout << "Operacion de multiplicacion a: "<<palabra<<endl;
						palabra = "";
						operadoresMultiplicacion++;
					} else if (ch == '/'){					
						Estado = q14;
						cout << "Operacion de division a: "<<palabra<<endl;
						palabra = "";
						operadoresDivision++;
					} else if (ch == '=' || ch == '!'){
						Estado = q18;
						cout << "q24 -> q18 Inicio de operador booleano " <<ch<< " despues de: "<<palabra<<endl;
						palabra = "";
						palabra += ch;
						if (ch == '='){
							signoIgual++;
						} else {
							signoAdmiracion++;
						}
					} else if (ch == '<' || ch == '>'){
						Estado = q25;
						cout << "q24 -> q18 Inicio de operador booleano " <<ch<< " despues de: "<<palabra<<endl;
						palabra = "";
						palabra += ch;
						if (ch == '<'){
						signoMenor++;
						} else {
							signoMayor++;
						}
					} else {
						
					}
				} else if (esReservada(tabla,palabra) == 0){
					Estado = qe;
					cout << "q24 -> qe: " <<palabra<<" Es una palabra reservada."<< endl;
				} else {
					Estado = qe;
					cout << "q24 -> qe Se esperaba [<letra>,+,-,*,/,;]" << endl;
				}
				break;
			case q25:
				if (digitoValido(ch)){
					Estado = q20;
					cout<<"q25 -> q20: "<<ch<<endl;
					palabra += ch;
				} else if(ch=='+'){
					Estado = q20;
					cout<<"q25 -> q20: "<<ch<<endl;
					palabra += ch;
					operadoresSuma++;
				}else if(ch=='-'){
					Estado = q20;
					cout<<"q25 -> q20: "<<ch<<endl;
					palabra += ch;
					operadoresResta++;
				} else if (letraValida(ch)){
					Estado = q26;
					palabra += ch;
					cout<<"q25 -> q26: "<<ch<<endl;
				}else{
					Estado = qe;
					cout<<"q25 -> qe: se esperaba una letra."<<ch<<endl;
				}
				break;
			case q26:	
				if(letraValida(ch)){
					Estado = q26;
					palabra += ch;
				} else if (esReservada(tabla,palabra) != 0){
					if (ch == ')'){
						Estado = q23;
						cout<<"q26 -> q23: "<<ch<<endl;
						parentesisCerrados++;
						palabra = "";
					} else if (ch == '+'){
						Estado = q19;
						cout << "Operacion de suma a: "<<palabra<<endl;
						palabra = "";
						operadoresSuma++;
					} else if (ch == '-'){
						Estado = q19;
						cout << "Operacion de resta a: "<<palabra<<endl;
						palabra = "";
						operadoresResta++;
					} else if (ch == '*'){
						Estado = q19;
						cout << "Operacion de multiplicacion a: "<<palabra<<endl;
						palabra = "";
						operadoresMultiplicacion++;
					} else if (ch == '/'){					
						Estado = q19;
						cout << "Operacion de division a: "<<palabra<<endl;
						palabra = "";
						operadoresDivision++;
					} else {
						
					}					
				} else if (esReservada(tabla,palabra) == 0){
					Estado = qe;
					cout << "q26 -> qe: " <<palabra<<" Es una palabra reservada."<< endl;
				} else {
					Estado = qe;
					cout << "q26 -> qe Se esperaba [<letra>,+,-,*,/,;]" << endl;
				}
				break;
			case q27:
				if (ch == '('){
					Estado = q23;
					cout<<"q27 -> q23: "<<ch<<endl;
					parentesisCerrados++;
					palabra = "";					
				}else{
					Estado = qe;
					cout << "q27 -> qe:" <<ch<< endl;
				}
				break;
			case q28:
				if (ch == '('){
					Estado = q29;
					cout << "q28 Parentesis abierto."<<endl;
					parentesisAbiertos++;
					palabra = "";
				} else {
					Estado = qe;
					cout << "q28 -> qe Se esperaba [(]" <<ch<< endl;
				}				
				break;
			case q29:
				if (digitoValido(ch)){
					Estado = q30;
					palabra += ch;
				}else if(ch=='+'){
					Estado = q30;
					palabra += ch;
					operadoresSuma++;
				}else if(ch=='-'){
					Estado = q30;
					palabra += ch;
					operadoresResta++;
				}else if(letraValida(ch)){
					Estado = q39;
					palabra += ch;
				}else{
					Estado = qe;
					cout << "q29 -> qe Se esperaba [<digito>,+,-,<letra>]" <<ch<< endl;
				}				
				break;
			case q30:
				if(digitoValido(ch)){
					Estado = q30;
					palabra += ch;
				} else if (ch == '.'){
					Estado = q31;
					palabra += ch;
					cout << "Numero decimal." << endl;
					punto++;
				} else if (ch == '+'){
					Estado = q29;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q29;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q29;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q29;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == '=' || ch == '!'){
					Estado = q33;
					cout << "q30 Inicio de operador booleano despues de: "<<palabra<<endl;
					palabra = "";
					palabra += ch;
					if (ch == '='){
						signoIgual++;
					} else {
						signoAdmiracion++;
					}
				} else if (ch == '<' || ch == '>'){
					Estado = q40;
					cout << "q30 Inicio de operador booleano despues de: "<<palabra<<endl;
					palabra = "";
					palabra += ch;
					if (ch == '<'){
						signoMenor++;
					} else {
						signoMayor++;
					}
				} else {
					Estado = qe;
					cout << "q30 -> qe: "<<ch<<endl;
				}
				break;
			case q31:
				if(digitoValido(ch)){
					Estado = q32;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q31 -> qe Se esperaba <digito>" <<ch<< endl;
				}
				break;
			case q32:
				if(digitoValido(ch)){
					Estado = q32;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q29;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q29;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q29;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q29;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == '=' || ch == '!'){
					Estado = q33;
					cout << "q32 Inicio de operador booleano despues de: "<<palabra<<endl;
					palabra = "";
					palabra += ch;
					if (ch == '='){
						signoIgual++;
					} else {
						signoAdmiracion++;
					}
				} else if (ch == '<' || ch == '>'){
					Estado = q40;
					cout << "q32 Inicio de operador booleano despues de: "<<palabra<<endl;
					palabra = "";
					palabra += ch;
					if (ch == '<'){
						signoMenor++;
					} else {
						signoMayor++;
					}
				} else {
					Estado = qe;
					cout << "q32 -> qe: "<<ch<<endl;
				}
				break;
			case q33:
				if (ch == '='){
					Estado = q34;
					palabra += ch;
					cout << "q33 -> q34 Operador booleano: "<<palabra<<endl;
					palabra = "";
					signoIgual++;
				}else{
					Estado = qe;
					cout << "q33 -> qe: "<<ch<<endl;
				}
				break;
			case q34:
				if (digitoValido(ch)){
					Estado = q35;
					palabra += ch;
				}else if(ch=='+'){
					Estado = q35;
					palabra += ch;
					operadoresSuma++;
				}else if(ch=='-'){
					Estado = q35;
					palabra += ch;
					operadoresResta++;
				}else if(letraValida(ch)){
					Estado = q42;
					palabra += ch;
				}else{
					Estado = qe;
					cout << "q34 -> qe: " <<ch<< endl;
				}
				break;	
			case q35:
				if(digitoValido(ch)){
					Estado = q35;
					palabra += ch;
				} else if (ch == '.'){
					Estado = q36;
					palabra += ch;
					cout << "Numero decimal." << endl;
					punto++;
				} else if (ch == '+'){
					Estado = q34;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q34;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q34;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q34;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ')'){
					Estado = q38a;
					cout << "q35 -> q38 Cierre de parentesis: "<<palabra<<endl;
					palabra = "";
					parentesisCerrados++;
				} else {
					Estado = qe;
					cout << "q35 -> qe: "<<ch<<endl;
				}
				break;			
			case q36:
				if(digitoValido(ch)){
					Estado = q37;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q36 -> qe: "<<ch<<endl;
				}	
				break;
			case q37:
				if(digitoValido(ch)){
					Estado = q37;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q34;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q34;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q34;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q34;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ')'){
					Estado = q38a;
					cout << "q37 -> q38 Cierre de parentesis: "<<ch<<endl;
					palabra = "";
					parentesisCerrados++;
				} else {
					Estado = qe;
					cout << "q37 -> qe: "<<ch<<endl;
				}
				break;
			case q38a:
				if (letraValida(ch)){
    				Estado = q38b;
    				cout<<"q38a->q38b: "<<ch<<endl;
    				palabra += ch;
				}else{
					Estado = qe;
                	cout << "q38a -> qe Se esperaba una letra." <<ch<< endl;
				}
				break;
			case q38b:
				if (compararPalabra(tabla[0][10],palabra,ch)==0){
					Estado = q23;
					palabra += ch;
					cout<<"q38 -> q23: palabra reservada "<<palabra<<endl;
					palabra = "";
				} else if (letraValida(ch)){
    				Estado = q38b;
    				palabra += ch;
				}else{
					Estado = qe;
                	cout << "q38a -> qe Se palabra reservada <entonces>" <<ch<< endl;
				}
				break;
			case q39:
				if(compararPalabra(tabla[0][14],palabra,ch)==0){ //Si es la palabra reservada 'pedestal'
            		Estado = q41;
            		palabra += ch;
            		cout<<"q39->q41 Palabra reservada: "<<palabra<<endl;
					
					IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(palabraReservadaBool(tabla,palabra,ch)==0){ //Si es la palbra false
					Estado = q41;
            		palabra += ch;
            		cout<<"q39->q41 Palabra reservada: "<<palabra<<endl;
					
					IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q39;
					palabra += ch;
				} else if (esReservada(tabla,palabra) != 0){
					if (ch == '+'){
						Estado = q29;
						cout << "Operacion de suma a: "<<palabra<<endl;
						palabra = "";
						operadoresSuma++;
					} else if (ch == '-'){
						Estado = q29;
						cout << "Operacion de resta a: "<<palabra<<endl;
						palabra = "";
						operadoresResta++;
					} else if (ch == '*'){
						Estado = q29;
						cout << "Operacion de multiplicacion a: "<<palabra<<endl;
						palabra = "";
						operadoresMultiplicacion++;
					} else if (ch == '/'){					
						Estado = q29;
						cout << "Operacion de division a: "<<palabra<<endl;
						palabra = "";
						operadoresDivision++;
					} else if (ch == '=' || ch == '!'){
						Estado = q33;
						cout << "q39->q33 Inicio de operador booleano despues de: "<<palabra<<endl;
						palabra = "";
						palabra += ch;
						if (ch == '='){
							signoIgual++;
						} else {
							signoAdmiracion++;
						}
					} else if (ch == '<' || ch == '>'){
						Estado = q40;
						cout << "q39->q40 Inicio de operador booleano despues de: "<<palabra<<endl;
						palabra = "";
						palabra += ch;
						if (ch == '<'){
							signoMenor++;
						} else {
							signoMayor++;
						}
					} else {
						
					}
				} else if (esReservada(tabla,palabra) == 0){
					Estado = qe;
					cout << "q39 -> qe: " <<palabra<<" Es una palabra reservada."<< endl;
				} else {
					Estado = qe;
					cout << "q39 -> qe Se esperaba [<letra>,+,-,*,/,;]" << endl;
				}
				break;
			case q40:
				if (letraValida(ch)){
					Estado = q42;
					palabra += ch;
					cout<<"q40 -> q42: "<<ch<<endl;
				}else{
					Estado = qe;
					cout<<"q40 -> qe: se esperaba una letra."<<ch<<endl;
				}
				break;
			case q41:
				if (ch == '('){
					Estado = q23;
					cout<<"q41 -> q38: "<<ch<<endl;
					parentesisCerrados++;
					palabra = "";					
				}else{
					Estado = qe;
					cout << "q41 -> qe:" <<ch<< endl;
				}
				break;
			case q42:
				if(letraValida(ch)){
					Estado = q42;
					palabra += ch;
				} else if (esReservada(tabla,palabra) != 0){
					if (ch == ')'){
						Estado = q38a;
						cout<<"q42 -> q23: "<<ch<<endl;
						parentesisCerrados++;
						palabra = "";
					} else if (ch == '+'){
						Estado = q34;
						cout << "Operacion de suma a: "<<palabra<<endl;
						palabra = "";
						operadoresSuma++;
					} else if (ch == '-'){
						Estado = q34;
						cout << "Operacion de resta a: "<<palabra<<endl;
						palabra = "";
						operadoresResta++;
					} else if (ch == '*'){
						Estado = q34;
						cout << "Operacion de multiplicacion a: "<<palabra<<endl;
						palabra = "";
						operadoresMultiplicacion++;
					} else if (ch == '/'){					
						Estado = q34;
						cout << "Operacion de division a: "<<palabra<<endl;
						palabra = "";
						operadoresDivision++;
					} else {
						
					}					
				} else if (esReservada(tabla,palabra) == 0){
					Estado = qe;
					cout << "q42 -> qe: " <<palabra<<" Es una palabra reservada."<< endl;
				} else {
					Estado = qe;
					cout << "q42 -> qe Se esperaba [<letra>,+,-,*,/,;]" << endl;
				}
				break;
			case q43:
				if (ch == '('){
					Estado = q44;
					cout<<"q43 -> q44 parentesis abiertos "<<ch<<endl,
					parentesisAbiertos++;
					palabra = "";
				}else{
					Estado = qe;
					cout<<"q43 -> qe: "<<ch<<endl;
				}
				break;
			case q44:
				if (letraValida(ch)){
					Estado = q45;
					cout << "q44 -> q45"<<endl;
					palabra += ch;
				}else{
					Estado = qe;
					cout<<"q44 -> qe: "<<ch<<endl;
				}
				break;
			case q45:
				if(compararPalabra(tabla[0][14],palabra,ch)==0){ //Si es la palabra reservada 'pedestal'.
            		Estado = q46;
            		palabra += ch;
            		cout<<"q45->q46 Palabra reservada: "<<palabra<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q45;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q45 ->qe: " <<ch<< endl;
				}
				break;
			case q46:
				if (ch == ','){
					Estado = q47;
					cout<<"q46->q47: "<<ch<<endl;
					coma++;
				} else {
					Estado = qe;
					cout << "q46 ->qe: " <<ch<< endl;
				}
				break;
			case q47:
				if (digitoValido(ch)){
					Estado = q48;
					palabra += ch;
					cout<<"q47->q48: "<<ch<<endl;
				}else if(ch=='+'){
					Estado = q48;
					palabra += ch;
					cout<<"q47->q48: "<<ch<<endl;
					operadoresSuma++;
				}else if(ch=='-'){
					Estado = q48;
					palabra += ch;
					cout<<"q47->q48: "<<ch<<endl;
					operadoresResta++;
				}else if(letraValida(ch)){
					Estado = q52;
					palabra += ch;
					cout<<"q47->q52: "<<ch<<endl;
				}else{
					Estado = qe;
					cout << "q47 -> qe Se esperaba [<digito>,+,-,<letra>] "<<ch << endl;
				}
				break;
			case q48:
				if(digitoValido(ch)){
					Estado = q48;
					palabra += ch;
				} else if (ch == '.'){
					Estado = q49;
					palabra += ch;
					cout << "q48 -> q49 Numero decimal." << endl;
					punto++;
				} else if (ch == '+'){
					Estado = q47;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q47;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q47;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q47;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ')'){
					Estado = q51;
					cout << "q48 -> q51: "<<ch<<endl;
					parentesisCerrados++;
					palabra = "";
				} else {
					Estado = qe;
					cout << "q48 -> qe: "<<ch << endl;
				}
				break;
			case q49:
				if(digitoValido(ch)){
					Estado = q50;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q9 -> qe Se esperaba <digito>: " <<ch<< endl;
				}
				break;
			case q50:
				if(digitoValido(ch)){
					Estado = q50;
					palabra += ch;
				} else if (ch == '+'){
					Estado = q47;
					cout << "Operacion de suma al numero: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-'){
					Estado = q47;
					cout << "Operacion de resta al numero: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*'){
					Estado = q47;
					cout << "Operacion de multiplicacion al numero: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/'){
					Estado = q47;
					cout << "Operacion de division al numero: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ')'){
					Estado = q51;
					cout << "q50 -> q51: "<<ch<<endl;
					parentesisCerrados++;
					palabra = "";
				} else {
					Estado = qe;
					cout << "q50 -> qe: "<<ch << endl;
				}
				break;
			case q51:
				if (ch == ';'){
					Estado = q2;
					cout << "q51 Fin de linea."<<endl;
					palabra = "";
					puntoComa++;
				} else {
					Estado = qe;
					cout << "q51 -> qe Se esperaba [;]" <<ch<< endl;
				}
				break;
			case q52:
				if(letraValida(ch)){
					Estado = q52;
					palabra += ch;
				} else if (ch == '+' && esReservada(tabla,palabra)!=0){
					Estado = q47;
					cout << "Operacion de suma a: "<<palabra<<endl;
					palabra = "";
					operadoresSuma++;
				} else if (ch == '-' && esReservada(tabla,palabra)!=0){
					Estado = q47;
					cout << "Operacion de resta a: "<<palabra<<endl;
					palabra = "";
					operadoresResta++;
				} else if (ch == '*' && esReservada(tabla,palabra)!=0){
					Estado = q47;
					cout << "Operacion de multiplicacion a: "<<palabra<<endl;
					palabra = "";
					operadoresMultiplicacion++;
				} else if (ch == '/' && esReservada(tabla,palabra)!=0){
					Estado = q47;
					cout << "Operacion de division a: "<<palabra<<endl;
					palabra = "";
					operadoresDivision++;
				} else if (ch == ')'){
					if(esReservada(tabla,palabra)!=0){
						Estado = q51;
						cout << "q52 -> q51: "<<ch<<endl;
						parentesisCerrados++;
						palabra = "";
					}else{
						Estado  = qe;
						cout<< "q52 -> qe: "<<palabra<<" Es una palabra reservada."<<endl;
					}
					
					palabra = "";
				} else {
					Estado = qe;
					cout << "q52 -> qe: "<<ch<<endl;
				}
				break;
			case q53:
				if (ch == '('){
					Estado = q54;
					cout<<"q53 -> q54 parentesis abiertos "<<ch<<endl,
					parentesisAbiertos++;
					palabra = "";
				}else{
					Estado = qe;
					cout<<"q53 -> qe: "<<ch<<endl;
				}
				break;
			case q54:
				if (letraValida(ch)){
					Estado = q55;
					cout << "q54 -> q55"<<endl;
					palabra += ch;
				}else{
					Estado = qe;
					cout<<"q54 -> qe: "<<ch<<endl;
				}
				break;
			case q55:
				if(compararPalabra(tabla[0][14],palabra,ch)==0 || compararPalabra(tabla[0][13],palabra,ch)==0 ){ //Si es la palabra reservada 'pedestal' o 'camara'.
            		Estado = q56;
            		palabra += ch;
            		cout<<"q55->q56 Palabra reservada: "<<palabra<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q55;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q55 ->qe: " <<ch<< endl;
				}
				break;
			case q56:
				if (ch == ','){
					Estado = q57a;
					cout<<"q56->q57: "<<ch<<endl;
					coma++;
				} else {
					Estado = qe;
					cout << "q56 ->qe: " <<ch<< endl;
				}
				break;
			case q57a:
				if (letraValida(ch)){
					Estado = q57b;
					cout << "q57a -> q57b"<<endl;
					palabra += ch;
				}else{
					Estado = qe;
					cout<<"q57a -> qe: "<<ch<<endl;
				}
				break;
			case q57b:
				if(esDireccion(tabla,palabra,ch)==0){ //Si es la palabra reservada de <direccion>
            		Estado = q58;
            		palabra += ch;
            		cout<<"q57->q58 Palabra reservada: "<<palabra<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q57b;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q57b ->qe: " <<ch<< endl;
				}
				break;
			case q58:
				if (ch == ','){
					Estado = q47;
					cout<<"q58->q47: "<<ch<<endl;
					coma++;
				} else {
					Estado = qe;
					cout << "q58 ->qe: " <<ch<< endl;
				}
				break;
			case q59:
				if (ch == '('){
					Estado = q60;
					cout<<"q59 -> q60 parentesis abiertos "<<ch<<endl,
					parentesisAbiertos++;
					palabra = "";
				}else{
					Estado = qe;
					cout<<"q59 -> qe: "<<ch<<endl;
				}
				break;
			case q60:
				if (letraValida(ch)){
					Estado = q61;
					cout << "q60 -> q61"<<endl;
					palabra += ch;
				}else{
					Estado = qe;
					cout<<"q60 -> qe: "<<ch<<endl;
				}
				break;
			case q61:
				if(esParte(tabla,palabra,ch)==0){ //Si es la palabra reservada de <parte>
            		Estado = q62;
            		palabra += ch;
            		cout<<"q61->q62 Palabra reservada: "<<palabra<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q61;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q61 ->qe: " <<ch<< endl;
				}
				break;
			case q62:
				if (ch == ','){
					Estado = q57a;
					cout<<"q62->q57: "<<ch<<endl;
					coma++;
				} else {
					Estado = qe;
					cout << "q62 ->qe: " <<ch<< endl;
				}
				break;
			case q63:
				if (ch == '('){
					Estado = q64;
					cout<<"q63 -> q64 parentesis abiertos "<<ch<<endl,
					parentesisAbiertos++;
					palabra = "";
				}else{
					Estado = qe;
					cout<<"q63 -> qe: "<<ch<<endl;
				}
				break;
			case q64:
				if (letraValida(ch)){
					Estado = q65;
					cout << "q64 -> q65"<<endl;
					palabra += ch;
				}else{
					Estado = qe;
					cout<<"q64 -> qe: "<<ch<<endl;
				}
				break;
			case q65:
				if(esDireccion(tabla,palabra,ch)==0){ //Si es la palabra reservada de <direccion>
            		Estado = q58;
            		palabra += ch;
            		cout<<"q65->q58 Palabra reservada: "<<palabra<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				} else if(esParteMovimiento(tabla,palabra,ch)==0){
					Estado = q66;
            		palabra += ch;
            		cout<<"q65->q66 Palabra reservada: "<<palabra<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";
				} else if(letraValida(ch)){
					Estado = q65;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q65->qe: " <<ch<< endl;
				}
				break;
			case q66:
				if (ch == ','){
					Estado = q67;
					cout<<"q66->q67: "<<ch<<endl;
					coma++;
				} else {
					Estado = qe;
					cout << "q66 ->qe: " <<ch<< endl;
				}
				break;
			case q67:
				if (letraValida(ch)){
					Estado = q68;
					cout << "q67 -> q68"<<endl;
					palabra += ch;
				}else{
					Estado = qe;
					cout<<"q67 -> qe: "<<ch<<endl;
				}
				break;
			case q68:
				if(esDireccion(tabla,palabra,ch)==0){ //Si es la palabra reservada de <direccion>
            		Estado = q58;
            		palabra += ch;
            		cout<<"q68->q58 Palabra reservada: "<<palabra<<endl;
            		IngresoPalabraReservada(palabra);
					palabra = "";	
				} else if(letraValida(ch)){
					Estado = q68;
					palabra += ch;
				} else {
					Estado = qe;
					cout << "q68 ->qe: " <<ch<< endl;
				}
				break;
			case q69:
				if (ch == '@'){ //Verifica que cada bloque esté completo antes del final del programa.
					if (llavesAbiertas == llavesCerradas){
						Estado = q70;
						cout<<"q69->q70 Final del archivo: "<<ch<<endl;
					} else {
						Estado = qe;
						cout << "q69 ->qe: falta al menos una llave cerrada }" <<ch<< endl;
					}
					
				} else if (ch == ';'){//Fin de linea para un bloque de repeticion o condision.
					if (llavesAbiertas > llavesCerradas){
						Estado = q2;
						cout<<"q69->q2 fin de linea de bloque: "<<ch<<endl;
						puntoComa++;
					} else {
						Estado = qe;
						cout << "q69 ->qe: Existe un número igual o mayor de bloques cerrados. " <<ch<< endl;
					}
				} else {
					Estado = qe;
					cout << "q69 ->qe: " <<ch<< endl;
				}
				break;
			}	
		}

	}
	archivoEntrada.close();
	cout<< "Total llaves abiertas: " <<llavesAbiertas<<endl;
	cout<< "Total llaves cerradas: " <<llavesCerradas<<endl;
	cout<< "Total parentesis abiertos: "<<parentesisAbiertos<<endl;
	cout<< "Total parentesis cerrados: "<<parentesisCerrados<<endl;
	cout<< "Total signos =: " <<signoIgual<<endl;
	cout<< "Total signos !: " <<signoAdmiracion<<endl;
	cout<< "Total signos +: " <<operadoresSuma<<endl;
	cout<< "Total signos -: " <<operadoresResta<<endl;
	cout<< "Total signos /: " <<operadoresDivision<<endl;
	cout<< "Total signos *: " <<operadoresMultiplicacion<<endl;
	cout<< "Total signos <: " <<signoMenor<<endl;
	cout<< "Total signos >: " <<signoMayor<<endl;
	cout<< "Total signos ; (fin de linea): " <<puntoComa<<endl;
	cout<< "Total signos .: " <<punto<<endl;
	cout<< "Total signos ,: " <<coma<<endl;

	cout<<"Total variables creadas: "<<identificadores<<endl;
	MostrarLista();
	
	//Escritura del archivo de salida
	ofstream salida;
	salida.open("salida.txt");
	salida<< "Total llaves abiertas: " <<llavesAbiertas<<endl;
	salida<< "Total llaves cerradas: " <<llavesCerradas<<endl;
	salida<< "Total parentesis abiertos: "<<parentesisAbiertos<<endl;
	salida<< "Total parentesis cerrados: "<<parentesisCerrados<<endl;
	salida<< "Total signos =: " <<signoIgual<<endl;
	salida<< "Total signos !: " <<signoAdmiracion<<endl;
	salida<< "Total signos +: " <<operadoresSuma<<endl;
	salida<< "Total signos -: " <<operadoresResta<<endl;
	salida<< "Total signos /: " <<operadoresDivision<<endl;
	salida<< "Total signos *: " <<operadoresMultiplicacion<<endl;
	salida<< "Total signos <: " <<signoMenor<<endl;
	salida<< "Total signos >: " <<signoMayor<<endl;
	salida<< "Total signos ; (fin de linea): " <<puntoComa<<endl;
	salida<< "Total signos .: " <<punto<<endl;
	salida<< "Total signos ,: " <<coma<<endl;
	salida<<"Total variables creadas: "<<identificadores<<endl;
	salida<<"------------Variables Creadas----------"<<endl;
	for (int i = 0; i < identificadores; i++){
		salida<<tabla[1][i]<<endl;
	}
	salida<<"---------------------------------------"<<endl;
	
	salida<<"------------Lista de Variables y Palabras Reservadas----------"<<endl;
	for(int i=0; i<50; i++){
		salida<<endl;
		for(int j=0; j<2; j++){
			salida<<"      "<<lista[i][j]<<"     ";
		}
	}
	
	salida.close();

	
	return 0;
}



