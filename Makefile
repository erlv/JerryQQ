all:
	gcc client.c -o client.exe -Wall -Werror -O0 -g3
	gcc server.c -o server.exe -Wall -Werror -O0 -g3

run:
	echo "Run the server.exe first, and then run client.exe in another terminal"
	echo ">>> Run server.exe"
	echo "./server.exe"
	echo ">>> Run client.exe"
	echo "./client 127.0.0.1 7000 testing"

clean:
	-rm client.exe
	-rm server.exe
