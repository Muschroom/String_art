
SFML_PATH = D:/SFML/SFML-2.6.1

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -I"$(SFML_PATH)/include" -DSFML_STATIC -static-libgcc -static-libstdc++
LDFLAGS = -static -L"$(SFML_PATH)/lib"
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lcomdlg32

SRCDIR = src
HEADERDIR = headers
RESDIR = resources
OBJDIR = build


SOURCES = $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

TARGET = main.exe

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(HEADERDIR) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf $(OBJDIR)

run: $(TARGET)
	./$(TARGET)