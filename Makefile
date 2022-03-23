

sample: sample.o imageio.o invert.o
	g++ -o sample sample.o imageio.o invert.o

main: main.o imageio.o invert.o
	g++ -o sample sample.o imageio.o invert.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

invert.o: invert.cpp invert.h

clean:
	rm -f sample.o imageio.o invert.o main.o
