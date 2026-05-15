# 👥 Proceso de Desarrollo — CryptoNote

**Equipo:** Estructuradores  
**Proyecto:** CryptoNote — Sistema de Gestión y Cifrado de Archivos

---

## Participación individual en la codificación

> Este documento reporta la participación de cada integrante respecto a la implementación de los módulos del sistema.

### Barrera Escalante Cristofer — Desarrollador A (Módulo de Autenticación)

**Módulo asignado:** Autenticación de usuarios

**Funciones implementadas:**
- `crear_cuenta()` — Flujo completo de registro: captura de nombre, validación de duplicados, escritura en archivo.
- `iniciar_sesion()` — Verificación de credenciales y redirección al menú secundario.
- `usuario_existe()` — Búsqueda secuencial en `file_usuarios.txt` para evitar duplicados.
- `verificar_usuario()` — Lectura y comparación de credenciales almacenadas.

**Contribución:** Implementación completa del módulo de autenticación, incluyendo el manejo de errores de archivo (`perror`), gestión del buffer de entrada con `fgets`/`strcspn`, y lógica de control de flujo entre el menú principal y el menú de sesión.

---

### Couoh Mis Guillermo Moisés — Desarrollador B (Módulo de Archivos y Cifrado)

**Módulo asignado:** Gestión de archivos y cifrado XOR

**Funciones implementadas:**
- `crear_archivo()` — Creación de archivos `.txt` con manejo de errores.
- `escribir_archivo()` — Entrada multilínea con terminación por palabra reservada `salir`.
- `cifrar_archivo()` — Interfaz de usuario para el proceso de cifrado.
- `descifrar_archivo()` — Interfaz de usuario para el proceso de descifrado.
- `aplicar_xor()` — Algoritmo XOR cíclico byte a byte para cifrado/descifrado simétrico.
- `segundo_menu()` — Menú de opciones del usuario autenticado.

**Contribución:** Implementación del módulo de manejo de archivos con operaciones de lectura/escritura binaria (`fopen` en modos `rb`/`wb`), diseño e implementación del algoritmo XOR cíclico con clave personalizada, y desarrollo del menú secundario.

---

### García Gamboa Eric Emir — Tester

**Responsabilidad:** Validación y pruebas del sistema

**Actividades realizadas:**
- Diseño de casos de prueba basados en los casos de uso (flujos básicos y alternativos).
- Pruebas de registro con nombres duplicados.
- Pruebas de inicio de sesión con credenciales correctas e incorrectas.
- Pruebas de creación de archivos con nombres válidos e inválidos.
- Pruebas de cifrado y descifrado con claves correctas e incorrectas.
- Verificación de la simetría del algoritmo XOR (cifrar y descifrar produce el archivo original).
- Documentación de bugs encontrados (división entre cero con clave vacía, comportamiento con entrada no numérica en menús).
- Compilación y ejecución en Zinjal para validación final.

---

### Jiménez Hernández Xicoténcatl — Documentador

**Responsabilidad:** Documentación técnica del proyecto

**Actividades realizadas:**
- Redacción de los requerimientos funcionales RF-001 a RF-009.
- Elaboración de los casos de uso CU1, CU2 y CU3 con flujos básicos y alternativos.
- Elaboración del diagrama de casos de uso.
- Documentación del estándar de codificación (nombrado, comentarios, estilo).
- Mantenimiento de la bitácora del equipo en Google Sheets.
- Redacción de la sección de antecedentes y comparativa con productos similares.

---

### Sandoval Tamayo José Heynar — Documentador

**Responsabilidad:** Documentación técnica del proyecto

**Actividades realizadas:**
- Redacción de los requerimientos funcionales RF-010 a RF-017.
- Elaboración de los casos de uso CU4, CU5 y CU6 con flujos básicos y alternativos.
- Elaboración de la matriz de requerimientos vs objetivos específicos (RF y RNF).
- Redacción de los requerimientos no funcionales RNF-001 a RNF-007.
- Elaboración del modelo de desarrollo y organización del equipo.
- Documentación del diagrama de bloques del sistema.

---

## Contribución general del equipo

### Resumen de participación por módulo

