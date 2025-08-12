# Simple TCP Chat using Boost.Asio

A minimal TCP client-server chat application written in C++ using Boost.Asio.
## Features

- 🖥 Server listens on specified port for one client connection
- 💬 Simple line-based text message exchange
- 👤 Client sends username on connect

## Requirements
- C++17 compatible compiler
- Boost library 

## Build
```bash
make INCLUDE=/your/include/path LIB=/your/lib/path
```

## Usage
### Server
- Run the server executable:
  
```bash
./server
```

- Enter the port number to listen on.
- Wait for client connection.
- To exit, type exit.

### Client
- Run the client executable:
  
```bash
./client
```

- Enter server IP address and port.
- Enter your username.
- Exchange messages with the server.
- To exit, type exit.
