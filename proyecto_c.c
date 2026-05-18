/*
 * Proyecto: CryptoNote - Sistema de Gestion y Cifrado de Archivos
 * Equipo: Estructuradores
 * Integrantes:
 *   - Barrera Escalante Cristofer
 *   - Couoh Mis Guillermo Moises
 *   - Garcia Gamboa Eric Emir
 *   - Jimenez Hernandez Xicotenctl
 *   - Sandoval Tamayo Jose Heynar
 *
 * Materia: Programacion Estructurada - Segundo Semestre
 * Facultad de Matematicas, UADY
 *
 * Descripcion: Aplicacion de consola en ANSI C que permite registrar
 *   usuarios, crear archivos de texto y aplicar cifrado/descifrado XOR
 *   con clave personalizada. Funciona completamente offline.
 *
 * Compilacion: gcc proyecto_c.c -o cryptonote
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Constantes simbolicas --- */
#define MAX_NOMBRE   50    /* Longitud maxima del nombre de usuario */
#define MAX_CONS     20    /* Longitud maxima de la contrasena */
#define FILE_USUARIOS "file_usuarios.txt"  /* Archivo de credenciales */


/* --- Declaracion de funciones --- */
void crear_cuenta(void);
void iniciar_sesion(void);
void segundo_menu(const char *nombre);
void crear_archivo(void);
void escribir_archivo(const char *nombre_archivo);
void cifrar_archivo(void);
void descifrar_archivo(void);
void aplicar_xor(const char *archivo_origen, const char *archivo_cifrado, const char *clave);
int  usuario_existe(const char *nombre);
int  verificar_usuario(const char *nombre, const char *contrasena);


