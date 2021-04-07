CMP = gcc
FUNC = statesfunc
MAIN = statesmain
EXEC = runstates

$(EXEC): $(FUNC).o $(MAIN).o
	$(CMP) -Wall -std=c11 $(FUNC).o $(MAIN).o -o $(EXEC)

$(FUNC).o: $(FUNC).c $(FUNC).h
	$(CMP) -Wall -std=c11 -c $(FUNC).c -o $(FUNC).o

$(MAIN).o: $(MAIN).c $(FUNC).h
	$(CMP) -Wall -std=c11 -c $(MAIN).c -o $(MAIN).o

clean:
	rm *.o
	rm $(EXEC)

