CLIBS= 		-lm -lglut -lGL -lGLU -lX11 # 2016
CPATHS=		-I/usr/include -L/usr/lib # 2016
CFLAGS=		$(CPATHS)$(CLIBS)

ScienceCenter2nd:		ScienceCenter2nd.cpp
		g++ ScienceCenter2nd.cpp -o ScienceCenter2nd $(CFLAGS)

clean:
		rm *.o
