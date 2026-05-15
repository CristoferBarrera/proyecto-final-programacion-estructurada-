# 📄 Documentación Completa — CryptoNote

**Universidad Autónoma de Yucatán — Facultad de Matemáticas**  
**Licenciatura en Ingeniería de Software — Segundo Semestre**  
**Materia:** Programación Estructurada  
**Equipo:** Estructuradores  
**Proyecto:** CryptoNote — Sistema de Gestión y Cifrado de Archivos

---

## 1. Antecedentes del proyecto

En el mercado actual existen numerosas herramientas para la edición y protección de archivos de texto. Los editores de texto comunes como el Bloc de notas, Notepad++ o Gedit permiten crear y editar archivos sin mecanismos de seguridad integrados. Por su parte, soluciones de cifrado como VeraCrypt o AxCrypt protegen archivos mediante algoritmos robustos (AES, Serpent), pero están orientadas a volúmenes completos o requieren instalación especializada, resultando complejas para usuarios no técnicos. Aplicaciones de notas seguras como Standard Notes o Evernote dependen de conexión a internet y almacenamiento en la nube, lo que introduce riesgos de privacidad.

**CryptoNote** se distingue por ser una aplicación de consola ligera, autónoma y de código abierto que integra autenticación de usuarios, creación de archivos de texto y cifrado XOR personalizado desde una interfaz de menús intuitiva. Su principal contribución es ofrecer una herramienta didáctica y funcional que:

- No requiere instalación adicional.
- Funciona completamente offline.
- Permite comprender y aplicar conceptos de programación estructurada, manejo de archivos y criptografía simétrica básica.
- Centraliza la gestión de usuarios en un archivo local, sin dependencias de red.

### Comparativa con productos similares

| Característica | Notepad++ | VeraCrypt | Standard Notes | **CryptoNote** |
|---|---|---|---|---|
| Cifrado integrado | ✗ | ✓ | ✓ | ✓ |
| Requiere instalación | ✓ | ✓ | ✓ | ✗ |
| Funciona offline | ✓ | ✓ | Parcial | ✓ |
| Interfaz simple | ✓ | ✗ | ✓ | ✓ |
| Gestión de usuarios | ✗ | ✗ | ✓ | ✓ |
| Código educativo | ✗ | ✗ | ✗ | ✓ |

---

## 2. Descripción del producto

CryptoNote es un software de consola desarrollado en lenguaje C estándar (ANSI C), diseñado para la creación, edición y protección de archivos de texto mediante cifrado simétrico. Permite a los usuarios:

- Registrarse e iniciar sesión con credenciales locales.
- Crear archivos de texto con múltiples líneas.
- Aplicar cifrado/descifrado XOR con clave personalizada.

La interfaz usa menús numéricos con limpieza de pantalla entre operaciones. Todo el almacenamiento (credenciales y archivos) es local. El sistema es compatible con cualquier plataforma que soporte compiladores estándar de C (GCC, Clang).

---

## 3. Objetivo general

Desarrollar una aplicación integral de gestión de archivos en lenguaje C que implemente un sistema de seguridad basado en criptografía simétrica (XOR) y control de acceso por usuarios, garantizando la confidencialidad de la información almacenada mediante una interfaz de consola funcional y eficiente.

---

## 4. Objetivos específicos

**OE1 — Registro sin duplicados:** Implementar un sistema de gestión de identidades usando `file_usuarios.txt` como base de datos persistente, con búsqueda secuencial antes de cada registro para garantizar unicidad de nombres de usuario.

**OE2 — Creación de archivos:** Desarrollar funciones de manipulación de flujos de datos (`FILE *`) que permitan generar documentos `.txt` dinámicamente con entrada de múltiples líneas.

**OE3 — Cifrado XOR:** Codificar una rutina criptográfica que use el operador lógico binario XOR para transformar caracteres legibles en bytes cifrados, aplicando una máscara de bits basada en la clave del usuario.

**OE4 — Recuperación con misma clave:** Garantizar la integridad de recuperación de datos mediante simetría algorítmica: la misma clave aplicada al archivo cifrado restaura el estado original bit a bit.

