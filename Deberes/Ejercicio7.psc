Algoritmo MaxMinMed
	Definir x,media,min,max,suma Como Real
	Definir divisor Como Entero
	suma<-0
	divisor<-0
	Escribir "Ingrese una altura"
	Leer x
	min<-x
	max<-x
	Mientras x>=0 Hacer
	Si x>=0 Entonces
		suma<-suma+x
		divisor<-divisor+1
	FinSi
	Si min>x Entonces
		min<-x
	FinSi
	Si max<x Entonces
		max<-x
	FinSi
	Escribir "Ingrese otra altura"
	Leer x
	FinMientras
	media<-suma/divisor
	Escribir "La media es ", media ",el minimo es ", min ", el maximo es ", max
FinAlgoritmo