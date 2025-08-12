CXX = clang++
INCLUDE = 
LIB = 
CXXFLAGS = $(if $(INCLUDE),-I$(INCLUDE))
LDFLAGS = $(if $(LIB),-L$(LIB)) -lboost_system

all: server client

server: server.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

client: client.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)
