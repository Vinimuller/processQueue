# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Diretórios
SRCDIRS = src
INCDIR = inc
OUTDIR = out

# Busca todos os .cpp nas pastas de código-fonte
SOURCES = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))

# Gera os caminhos dos objetos na pasta out/
OBJECTS = $(patsubst %.cpp,$(OUTDIR)/%.o,$(notdir $(SOURCES)))

# Executável
TARGET = $(OUTDIR)/app

# Regra padrão
all: $(TARGET)

# Linkagem final
$(TARGET): $(OBJECTS)
	@mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar .cpp → .o na pasta out/
$(OUTDIR)/%.o: $(SRCDIRS)/%.cpp
	@mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Executar
run: all
	./$(TARGET)

# Limpeza
clean:
	rm -rf $(OUTDIR)

.PHONY: all clean run
