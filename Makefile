all: server client

server: 
	g++ server.cpp -o server -lboost_system
client:
	g++ client.cpp -o client -lboost_system