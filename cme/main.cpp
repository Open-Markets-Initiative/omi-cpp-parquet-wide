#include "program/Args.hpp"
#include "program/Runner.hpp"

int main(const int argc, char** argv) {
    try {
        const auto options = program::args(argc, argv);
        program::Runner runner{ options };
        runner.run();
        return 0;
    }
    catch (const std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}