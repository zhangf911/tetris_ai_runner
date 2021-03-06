
#pragma once

#include "rule_qq.h"

using namespace m_tetris;
using namespace m_tetris_rule_tools;

namespace rule_qq
{
    bool TetrisRuleSet::init(int w, int h)
    {
        return h < max_height;
    }

    template<unsigned char R>
    bool qq_rotate_template(TetrisNode &node, TetrisContext const *context)
    {
        TetrisBlockStatus status =
        {
            node.status.t, node.status.x, node.status.y, R
        };
        if(!context->create(status, node))
        {
            return false;
        }
        return node.row + node.height <= context->height();
    }

    template<unsigned char T>
    TetrisBlockStatus init_generate_template(TetrisContext const *context)
    {
        TetrisBlockStatus status =
        {
            T, context->width() / 2 - 2, 39, 0
        };
        return status;
    }

    template<unsigned char T>
    TetrisBlockStatus game_generate_template(TetrisContext const *context)
    {
        TetrisBlockStatus status =
        {
            T, context->width() / 2 - 2, context->height() - 1, 0
        };
        return status;
    }

    std::map<std::pair<unsigned char, unsigned char>, TetrisOpertion> TetrisRuleSet::get_init_opertion()
    {
        std::map<std::pair<unsigned char, unsigned char>, TetrisOpertion> info;
#define T(a, b, c, d) (((a) ? 1 : 0) | ((b) ? 2 : 0) | ((c) ? 4 : 0) | ((d) ? 8 : 0))
        TetrisOpertion op_O1 =
        {
            create_node<'O', 0, 0, 0,
            T(0, 1, 1, 0),
            T(0, 1, 1, 0),
            T(0, 0, 0, 0),
            T(0, 0, 0, 0)>,
            nullptr,
            nullptr,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_I1 =
        {
            create_node<'I', 0, 0, 0,
            T(0, 0, 0, 0),
            T(1, 1, 1, 1),
            T(0, 0, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<1>,
            qq_rotate_template<1>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_I2 =
        {
            create_node<'I', 0, 0, 1,
            T(0, 0, 1, 0),
            T(0, 0, 1, 0),
            T(0, 0, 1, 0),
            T(0, 0, 1, 0)>,
            qq_rotate_template<0>,
            qq_rotate_template<0>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_S1 =
        {
            create_node<'S', 0, 0, 0,
            T(0, 1, 1, 0),
            T(1, 1, 0, 0),
            T(0, 0, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<1>,
            qq_rotate_template<1>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_S2 =
        {
            create_node<'S', 0, 0, 1,
            T(0, 1, 0, 0),
            T(0, 1, 1, 0),
            T(0, 0, 1, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<0>,
            qq_rotate_template<0>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_Z1 =
        {
            create_node<'Z', 0, 0, 0,
            T(1, 1, 0, 0),
            T(0, 1, 1, 0),
            T(0, 0, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<1>,
            qq_rotate_template<1>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_Z2 =
        {
            create_node<'Z', 0, 0, 1,
            T(0, 0, 1, 0),
            T(0, 1, 1, 0),
            T(0, 1, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<0>,
            qq_rotate_template<0>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_L1 =
        {
            create_node<'L', 0, 0, 0,
            T(1, 1, 0, 0),
            T(0, 1, 0, 0),
            T(0, 1, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<3>,
            qq_rotate_template<1>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_L2 =
        {
            create_node<'L', 0, 0, 1,
            T(0, 0, 0, 0),
            T(1, 1, 1, 0),
            T(1, 0, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<0>,
            qq_rotate_template<2>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_L3 =
        {
            create_node<'L', 0, 0, 2,
            T(0, 1, 0, 0),
            T(0, 1, 0, 0),
            T(0, 1, 1, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<1>,
            qq_rotate_template<3>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_L4 =
        {
            create_node<'L', 0, 0, 3,
            T(0, 0, 1, 0),
            T(1, 1, 1, 0),
            T(0, 0, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<2>,
            qq_rotate_template<0>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_J1 =
        {
            create_node<'J', 0, 0, 0,
            T(0, 1, 1, 0),
            T(0, 1, 0, 0),
            T(0, 1, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<3>,
            qq_rotate_template<1>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_J2 =
        {
            create_node<'J', 0, 0, 1,
            T(1, 0, 0, 0),
            T(1, 1, 1, 0),
            T(0, 0, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<0>,
            qq_rotate_template<2>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_J3 =
        {
            create_node<'J', 0, 0, 2,
            T(0, 1, 0, 0),
            T(0, 1, 0, 0),
            T(1, 1, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<1>,
            qq_rotate_template<3>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_J4 =
        {
            create_node<'J', 0, 0, 3,
            T(0, 0, 0, 0),
            T(1, 1, 1, 0),
            T(0, 0, 1, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<2>,
            qq_rotate_template<0>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_T1 =
        {
            create_node<'T', 0, 0, 0,
            T(0, 0, 0, 0),
            T(1, 1, 1, 0),
            T(0, 1, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<3>,
            qq_rotate_template<1>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_T2 =
        {
            create_node<'T', 0, 0, 1,
            T(0, 1, 0, 0),
            T(0, 1, 1, 0),
            T(0, 1, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<0>,
            qq_rotate_template<2>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_T3 =
        {
            create_node<'T', 0, 0, 2,
            T(0, 1, 0, 0),
            T(1, 1, 1, 0),
            T(0, 0, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<1>,
            qq_rotate_template<3>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
        TetrisOpertion op_T4 =
        {
            create_node<'T', 0, 0, 3,
            T(0, 1, 0, 0),
            T(1, 1, 0, 0),
            T(0, 1, 0, 0),
            T(0, 0, 0, 0)>,
            qq_rotate_template<2>,
            qq_rotate_template<0>,
            nullptr,
            move_left,
            move_right,
            move_down,
        };
#undef T
        info.insert(std::make_pair(std::make_pair('O', 0), op_O1));
        info.insert(std::make_pair(std::make_pair('I', 0), op_I1));
        info.insert(std::make_pair(std::make_pair('I', 1), op_I2));
        info.insert(std::make_pair(std::make_pair('S', 0), op_S1));
        info.insert(std::make_pair(std::make_pair('S', 1), op_S2));
        info.insert(std::make_pair(std::make_pair('Z', 0), op_Z1));
        info.insert(std::make_pair(std::make_pair('Z', 1), op_Z2));
        info.insert(std::make_pair(std::make_pair('L', 0), op_L1));
        info.insert(std::make_pair(std::make_pair('L', 1), op_L2));
        info.insert(std::make_pair(std::make_pair('L', 2), op_L3));
        info.insert(std::make_pair(std::make_pair('L', 3), op_L4));
        info.insert(std::make_pair(std::make_pair('J', 0), op_J1));
        info.insert(std::make_pair(std::make_pair('J', 1), op_J2));
        info.insert(std::make_pair(std::make_pair('J', 2), op_J3));
        info.insert(std::make_pair(std::make_pair('J', 3), op_J4));
        info.insert(std::make_pair(std::make_pair('T', 0), op_T1));
        info.insert(std::make_pair(std::make_pair('T', 1), op_T2));
        info.insert(std::make_pair(std::make_pair('T', 2), op_T3));
        info.insert(std::make_pair(std::make_pair('T', 3), op_T4));
        return info;
    }

    std::map<unsigned char, m_tetris::TetrisBlockStatus(*)(TetrisContext const *)> TetrisRuleSet::get_init_generate()
    {
        std::map<unsigned char, m_tetris::TetrisBlockStatus(*)(TetrisContext const *)> info;
        info.insert(std::make_pair('O', &init_generate_template<'O'>));
        info.insert(std::make_pair('I', &init_generate_template<'I'>));
        info.insert(std::make_pair('S', &init_generate_template<'S'>));
        info.insert(std::make_pair('Z', &init_generate_template<'Z'>));
        info.insert(std::make_pair('L', &init_generate_template<'L'>));
        info.insert(std::make_pair('J', &init_generate_template<'J'>));
        info.insert(std::make_pair('T', &init_generate_template<'T'>));
        return info;
    }

    std::map<unsigned char, m_tetris::TetrisBlockStatus(*)(TetrisContext const *)> TetrisRuleSet::get_game_generate()
    {
        std::map<unsigned char, m_tetris::TetrisBlockStatus(*)(TetrisContext const *)> info;
        info.insert(std::make_pair('O', &game_generate_template<'O'>));
        info.insert(std::make_pair('I', &game_generate_template<'I'>));
        info.insert(std::make_pair('S', &game_generate_template<'S'>));
        info.insert(std::make_pair('Z', &game_generate_template<'Z'>));
        info.insert(std::make_pair('L', &game_generate_template<'L'>));
        info.insert(std::make_pair('J', &game_generate_template<'J'>));
        info.insert(std::make_pair('T', &game_generate_template<'T'>));
        return info;
    }

}