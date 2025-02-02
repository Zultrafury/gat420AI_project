#include "NodeFunctions.h"

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

std::vector<char_node_t*> NodeFunctions::getDFS(char_node_t* root, char target)
{
    if (root == nullptr) return {};

    stack<char_node_t*> node_stack;
    root->visited = true;
    node_stack.push(root);

    while (!node_stack.empty())
    {
        char_node_t* current = node_stack.top();

        if (current->data == target)
        {
            cout << "found: " << current->data << '\n';
            break;
        }
        cout << "visited: " << current->data << '\n';

        bool popNode = true;
        for (auto child : current->children)
        {
            if (!child->visited)
            {
                child->visited = true;
                node_stack.push(child);
                popNode = false;
                break;
            }
        }
        if (popNode)
        {
            node_stack.pop();
        }
    }

    vector<char_node_t*> path;
    while (!node_stack.empty())
    {
        path.insert(path.begin(), node_stack.top());
        node_stack.pop();
    }

    return path;
}

vector<char_node_t*> NodeFunctions::getBFS(char_node_t* root, char target)
{
    if (root == nullptr) return {};

    queue<char_node_t*> node_queue;
    root->visited = true;
    node_queue.push(root);

    while (!node_queue.empty())
    {
        char_node_t* current = node_queue.front();

        if (current->data == target)
        {
            cout << "found: " << current->data << '\n';
            break;
        }
        cout << "visit: " << current->data << '\n';

        for (auto child : current->children)
        {
            if (!child->visited)
            {
                child->visited = true;
                child->parent = current;
                node_queue.push(child);
            }
        }

        node_queue.pop();
    }

    vector<char_node_t*> path;
    char_node_t* node = (!node_queue.empty()) ? node_queue.front() : nullptr;
    while (node)
    {
        path.insert(path.begin(), node);
        node = node->parent;
    }

    return path;
}