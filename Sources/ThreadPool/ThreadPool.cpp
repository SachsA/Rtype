//
// EPITECH PROJECT, 2021
// CPP_rtype_2018
// File description:
// Created by kellian CIPIERRE,
//

#include "ThreadPool.hpp"

ThreadPool::~ThreadPool()
{
    int i = 0;
    while (i < _threadTable.size()) {
        if (_threadTable[i].joinable()) {
            _threadTable[i].join();
        }
    }
}

bool ThreadPool::createThread(GameInstance *object, void *param)
{
    if (object == nullptr || param == nullptr)
        return false;

    _threadTable.emplace_back(std::thread(&GameInstance::mainLoopThread, object, param));
    _threadTable[_threadTable.size() - 1].detach();
    return true;
}

unsigned long ThreadPool::getThreadTableSize()
{
    return _threadTable.size();
}

bool ThreadPool::joinThread(int i)
{
    if (_threadTable[i].joinable()) {
        _threadTable[i].join();
        return true;
    }
    return false;
}