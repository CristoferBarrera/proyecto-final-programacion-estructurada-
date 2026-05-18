<div align="center">

<br>

<img src="https://img.shields.io/badge/UADY-Facultad%20de%20Matem%C3%A1ticas-4B3F8C?style=flat-square" />
<img src="https://img.shields.io/badge/Ingenier%C3%ADa%20de%20Software-Segundo%20Semestre-1D9E75?style=flat-square" />
<img src="https://img.shields.io/badge/Programaci%C3%B3n%20Estructurada-2025--2026-BA7517?style=flat-square" />

<br><br>

# 🔐 CryptoNote

### Sistema de Gestión y Cifrado de Archivos

*Aplicación de consola en lenguaje C que integra autenticación de usuarios,*  
*creación de archivos de texto y cifrado simétrico XOR con clave personalizada.*

<br>

![C](https://img.shields.io/badge/Lenguaje-ANSI%20C-A8B9CC?style=flat-square&logo=c&logoColor=white)
![Offline](https://img.shields.io/badge/Modo-Offline-1D9E75?style=flat-square)
![Cifrado](https://img.shields.io/badge/Cifrado-XOR%20C%C3%ADclico-4B3F8C?style=flat-square)
![Estado](https://img.shields.io/badge/Estado-Entrega%20Final-1D9E75?style=flat-square)

</div>

---

## 👥 Equipo: Estructuradores

| Integrante | Rol |
|---|---|
| Barrera Escalante Cristofer | Desarrollador — Módulo de autenticación |
| Couoh Mis Guillermo Moisés | Desarrollador — Módulo de cifrado y archivos |
| García Gamboa Eric Emir | Tester |
| Jiménez Hernández Xicoténcatl | Documentador |
| Sandoval Tamayo José Heynar | Documentador |

---

## 📁 Contenido del repositorio

| Archivo | Descripción |
|---|---|
| [`proyecto_c.c`](proyecto_c.c) | Código fuente completo documentado en ANSI C |
| [`README.md`](README.md) | Descripción general, instrucciones de compilación y uso |
| [`DOCUMENTACION.md`](DOCUMENTACION.md) | Reporte completo: antecedentes, objetivos, requerimientos, casos de uso, estándar de código y modelo de desarrollo |
| [`MAPEO_REQUERIMIENTOS.md`](MAPEO_REQUERIMIENTOS.md) | Matrices RF / RNF vs objetivos específicos y revisión de funcionalidad |
| [`PROCESO_DESARROLLO.md`](PROCESO_DESARROLLO.md) | Participación individual, contribución del equipo y listas de cotejo |

---

## ⚡ Inicio rápido

```bash
# Compilar
gcc proyecto_c.c -o cryptonote

# Ejecutar (Windows)
cryptonote.exe
```

---

## 🔒 ¿Qué hace CryptoNote?

```
--- MENU ---          --- MENU (sesión) ---
1. Crear cuenta       1. Crear archivo txt
2. Iniciar sesión     2. Cifrar archivo txt
3. Salir              3. Descifrar archivo txt
                      4. Cerrar sesión
```

1. **Registrarse** con nombre de usuario y contraseña (sin duplicados).
2. **Crear** un archivo `.txt` y escribir contenido multilínea.
3. **Cifrar** el archivo con una clave personalizada usando XOR cíclico.
4. **Descifrar** con la misma clave para recuperar el contenido original.

---

<div align="center">

Universidad Autónoma de Yucatán · Facultad de Matemáticas · 2025–2026

</div>
