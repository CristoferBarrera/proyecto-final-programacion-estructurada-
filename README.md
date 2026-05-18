# 🔐 CryptoNote — Sistema de Gestión y Cifrado de Archivos

**Equipo:** Estructuradores  
**Materia:** Programación Estructurada — Segundo Semestre  
**Facultad de Matemáticas, UADY**

---

## 📋 Descripción

CryptoNote es una aplicación de consola desarrollada en lenguaje C estándar (ANSI C) que integra tres funcionalidades principales:

- **Autenticación de usuarios** con registro e inicio de sesión local.
- **Creación y edición de archivos de texto** desde la consola.
- **Cifrado y descifrado de archivos** mediante el algoritmo XOR con clave personalizada.

El sistema opera completamente **offline**, sin dependencias externas ni conexión a internet. Todo el almacenamiento es local.

---

## 🗂️ Estructura del repositorio

```
CryptoNote/
├── proyecto_c.c              # Código fuente principal
├── README.md                 # Este archivo
├── DOCUMENTACION.md          # Reporte completo del proyecto
├── MAPEO_REQUERIMIENTOS.md   # Tabla de RF, RNF y objetivos específicos
└── PROCESO_DESARROLLO.md     # Participación individual y contribución del equipo
```

---

## 👥 Integrantes

| Nombre | Rol |
|--------|-----|
| Barrera Escalante Cristofer | Desarrollador — Módulo A (Autenticación) |
| Couoh Mis Guillermo Moisés | Desarrollador — Módulo B (Archivos y Cifrado) |
| García Gamboa Eric Emir | Tester |
| Jiménez Hernández Xicoténcatl | Documentador |
| Sandoval Tamayo José Heynar | Documentador |

---

## ⚙️ Compilación y ejecución

### Requisitos
- Compilador C estándar: GCC o Clang
- Sistema operativo: Windows (usa `system("cls")` para limpiar pantalla)

### Compilar con GCC
```bash
gcc proyecto_c.c -o cryptonote
```

### Ejecutar
```bash
./cryptonote
```
> En Windows: `cryptonote.exe`

---

## 🚀 Funcionalidades

### Menú principal
```
--- MENU ---
1. Crear cuenta
2. Iniciar sesión
3. Salir
```

### Menú de sesión (usuario autenticado)
```
--- MENU ---
¡Hola, [usuario]!
1. Crear archivo txt
2. Cifrar archivo txt
3. Descifrar archivo txt
4. Cerrar sesión
```

### Flujo de uso típico
1. Crear una cuenta con nombre de usuario y contraseña.
2. Iniciar sesión.
3. Crear un archivo `.txt` y escribir contenido (escribe `salir` para terminar).
4. Cifrar el archivo con una clave personalizada.
5. Descifrar el archivo con la misma clave para recuperar el contenido original.

---

## 🔒 Algoritmo de cifrado

Se utiliza cifrado **XOR cíclico**:

- Cada byte del archivo se combina con un carácter de la clave usando la operación lógica XOR.
- La clave se recorre cíclicamente (`clave[contador % longitud_clave]`).
- La operación es **simétrica**: aplicar XOR dos veces con la misma clave restaura el dato original.
- ⚠️ No es un cifrado criptográficamente robusto; es adecuado para fines educativos y protección ligera.

---

## ⚠️ Limitaciones conocidas

- Las contraseñas se almacenan en texto plano en `file_usuarios.txt`.
- `system("cls")` solo funciona en Windows. En Linux usar `system("clear")`.
- Si se ingresa una clave vacía al cifrar/descifrar, el programa produce un error de división entre cero.
- No se valida la sobreescritura de archivos existentes al cifrar.

---

## 📄 Documentación completa

Consulta [`DOCUMENTACION.md`](DOCUMENTACION.md) para el reporte completo incluyendo antecedentes, descripción del producto, objetivos, diagrama de casos de uso, requerimientos funcionales y no funcionales, casos de uso detallados, estándar de codificación y modelo de desarrollo.
