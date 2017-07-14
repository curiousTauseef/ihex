all : ihex ihexout

ihex : ihex.cpp ihex.h
	g++ -g -DDEMO=1 -o ihex ihex.cpp

ihexout : ihexout.cpp ihex.h
	g++ -g -DDEMO=1 -o ihexout ihexout.cpp
