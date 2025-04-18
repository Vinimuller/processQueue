# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Arquivos fonte e objeto
SOURCES = DungeonPOO.cpp 
OBJECTS = $(SOURCES:.cpp=.o)

# Nome do executável
TARGET = app

# Regra padrão
all: $(TARGET)

# Como construir o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Como compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
