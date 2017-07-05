all: BBoard.cpp Message.cpp User.cpp Topic.cpp Reply.cpp
	g++ -W -Wall -Werror -ansi -pedantic -c BBoard.cpp -o BBoard.o
BBoard:
	g++ -W -Wall -Werror -ansi -pedantic -c BBoard.cpp -o BBoard.o
Message:
	g++ -W -Wall -Werror -ansi -pedantic -c Message.cpp -o Message.o
User:
	g++ -W -Wall -Werror -ansi -pedantic -c User.cpp -o User.o
Topic:
	g++ -W -Wall -Werror -ansi -pedantic -c Topic.cpp -o Topic.o
Reply:
	g++ -W -Wall -Werror -ansi -pedantic -c Reply.cpp -o Reply.o
full:
	g++ -W -Wall -Werror -ansi -pedantic main.cpp BBoard.o Message.o User.o Topic.o Reply.o
run:
	./a.out userList.txt messageList.txt
clean:
	rm BBoard Message User Topic Reply a.out