/*
Nombre: main
Objetivo: Funcion base del programa.
Descripcion: Muestra el menu principal y despacha las opciones de registro,
  inicio de sesion y salida. Usa un bucle do-while que termina al seleccionar
  la opcion 3 (Salir).
Parametros: ninguno
Retorno: int - 0 al finalizar correctamente
Precondiciones: ninguna
Postcondiciones: El programa termina con return 0.
*/
int main(void)
{
    int opc;

    do {
        printf("--- MENU ---\n");
        printf("1. Crear cuenta\n");
        printf("2. Iniciar sesion\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");

        /* Entrada: leer opcion numerica */
        scanf("%d", &opc);
        getchar(); /* Consumir el salto de linea residual */
        system("cls");

        /* Proceso: despachar segun opcion */
        switch (opc) {
            case 1:
                crear_cuenta();
                break;
            case 2:
                iniciar_sesion();
                break;
            case 3:
                /* Salida: mensaje de cierre */
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opc != 3);

    return 0;
}


/*
Nombre: crear_cuenta
Objetivo: Registrar un nuevo usuario en el sistema evitando duplicados.
Descripcion: Solicita nombre de usuario y contrasena. Verifica que el nombre
  no exista previamente en file_usuarios.txt mediante usuario_existe(). Si es
  unico, guarda la nueva credencial en modo append. Las entradas se leen con
  fgets para evitar desbordamiento de buffer.
Parametros: ninguno
Retorno: void
Precondiciones: El programa tiene permisos de lectura/escritura en el directorio.
Postcondiciones: Si exitoso, file_usuarios.txt contiene una nueva linea
  "nombre contrasena\n". Si hay duplicado o error, el archivo no se modifica.
*/
void crear_cuenta(void)
{
    char nombre[MAX_NOMBRE];
    char contrasena[MAX_CONS];

    /* Salida: solicitar nombre */
    printf("--- Crear cuenta ---\n");
    printf("Ingrese un nombre de usuario: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = 0; /* Eliminar salto de linea */

    /* Proceso: verificar duplicados */
    if (usuario_existe(nombre)) {
        printf("Nombre de usuario existente. Pruebe con otro.\n");
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");
        return;
    }

    /* Entrada: solicitar contrasena */
    printf("Ingrese una contrasena: ");
    fgets(contrasena, MAX_CONS, stdin);
    contrasena[strcspn(contrasena, "\n")] = 0; /* Eliminar salto de linea */
    system("cls");

    /* Proceso: abrir archivo en modo append */
    FILE *archivo = fopen(FILE_USUARIOS, "a");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");
        return;
    }

    /* Salida: escribir credencial y confirmar */
    fprintf(archivo, "%s %s\n", nombre, contrasena);
    fclose(archivo);

    printf("Cuenta creada exitosamente.\n");
    printf("Presiona Enter para continuar...");
    getchar();
    system("cls");
}


/*
Nombre: iniciar_sesion
Objetivo: Verificar las credenciales del usuario y otorgar acceso al menu secundario.
Descripcion: Solicita nombre y contrasena. Llama a verificar_usuario() para comparar
  contra file_usuarios.txt. Si coinciden, llama a segundo_menu(). Si no, muestra
  mensaje de error y regresa al menu principal.
Parametros: ninguno
Retorno: void
Precondiciones: file_usuarios.txt existe y puede leerse.
Postcondiciones: Si exitoso, el control pasa a segundo_menu(). Si falla, regresa
  al bucle del menu principal.
*/
void iniciar_sesion(void)
{
    char nombre[MAX_NOMBRE];
    char contrasena[MAX_CONS];

    /* Entrada: solicitar credenciales */
    printf("--- Iniciar sesion ---\n");
    printf("Ingrese su nombre de usuario: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = 0; /* Eliminar salto de linea */

    printf("Ingrese su contrasena: ");
    fgets(contrasena, MAX_CONS, stdin);
    contrasena[strcspn(contrasena, "\n")] = 0; /* Eliminar salto de linea */
    system("cls");

    /* Proceso: verificar credenciales */
    if (verificar_usuario(nombre, contrasena)) {
        /* Salida: acceso concedido */
        printf("Inicio de sesion exitoso. !Bienvenido(a), %s!\n", nombre);
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");
        segundo_menu(nombre);
    } else {
        /* Salida: acceso denegado */
        printf("Nombre de usuario o contrasena incorrectos.\n");
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");
    }
}


/*
Nombre: segundo_menu
Objetivo: Mostrar el menu de opciones disponibles para el usuario autenticado.
Descripcion: Presenta un menu ciclico con las operaciones de creacion de archivo,
  cifrado, descifrado y cierre de sesion. El bucle termina al seleccionar la opcion 4.
  Al terminar, el control regresa a iniciar_sesion() y luego al menu principal.
Parametros:
  - nombre : const char* - nombre del usuario autenticado para el saludo
Retorno: void
Precondiciones: El usuario ha sido autenticado exitosamente.
Postcondiciones: Al cerrar sesion, el usuario regresa al menu principal como
  no autenticado (sin variable global de sesion).
*/
void segundo_menu(const char *nombre)
{
    int opc2;

    do {
        printf("--- MENU ---\n");
        printf("!Hola, %s!\n", nombre);
        printf("1. Crear archivo txt\n");
        printf("2. Cifrar archivo txt\n");
        printf("3. Descifrar archivo txt\n");
        printf("4. Cerrar sesion\n");
        printf("Seleccione una opcion: ");

        /* Entrada: leer opcion */
        scanf("%d", &opc2);
        getchar(); /* Consumir salto de linea */
        system("cls");

        /* Proceso: despachar segun opcion */
        switch (opc2) {
            case 1:
                crear_archivo();
                break;
            case 2:
                cifrar_archivo();
                break;
            case 3:
                descifrar_archivo();
                break;
            case 4:
                /* Salida: cerrar sesion */
                printf("Cerrando sesion...\n");
                printf("Presiona Enter para continuar...");
                getchar();
                system("cls");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opc2 != 4);
}


/*
Nombre: crear_archivo
Objetivo: Crear un archivo de texto con el nombre proporcionado por el usuario.
Descripcion: Solicita el nombre del archivo (debe incluir extension .txt). Intenta
  abrirlo en modo escritura "w". Si tiene exito, confirma la creacion, lo cierra y
  llama a escribir_archivo() para agregar contenido.
Parametros: ninguno
Retorno: void
Precondiciones: El usuario tiene permisos de escritura en el directorio.
Postcondiciones: El archivo existe en disco. Si fopen falla, no se crea nada.
*/
void crear_archivo(void)
{
    char nombre_archivo[100];

    /* Entrada: solicitar nombre del archivo */
    printf("--- Crear archivo ---\n");
    printf("Ingrese el nombre del archivo (incluir extension .txt): ");
    fgets(nombre_archivo, sizeof(nombre_archivo), stdin);
    nombre_archivo[strcspn(nombre_archivo, "\n")] = '\0'; /* Eliminar salto de linea */
    system("cls");

    /* Proceso: crear el archivo */
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo != NULL) {
        /* Salida: confirmacion de creacion */
        printf("El archivo '%s' se ha creado correctamente.\n", nombre_archivo);
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");
        fclose(archivo);
        /* Llamar a la funcion de escritura inmediatamente */
        escribir_archivo(nombre_archivo);
    } else {
        /* Salida: error al crear */
        printf("Ocurrio un error al crear el archivo.\n");
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");
    }
}


/*
Nombre: escribir_archivo
Objetivo: Permitir al usuario escribir contenido multilínea en el archivo creado.
Descripcion: Abre el archivo en modo "w" y entra en un bucle infinito que lee
  lineas con fgets. Cada linea se escribe en el archivo hasta que el usuario
  ingrese exactamente "salir" (sensible a mayusculas) en una linea nueva.
Parametros:
  - nombre_archivo : const char* - nombre del archivo donde se escribira el contenido
Retorno: void
Precondiciones: El archivo ha sido creado previamente (crear_archivo lo garantiza).
Postcondiciones: El archivo contiene todas las lineas ingresadas excepto "salir".
  El archivo queda cerrado al terminar.
*/
void escribir_archivo(const char *nombre_archivo)
{
    char linea[256];

    /* Proceso: abrir archivo para escritura */
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");
        return;
    }

    /* Salida: instrucciones al usuario */
    printf("--- Importante ---\n");
    printf("Escribe lo que quieras.\n");
    printf("Cuando quieras cambiar de linea presiona Enter.\n");
    printf("Para salir, en una nueva linea escribe 'salir' y presiona Enter\n");
    printf("Contenido del archivo:\n");

    /* Proceso: bucle de escritura linea por linea */
    while (1) {
        fgets(linea, sizeof(linea), stdin);
        linea[strcspn(linea, "\n")] = '\0'; /* Eliminar salto de linea */

        /* Comparacion exacta con palabra reservada de salida */
        if (strcmp(linea, "salir") == 0) {
            break;
        }

        /* Escribir linea en el archivo con salto de linea */
        fprintf(archivo, "%s\n", linea);
    }

    fclose(archivo);
    system("cls");

    /* Salida: confirmacion de guardado */
    printf("El archivo '%s' se ha guardado correctamente.\n", nombre_archivo);
    printf("Presiona Enter para continuar...");
    getchar();
    system("cls");
}


/*
Nombre: cifrar_archivo
Objetivo: Aplicar cifrado XOR a un archivo de texto, generando uno nuevo cifrado.
Descripcion: Solicita el nombre del archivo original, el nombre del archivo de
  salida y la clave de cifrado. Advierte al usuario que guarde la clave. Llama a
  aplicar_xor() con los parametros recibidos. El archivo cifrado contiene los
  mismos bytes del original transformados bit a bit mediante XOR con la clave.
Parametros: ninguno
Retorno: void
Precondiciones: El archivo original existe y es legible.
Postcondiciones: Se genera el archivo cifrado. Si falla, no se modifica nada.
  Advertencia: clave vacia produce error de division entre cero en aplicar_xor().
*/
void cifrar_archivo(void)
{
    char archivo_origen[100];
    char archivo_cifrado[100];
    char clave[50];

    /* Entrada: solicitar datos para el cifrado */
    printf("--- Cifrar archivo ---\n");
    printf("Ingrese el nombre del archivo original a cifrar: ");
    fgets(archivo_origen, sizeof(archivo_origen), stdin);
    archivo_origen[strcspn(archivo_origen, "\n")] = '\0';

    printf("Ingrese el nombre del nuevo archivo cifrado: ");
    fgets(archivo_cifrado, sizeof(archivo_cifrado), stdin);
    archivo_cifrado[strcspn(archivo_cifrado, "\n")] = '\0';

    printf("\n--- Importante ---\n");
    printf("Guarda la clave, sin ella no podras descifrar el archivo y se perdera la informacion\n");
    printf("Ingrese su clave de cifrado: ");
    fgets(clave, sizeof(clave), stdin);
    clave[strcspn(clave, "\n")] = '\0';

    printf("Presiona Enter para continuar...");
    getchar();
    system("cls");

    /* Proceso: aplicar XOR para cifrar */
    aplicar_xor(archivo_origen, archivo_cifrado, clave);

    /* Salida: confirmacion */
    printf("Archivo cifrado correctamente: %s\n", archivo_cifrado);
    printf("Presiona Enter para continuar...");
    getchar();
    system("cls");
}


/*
Nombre: descifrar_archivo
Objetivo: Revertir el cifrado XOR de un archivo, recuperando el contenido original.
Descripcion: Solicita el nombre del archivo cifrado, el nombre del archivo de
  salida y la clave utilizada al cifrar. Llama a aplicar_xor() con los mismos
  parametros. Dado que XOR es su propia inversa, aplicar la misma clave sobre
  el archivo cifrado produce el archivo original.
Parametros: ninguno
Retorno: void
Precondiciones: El archivo cifrado existe. La clave debe ser identica a la usada
  al cifrar para recuperar el contenido original.
Postcondiciones: Se genera el archivo descifrado. Si la clave es incorrecta, el
  archivo contiene datos incoherentes sin mensaje de advertencia.
*/
void descifrar_archivo(void)
{
    char archivo_origen[100];
    char archivo_cifrado[100];
    char clave[50];

    /* Entrada: solicitar datos para el descifrado */
    printf("--- Descifrar archivo ---\n");
    printf("Ingrese el nombre del archivo a descifrar: ");
    fgets(archivo_origen, sizeof(archivo_origen), stdin);
    archivo_origen[strcspn(archivo_origen, "\n")] = '\0';

    printf("Ingrese el nombre del nuevo archivo descifrado: ");
    fgets(archivo_cifrado, sizeof(archivo_cifrado), stdin);
    archivo_cifrado[strcspn(archivo_cifrado, "\n")] = '\0';

    printf("Ingrese la clave de cifrado: ");
    fgets(clave, sizeof(clave), stdin);
    clave[strcspn(clave, "\n")] = '\0';

    printf("Presiona Enter para continuar...");
    getchar();
    system("cls");

    /* Proceso: aplicar XOR para descifrar (operacion simetrica) */
    aplicar_xor(archivo_origen, archivo_cifrado, clave);

    /* Salida: confirmacion */
    printf("Archivo descifrado correctamente: %s\n", archivo_cifrado);
    printf("Presiona Enter para continuar...");
    getchar();
    system("cls");
}


/*
Nombre: aplicar_xor
Objetivo: Realizar la transformacion XOR byte a byte entre un archivo origen y uno destino.
Descripcion: Abre el archivo origen en modo binario ("rb") y el archivo destino
  en modo escritura binaria ("wb"). Lee un byte a la vez del origen, aplica XOR
  con el caracter de la clave en la posicion (contador % longitud_clave), y escribe
  el resultado en el archivo destino. La clave se recorre ciclicamente.
  Dado que XOR(XOR(byte, clave), clave) == byte, la misma funcion sirve tanto
  para cifrar como para descifrar.
Parametros:
  - archivo_origen  : const char* - nombre del archivo fuente (leer)
  - archivo_cifrado : const char* - nombre del archivo destino (escribir)
  - clave           : const char* - clave de cifrado/descifrado
Retorno: void
Precondiciones: archivo_origen debe existir y ser legible. La clave no debe ser
  vacia (longitud 0 causa division entre cero).
Postcondiciones: archivo_cifrado contiene los bytes transformados. Ambos archivos
  quedan cerrados al finalizar.
*/
void aplicar_xor(const char *archivo_origen, const char *archivo_cifrado, const char *clave)
{
    FILE *origen  = fopen(archivo_origen,  "rb"); /* Lectura binaria */
    FILE *cifrado = fopen(archivo_cifrado, "wb"); /* Escritura binaria */

    /* Proceso: verificar apertura de ambos archivos */
    if (origen == NULL || cifrado == NULL) {
        perror("Error al abrir los archivos");
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");

        /* Cerrar el que se haya abierto para evitar fugas */
        if (origen  != NULL) fclose(origen);
        if (cifrado != NULL) fclose(cifrado);
        return;
    }

    int clave_tamanio = strlen(clave); /* Longitud de la clave para el ciclo modular */
    int contador = 0;                  /* Indice ciclico sobre la clave */
    char byte;                         /* Byte leido del archivo origen */

    /* Proceso: leer, transformar y escribir byte a byte */
    while (fread(&byte, sizeof(byte), 1, origen) == 1) {
        /* Cifrado XOR: byte ^ clave[contador % longitud_clave] */
        byte ^= clave[contador % clave_tamanio];

        /* Salida: escribir byte transformado en el archivo destino */
        fwrite(&byte, sizeof(byte), 1, cifrado);
        contador++;
    }

    fclose(origen);
    fclose(cifrado);
}


/*
Nombre: usuario_existe
Objetivo: Verificar si un nombre de usuario ya esta registrado en file_usuarios.txt.
Descripcion: Abre file_usuarios.txt en modo lectura y recorre cada linea con
  fscanf leyendo dos tokens (nombre y contrasena). Compara cada nombre con el
  buscado usando strcmp (comparacion exacta, sensible a mayusculas).
Parametros:
  - nombre : const char* - nombre de usuario a buscar
Retorno: int - 1 si el nombre ya existe, 0 si no existe o si no se puede abrir el archivo
Precondiciones: nombre no debe ser NULL.
Postcondiciones: El archivo queda cerrado. No se modifica.
*/
int usuario_existe(const char *nombre)
{
    char nombre_archivo[MAX_NOMBRE];
    char contrasena[MAX_CONS];

    /* Proceso: abrir archivo para lectura */
    FILE *archivo = fopen(FILE_USUARIOS, "r");
    if (archivo == NULL) {
        /* Si no existe aun, no hay usuarios registrados */
        return 0;
    }

    /* Proceso: busqueda secuencial por nombre */
    while (fscanf(archivo, "%49s %19s", nombre_archivo, contrasena) == 2) {
        if (strcmp(nombre_archivo, nombre) == 0) {
            fclose(archivo);
            return 1; /* Nombre encontrado: usuario existe */
        }
    }

    fclose(archivo);
    return 0; /* Nombre no encontrado: usuario unico */
}


/*
Nombre: verificar_usuario
Objetivo: Comprobar que el par nombre/contrasena coincide con un registro existente.
Descripcion: Abre file_usuarios.txt en modo lectura y recorre cada linea con
  fscanf. Compara simultaneamente nombre y contrasena con los valores almacenados.
  La comparacion es exacta y sensible a mayusculas en ambos campos.
Parametros:
  - nombre    : const char* - nombre de usuario ingresado
  - contrasena: const char* - contrasena ingresada
Retorno: int - 1 si las credenciales son validas, 0 si no coinciden o hay error
Precondiciones: nombre y contrasena no deben ser NULL.
Postcondiciones: El archivo queda cerrado. No se modifica.
*/
int verificar_usuario(const char *nombre, const char *contrasena)
{
    char nombre_archivo[MAX_NOMBRE];
    char contrasena_archivo[MAX_CONS];

    /* Proceso: abrir archivo para lectura */
    FILE *archivo = fopen(FILE_USUARIOS, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        printf("Presiona Enter para continuar...");
        getchar();
        system("cls");
        return 0;
    }

    /* Proceso: busqueda secuencial por nombre y contrasena */
    while (fscanf(archivo, "%49s %19s", nombre_archivo, contrasena_archivo) == 2) {
        if (strcmp(nombre_archivo, nombre) == 0 &&
            strcmp(contrasena_archivo, contrasena) == 0) {
            fclose(archivo);
            return 1; /* Credenciales correctas */
        }
    }

    fclose(archivo);
    return 0; /* Credenciales incorrectas o no encontradas */
}
