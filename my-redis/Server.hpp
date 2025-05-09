//
// Created by admin on 25-5-9.
//

#include <iostream>
#include<boost/asio.hpp>

#include "Session.h"
using boost::asio::ip::tcp;

// 服务器类，负责接受客户端连接
class Server
{
public:
    Server(boost::asio::io_context& io_context, short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)),
          io_context_(io_context)
    {
        start_accept();
    }

private:
    // 开始接受客户端连接
    void start_accept()
    {
        // 创建新会话对象
        auto new_session = std::make_shared<Session>(io_context_);

        // 异步接受连接
        acceptor_.async_accept(
            new_session->socket(),
            [this, new_session](boost::system::error_code ec)
            {
                if (!ec)
                {
                    std::cout << "New client connected" << std::endl;
                    // 启动新会话
                    new_session->start();
                }
                else
                {
                    std::cerr << "Accept error: " << ec.message() << std::endl;
                }

                // 继续接受下一个连接
                start_accept();
            });
    }

    tcp::acceptor acceptor_; // 连接接收器
    boost::asio::io_context& io_context_; // IO上下文引用
};
