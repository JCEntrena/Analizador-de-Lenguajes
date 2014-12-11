                 /*----- Sección de Declaraciones --------------*/ 
%{

#include"analizador.cpp"

Analizador nuevo; 
 
%}
		/*---Alias---*/

letra			[[:alpha:]]
palabra			{letra}+
%%
                 /*----- Sección de Reglas ----------------*/ 

{palabra}		{nuevo.Aniade(yytext);}
.|\n 			{;}


%%   
                /*----- Sección de Procedimientos --------*/ 

int main (int argc, char *argv[]){   
    if (argc == 2){     
        yyin = fopen (argv[1], "rt");     

        if (yyin == NULL){       
            printf ("El fichero %s no se puede abrir\n", argv[1]);       
            exit (-1);     
        }   
    }   	
    else 
        yyin = stdin;   

    yylex (); 
    nuevo.Resuelve(); 
}




 
