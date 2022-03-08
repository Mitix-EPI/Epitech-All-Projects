// /*
// ** EPITECH PROJECT, 2021
// ** network.hpp
// ** File description:
// ** network.hpp
// */

// #ifndef NETWORK_HPP_
// #define NETWORK_HPP_

// #include <boost/asio.hpp>
// #include <iostream>
// #include <string>

// class Network {
//     public:
//         Network(short port, boost::asio::io_service &io_service);
//         ~Network();
//         // startServer();
//         // stopServer();

//         // getters
//         boost::asio::ip::udp::socket getSocket() const;
//         boost::asio::ip::udp::endpoint getEndpoint() const;
//         boost::asio::io_service getIoService() const;
//         std::array<char, 1024> getRecvBuffer() const;

//         // setters
//         void setSocket(const boost::asio::ip::udp::socket &);
//         void getRemoteEndpoint(const boost::asio::ip::udp::endpoint &);
//         void getIoService(const boost::asio::io_service &);
//         void getRecvBuffer(const std::array<char, 1024> &);
//     private:
//         boost::asio::ip::udp::socket _socket;
//         boost::asio::ip::udp::endpoint _remoteEndpoint;
//         std::array<char, 1024> _recvBuffer;
//         boost::asio::io_service _ioService;
//         short _port;
//     protected:

// }

// #endif /* !NETWORK_HPP_ */
