#include <iostream>

struct Details
{
};

struct Details_with_noexcept_at_dtor
{
    ~Details_with_noexcept_at_dtor() noexcept(false) {}
};

struct X
{
    Details_with_noexcept_at_dtor d;
    //Details d;
    ~X() { throw std::logic_error("error3"); }
};

int main(int argc, char** argv)
{
    std::cout << "c++ std=" << __cplusplus << std::endl;
    std::cout << "-----" << std::endl;

    try
    {
	X x;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}
