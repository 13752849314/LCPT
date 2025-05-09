//
// Created by admin on 25-5-9.
//

#include "Session.h"

Session::Session(boost::asio::io_context& io_context): socket_(io_context)
{
}

tcp::socket& Session::socket()
{
    return socket_;
}

void Session::start()
{
    async_read();
}

void Session::async_read()
{
    auto self(shared_from_this());
    boost::asio::async_read_until(socket_, buffer_, '\n', [this,self](boost::system::error_code ec, std::size_t length)
    {
        if (!ec) // 读取成功
        {
            handle_read(length);
        }
        else
        {
            std::cerr << "Read error: " << ec.message() << std::endl;
        }
    });
}

void Session::handle_read(std::size_t length)
{
    std::istream is(&buffer_);
    std::string line;
    std::getline(is, line); // 提取一行数据

    std::cout << "Client: " << line << std::endl;

    // 异步回显数据给客户端
    auto self(shared_from_this());
    boost::asio::async_write(
        socket_,
        boost::asio::buffer(line + "\n"),
        [this, self](boost::system::error_code ec, std::size_t /*length*/) {
            if (!ec) {
                // 继续读取下一条消息
                async_read();
            } else {
                std::cerr << "Write error: " << ec.message() << std::endl;
            }
        });
}
