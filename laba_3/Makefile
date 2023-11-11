TARGET = lab_3
CC = g++
CFLAGS = -pedantic -Wall

SCR = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SCR))
HEADERS = $(wildcard ./include/*.h)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# main.o : main.c Tree_OV.h term.h 
# 	$(CC) -c $(CFLAGS) main.c -o main.o

# Tree_OV.o : Tree_OV.c Tree_OV.h
# 	$(CC) -c $(CFLAGS) Tree_OV.c -o Tree_OV.o

# term.o : term.c Tree_OV.h term.h
# 	$(CC) -c $(CFLAGS) term.c -o term.o

%.o : %.cpp $(HEADERS)
	$(CC) -c $< -o $@

clean : 
	rm $(TARGET) *.o 
