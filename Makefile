TARGET=main3
SRC_FILE=$(TARGET).cpp

CC=g++
CFLAGS=-lm -Wall -Wextra -std=c++11

all: $(TARGET)

$(TARGET): $(SRC_FILE)
	$(CC) $(SRC_FILE) -o $(TARGET) $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

push:
	git add .
	git commit -m "mama"
	git push

.PHONY: clean all run push