**OE5 — Interfaz y manejo de errores:** Diseñar menús jerárquicos con limpieza de consola, validación de errores críticos (archivos no encontrados, credenciales incorrectas, etc.) y mensajes claros al usuario.

---

## 5. Diagrama de casos de uso

El sistema contempla tres actores:

**Usuario no autenticado:** Puede registrar una cuenta o iniciar sesión. No tiene acceso a la gestión de archivos.

**Usuario autenticado:** Tras iniciar sesión, puede crear archivos de texto, cifrarlos, descifrarlos y cerrar sesión.

**Administrador (futuro):** Rol previsto para una segunda iteración con privilegios adicionales como gestión de usuarios y visualización de logs.

### Casos de uso principales

| Caso de uso | Actor | Requerimientos |
|---|---|---|
| CU1: Registrar cuenta | Usuario no autenticado | RF-002, RF-003, RF-004 |
| CU2: Iniciar sesión | Usuario no autenticado | RF-005 |
| CU3: Crear archivo y escribir | Usuario autenticado | RF-008, RF-009 |
| CU4: Cifrar archivo | Usuario autenticado | RF-010, RF-012 |
| CU5: Descifrar archivo | Usuario autenticado | RF-011, RF-012 |
| CU6: Cerrar sesión | Usuario autenticado | RF-007 |

---

## 6. Interfaces de usuario

### Menú principal
```
--- MENU ---
1. Crear cuenta
2. Iniciar sesión
3. Salir
Seleccione una opción: _
```

### Menú de sesión
```
--- MENU ---
¡Hola, <nombre_usuario>!
1. Crear archivo txt
2. Cifrar archivo txt
3. Descifrar archivo txt
4. Cerrar sesión
Seleccione una opción: _
```

### Pantalla: Crear cuenta
```
--- Crear cuenta ---
Ingrese un nombre de usuario: [usuario]
Ingrese una contraseña: [****]
Cuenta creada exitosamente.
Presiona Enter para continuar...
```

### Pantalla: Inicio de sesión
```
--- Iniciar sesion ---
Ingrese su nombre de usuario: [usuario]
Ingrese su contraseña: [****]
Inicio de sesión exitoso. ¡Bienvenido(a), [usuario]!
Presiona Enter para continuar...
```

### Pantalla: Cifrar archivo
```
--- Cifrar archivo ---
Ingrese el nombre del archivo original a cifrar: notas_personales.txt
Ingrese el nombre del nuevo archivo cifrado: notas_secretas.dat
--- Importante ---
Guarda la clave, sin ella no podrás descifrar el archivo
Ingrese su clave de cifrado: MiClaveMaestra_2026!
Archivo cifrado correctamente: notas_secretas.dat
Presiona Enter para continuar...
```

### Pantalla: Descifrar archivo
```
--- Descifrar archivo ---
Ingrese el nombre del archivo a descifrar: notas_secretas.dat
Ingrese el nombre del nuevo archivo descifrado: notas_recuperadas.txt
Ingrese la clave de cifrado: MiClaveMaestra_2026!
Archivo descifrado correctamente: notas_recuperadas.txt
Presiona Enter para continuar...
```

---

## 7. Requerimientos funcionales

### RF-001: Menú principal interactivo
**Actor:** Usuario no autenticado.  
**Objetivo:** Navegación inicial mediante menú cíclico con operaciones de registro, inicio de sesión y salida.  
**Precondición:** Programa iniciado sin sesión activa.  
**Postcondición:** Ejecuta la operación seleccionada; si el usuario escoge Salir, el programa termina.  
**Manejo de errores:** Opción fuera de rango muestra "Opción inválida."; no se valida entrada no numérica.

---

### RF-002: Registro de nueva cuenta
**Actor:** Usuario no autenticado.  
**Objetivo:** Crear cuenta evitando nombres duplicados y almacenándola en `file_usuarios.txt`.  
**Precondición:** El programa tiene permisos de lectura/escritura en el directorio.  
**Postcondición:** Nueva línea `nombre contraseña` en `file_usuarios.txt` si el registro fue exitoso.  
**Manejo de errores:** Nombre duplicado muestra mensaje específico; fallo de archivo muestra `perror`.

