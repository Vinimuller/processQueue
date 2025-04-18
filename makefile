# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Pastas
OUTDIR = out

# Arquivos fonte
SOURCES = DungeonPOO.cpp

# Arquivos objeto na pasta de saída
OBJECTS = $(patsubst %.cpp,$(OUTDIR)/%.o,$(SOURCES))

# Nome do executável (com caminho de saída)
TARGET = $(OUTDIR)/app

# Regra padrão
all: $(TARGET)

# Criação do executável
$(TARGET): $(OBJECTS)
	@mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilação dos .cpp para .o na pasta out
$(OUTDIR)/%.o: %.cpp
	@mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Diretiva para compilar e rodar
run: all
	./$(TARGET)

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OUTDIR)

.PHONY: all clean run
