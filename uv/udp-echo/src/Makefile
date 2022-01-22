udp-echo:udp-echo.o
	$(CC) $(LDFLAGS) udp-echo.o -o udp-echo -luv

udp-echo.o:udp-echo.c
	$(CC) $(CFLAGS) -c udp-echo.c

clean:
	rm *.o udp-echo
