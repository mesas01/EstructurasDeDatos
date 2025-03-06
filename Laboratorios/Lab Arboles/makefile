CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Nombre del ejecutable final
TARGET = programa

# Archivos fuente del proyecto
SOURCES = main.cpp arbolBinario.cpp

# Archivos objeto generados a partir de los fuentes
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal para compilar todo
all: $(TARGET)

# Enlaza los archivos objeto para crear el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada archivo fuente a objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ejecutar el programa después de compilar
run: $(TARGET)
	./$(TARGET)

# Limpia los archivos generados (objetos y ejecutable)
clean:
	rm -f $(OBJECTS) $(TARGET)
