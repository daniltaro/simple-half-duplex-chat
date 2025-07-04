#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

string getData(tcp::socket& socket);
void sendData(tcp::socket& socket, const string& message);

int main(){
    int port;
    cout << "PORT: ";
    cin >> port;
    cin.ignore();

    cout << "Waiting for client..." << endl;
    io_service io_service;

    //listening
    tcp::acceptor acceptor_server(io_service, 
            tcp::endpoint(tcp::v4(), port));

    tcp::socket server_socket(io_service);

    //waiting for connection
    acceptor_server.accept(server_socket);

    //reading user name
    string u_name = getData(server_socket); 
    u_name.pop_back();  //Убираю '\n'
    
    string reply = u_name + " connected!";
    cout << reply << endl;
    sendData(server_socket, reply);
    
    string response;
    while(true){
        response = getData(server_socket);
        response.pop_back();

        //exit
        if(response == "exit"){
            cout << u_name << " left!" << endl;
            break;
        }
        
        cout << u_name << ": " << response << endl;

        //reading 
        cout << "Server: ";
        getline(cin, reply);
        sendData(server_socket, reply);
        
        //exit
        if(reply == "exit"){
            break;
        }

    }

    return 0;
}

string getData(tcp::socket& socket){
    boost::asio::streambuf buf;
    read_until(socket, buf, "\n");
    string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}

void sendData(tcp::socket& socket, const string& message){
    write(socket, buffer(message + "\n"));
}
