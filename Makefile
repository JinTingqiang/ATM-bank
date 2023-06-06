CC=gcc
STD=-std=gnu99
FLAG=-Wall -Werror
BIN=open destroy login unlock save take query repass transfer 
TRGET=server client
TOOLS=tools.c zmsg.c
INCLUDE=bank.h tools.h zmsg.h

all:$(BIN) $(TRGET)
	mv $(BIN) ./bin
	./server

%:%.c $(TOOLS) $(INCLUDE)
	$(CC) $(STD) $(FLAG) $(TOOLS) $< -o $@

clean:
	cd ./bin && rm -rf $(BIN)
	rm -rf *.o
	rm -rf *.h.gch
	rm -rf *~
	rm -rf $(TRGET)




