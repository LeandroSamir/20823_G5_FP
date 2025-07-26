#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONTRASENA "admin123"
#define ARCHIVO "inventario.txt"

// Definición de la estructura Producto
typedef struct {
    char codigo[20];
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

// Función para verificar contraseña
int verificarContrasena() {
    char ingreso[20];
    printf("Ingrese la contrasena para acceder al sistema: ");
    fgets(ingreso, 20, stdin);
    ingreso[strcspn(ingreso, "\n")] = '\0';

    if (strcmp(ingreso, CONTRASENA) == 0) {
        system("cls");
        return 1; // Contraseña correcta
    } else {
        return 0; // Contraseña incorrecta
    }
}

// Carga productos desde archivo a inventario, retorna cantidad cargada
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

// Guarda todo el inventario en el archivo
void guardarInventario(Producto inventario[], int cantidad) {
    FILE *file = fopen(ARCHIVO, "w");
    if (!file) {
        printf("Error al guardar el archivo.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        fprintf(file, "%s|%s|%.2f|%d\n",
                inventario[i].codigo,
                inventario[i].nombre,
                inventario[i].precio,
                inventario[i].cantidad);
    }

    fclose(file);
}

// Función auxiliar para validar número flotante positivo
float leerPrecio() {
    char entrada[50];
    float valor;
    char *endptr;
    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        valor = strtof(entrada, &endptr);
        if (*endptr != '\0' || valor < 0) {
            printf("Entrada invalida. Ingrese un precio valido: ");
        } else {
            return valor;
        }
    }
}

// Función auxiliar para validar número entero positivo
int leerCantidad() {
    char entrada[50];
    int valor;
    char *endptr;
    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        valor = strtol(entrada, &endptr, 10);
        if (*endptr != '\0' || valor < 0) {
            printf("Entrada invalida. Ingrese una cantidad entera valida: ");
        } else {
            return valor;
        }
    }
}

// Función auxiliar para leer la opción del menú (1 a 5)
int leerOpcionMenu() {
    char entrada[10];
    int opcion;
    char *endptr;
    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        opcion = strtol(entrada, &endptr, 10);
        if (*endptr != '\0' || opcion < 1 || opcion > 5) {
            printf("Opcion invalida. Ingrese un numero entre 1 y 5: ");
        } else {
            return opcion;
        }
    }
}

// Función para agregar un producto nuevo
void crearProducto(Producto *p) {
    system("cls");
    printf("Ingrese el codigo del producto: ");
    fgets(p->codigo, 20, stdin);
    p->codigo[strcspn(p->codigo, "\n")] = '\0';

    printf("Ingrese el nombre del producto: ");
    fgets(p->nombre, 50, stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0';

    printf("Ingrese el precio del producto: ");
    p->precio = leerPrecio();

    printf("Ingrese la cantidad disponible: ");
    p->cantidad = leerCantidad();

    printf("Producto agregado correctamente. Presione ENTER para continuar...");
    getchar();
    system("cls");
}

// Función para mostrar los datos de un producto
void mostrarProducto(Producto p) {
    printf("\nCodigo: %s\n", p.codigo);
    printf("Nombre: %s\n", p.nombre);
    printf("Precio: $%.2f\n", p.precio);
    printf("Cantidad disponible: %d\n", p.cantidad);
}

// Función para buscar un producto por codigo
int buscarProducto(Producto inventario[], int cantidad, const char *codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

// Función para eliminar un producto
void eliminarProducto(Producto inventario[], int *cantidad) {
    system("cls");
    char codigo[20];
    printf("Ingrese el codigo del producto a eliminar: ");
    fgets(codigo, 20, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    int index = buscarProducto(inventario, *cantidad, codigo);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        printf("Presione ENTER para continuar...");
        getchar();
        system("cls");
        return;
    }

    for (int i = index; i < *cantidad - 1; i++) {
        inventario[i] = inventario[i + 1];
    }

    (*cantidad)--;
    printf("Producto eliminado correctamente.\n");
    printf("Presione ENTER para continuar...");
    getchar();
    system("cls");
}

// Función para actualizar un producto
void actualizarProducto(Producto inventario[], int cantidad) {
    system("cls");
    char codigo[20];
    printf("Ingrese el codigo del producto a actualizar: ");
    fgets(codigo, 20, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    int index = buscarProducto(inventario, cantidad, codigo);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        printf("Presione ENTER para continuar...");
        getchar();
        system("cls");
        return;
    }

    printf("Ingrese el nuevo nombre del producto (actual: %s): ", inventario[index].nombre);
    fgets(inventario[index].nombre, 50, stdin);
    inventario[index].nombre[strcspn(inventario[index].nombre, "\n")] = '\0';

    printf("Ingrese el nuevo precio del producto (actual: %.2f): ", inventario[index].precio);
    inventario[index].precio = leerPrecio();

    printf("Ingrese la nueva cantidad disponible (actual: %d): ", inventario[index].cantidad);
    inventario[index].cantidad = leerCantidad();

    printf("Producto actualizado correctamente.\n");
    printf("Presione ENTER para continuar...");
    getchar();
    system("cls");
}

int main() {
    if (!verificarContrasena()) {
        printf("Contrasena incorrecta. Acceso denegado.\n");
        return 1;
    }

    Producto inventario[100];
    int cantidad = cargarInventario(inventario);
    int opcion;

    while (1) {
        system("cls");
        printf("\n--- MENU DE INVENTARIO ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Eliminar producto\n");
        printf("4. Actualizar producto\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        opcion = leerOpcionMenu();

        switch (opcion) {
            case 1:
                crearProducto(&inventario[cantidad]);
                cantidad++;
                guardarInventario(inventario, cantidad);
                break;

            case 2:
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

            case 3:
                if (cantidad == 0) {
                    system("cls");
                    printf("No hay productos para eliminar.\n");
                    printf("Presione ENTER para continuar...");
                    getchar();
                    system("cls");
                } else {
                    eliminarProducto(inventario, &cantidad);
                    guardarInventario(inventario, cantidad);
                }
                break;

            case 4:
                if (cantidad == 0) {
                    system("cls");
                    printf("No hay productos para actualizar.\n");
                    printf("Presione ENTER para continuar...");
                    getchar();
                    system("cls");
                } else {
                    actualizarProducto(inventario, cantidad);
                    guardarInventario(inventario, cantidad);
                }
                break;

            case 5:
                system("cls");
                printf("Saliendo del sistema...\n");
                return 0;
        }
    }

    return 0;
}
