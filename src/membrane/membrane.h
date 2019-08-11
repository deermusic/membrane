// Copyright (c) 2019 Micha Hanselmann
// Use of this source code is governed by the MIT license that can be found in the LICENSE file.

#ifndef MEMBRANE_MEMBRANE_H_
#define MEMBRANE_MEMBRANE_H_

#include <string>

namespace membrane {

std::string GetVersion() {
    return MEMBRANE_VERSION_STRING;
}

}  // namespace membrane

#endif  // MEMBRANE_MEMBRANE_H_
