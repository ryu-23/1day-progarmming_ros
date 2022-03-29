CC = g++

CFLAGS = -w -Wall -O2
SRCS = thread.cpp  

PROG = test

OPENCV = `pkg-config --cflags --libs opencv`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

	$(./PROG)
