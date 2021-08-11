CXX=g++
CXXFLAGS=-std=c++14 -MMD -Werror=vla
OBJECTS=cell.o level.o board.o blocks.o biquadris.o main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=biquadris

${EXEC}: ${OBJECTS}
	                        ${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	                        rm ${OBJECTS} ${DEPENDS} ${EXEC}
