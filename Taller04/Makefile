# Nombre del ejecutable
TARGET = citaciones

# Compilador y opciones
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./src

# Archivos fuente
SRC = \
  src/main.cpp \
  src/Articulo.cpp \
  src/MapaDeCitaciones.cpp \
  src/cargar_archivo.cpp \
  src/algoritmos/Algoritmo1.cpp \
  src/algoritmos/Algoritmo2.cpp \
  src/algoritmos/Algoritmo3.cpp \
  src/algoritmos/Algoritmo4.cpp

# Regla por defecto para compilar
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET).exe

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET).exe

# Limpiar archivos generados
clean:
	del /Q $(TARGET).exe 2>nul
