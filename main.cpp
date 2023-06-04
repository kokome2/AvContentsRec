//
// Created by 김명재 on 2023/05/29.
//
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <iostream>

class hello_world_test : public cppcms::application {
public:
    hello_world_test(cppcms::service &srv) : cppcms::application(srv) { }
    virtual void main(std::string url);
};

void hello_world_test ::main(std::string /*url*/)
{
    response().out() << "Hello, World!";
}

int main(int argc, char **argv) {
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
