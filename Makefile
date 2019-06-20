CLIBS= 		-lm -lglut -lGL -lGLU -lX11 # 2016
CPATHS=		-I/usr/include -L/usr/lib # 2016
CFLAGS=		$(CPATHS)$(CLIBS)

WangG1:		WangG1.cpp
		g++ WangG1.cpp -o WangG1 $(CFLAGS)

clean:
		rm *.o
