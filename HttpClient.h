/**
 * The HTTPClient interface file.
 * @file HttpClient.h
 * @author Sebastian Davaris
 * @date 21-09-2020
 */


// Includes.
#include "EthernetInterface.h"
#include "TCPSocket.h"
#include <string>

// Custom defines.
#define NEWLINE "\r\n"
#define CONTENT_TYPE_URLENCODED "Content-Type: application/x-www-form-urlencoded"

/**
 * The interface of a custom HTTP client implementation.
 * @class HttpClient
 * @author Sebastian Davaris
 * @date 21-09-2020
 */
class HttpClient {
public:
    /**
     * Constructor
     * @param remote The remote host to connect to.
     * @param port The remote port to use while connecting.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    HttpClient(const std::string remote, int port);

    //void setRemoteHost(const std::string remote, int port);

    /**
     * Adds a new parameter to the POST body (NOT used in GET requests).
     * @param key The parameter key.
     * @param value The parameter value.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void addBodyParameter(std::string key, std::string value);

    /**
     * Sends a request to the remote host (currently only POST is supported).
     * @param path The URI path to call.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void send(const std::string path);

    /**
     * WARNING: DEPRECATED!!! SHOULD NOT BE USED!!!!
     * @deprecated
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void saveResponseBMP();
private:
    EthernetInterface m_eth;
    
    TCPSocket m_socket;

    std::string m_headers;

    std::string m_bodyData;
    
    std::string m_remote;
    
    int m_port;
};