#pragma once

#include "test.h"

class TestCommon : public Test {
public:
    using Test::Test;

private:
    void testSection1() override;
};
