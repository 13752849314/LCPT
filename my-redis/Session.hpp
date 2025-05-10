//
// Created by admin on 25-5-9.
//

#ifndef SESSION_H
#define SESSION_H
#include <iostream>
#include<boost/asio.hpp>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session>
{
public:
    explicit Session(boost::asio::io_context& io_context);

    tcp::socket& socket();

    void start(); // 开始会话
private:
    void async_read();

    void handle_read(std::size_t length);

    tcp::socket socket_; // 客户端套接字
    boost::asio::streambuf buffer_; // 数据缓冲区
};


#endif //SESSION_H
