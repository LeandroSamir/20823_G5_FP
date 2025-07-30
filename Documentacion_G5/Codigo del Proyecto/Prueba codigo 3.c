#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO "inventario.txt"
#define ARCHIVO_CONTRASENA "contrasena.txt"
#define ARCHIVO_VENTAS "ventas.txt"

typedef struct {
    char codigo[20];
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

//Funcion para evitar entradas vacías y solo espacios

// Funcion para verificar si una cadena contiene solo espacios
int esSoloEspacios(const char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ' && cadena[i] != '\t') {
            return 0;
        }
    }
    return 1; // Solo contiene espacios
}

void leerCadena(char *buffer, int tamano) {
    while (1) {
        fgets(buffer, tamano, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        // Eliminar espacios al inicio
        char *inicio = buffer;
        while (*inicio == ' ' || *inicio == '\t') inicio++;

        // Eliminar espacios al final
        char *fin = buffer + strlen(buffer) - 1;
        while (fin >= inicio && (*fin == ' ' || *fin == '\t')) *fin-- = '\0';

        if (strlen(inicio) == 0 || esSoloEspacios(inicio)) {
            printf("Entrada invalida (no se permiten cadenas vacias ni solo espacios). Ingrese un valor valido: ");
        } else {
            if (inicio != buffer) memmove(buffer, inicio, strlen(inicio) + 1);
            break;
        }
    }
}

// ----------------- Contrasena -----------------

//Funcion para guardar contrasenas
void guardarContrasena(const char *nuevaContrasena) {
    FILE *file = fopen(ARCHIVO_CONTRASENA, "w");
    if (file) {
        fprintf(file, "%s\n", nuevaContrasena);
        fclose(file);
    }
}

int cargarContrasena(char *buffer) {
    FILE *file = fopen(ARCHIVO_CONTRASENA, "r");
    if (!file) return 0;
    fgets(buffer, 50, file);
    buffer[strcspn(buffer, "\n")] = '\0';
    fclose(file);
    return 1;
}

//Funcion para cambiar contrasenas
void cambiarContrasena() {
    char nueva[50], confirmacion[50];
    printf("Ingrese la nueva contrasena: ");
    leerCadena(nueva, 50);

    printf("Confirme la nueva contrasena: ");
    leerCadena(confirmacion, 50);

    if (strcmp(nueva, confirmacion) == 0) {
        guardarContrasena(nueva);
        printf("Contrasena cambiada correctamente.\n");
    } else {
        printf("Las contrasenas no coinciden. No se hizo el cambio.\n");
    }

    printf("Presione ENTER para continuar...");
    getchar();
    system("cls");
}

int verificarContrasena() {
    char guardada[50], ingreso[50];

    if (!cargarContrasena(guardada)) {
        printf("No hay contrasena configurada.\n");
        printf("Cree una nueva contrasena: ");
        leerCadena(guardada, 50);
        guardarContrasena(guardada);
        printf("Contrasena guardada exitosamente.\n");
    }

    printf("Ingrese la contrasena: ");
    leerCadena(ingreso, 50);

    if (strcmp(ingreso, guardada) == 0) {
        system("cls");
        return 1;
    } else {
        return 0;
    }
}
// ----------------- Validaciones -----------------

//Funcion para impedir entradas invalidas en el precio
float leerPrecio() {
    char entrada[50];
    float valor;
    char *endptr;
    while (1) {
        leerCadena(entrada, sizeof(entrada));
        valor = strtof(entrada, &endptr);
        if (*endptr != '\0' || valor <= 0) {
            printf("Entrada invalida. Ingrese un precio mayor que 0: ");
        } else {
            return valor;
        }
    }
}

//Funcion para impedir entradas invalidas en la cantidad
int leerCantidad() {
    char entrada[50];
    int valor;
    char *endptr;
    while (1) {
        leerCadena(entrada, sizeof(entrada));
        valor = strtol(entrada, &endptr, 10);
        if (*endptr != '\0' || valor < 0) {
            printf("Entrada invalida. Ingrese una cantidad entera valida: ");
        } else {
            return valor;
        }
    }
}

//Funcion para impedir entradas invalidas en las opciones del menu principal
int leerOpcionMenu() {
    char entrada[10];
    int opcion;
    char *endptr;
    while (1) {
        leerCadena(entrada, sizeof(entrada));
        opcion = strtol(entrada, &endptr, 10);
        if (*endptr != '\0' || opcion < 1 || opcion > 9) {
            printf("Opcion invalida. Ingrese un numero entre 1 y 9: ");
        } else {
            return opcion;
        }
    }
}

// ----------------- Inventario -----------------

//Funcion para buscar un producto con su codigo
int buscarProducto(Producto inventario[], int cantidad, const char *codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

//Funcion para leer los productos desde el txt
int cargarInventario(Producto inventario[]) {
    FILE *file = fopen(ARCHIVO, "r");
    if (!file) return 0;

    int cantidad = 0;
    while (fscanf(file, "%[^|]|%[^|]|%f|%d\n",
                  inventario[cantidad].codigo,
                  inventario[cantidad].nombre,
                  &inventario[cantidad].precio,
                  &inventario[cantidad].cantidad) == 4) {
        cantidad++;
        if (cantidad >= 100) break;
    }

    fclose(file);
    return cantidad;
}

//Funcion para guardar cambios en los productos del inventario
void guardarInventario(Producto inventario[], int cantidad) {
    FILE *file = fopen(ARCHIVO, "w");
    if (!file) return;

    for (int i = 0; i < cantidad; i++) {
        fprintf(file, "%s|%s|%.2f|%d\n",
                inventario[i].codigo,
                inventario[i].nombre,
                inventario[i].precio,
                inventario[i].cantidad);
    }

    fclose(file);
}

// ----------------- Producto -----------------

//Funcion para mostrar un producto
void mostrarProducto(Producto p) {
    printf("\nCodigo: %s\n", p.codigo);
    printf("Nombre: %s\n", p.nombre);
    printf("Precio: $%.2f\n", p.precio);
    printf("Cantidad disponible: %d\n", p.cantidad);
}
void crearProducto(Producto *p, Producto inventario[], int cantidadActual) {
    system("cls");
    while (1) {
        printf("Ingrese el codigo del producto: ");
        leerCadena(p->codigo, 20);

        if (buscarProducto(inventario, cantidadActual, p->codigo) != -1) {
            printf("Error: El codigo '%s' ya esta en uso. Intente con otro.\n", p->codigo);
        } else {
            break;
        }
    }

    printf("Ingrese el nombre del producto: ");
    leerCadena(p->nombre, 50);

    printf("Ingrese el precio del producto: ");
    p->precio = leerPrecio();

    printf("Ingrese la cantidad disponible: ");
    p->cantidad = leerCantidad();

    printf("Producto agregado correctamente. Presione ENTER para continuar...");
    getchar();
    system("cls");
}

void buscarProductoPorCodigo(Producto inventario[], int cantidad) {
    system("cls");
    char codigo[20];
    printf("Ingrese el codigo del producto a buscar: ");
    leerCadena(codigo, 20);

    int index = buscarProducto(inventario, cantidad, codigo);
    if (index == -1) {
        printf("Producto no encontrado.\n");
    } else {
        mostrarProducto(inventario[index]);
    }

    printf("\nPresione ENTER para continuar...");
    getchar();
    system("cls");
}

void eliminarProducto(Producto inventario[], int *cantidad) {
    system("cls");
    char codigo[20];
    printf("Ingrese el codigo del producto a eliminar: ");
    leerCadena(codigo, 20);

    int index = buscarProducto(inventario, *cantidad, codigo);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        printf("Presione ENTER para continuar...");
        getchar();
        system("cls");
        return;
    }

    char confirmacion;
    printf("Seguro que desea eliminar el producto '%s'? (S/N): ", inventario[index].nombre);
    scanf(" %c", &confirmacion);
    getchar();

    if (confirmacion == 'S' || confirmacion == 's') {
        for (int i = index; i < *cantidad - 1; i++) {
            inventario[i] = inventario[i + 1];
        }
        (*cantidad)--;
        printf("Producto eliminado correctamente.\n");
    } else {
        printf("Eliminacion cancelada.\n");
    }

    printf("Presione ENTER para continuar...");
    getchar();
    system("cls");
}

void actualizarProducto(Producto inventario[], int cantidad) {
    system("cls");
    char codigo[20];
    printf("Ingrese el codigo del producto a actualizar: ");
    leerCadena(codigo, 20);

    int index = buscarProducto(inventario, cantidad, codigo);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        printf("Presione ENTER para continuar...");
        getchar();
        system("cls");
        return;
    }

    char confirmacion;
    printf("Seguro que desea actualizar el producto '%s'? (S/N): ", inventario[index].nombre);
    scanf(" %c", &confirmacion);
    getchar();

    if (confirmacion != 'S' && confirmacion != 's') {
        printf("Actualizacion cancelada.\n");
        printf("Presione ENTER para continuar...");
        getchar();
        system("cls");
        return;
    }

    int opcion;
    do {
        system("cls");
        printf("--- MENU DE ACTUALIZACION ---\n");
        printf("1. Actualizar nombre\n");
        printf("2. Actualizar precio\n");
        printf("3. Actualizar cantidad\n");
        printf("4. Actualizar todo\n");
        printf("5. Cancelar\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                printf("Ingrese el nuevo nombre (actual: %s): ", inventario[index].nombre);
                leerCadena(inventario[index].nombre, 50);
                printf("Nombre actualizado correctamente.\n");
                break;

            case 2:
                printf("Ingrese el nuevo precio (actual: %.2f): ", inventario[index].precio);
                inventario[index].precio = leerPrecio();
                printf("Precio actualizado correctamente.\n");
                break;

            case 3:
                printf("Ingrese la nueva cantidad (actual: %d): ", inventario[index].cantidad);
                inventario[index].cantidad = leerCantidad();
                printf("Cantidad actualizada correctamente.\n");
                break;

            case 4:
                printf("Ingrese el nuevo nombre (actual: %s): ", inventario[index].nombre);
                leerCadena(inventario[index].nombre, 50);
                printf("Ingrese el nuevo precio (actual: %.2f): ", inventario[index].precio);
                inventario[index].precio = leerPrecio();
                printf("Ingrese la nueva cantidad (actual: %d): ", inventario[index].cantidad);
                inventario[index].cantidad = leerCantidad();
                printf("Producto actualizado completamente.\n");
                break;

            case 5:
                printf("Actualizacion cancelada.\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

        if (opcion >=1 && opcion <=4) {
            printf("Presione ENTER para continuar...");
            getchar();
        }

    } while(opcion < 1 || opcion > 5);

    system("cls");
}

// ----------------- Registrar Venta y Historial -----------------

void registrarVenta(Producto inventario[], int *cantidad, FILE *historial) {
    char codigo[20];
    int cantidadVenta;

    system("cls");
    printf("Ingrese el codigo del producto a vender: ");
    leerCadena(codigo, 20);

    int index = buscarProducto(inventario, *cantidad, codigo);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        printf("Presione ENTER para continuar...");
        getchar();
        system("cls");
        return;
    }

    printf("\n--- INFORMACION DEL PRODUCTO ---\n");
    printf("Codigo: %s\n", inventario[index].codigo);
    printf("Nombre: %s\n", inventario[index].nombre);
    printf("Precio Unitario: $%.2f\n", inventario[index].precio);
    printf("Cantidad Disponible: %d\n\n", inventario[index].cantidad);

    while (1) {
        printf("Ingrese la cantidad a vender: ");
        cantidadVenta = leerCantidad();

        if (cantidadVenta <= 0) {
            printf("Error: La cantidad debe ser mayor que cero.\n");
        } else if (cantidadVenta > inventario[index].cantidad) {
            printf("Error: No hay suficiente stock disponible.\n");
        } else {
            break;
        }
    }

    inventario[index].cantidad -= cantidadVenta;

    fprintf(historial, "%s|%s|%d|%.2f|%.2f\n",
            inventario[index].codigo,
            inventario[index].nombre,
            cantidadVenta,
            inventario[index].precio,
            inventario[index].precio * cantidadVenta);

    printf("Venta registrada. \nTotal: $%.2f\n", inventario[index].precio * cantidadVenta);
    printf("Presione ENTER para continuar...");
    getchar();
    system("cls");
}

void mostrarHistorialVentas() {
    system("cls");
    FILE *file = fopen(ARCHIVO_VENTAS, "r");
    if (!file) {
        printf("No hay ventas registradas aun.\n");
        printf("Presione ENTER para continuar...");
        getchar();
        system("cls");
        return;
    }

    char linea[200];
    printf("\n--- HISTORIAL DE VENTAS ---\n\n");
    while (fgets(linea, sizeof(linea), file)) {
        char codigo[20], nombre[50];
        int cantidad;
        float precio, total;
        sscanf(linea, "%[^|]|%[^|]|%d|%f|%f", codigo, nombre, &cantidad, &precio, &total);
        printf("Codigo: %s\nNombre: %s\nCantidad: %d\nPrecio Unitario: $%.2f\nTotal: $%.2f\n\n",
               codigo, nombre, cantidad, precio, total);
    }

    fclose(file);
    printf("Presione ENTER para continuar...");
    getchar();
    system("cls");
}

// ----------------- Menu Principal -----------------

int main() {
    if (!verificarContrasena()) {
        printf("Contrasena incorrecta. Acceso denegado.\n");
        return 1;
    }

    Producto inventario[100];
    int cantidad = cargarInventario(inventario);

    FILE *historial = fopen(ARCHIVO_VENTAS, "a");
    if (!historial) {
        printf("Error al abrir el archivo de historial de ventas.\n");
        return 1;
    }

    int opcion;
    while (1) {
        system("cls");
        printf("\n--- MENU DE INVENTARIO ---\n");
        printf("1. Agregar producto\n");
        printf("2. Buscar producto por codigo\n");
        printf("3. Mostrar todos los productos\n");
        printf("4. Eliminar producto\n");
        printf("5. Actualizar producto\n");
        printf("6. Realizar venta\n");
        printf("7. Ver historial de ventas\n");
        printf("8. Cambiar contrasena\n");
        printf("9. Salir\n");
        printf("Opcion: ");
        opcion = leerOpcionMenu();

        switch (opcion) {
            case 1:
                if (cantidad >= 100) {
                    printf("El inventario esta lleno. No se pueden agregar mas productos.\n");
                    printf("Presione ENTER para continuar...");
                    getchar();
                } else {
                    crearProducto(&inventario[cantidad], inventario, cantidad);
                    cantidad++;
                    guardarInventario(inventario, cantidad);
                }
                break;

            case 2:
                buscarProductoPorCodigo(inventario, cantidad);
                break;

            case 3:
                system("cls");
                if (cantidad == 0) {
                    printf("No hay productos registrados aun.\n");
                } else {
                    for (int i = 0; i < cantidad; i++) {
                        mostrarProducto(inventario[i]);
                    }
                }
                printf("\nPresione ENTER para continuar...");
                getchar();
                system("cls");
                break;

            case 4:
                if (cantidad == 0) {
                    system("cls");
                    printf("No hay productos para eliminar.\n");
                    printf("Presione ENTER para continuar...");
                    getchar();
                } else {
                    eliminarProducto(inventario, &cantidad);
                    guardarInventario(inventario, cantidad);
                }
                break;

            case 5:
                if (cantidad == 0) {
                    system("cls");
                    printf("No hay productos para actualizar.\n");
                    printf("Presione ENTER para continuar...");
                    getchar();
                } else {
                    actualizarProducto(inventario, cantidad);
                    guardarInventario(inventario, cantidad);
                }
                break;

            case 6:
                registrarVenta(inventario, &cantidad, historial);
                guardarInventario(inventario, cantidad);
                break;

            case 7:
                mostrarHistorialVentas();
                break;

            case 8:
                cambiarContrasena();
                break;

            case 9:
                printf("Saliendo del sistema...\n");
                fclose(historial);
                return 0;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    }

    fclose(historial);
    return 0;
}
