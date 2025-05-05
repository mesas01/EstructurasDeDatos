# 🖼️ Proyecto de Procesamiento de Imágenes en C++

## 📌 Introducción

Este proyecto es una aplicación en **C++** diseñada para el procesamiento de imágenes en escala de grises, utilizando estructuras de datos avanzadas.

El sistema permite trabajar con imágenes individuales y volúmenes 3D, proporcionando herramientas para:

- 📷 **Cargar imágenes** en memoria.
- 📚 **Cargar volúmenes** de imágenes secuenciales.
- 🔍 **Extraer información** de imágenes y volúmenes.
- 🏥 **Simular proyecciones 2D** de un volumen (como en radiografías).
- 🔒 **Codificar y decodificar imágenes** con el algoritmo de Huffman.
- 🎭 **Segmentar imágenes** utilizando representaciones de grafos.

---

## 🎯 Objetivo del Proyecto

Este proyecto forma parte de la materia **Estructuras de Datos** y tiene como propósito aplicar conocimientos de organización y manipulación eficiente de datos.

Se busca implementar estructuras como **listas, árboles binarios y grafos** para realizar operaciones avanzadas en imágenes digitales.

---

## 🏗️ Arquitectura del Código

El proyecto sigue una estructura modular, con los siguientes archivos principales:

📂 **EstructurasDeDatos/ProyectoDelCurso/**

```
├── src/                     # Código fuente
│   ├── clases.h             # Definición de clases Imagen y Volumen
│   ├── clases.cpp           # Implementación de las clases
│   ├── comandos.h           # Definición de funciones de comandos
│   ├── comandos.cpp         # Implementación de comandos del sistema
│   ├── interfaz.h           # Definición de funciones de interfaz
│   ├── interfaz.cpp         # Implementación de la interfaz de usuario
│   ├── utilidades.h         # Definición de funciones auxiliares
│   ├── utilidades.cpp       # Implementación de utilidades
│   ├── main.cpp             # Punto de entrada del programa
│   └── Makefile             # Archivo de compilación
│
└── imagenesPrueba/          # Carpeta con imágenes de prueba (PGM y PPM)
```

📌 **Descripción de los módulos:**

- 📦  → Definen la estructura de las imágenes y volúmenes.
- 🎮  → Contienen la lógica de ejecución de comandos.
- 💻  → Controlan la interacción con el usuario en la terminal.
- 🔧  → Incluyen funciones auxiliares como el manejo de cadenas.
- 🚀  → Punto de entrada que gestiona la ejecución de comandos.

---

## 🛠️ ¿Cómo ejecutar el proyecto?

### 🔹 1️⃣ Compilar el proyecto

Asegúrate de tener **G++** instalado y ejecuta el siguiente comando en la terminal:

```bash
make
```

Esto generará un ejecutable llamado `programa.exe` o `programa` (según el sistema operativo).

### 🔹 2️⃣ Ejecutar el programa

Para iniciar la aplicación, usa el siguiente comando:

```bash
make run
```

Esto abrirá la consola interactiva donde puedes ingresar comandos.

### 🔹 3️⃣ Limpiar archivos generados

Si deseas eliminar los archivos compilados y el ejecutable:

```bash
make clean
```

---

## 🔗 Comandos disponibles

Dentro de la aplicación, puedes utilizar los siguientes comandos:

```
ayuda                                  # Muestra la lista de comandos disponibles
cargar_imagen <archivo.pgm>            # Carga una imagen en memoria
cargar_volumen <nombre_base> <n_im>    # Carga un volumen de imágenes en memoria
info_imagen                            # Muestra información de la imagen cargada
info_volumen                           # Muestra información del volumen cargado
proyeccion2D <direccion> <criterio> <archivo.pgm>  # Genera una proyección 2D de un volumen
codificar_imagen <archivo.huf>         # Codifica la imagen cargada usando Huffman
decodificar_archivo <archivo.huf> <archivo.pgm>  # Decodifica una imagen comprimida
segmentar <salida.pgm> <semillas>      # Segmenta una imagen en regiones
salir                                  # Cierra la aplicación
```

📌 **Ejemplo de uso:**

```bash
$ cargar_imagen img_04.pgm
La imagen img_04.pgm ha sido cargada.
$ info_imagen
Imagen cargada en memoria: img_02.pgm, ancho: 256, alto: 256.
```

---
## 🧩 Entrega 2 – Codificación de imágenes con Huffman

### 🎯 Objetivo

Implementar la compresión de imágenes en escala de grises utilizando el algoritmo de **Huffman**, generando archivos `.huf` compactos y decodificables a su versión original `.pgm`.

---

### 📁 Estructura de archivo `.huf`

```
[W][H][M][F0]...[FM][bits...][numBitsValidos]
```

- `W`, `H`: ancho y alto de la imagen (2 bytes cada uno)
- `M`: intensidad máxima (1 byte)
- `F0` a `FM`: frecuencias de cada intensidad (8 bytes cada una)
- `bits...`: stream de bits con la codificación
- `numBitsValidos`: número total de bits útiles (al final del archivo)

---

### 🔧 Comandos implementados

```bash
cargar_imagen <nombre_archivo.pgm>
codificar_imagen <nombre_archivo.huf>
decodificar_archivo <archivo.huf> <archivo_salida.pgm>
info_imagen
```

---

### 🧪 Ejemplo de uso

```bash
$ cargar_imagen img_04.pgm
La imagen ha sido cargada.

$ codificar_imagen img_04.huf
La imagen en memoria ha sido codificada exitosamente y almacenada en el archivo img_04.huf.

$ decodificar_archivo img_04.huf salida.pgm
El archivo img_04.huf ha sido decodificado exitosamente y la imagen correspondiente se ha almacenado en salida.pgm.
```

---

### 🧠 ¿Cómo funciona Huffman?

- Se calcula cuántas veces aparece cada tono de gris.
- Se construye un árbol de Huffman con esas frecuencias.
- Se asignan códigos binarios más cortos a los tonos más comunes.
- Se codifica toda la imagen en bits y se guarda en un archivo `.huf`.
- Para decodificar, se reconstruye el árbol y se traduce el bitstream a los píxeles originales.

---

### 📂 Archivos importantes

- `clases.cpp/h`: contiene la implementación de Huffman (`HuffmanTree`, `HuffmanNode`).
- `comandos.cpp`: funciones `codificarImagen()` y `decodificarArchivo()`.
- `imagenesPrueba/`: contiene imágenes `.pgm` para prueba.
- `main.cpp`: bucle principal que interpreta comandos desde terminal.

---

### ✅ Estado del proyecto

✔️ Carga y visualización de imágenes  
✔️ Codificación con Huffman  
✔️ Decodificación exacta  
✔️ Validaciones por consola  
✔️ Pruebas con múltiples imágenes

---

## 🏆 Conclusión

Este proyecto es una aplicación educativa para entender cómo las estructuras de datos pueden ser utilizadas en **procesamiento de imágenes**.

Se pueden explorar mejoras como:

- ✅ Implementación de estructuras más eficientes.
- ✅ Optimización del uso de memoria.
- ✅ Extender la funcionalidad a imágenes a color.

🚀 ¡Espero que esta documentación sea útil para entender y ejecutar el proyecto! 🎯

---
### 👥 Autores

- Santiago Mesa  
- Jerónimo Chaparro Tenorio

---