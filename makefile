# Detecta o sistema operacional
ifeq ($(OS),Windows_NT)
    RM = del /Q /F
    RMDIR = rmdir /S /Q
    MKDIR = if not exist "$(OUTDIR)" mkdir "$(OUTDIR)"
    EXEC_EXT = .exe
    RUN = $(TARGET)
else
    RM = rm -f
    RMDIR = rm -rf
    MKDIR = mkdir -p $(OUTDIR)
    EXEC_EXT =
    RUN = ./$(TARGET)
endif

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
TARGET = $(OUTDIR)/app$(EXEC_EXT)

# Regra padrão
all: $(TARGET)

# Linkagem final
$(TARGET): $(OBJECTS)
	@$(MKDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar .cpp → .o na pasta out/
$(OUTDIR)/%.o: $(SRCDIRS)/%.cpp
	@$(MKDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Executar
run: all
	$(RUN)

# Limpeza
clean:
	-$(RM) $(OUTDIR)/*$(EXEC_EXT) $(OUTDIR)/*.o 2>nul || true
	-$(RMDIR) $(OUTDIR) 2>nul || true

.PHONY: all clean run
