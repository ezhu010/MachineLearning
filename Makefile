CC = g++
CFLAGS = -std=c++11
HEADER = header
SOURCEFOLDER = src
SOURCEFILES = $(SOURCEFOLDER)/main.cpp $(SOURCEFOLDER)/DataSet.cpp $(SOURCEFOLDER)/GreedySearch.cpp $(SOURCEFOLDER)/NNClassifier.cpp $(SOURCEFOLDER)/Node.cpp $(SOURCEFOLDER)/Validator.cpp 
DEPS = $(HEADER)/Classifer.h $(HEADER)/DataSet.h $(HEADER)/GreedySearch.h $(HEADER)/NNClassifier.h $(HEADER)/Node.h $(HEADER)/Validator.h
OBJ = ML

all:
	$(CC) $(SOURCEFILES) $(CFLAGS) -o $(OBJ)

clean:
	rm -rf $(OBJ)

