// SPDX-License-Identifier: BSD-3-Clause

#pragma once
#include <memory>
#include <string>
#include <vector>

namespace scratch3cpp {
/**
 * @brief Represents a field in a Scratch block.
 *
 * A field is a piece of data associated with a block, such as a label or input value.
 */
class Field {
    public:
        Field(const std::string& name, const std::string& type)
            : name(name), type(type) {}

        std::string getName() const { return name; }
        std::string getType() const { return type; }

    private:
        std::string name;
        std::string type;
};
}
