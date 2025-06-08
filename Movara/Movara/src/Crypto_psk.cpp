#include "Crypto_psk.h"
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt.lib")

std::string Crypto::hashSHA512(const std::string& input) {
    BCRYPT_ALG_HANDLE hAlg = nullptr;
    BCRYPT_HASH_HANDLE hHash = nullptr;
    NTSTATUS status;
    DWORD hashLen = 0, dataLen = 0;
    status = BCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA512_ALGORITHM, nullptr, 0);
    status = BCryptGetProperty(hAlg, BCRYPT_HASH_LENGTH, (PUCHAR)&hashLen, sizeof(DWORD), &dataLen, 0);
    std::vector<BYTE> hash(hashLen);
    BCryptCreateHash(hAlg, &hHash, nullptr, 0, nullptr, 0, 0);
    status = BCryptHashData(hHash, reinterpret_cast<PUCHAR>(const_cast<char*>(input.data())), static_cast<ULONG>(input.size()), 0);
    BCryptFinishHash(hHash, hash.data(), hashLen, 0);
    std::stringstream ss;
    for (auto b : hash) ss << std::hex << std::setw(2) << std::setfill('0') << (int)b;
    BCryptDestroyHash(hHash);
    BCryptCloseAlgorithmProvider(hAlg, 0);
    return ss.str();
}