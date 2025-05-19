Algoritmo MedialumPositivos
	Definir x,suma,media,positivos Como Real
	Definir contador Como Entero
	suma<-0
	contador<-0
	Mientras contador<3 Hacer
	Escribir "Ingrese un nümero real positivo:"
	Leer x
	Si x>0 Entonces
		suma<-suma+x
		contador<-contador+1
		positivos<-positivos+1
	SiNo
		suma<-suma+0
		contador<-contador+1
		positivos<-positivos+0
	FinSi
	FinMientras
	Si positivos=0 Entonces
		Escribir "La media de los nimeros positivos es:e"
	SiNo
		media<-suma/positivos
		Escribir "La media de los nümeros positivos es:",media
	FinSi
FinAlgoritmo