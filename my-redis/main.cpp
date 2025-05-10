#include <iostream>
#include <boost/asio/io_context.hpp>

#include "Server.hpp"
#include "Config.hpp"

int main(int argc, const char* argv[])
{
    config::initConfigFromCmd(argc, argv);
    try
    {
        boost::asio::io_context io_context;
        // 创建服务器对象，监听9999端口
        Server server(io_context, boost::any_cast<short>(config::Config["port"]));

        std::cout << "Server started. Listening on port " << boost::any_cast<short>(config::Config["port"]) << "..." <<
            std::endl;

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
