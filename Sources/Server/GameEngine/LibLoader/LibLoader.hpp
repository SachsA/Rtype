/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_LIBLOADER_HPP
    #define CPP_RTYPE_2018_LIBLOADER_HPP

#ifdef _WIN32
#include <Windows.h>
#elif defined (linux)
#include <dlfcn.h>
#endif

#include <string>
#include "../Entities/AEntity.hpp"
#include "ErrorsLibLoader.hpp"

template<typename T>
class LibLoader
{
public:
    LibLoader() = default;
    LibLoader(const LibLoader<T> &) = default;

    LibLoader(const char *libPath) :
            _libPath(libPath), _handle(nullptr), _sym(nullptr)
    {}

	LibLoader(std::string &libPath) :
            _libPath(libPath), _handle(nullptr), _sym(nullptr)
    {}

    ~LibLoader() {}

    T *load(const std::string &symbol, std::string str = "")
    {
		void *ptr;

        if (!str.empty())
            this->_libPath = str;

		openLib();
		ptr = getSym(symbol);
        this->_sym = reinterpret_cast<T *(*)()>(ptr);
        if (!this->_sym)
			throw ErrorsLibLoader(std::cerr, "Sym null.");
		return this->_sym();
    }

private:
	T *(*_sym)();
	std::string _libPath;

#ifdef _WIN32
	HINSTANCE _handle;
#elif defined (linux)
    void *_handle{};
#endif

	void openLib() {
#ifdef _WIN32
		this->_handle = LoadLibrary(this->_libPath.c_str());
#elif defined (linux)
		this->_handle = dlopen(this->_libPath.c_str(), RTLD_LAZY);
#endif
		if (!this->_handle)
			throw ErrorsLibLoader(std::cerr, "Handle fail.");
	};

	void *getSym(const std::string &symbol) {
		void *ptr;

#ifdef _WIN32
		ptr = GetProcAddress(this->_handle, symbol.c_str());
#elif defined (linux)
		ptr = dlsym(this->_handle, symbol.c_str());
#endif
		if (ptr == nullptr)
			throw ErrorsLibLoader(std::cerr, "Ptr null.");
		return ptr;
	}

};

using EntityLoader = LibLoader<AEntity>;

#endif //CPP_RTYPE_2018_LIBLOADER_HPP
