# Makefile
# Compila la práctica de lex para el análisis de lenguajes. 
 
default: ./proyecto
 
./proyecto: lex.yy.o analizador.cpp
	g++ -o $@ $^ -ll
 
lex.yy.o: lex.yy.c
	g++ -c -x c++ $<
 
lex.yy.c: plantilla.l
	lex $<

clean: 
	rm proyecto lex.yy.o lex.yy.c
 

