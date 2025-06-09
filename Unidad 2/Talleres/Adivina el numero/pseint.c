Proceso Principal
    Definir numeroSecreto, adivinado, intentosRealizados Como Entero
    Definir intentos[MAX_INTENTOS] Como Entero
    Const MAX_INTENTOS = 5

    adivinado <- 0
    intentosRealizados <- 0

    numeroSecreto <- Aleatorio(1, 100)  // Generar numero aleatorio entre 1 y 100

    Escribir "Adivina el numero entre 1 y 100. Tienes ", MAX_INTENTOS, " intentos."

    Llamar ingresarDatos(intentos, adivinado, numeroSecreto, intentosRealizados)

    Si adivinado = 1 Entonces
        Escribir "¡Correcto! Adivinaste el numero durante los intentos."
    Sino
        Escribir "No lograste adivinar. El numero era: ", numeroSecreto
    FinSi

    Llamar imprimirIntentos(intentos, intentosRealizados)
FinProceso

Proceso ingresarDatos (PorRef intentos[], PorRef adivinado, numeroSecreto, PorRef intentosRealizados)
    Definir intento Como Entero

    Para i <- 1 Hasta MAX_INTENTOS
        Escribir "Intento ", i, ": "
        Leer intento

        intentos[i] <- intento
        intentosRealizados <- i

        Si intento = numeroSecreto Entonces
            adivinado <- 1
            Escribir "¡Correcto!"
            SalirProceso
        Sino
            Si intento < numeroSecreto Entonces
                Escribir "El numero es más alto."
            Sino
                Escribir "El numero es más bajo."
            FinSi
        FinSi
    FinPara
FinProceso

Proceso imprimirIntentos (intentos[], intentosRealizados)
    Escribir "Tus intentos fueron: "
    Para i <- 1 Hasta intentosRealizados
        Escribir intentos[i], " "
    FinPara
    Escribir ""
FinProceso
