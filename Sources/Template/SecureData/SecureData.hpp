//
// EPITECH PROJECT, 2018
// cpp_rtype
// File description:
// SecureData template declaration
//

#include <mutex>

template<typename T>
struct SecuredData {
    SecuredData()
    {

    };

    SecuredData(SecuredData const &original)
    {
        data = original.data;
    }

    SecuredData &operator=(SecuredData const &original) {
        data = original.data;
        return *this;
    }

    T data;
    std::mutex mutex;
};