| Módulo | Responsable principal | Funciones |
|---|---|---|
| Autenticación | Barrera Escalante Cristofer | `crear_cuenta`, `iniciar_sesion`, `usuario_existe`, `verificar_usuario` |
| Archivos y cifrado | Couoh Mis Guillermo Moisés | `crear_archivo`, `escribir_archivo`, `cifrar_archivo`, `descifrar_archivo`, `aplicar_xor`, `segundo_menu` |
| Menú principal | Ambos desarrolladores | `main()` |
| Pruebas | García Gamboa Eric Emir | Casos de prueba y validación |
| Documentación | Jiménez Hernández / Sandoval Tamayo | Reporte completo, requerimientos, diagramas |

---

## Estadísticas del repositorio

> Las siguientes métricas se pueden verificar directamente en el repositorio de GitHub del equipo.

### Commits por integrante
Consultar la pestaña **Insights → Contributors** en GitHub para ver el número de commits, líneas agregadas y eliminadas por cada miembro del equipo.

### Distribución de trabajo
- **Líneas de código fuente:** ~350 líneas en `proyecto_c.c`
- **Funciones totales:** 11 funciones + `main()`
- **Módulo A (autenticación):** 4 funciones (~130 líneas)
- **Módulo B (archivos y cifrado):** 7 funciones + menú secundario (~220 líneas)

### Hitos cumplidos

| Semana | Hito | Estado |
|---|---|---|
| Semana 1 | Módulo de autenticación funcionando | ✓ Completado |
| Semana 2 | Módulo de cifrado y descifrado | ✓ Completado |
| Semana 3 | Integración, pruebas y documentación final | ✓ Completado |

---

## Herramientas utilizadas

| Herramienta | Uso |
|---|---|
| **Zinjal** | Compilador y editor de código C |
| **GCC** | Compilación estándar |
| **GitHub** | Control de versiones y repositorio del proyecto |
| **GitHub Projects** | Tablero Kanban: Por hacer / En progreso / Hecho |
| **Google Sheets** | Bitácora diaria de actividades |
| **Google Drive** | Compartición de documentación |

---

## Listas de cotejo

### Lista de cotejo — Propuesta original

| Elemento | Cumplido |
|---|---|
| Nombre del equipo e integrantes | ✓ |
| Nombre representativo del proyecto | ✓ |
| Antecedentes y comparativa con productos similares | ✓ |
| Descripción del producto software | ✓ |
| Objetivo general y específicos | ✓ |
| Diagrama de casos de uso | ✓ |
| Interfaces de usuario (mockups de consola) | ✓ |
| Mapeo de requerimientos RF | ✓ |
| Mapeo de requerimientos RNF | ✓ |
| Casos de uso detallados | ✓ |
| Estándar de codificación | ✓ |
| Diagrama de bloques | ✓ |
| Modelo de desarrollo | ✓ |
| Organización del equipo | ✓ |
| Esquema de monitoreo y bitácoras | ✓ |

### Lista de cotejo — Avances

| Elemento | Cumplido |
|---|---|
| Código fuente documentado en ANSI C | ✓ |
| Descripción de proyectos/productos similares con diferencias técnicas | ✓ |
| Alcance del proyecto revisado | ✓ |
| Diagrama de casos de uso ampliado (una página) | ✓ |
| Ayudas incluidas en el menú de opciones | ✓ |
| Descripción de Usuarios (no Distinción) | ✓ |
| RF(17) y RNF(7) con tabla compacta | ✓ |
| Tabla de casos de uso | ✓ |
| Formato aplicado al reporte y texto | ✓ |
| Diagrama de bloques corregido | ✓ |
| Proceso de Desarrollo (no Módulo) | ✓ |
| Participación de cada integrante señalada | ✓ |

### Lista de cotejo — Entrega final

| Elemento | Cumplido |
|---|---|
| Reporte completo (propuesta + avances mejorado + entrega final) | ✓ |
| Mapeo de requerimientos con revisión de funcionalidad | ✓ |
| Código fuente completo y documentado (ANSI C, buenas prácticas) | ✓ |
| Organización general del sistema documentada | ✓ |
| Organización del código con base en entradas, procesamiento y salidas | ✓ |
| Mapeo de requerimientos con funciones del sistema | ✓ |
| Reporte de participación individual | ✓ |
| Contribución general con elementos objetivos y medibles | ✓ |
| Reporte de estadísticas del repositorio (GitHub) | ✓ |
