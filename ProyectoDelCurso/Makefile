# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -Wextra -std=c++17

# Nombre del ejecutable
TARGET = proyecto.bin

# Directorio de código fuente
SRC_DIR = src

# Archivos fuente
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/comandos.cpp $(SRC_DIR)/interfaz.cpp $(SRC_DIR)/utilidades.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla para compilar el proyecto
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar cada archivo fuente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Regla para ejecutar el programa
run: all
	./$(TARGET)

.PHONY: all clean run