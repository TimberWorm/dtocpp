#pragma once

#include <list>
#include <string>
#include <stdexcept>
#include <sstream>

using TTestException = std::runtime_error;

struct TestStatistic {
    std::string mTestName;
    std::string mTestFunc;
    int mCompares = 0;
    int mFails = 0;
};


class Test {
public:
    Test();
    virtual ~Test();

    TestStatistic run();

    template< typename compare_type >
    bool compare(const compare_type & v1, const compare_type & v2,
                 const char * v1Str, const char * v2Str, const char *fileName, int lineNr) {
        ++mStatistic.mCompares;
        bool result = v1 == v2;
        if(!result){
            ++mStatistic.mFails;
            std::ostringstream exceptionText;
            exceptionText << "Incorrect comparison found : (" << v1Str << " == " << v2Str << ") " << fileName << ":" << lineNr << std::endl
                          << "  v1 : " << v1 << " , v2 : " << v2;
            throw TTestException(exceptionText.str());
        }
        return result;
    }

private:
    virtual void testSection1();
    virtual void testSection2();
    virtual void testSection3();
    virtual void testSection4();
    virtual void testSection5();
    virtual void testSection6();
    virtual void testSection7();
    virtual void testSection8();
    virtual void testSection9();

private:
    bool mOwnFunction = true;
    TestStatistic mStatistic;
};

#define TEST_COMPARE(v1, v2)  this->compare(v1, v2, #v1, #v2, __FILE__, __LINE__ )

template< typename test_type, typename ... test_args >
std::list< TestStatistic >  TestRunRecursive(){
    std::list< TestStatistic > result;
    test_type test;
    result.push_back(test.run());
    result.back().mTestName = typeid(test_type).name();
    if constexpr (sizeof...(test_args) > 0){
        result += TestRunRecursive<test_args ...>();
    }
    return result;
}

template< typename ... test_types >
class Tests{

public:
    void run(){
        auto statisticList = TestRunRecursive<test_types...>();
    }
private:
};





