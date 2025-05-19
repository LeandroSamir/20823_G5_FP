Algoritmo Verificar_Divisibilidad
	//Declaracion de variables
	Definir x, z,r Como Entero
	
	//Solicitar y leer el primer numero
	Escribir "Ingrese el primer numero entero"
	Leer x
	
	//Solicitar y leer el segundo numero
	Escribir "Ingrese el segundo numero entero"
	Leer z
	
	//Verificar que el segundo numero no sea cero
	si z= 0 Entonces
		Escribir "Error: El segundo numero no puede ser cero"
	SiNo
		//Calcular el residuo de la division
		r<- x MOD z
		
		//Verificar si el primer numero es divisible para el segundo
		Si r = 0 Entonces
			Escribir "El primer numero es divisible por el segundo."
		Sino
			Escribir "El primer numero NO es divisible por el segundo"
		FinSi
	FinSi
FinAlgoritmo
