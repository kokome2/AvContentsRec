//
// Created by 김명재 on 2023/05/29.
//
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <iostream>

#include <boost/log/trivial.hpp>


class hello_world_test : public cppcms::application {
public:
    hello_world_test(cppcms::service &srv) : cppcms::application(srv) { }
    virtual void main(std::string url);
};

void hello_world_test ::main(std::string /*url*/)
{
    response().out() << "hello_world_test";
}

int main(int argc, char* argv[]) {

//    boost log sample
//    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
//    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
//    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
//    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
//    BOOST_LOG_TRIVIAL(error) << "An error severity message";
//    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    try {
        cppcms::service srv(argc, argv);
        srv.applications_pool().mount(
                cppcms::create_pool<hello_world_test>()
        );
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
