// Copyright (c) 2019 Micha Hanselmann
// Use of this source code is governed by the MIT license that can be found in the LICENSE file.

#include "gtest/gtest.h"
#include "membrane/membrane.h"

TEST(Membrane, ReturnsCorrectVersion) {
    EXPECT_EQ(membrane::GetVersion(), MEMBRANE_VERSION_STRING);
}
