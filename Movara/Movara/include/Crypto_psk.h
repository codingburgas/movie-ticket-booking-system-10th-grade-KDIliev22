#pragma once
#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>

namespace Crypto {
    std::string hashSHA512(const std::string& input);
}

#endif // CRYPTO_H