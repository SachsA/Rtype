//
// EPITECH PROJECT, 2021
// CPP_rtype_2018
// File description:
// Created by kellian CIPIERRE,
//

#ifndef CPP_RTYPE_2018_THREADPOOL_HPP
#define CPP_RTYPE_2018_THREADPOOL_HPP

#include <thread>
#include <vector>
//#include "../Server/CoreServer/CoreServer.hpp"
#include "../Server/GameInstance/GameInstance.hpp"

class ThreadPool {
public:
	ThreadPool() = default;
	~ThreadPool();

	bool createThread(GameInstance*, void *param);
	unsigned long getThreadTableSize();
	bool joinThread(int i);

private:
	std::vector<std::thread> _threadTable;
};

#endif //CPP_RTYPE_2018_THREADPOOL_HPP
