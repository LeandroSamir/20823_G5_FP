#include <stdio.h>
#include <string.h>

#define CONTRASENA "admin123"

typedef struct {
    char codigo[20];
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

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

    getchar();
}

void mostrarProducto(Producto p) {
    printf("\nCodigo: %s\n", p.codigo);
    printf("Nombre: %s\n", p.nombre);
    printf("Precio: %.2f\n", p.precio);
    printf("Cantidad disponible: %d\n", p.cantidad);
}

int buscarProducto(Producto inventario[], int cantidad, const char *codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(inventario[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

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

    for (int i = index; i < *cantidad - 1; i++) {
        inventario[i] = inventario[i + 1];
    }

    (*cantidad)--;
    printf("Producto eliminado correctamente.\n");
}

int verificarContrasena() {
    char ingreso[20];
    printf("Ingrese la contrasena para acceder al sistema: ");
    fgets(ingreso, 20, stdin);
    ingreso[strcspn(ingreso, "\n")] = '\0';

    if (strcmp(ingreso, CONTRASENA) == 0) {
        return 1; // Correcta
    } else {
        return 0; // Incorrecta
    }
}

int main() {
    if (!verificarContrasena()) {
        printf("Contrasena incorrecta. Acceso denegado.\n");
        return 1;
    }

    Producto inventario[100];
    int cantidad = 0;
    int opcion;

    while (1) {
        printf("\nMENU DE INVENTARIO\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Eliminar producto\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

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
            printf("Saliendo del sistema...\n");
            break;
        } else {
            printf("Opcion no valida. Intente de nuevo.\n");
        }
    }

    return 0;
}
