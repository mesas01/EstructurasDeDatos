# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Nombre del ejecutable
TARGET = programa.exe

# Directorio de código fuente
SRC_DIR = src

# Archivos fuente
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/comandos.cpp $(SRC_DIR)/interfaz.cpp $(SRC_DIR)/utilidades.cpp $(SRC_DIR)/clases.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Detectar el sistema operativo
ifeq ($(OS), Windows_NT)
    RM = del /Q
    FIXPATH = $(subst /,\,$1)
    EXECUTABLE = $(TARGET)
else
    RM = rm -f
    FIXPATH = $1
    EXECUTABLE = ./$(TARGET)
endif

# Regla para compilar el proyecto
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
# Elimina los archivos objeto después de crear el ejecutable
	$(RM) $(call FIXPATH, $(OBJS))

# Regla para compilar cada archivo fuente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
# Elimina los archivos objeto y el ejecutable
	$(RM) $(call FIXPATH, $(OBJS) $(TARGET))

# Regla para ejecutar el programa
run: all
	$(EXECUTABLE)

# Regla para compilar y ejecutar en un solo paso
build-and-run: all run

.PHONY: all clean run build-and-run
