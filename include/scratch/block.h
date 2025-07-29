// SPDX-License-Identifier: BSD-3-Clause

#pragma once
#include <memory>
#include <string>
#include <vector>

#include "field.h"

//
namespace libscratch
{
  /*! \brief The Block class represents a Scratch block. */
  class Block {
    // Monitor blocks are sensor blocks.
    // Opcodes are like the unique identifier for blocks: move () steps might have something like move_steps
    Block(const std::string &id, const std::string &opcode, bool is_sensor_block = false);

    Block *next() const;
    const std::string &next_id() const;
    void set_next(Block *block);
    void set_next_id(const std::string &next_id);

    Block *parent() const;
    const std::string &parent_id();
    void set_parent(Block *block);
    void set_parent_id(const std::string &parent_id);

    const std::vector<std::shared_ptr<Field>> &get_fields() const;
  }
}
