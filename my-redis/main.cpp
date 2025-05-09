#include <iostream>
#include <boost/asio/io_context.hpp>
#include "Server.hpp"

int main()
{
    try
    {
        boost::asio::io_context io_context;
        // 创建服务器对象，监听9999端口
        Server server(io_context, 9999);

        std::cout << "Server started. Listening on port 9999..." << std::endl;

        // 运行IO服务
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