---

### RF-003: Verificación de duplicados
**Actor:** Sistema (invocado durante el registro).  
**Objetivo:** Determinar si un nombre de usuario ya está registrado.  
**Postcondición:** Retorna `1` si existe, `0` si no.

---

### RF-004: Almacenamiento persistente de credenciales
**Actor:** Sistema.  
**Objetivo:** Guardar nueva credencial en texto plano al final de `file_usuarios.txt`.  
**Postcondición:** Archivo contiene nueva línea con nombre y contraseña.

---

### RF-005: Inicio de sesión
**Actor:** Usuario no autenticado.  
**Objetivo:** Verificar credenciales y, si son válidas, dar acceso al menú secundario.  
**Postcondición:** Redirección al menú secundario si exitoso; regreso al menú principal si no.

---

### RF-006: Menú de usuario autenticado
**Actor:** Usuario autenticado.  
**Objetivo:** Mostrar operaciones disponibles y ejecutar la seleccionada.  
**Postcondición:** Tras cerrar sesión, el usuario regresa al menú principal.

---

### RF-007: Cierre de sesión
**Actor:** Usuario autenticado.  
**Objetivo:** Terminar la sesión y retornar al menú principal.  
**Postcondición:** El estado de autenticación se pierde; el usuario queda no autenticado.

---

### RF-008: Creación de archivo de texto
**Actor:** Usuario autenticado.  
**Objetivo:** Crear un archivo `.txt` con el nombre provisto.  
**Precondición:** Permiso de escritura en el directorio.  
**Postcondición:** El archivo existe en disco. Se llama a `escribir_archivo` para agregar contenido.

---

### RF-009: Escritura de contenido multilínea
**Actor:** Usuario autenticado.  
**Objetivo:** Permitir ingreso de múltiples líneas de texto, finalizando con la palabra reservada `salir`.  
**Postcondición:** El archivo contiene todas las líneas ingresadas excepto la palabra `salir`.  
**Manejo de errores:** La comparación es exacta (distingue mayúsculas/minúsculas). Cada línea limitada a 255 caracteres.

---

### RF-010: Cifrado de archivos (XOR cíclico)
**Actor:** Usuario autenticado.  
**Objetivo:** Transformar un archivo original en uno cifrado ilegible mediante XOR con clave cíclica.  
**Postcondición:** Archivo cifrado con bytes transformados por XOR.  
**Bug conocido:** Clave vacía produce división entre cero (comportamiento indefinido).

---

### RF-011: Descifrado de archivos
**Actor:** Usuario autenticado.  
**Objetivo:** Revertir el cifrado XOR, recuperando el contenido original con la misma clave.  
**Postcondición:** Archivo con texto original si la clave es correcta; datos incoherentes si no.

---

### RF-012: Solicitud de clave de cifrado/descifrado
**Actor:** Usuario autenticado.  
**Objetivo:** Obtener la clave sin almacenarla y pasarla al algoritmo XOR.  
**Postcondición:** La clave existe solo en memoria durante la operación; no se guarda en ningún archivo.

---

### RF-013: Manejo básico de errores de archivo
**Actor:** Sistema.  
**Objetivo:** Informar sobre fallos al abrir archivos y evitar terminación abrupta.  
**Implementación:** Se verifica `NULL` en cada `fopen`; se muestra `perror` con descripción del sistema.

---

### RF-014: Limpieza de pantalla
**Actor:** Sistema.  
**Objetivo:** Mantener la consola despejada.  
**Implementación:** `system("cls")` — dependiente de Windows.  
**Limitación:** No portable a sistemas Unix sin cambiar a `system("clear")`.

---

### RF-015: Pausa para lectura de mensajes
**Actor:** Sistema.  
**Objetivo:** Permitir leer mensajes de resultado antes de limpiar pantalla.  
**Implementación:** `printf("Presiona Enter para continuar...")` seguido de `getchar()`.

---

