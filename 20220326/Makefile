CC = g++

CFLAGS = -w -Wall -O2
SRCS = regression.cpp  

PROG = regression

OPENCV = `pkg-config --cflags --libs opencv`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

	$(./PROG)
