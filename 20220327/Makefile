CC = g++

CFLAGS = -w -Wall -O2
SRCS = least_squares.cpp  

PROG = least_squares

OPENCV = `pkg-config --cflags --libs opencv`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

	$(./PROG)
