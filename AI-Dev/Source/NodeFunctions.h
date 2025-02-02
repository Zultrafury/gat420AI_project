#pragma once
#include <vector>

#include "Node.h"
using char_node_t = node<char>;

class NodeFunctions
{
public:
    static std::vector<char_node_t*> getDFS(char_node_t* root, char target);
    static std::vector<char_node_t*> getBFS(char_node_t* root, char target);
};
