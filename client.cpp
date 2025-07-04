#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

string getData(tcp::socket& socket) {
    boost::asio::streambuf buf;
    read_until(socket, buf, "\n");
    string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}

void sendData(tcp::socket& socket, const string& message) {
    write(socket, buffer(message + "\n"));
}

int main() {
    io_service io_service;

    string IP;
    int port;

    cout << "IP: ";
    getline(cin, IP);

    cout << "PORT: ";
    cin >> port;
    cin.ignore();
  
    //connection
    tcp::socket client_socket(io_service);
    client_socket.connect(tcp::endpoint(address::from_string(IP), port));

    cout << "Enter your name: ";
    string u_name;
    getline(cin, u_name);

    sendData(client_socket, u_name);

    string reply, response;

    while (true) {
        response = getData(client_socket);
        response.pop_back(); // remove '\n'

        if (response == "exit") {
            cout << "Connection terminated" << endl;
            break;
        }

        cout << "Server: " << response << endl;

        cout << u_name << ": ";
        getline(cin, reply);

        sendData(client_socket, reply);

        if (reply == "exit") {
            break;
        }
    }

    return 0;
}
