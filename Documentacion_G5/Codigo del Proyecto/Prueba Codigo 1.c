#include <stdio.h>
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
        return 1; // Contraseña correcta
    } else {
        return 0; // Contraseña incorrecta
    }
}

// Carga productos desde archivo a inventario, retorna cantidad cargada
int cargarInventario(Producto inventario[]) {
    FILE *file = fopen(ARCHIVO, "r");
    if (!file) return 0; // No existe archivo o no se pudo abrir

    int cantidad = 0;
    while (fscanf(file, "%[^|]|%[^|]|%f|%d\n",
                  inventario[cantidad].codigo,
                  inventario[cantidad].nombre,
                  &inventario[cantidad].precio,
                  &inventario[cantidad].cantidad) == 4) {
        cantidad++;
        if (cantidad >= 100) break; // evitar overflow
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

// Función para agregar un producto nuevo
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

    getchar(); // Limpia el buffer del teclado
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

// Función para actualizar un producto
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

    getchar(); // Limpia el buffer

    printf("Producto actualizado correctamente.\n");
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
        printf("\n--- MENU DE INVENTARIO ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Eliminar producto\n");
        printf("4. Actualizar producto\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el buffer

        switch (opcion) {
            case 1:
                crearProducto(&inventario[cantidad]);
                cantidad++;
                guardarInventario(inventario, cantidad);
                break;

            case 2:
                if (cantidad == 0) {
                    printf("No hay productos registrados aun.\n");
                } else {
                    for (int i = 0; i < cantidad; i++) {
                        mostrarProducto(inventario[i]);
                    }
                }
                break;

            case 3:
                if (cantidad == 0) {
                    printf("No hay productos para eliminar.\n");
                } else {
                    eliminarProducto(inventario, &cantidad);
                    guardarInventario(inventario, cantidad);
                }
                break;

            case 4:
                if (cantidad == 0) {
                    printf("No hay productos para actualizar.\n");
                } else {
                    actualizarProducto(inventario, cantidad);
                    guardarInventario(inventario, cantidad);
                }
                break;

            case 5:
                printf("Saliendo del sistema...\n");
                return 0;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    }

    return 0;
}
