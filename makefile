


make:
  # a mac version but anyway x11 does not work as expected
  #	gcc -I/opt/X11/include/  -O3 m.c   -o m -L/opt/X11/lib/  -lX11
  gcc  -O3 m.c   -o m -lX11
clean:
	rm -f *.o *~
