# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -Wextra -std=c++17 -g  # Agregamos -g para depuración

# Nombre del ejecutable
TARGET = mi_programa.exe

# Directorio de código fuente
SRC_DIR = src

# Archivos fuente
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/comandos.cpp $(SRC_DIR)/interfaz.cpp $(SRC_DIR)/utilidades.cpp $(SRC_DIR)/clases.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Detectar el sistema operativo
ifeq ($(OS), Windows_NT)
    # Comandos para Windows
    RM = del /Q
    FIXPATH = $(subst /,\,$1)
    EXECUTABLE = $(TARGET)
else
    # Comandos para Linux
    RM = rm -f
    FIXPATH = $1
    EXECUTABLE = ./$(TARGET)
endif

# Regla para compilar el proyecto
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	$(RM) $(call FIXPATH, $(OBJS))  # Elimina los archivos objeto después de crear el ejecutable

# Regla para compilar cada archivo fuente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	$(RM) $(call FIXPATH, $(OBJS) $(TARGET))  # Elimina los archivos objeto y el ejecutable

# Regla para ejecutar el programa
run: all
	$(EXECUTABLE)

# Regla para compilar y ejecutar en un solo paso
build-and-run: all run

.PHONY: all clean run build-and-run