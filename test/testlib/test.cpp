#include <stdexcept>
#include <iostream>

#include "test.h"

Test::Test()
{}

Test::~Test()
{}

TestStatistic Test::run()
{
    mStatistic = TestStatistic();

    Test testBase;

    using TFunc = void (Test::*)();

    TFunc funcs[] = {
        &Test::testSection1,
        &Test::testSection2,
        &Test::testSection3,
        &Test::testSection4,
        &Test::testSection5,
        &Test::testSection6,
        &Test::testSection7,
        &Test::testSection8,
        &Test::testSection9
    };

    for( auto iter : funcs ) {
        try {
            mOwnFunction = false;
            (this->*iter)();

            if( !mOwnFunction ) {
                mStatistic.mTestFunc = typeid(iter).name();
            }
        }
        catch( const std::exception & exc ) {
            std::cout << "Fail : " << exc.what() << std::endl;
        }
        catch( ... ) {}
    }

    return mStatistic;
}

void Test::testSection1(){ mOwnFunction = true; }
void Test::testSection2(){ mOwnFunction = true; }
void Test::testSection3(){ mOwnFunction = true; }
void Test::testSection4(){ mOwnFunction = true; }
void Test::testSection5(){ mOwnFunction = true; }
void Test::testSection6(){ mOwnFunction = true; }
void Test::testSection7(){ mOwnFunction = true; }
void Test::testSection8(){ mOwnFunction = true; }
void Test::testSection9(){ mOwnFunction = true; }
