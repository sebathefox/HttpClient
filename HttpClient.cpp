#include "HttpClient.h"


#include <iostream>
#include <fstream>  
#include <sstream>

HttpClient::HttpClient(const std::string remote, int port) : m_remote(remote), m_port(port)
{
    m_eth.set_dhcp(false);
    m_eth.set_network("192.168.1.181","255.255.255.0","192.168.1.1");

    m_eth.connect();
}

void HttpClient::addBodyParameter(std::string key, std::string value) {
    m_bodyData.append(key + "=" + value);
}

void HttpClient::send(const std::string path) {
    m_socket.open(&m_eth);
    
    m_socket.connect(m_remote.c_str(), m_port);
    
    
    std::string request = "POST " + path + "\r\n" + "Host: " + m_remote + ":" + static_cast<ostringstream*>( &(ostringstream() << m_port) )->str() + "\r\n" CONTENT_TYPE_URLENCODED "\r\nContent-Length: " + static_cast<ostringstream*>( &(ostringstream() << strlen(m_bodyData.c_str())))->str() + "\r\n\r\n" + m_bodyData;
    
    m_socket.send(request.c_str(), strlen(request.c_str()));
    
    m_socket.close();
    
    m_bodyData = "";
}

void HttpClient::saveResponseBMP() {
    char* buffer = new char[256];
    nsapi_size_or_error_t result;
    
    FILE* fp = fopen("/fs/img.bmp", "w");
    
    m_socket.open(&m_eth);
    
    m_socket.connect(m_remote.c_str(), m_port);
    
    std::string request = "GET /images.bmp\r\nHost: " + m_remote + ":" + static_cast<ostringstream*>( &(ostringstream() << m_port) )->str() + "\r\n\r\n";
    
    m_socket.send(request.c_str(), strlen(request.c_str()));
    
    bool first = true;
    
    while((result = m_socket.recv(buffer, 255)) > 0) {
        wait(0.1);
        
        buffer[result] = 0;
        
        printf("TEST");
        
        if(first) {
            char* sub = strstr(buffer, "\r\n\r\n");
            sub += 4;
            fprintf(fp, sub);
            first = false;

            continue;
        }
        else {
            fprintf(fp, buffer);
        }
    }

    wait(0.1);

    fclose(fp);
    
    printf("CLOSED FILE");
    
    m_socket.close();

    printf("CLOSED SOCKET");
}