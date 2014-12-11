/* 

    Analizador.cpp
    Archivo en C++ que implementa una clase Analizador. 
    Dicha clase contiene los métodos necesarios para comparar un texto con los idiomas Inglés, Español, Alemán y Francés
    mediante el análisis de la frecuencia de cada letra. 

    Autor: José Carlos Entrena Jiménez. 

*/

#include<stdio.h>
#include<vector> 
#include<string> 
#include<ctype.h>
#include<cmath> 
#include<limits>
#include<iostream>
#include<cstdlib>
#include<cstring>


using namespace std; 

class Analizador{
private: 
	// Matriz que almacena los datos para cada idioma que consideremos y los datos del texto. 
	// Cada idioma será una fila de la matriz. 
	/* Índices de los lenguales: 
	0-. Español	1-. Inglés	2-. Francés	3-. Alemán	
	*/
	vector< vector <double> > matriz_lenguajes;
	// Vector que almacena los datos que vamos obteniendo del texto. 
	vector<double> texto; 

public: 

    // Constructor. Inicializa los vectores de los distintos idiomas a partir del archivo datos.txt 
    Analizador(){
	    // Inicializamos a 0 el contador de letras.  
	    for (int i = 0; i < 26; i++)
            texto.push_back(0); 

        // Abrimos el fichero de datos
	    FILE *fichero; 
	    fichero = fopen("datos.txt", "r"); 

	    if (fichero == NULL){
            cout << "No existe el archivo\n"; 
            exit(-1); 
	    }

	    char numero[7]; 
	    char idioma[10]; 
        vector<double> temporal; 

	    for (int i = 0; i < 4; i++){
            temporal.clear(); 
		    fgets(idioma, 10, fichero); 
		    printf("Introduciendo idioma: %s", idioma); 

		    for (int j = 0; j < 26; j++){

		        if (fgets(numero, 7, fichero) != NULL)
		            temporal.push_back(atof(numero));
                else {
		            cout << "Error en la lectura\n"; 
		            exit (-1); 
		        } 
		    } 
        matriz_lenguajes.push_back(temporal);      
		}
	}


	/* Función para añadir palabras al vector de datos. 
       Suma 1 a la posición del vector correspondiente a cada letra por cada iteracione de la letra dentro de palabra
    */
    void Aniade(const char* palabra){
        char caracter;
        int posicion;  
        for (int i = 0; i < (unsigned)strlen(palabra); i++){
            caracter = tolower(palabra[i]); 
            posicion = (int)caracter - (int)'a'; 
            texto.at(posicion) = texto.at(posicion) + 1;  
        }
    }

    /* Función de comparación que nos permite saber a qué lenguaje es más afín nuestro texto. Se encarga de imprimir el resultado. 
       La comparación se hace por suma de la distancia de los porcentajes de las letras en el texto y en el idioma. 
    */   
    void Resuelve(){
        int distancia = 0;
        int tamanio = matriz_lenguajes.size(); 
        double distancia_temporal;
        int indice_lenguaje = -1; 
        string lenguaje; 
        int numero_letras = 0; 
        vector<double> porcentajes; 

        for (int i = 0; i < 26; i++)
            numero_letras += texto.at(i); 
       
        // Calculamos los porcentajes
        for (int i = 0; i < 26; i++){
		    porcentajes.push_back(100.0 * (texto.at(i)/numero_letras));
            cout << "Letra " << char('a'+i) << ": " << porcentajes.at(i) << "%\n"; 
        } 
	
        // Calculamos las distancias para cada lenguaje
        for (int i = 0; i < tamanio; i++){
            distancia_temporal = 0; 
            for (int j = 0; j < 26; j++){
                distancia_temporal += (abs((matriz_lenguajes.at(i).at(j) - porcentajes.at(j))));
            }
            if (distancia_temporal < distancia || distancia == 0){
                indice_lenguaje = i; 
                distancia = distancia_temporal; 
            }
            cout << "Diferencia: " << distancia_temporal << endl; 
        }
        
	    switch (indice_lenguaje) {
	    case 0: {
	        // Español
	        lenguaje = "Español"; 
	    }; break;
	    case 1: {
	        // Inglés
	        lenguaje = "Inglés"; 
	    }; break;
        case 2: {
	        // Francés
	        lenguaje = "Francés"; 
	    }; break;
        case 3: {
	        // Alemán
	        lenguaje = "Alemán"; 
	    }; break;
        default: lenguaje = "Error en Switch"; 
        }

        cout << "El lenguaje al que el texto es más similar es el " << lenguaje << endl;  
    }

}; 