### RF-016: Control de entrada de datos
**Actor:** Sistema.  
**Objetivo:** Leer cadenas de forma segura evitando desbordamiento de buffer.  
**Implementación:** `fgets` con tamaño máximo explícito en todos los campos; eliminación de `\n` con `strcspn`.

---

### RF-017: Validación de opción numérica en menús
**Actor:** Sistema.  
**Objetivo:** Aceptar solo números dentro del rango esperado.  
**Implementación:** `scanf("%d", &opc)` con `default` en `switch` para valores fuera de rango.  
**Limitación:** Entrada no numérica puede causar comportamiento impredecible (no se limpia `stdin`).

---

## 8. Requerimientos no funcionales

| ID | Nombre | Descripción |
|---|---|---|
| RNF-001 | Código en C estándar (ANSI C) | Solo usa `<stdio.h>`, `<stdlib.h>`, `<string.h>`. Compatible con GCC y Clang. |
| RNF-002 | Funcionamiento completamente offline | Sin cabeceras de red ni llamadas externas. Persistencia local. |
| RNF-003 | Consistencia en la interfaz de consola | Todos los menús con formato `--- TITULO ---`. Patrón: operación + resultado + pausa + limpieza. |
| RNF-004 | Manejo seguro de buffers | Lecturas acotadas con `fgets`. Tamaños: nombre (50), contraseña (20), archivo (100), línea (256). |
| RNF-005 | Separación de responsabilidades | Cada función tiene un propósito único. `aplicar_xor` solo hace transformación; los menús solo despachan. |
| RNF-006 | Comentarios descriptivos | Cada función tiene bloque `/* Nombre / Objetivo / Descripción */`. |
| RNF-007 | Uso de identificadores legibles | Convención `snake_case`. Nombres reflejan acción o dato: `crear_cuenta`, `nombre_archivo`. |

---

## 9. Casos de uso detallados

### CU1: Registrar cuenta

**Flujo básico:**
1. Usuario selecciona `1` en el menú principal.
2. Se muestra `--- Crear cuenta ---` y solicita nombre de usuario.
3. Usuario ingresa nombre (máx. 49 caracteres).
4. El sistema verifica que el nombre no exista en `file_usuarios.txt`.
5. Si no existe, solicita contraseña (máx. 19 caracteres).
6. Se abre `file_usuarios.txt` en modo append y se escribe `nombre contraseña\n`.
7. Se muestra confirmación y regresa al menú principal.

**Flujo alternativo A — Nombre duplicado:** Muestra mensaje y regresa al menú sin crear la cuenta.  
**Flujo alternativo B — Error de archivo:** Muestra `perror` y regresa al menú.

---

### CU2: Iniciar sesión

**Flujo básico:**
1. Usuario selecciona `2` en el menú principal.
2. Solicita nombre de usuario y contraseña.
3. El sistema lee `file_usuarios.txt` buscando coincidencia exacta.
4. Si coincide, muestra bienvenida y presenta el menú secundario.

**Flujo alternativo A — Credenciales incorrectas:** Mensaje de error y regreso al menú principal.  
**Flujo alternativo B/C — Error o archivo inexistente:** Trata como credenciales incorrectas.

---

### CU3: Crear archivo de texto y escribir contenido

**Flujo básico:**
1. Usuario selecciona `1` en el menú secundario.
2. Ingresa nombre del archivo (incluyendo extensión `.txt`).
3. Sistema crea el archivo en modo `"w"`.
4. Usuario escribe líneas de texto; cada `Enter` guarda la línea.
5. Al escribir `salir` en una línea nueva, el sistema cierra el archivo.
6. Muestra confirmación y regresa al menú secundario.

---

### CU4: Cifrar archivo

**Flujo básico:**
1. Usuario selecciona `2` en el menú secundario.
2. Ingresa nombre del archivo a cifrar.
3. Ingresa nombre del archivo de salida cifrado.
4. Ingresa clave de cifrado.
5. Sistema aplica XOR byte a byte con clave cíclica.
6. Muestra confirmación del archivo cifrado.

**Flujo alternativo A — Archivo no encontrado:** Muestra `perror` y regresa.  
**Flujo alternativo B — Clave vacía:** Error de división entre cero (cierre abrupto).  
**Flujo alternativo C — Sobrescritura:** Si el archivo destino existe, se sobreescribe sin aviso.

