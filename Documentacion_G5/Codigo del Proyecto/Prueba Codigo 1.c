#include <stdio.h>
#include <string.h>

#define CONTRASENA "admin123"

// REQUISITO FUNCIONAL 1:
// El sistema debe pedir una contraseña al iniciar y permitir acceso solo si es correcta.
int verificarContrasena() {
    char ingreso[20];
    printf("Ingrese la contrasena para acceder al sistema: ");
    fgets(ingreso, 20, stdin);
    ingreso[strcspn(ingreso, "\n")] = '\0';

    if (strcmp(ingreso, CONTRASENA) == 0) {
        return 1; // Contraseña correcta
    } else {
        return 0; // Contraseña incorrecta
    }
}

// Definición de estructura Producto
typedef struct {
    char codigo[20];
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

// REQUISITO FUNCIONAL 2:
// Permitir registrar productos con código, nombre, precio y cantidad.
void crearProducto(Producto *p) {
    printf("Ingrese el codigo del producto: ");
    fgets(p->codigo, 20, stdin);
    p->codigo[strcspn(p->codigo, "\n")] = '\0';

    printf("Ingrese el nombre del producto: ");
    fgets(p->nombre, 50, stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0';

    printf("Ingrese el precio del producto: ");
    scanf("%f", &p->precio);

    printf("Ingrese la cantidad disponible: ");
    scanf("%d", &p->cantidad);

    getchar(); // Limpiar buffer
}

// REQUISITO FUNCIONAL 3:
// Mostrar la lista completa de productos con sus detalles.
void mostrarProducto(Producto p) {
    printf("\nCodigo: %s\n", p.codigo);
    printf("Nombre: %s\n", p.nombre);
    printf("Precio: %.2f\n", p.precio);
    printf("Cantidad disponible: %d\n", p.cantidad);
}

// Función auxiliar para buscar un producto por código.
// Retorna la posición si lo encuentra o -1 si no.
int buscarProducto(Producto inventario[], int cantidad, const char *codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

// REQUISITO FUNCIONAL 4:
// Permitir eliminar un producto por su código.
void eliminarProducto(Producto inventario[], int *cantidad) {
    char codigo[20];
    printf("Ingrese el codigo del producto a eliminar: ");
    fgets(codigo, 20, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    int index = buscarProducto(inventario, *cantidad, codigo);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    // Desplazar productos para eliminar el seleccionado
    for (int i = index; i < *cantidad - 1; i++) {
        inventario[i] = inventario[i + 1];
    }

    (*cantidad)--;
    printf("Producto eliminado correctamente.\n");
}

// REQUISITO FUNCIONAL 5:
// Permitir actualizar nombre, precio y cantidad de un producto existente.
void actualizarProducto(Producto inventario[], int cantidad) {
    char codigo[20];
    printf("Ingrese el codigo del producto a actualizar: ");
    fgets(codigo, 20, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    int index = buscarProducto(inventario, cantidad, codigo);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Ingrese el nuevo nombre del producto (actual: %s): ", inventario[index].nombre);
    fgets(inventario[index].nombre, 50, stdin);
    inventario[index].nombre[strcspn(inventario[index].nombre, "\n")] = '\0';

    printf("Ingrese el nuevo precio del producto (actual: %.2f): ", inventario[index].precio);
    scanf("%f", &inventario[index].precio);

    printf("Ingrese la nueva cantidad disponible (actual: %d): ", inventario[index].cantidad);
    scanf("%d", &inventario[index].cantidad);

    getchar(); // Limpiar buffer

    printf("Producto actualizado correctamente.\n");
}

// REQUISITO FUNCIONAL 6:
// Permitir salir del sistema con una opción del menú.
int main() {
    if (!verificarContrasena()) {
        printf("Contrasena incorrecta. Acceso denegado.\n");
        return 1;
    }

    Producto inventario[100];
    int cantidad = 0;
    int opcion;

    while (1) {
        printf("\n--- MENU DE INVENTARIO ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Eliminar producto\n");
        printf("4. Actualizar producto\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        if (opcion == 1) {
            crearProducto(&inventario[cantidad]);
            cantidad++;
        } else if (opcion == 2) {
            if (cantidad == 0) {
                printf("No hay productos registrados aun.\n");
            } else {
                for (int i = 0; i < cantidad; i++) {
                    mostrarProducto(inventario[i]);
                }
            }
        } else if (opcion == 3) {
            if (cantidad == 0) {
                printf("No hay productos para eliminar.\n");
            } else {
                eliminarProducto(inventario, &cantidad);
            }
        } else if (opcion == 4) {
            if (cantidad == 0) {
                printf("No hay productos para actualizar.\n");
            } else {
                actualizarProducto(inventario, cantidad);
            }
        } else if (opcion == 5) {
            printf("Saliendo del sistema...\n");
            break;
        } else {
            printf("Opcion no valida. Intente de nuevo.\n");
        }
    }

    return 0;
}

