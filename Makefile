# Nombre del compilador
CXX = g++

# Directorios de los archivos de encabezado y las bibliotecas
INCLUDE_DIR = /mingw64/include
LIB_DIR = /mingw64/lib

# Archivos de origen
SRC = src/main.cpp \
		src/bird.cpp

# Nombre del ejecutable
TARGET = Game

# Flags de compilación y enlace
CXXFLAGS = -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR) -lsfml-graphics -lsfml-system -lsfml-window

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)

.PHONY: all clean
