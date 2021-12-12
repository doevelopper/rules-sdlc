
#include <cstdlib>

#include <rules/sdlc/std/UnitTest.hpp>

int
main([[maybe_unused]] int argc,
     [[maybe_unused]] char * argv[])
{
    FLAGS_logtostderr = true;
    //    FLAGS_log_dir ="C:\\Users\\100034251\\CLionProjects\\coro\\cmake-build-debug";
    FLAGS_log_dir ="./log";

    rules::sdlc::stdc::test::UnitTest stdTest;

    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "###################################################################");
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "@@@                       TEST     Utils                        @@@");
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "###################################################################");

    std::uint8_t runStatus = stdTest.run(argc,argv);

    if (runStatus != EXIT_SUCCESS)
    {
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"**************************************************************************");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"========== . FAILURE . ========== . FAILURE . ========== . FAILURE . =====");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"**************************************************************************");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"███████╗ █████╗ ██╗██╗     ███████╗██████╗ ");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"██╔════╝██╔══██╗██║██║     ██╔════╝██╔══██╗");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"█████╗  ███████║██║██║     █████╗  ██║  ██║");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"██╔══╝  ██╔══██║██║██║     ██╔══╝  ██║  ██║");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"██║     ██║  ██║██║███████╗███████╗██████╔╝");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝╚═════╝ ");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"**************************************************************************");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"========== . FAILURE . ========== . FAILURE . ========== . FAILURE . =====");
        LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(),"**************************************************************************");

    }
    else
    {
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(),"");
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger()," ::::::::  :::    :::  ::::::::   ::::::::  :::::::::: ::::::::   ::::::::  ");
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(),":+:    :+: :+:    :+: :+:    :+: :+:    :+: :+:       :+:    :+: :+:    :+: ");
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(),"+:+        +:+    +:+ +:+        +:+        +:+       +:+        +:+        ");
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(),"+#++:++#++ +#+    +:+ +#+        +#+        +#++:++#  +#++:++#++ +#++:++#++ ");
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(),"       +#+ +#+    +#+ +#+        +#+        +#+              +#+        +#+ ");
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(),"#+#    #+# #+#    #+# #+#    #+# #+#    #+# #+#       #+#    #+# #+#    #+# ");
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger()," ########   ########   ########   ########  ########## ########   ########  ");
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(),"");
    }

    return ( EXIT_SUCCESS );

}