---

### CU5: Descifrar archivo

**Flujo básico:** Idéntico al cifrado. Se aplica el mismo algoritmo XOR con la misma clave.

**Flujo alternativo B — Clave incorrecta:** No hay notificación. El archivo de salida contiene datos incoherentes.

---

### CU6: Cerrar sesión

**Flujo básico:**
1. Usuario selecciona `4` en el menú secundario.
2. Muestra "Cerrando sesión..." y regresa al menú principal.

---

## 10. Estándar de codificación

### Nombrado de variables y funciones
- **Variables y funciones:** `snake_case` — ejemplo: `nombre_archivo`, `crear_cuenta`.
- **Macros y constantes:** `MAYUSCULAS_CON_GUIONES` — ejemplo: `MAX_NOMBRE`, `FILE_USUARIOS`.
- Contadores simples: se permite `i`, `j`, `contador` cuando el contexto es claro.

### Estructura de comentarios por función
```c
/*
Nombre: <nombre_funcion>
Objetivo: <breve objetivo>
Descripcion: <detalle del algoritmo, parametros y retorno>
Parametros:
  - <nombre> : <tipo> - <descripcion>
Retorno: <tipo y significado>
Precondiciones: <si las hay>
Postcondiciones: <efectos>
*/
```

### Estilo de código
- **Indentación:** tabulaciones (uniforme en todo el proyecto).
- **Llaves:** estilo K&R — llave de apertura al final de la línea.
- **Bloques:** siempre usar `{}` aunque sea una sola sentencia.
- **Longitud de línea:** máximo 100 caracteres.
- **Bibliotecas:** incluir solo las necesarias (`<stdio.h>`, `<stdlib.h>`, `<string.h>`).

### Archivos
- Código fuente: `proyecto_c.c` (único archivo; si se modulariza: `auth.c`, `crypto.c`).
- Datos: `file_usuarios.txt` para credenciales.
- Cabeceras: si se crean, mismo nombre que módulo con extensión `.h`.

---

## 11. Modelo de desarrollo

Se adopta un proceso **iterativo e incremental** con fases bien definidas:

| Fase | Actividad |
|---|---|
| Análisis | Levantamiento de requerimientos y diseño de arquitectura modular |
| Diseño | Diagrama de casos de uso, estructura de funciones, prototipo de interfaz |
| Implementación | Codificación por módulos: autenticación, archivos, cifrado, menús |
| Pruebas | Verificación de cada función, flujos alternativos, ejecución en consola |
| Revisión | Ciclos cortos de 1-2 semanas para refinar funcionalidades |

### Herramientas
- **Compilador/Editor:** Zinjal
- **Control de versiones:** Git con repositorio en GitHub
- **Documentación:** Archivos Markdown compartidos en Google Drive

---

## 12. Organización del equipo

| Rol | Responsable | Módulo |
|---|---|---|
| Desarrollador A | Barrera Escalante Cristofer | Autenticación (`crear_cuenta`, `iniciar_sesion`, funciones de verificación) |
| Desarrollador B | Couoh Mis Guillermo Moisés | Archivos y cifrado (`crear_archivo`, `escribir_archivo`, `aplicar_xor`, menús) |
| Tester | García Gamboa Eric Emir | Casos de prueba, validación en Zinjal |
| Documentador | Jiménez Hernández Xicoténcatl | Requerimientos, estándar de código, bitácoras |
| Documentador | Sandoval Tamayo José Heynar | Requerimientos, estándar de código, bitácoras |

### Esquema de monitoreo
- **Reunión diaria:** 10–15 minutos para reportar avances, bloqueos y plan del día.
- **Bitácora diaria (Google Sheets):** fecha, tareas realizadas, horas, problemas, porcentaje de avance.
- **Hitos semanales:** Semana 1 — autenticación; Semana 2 — cifrado y descifrado; Semana 3 — integración y pruebas.
- **Tablero Kanban:** GitHub Projects con columnas: *Por hacer*, *En progreso*, *Hecho*.
