PROGRAM = client
CC = g++ -std=c++17
LIBS = -lpthread

$(PROGRAM): $(PROGRAM).o
	$(CC) -o $(PROGRAM) $(PROGRAM).o $(LIBS)

$(PROGRAM).o: ../NetworkCommon/common.hpp ../NetworkCommon/ThreadSafeQueue.hpp ../NetworkCommon/Message.hpp
	$(CC) -c main.cpp -o $(PROGRAM).o

.PHONY: clean

clean:
	rm -f $(PROGRAM) *.o
