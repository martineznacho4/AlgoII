CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror
TARGET = aeropuertos
SRCS = main.cpp Aeropuerto.cpp TablaHashAbierta.cpp TablaHashCerrada.cpp NodoHash.cpp
OBJS = main.o Aeropuerto.o TablaHashAbierta.o TablaHashCerrada.o NodoHash.o
VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Aeropuerto.h TablaHashAbierta.h TablaHashCerrada.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Aeropuerto.o: Aeropuerto.cpp Aeropuerto.h
	$(CXX) $(CXXFLAGS) -c Aeropuerto.cpp

TablaHashAbierta.o: TablaHashAbierta.cpp TablaHashAbierta.h NodoHash.h
	$(CXX) $(CXXFLAGS) -c TablaHashAbierta.cpp

TablaHashCerrada.o: TablaHashCerrada.cpp TablaHashCerrada.h NodoHash.h
	$(CXX) $(CXXFLAGS) -c TablaHashCerrada.cpp

NodoHash.o: NodoHash.cpp NodoHash.h Aeropuerto.h
	$(CXX) $(CXXFLAGS) -c NodoHash.cpp

check: $(TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

