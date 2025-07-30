// SPDX-License-Identifier: BSD-3-Clause

#pragma once
#include <memory>
#include <string>
#include <vector>
#include <optional>

#include "field.h"

namespace scratch3cpp {
/**
 * @brief Represents a block in a Scratch project.
 *
 * A block is a fundamental unit in Scratch, representing a command or control structure.
 * It can have fields and may be connected to other blocks.
 */
class Block {
    protected:
        /**
         * @brief The block's opcode. This is a string that tells Scratch what kind of block it is. 
         * This is different from an ID, which is really just Scratch's way of keeping count of what block we're at!
         */
        std::string opcode;
        /**
         * @brief The block's ID. This is a unique identifier for the block within the project.
         */
        std::string id;
        /**
         * @brief The block's parent ID. This is the ID of the block that contains this block, if any.
         * For example, if blocks are nested, the parent ID would be the ID of the outer block.
         * This field is optional, as not all blocks have a parent.
         */
        std::optional<std::string> parent_id;

        std::vector<std::shared_ptr<Field>> fields; ///< The fields associated with this block.
        std::vector<std::shared_ptr<Block>> inputs; ///< The input blocks connected to this block.

    public:
        /**
         * @brief Constructs a Block with specified opcode and id.
         * @param opcode The opcode of the block.
         * @param id The ID of the block.
         * @param parent_id The parent ID of the block, if any.
         */
        Block(const std::string& opcode, const std::string& id, const std::optional<std::string>& parent_id = std::nullopt)
            : opcode(opcode), id(id), parent_id(parent_id) {}

        /**
         * @brief Constructs a Block with specified opcode, id, fields, and inputs.
         * @param opcode The opcode of the block.
         * @param id The ID of the block.
         * @param fields The fields associated with the block.
         * @param inputs The input blocks connected to this block.
         * @param parent_id The parent ID of the block, if any.
         */
        Block(const std::string &opcode, const std::string &id, const std::vector<std::shared_ptr<Field>>& fields, 
              const std::vector<std::shared_ptr<Block>>& inputs, 
              const std::optional<std::string>& parent_id = std::nullopt)
            : opcode(opcode), id(id), fields(fields), inputs(inputs), parent_id(parent_id) {}

        const std::string &get_opcode() const;

        const std::vector<std::shared_ptr<Field>>& get_fields() const;
        const std::vector<std::shared_ptr<Block>>& get_inputs() const;

        inline void add_field(const std::shared_ptr<Field>& field) {
            fields.push_back(field);
        }
        inline void add_input(const std::shared_ptr<Block>& input) {
            inputs.push_back(input);
        }
    };
};
