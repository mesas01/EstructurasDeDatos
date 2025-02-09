#include <sstream>
#include "utilidades.h"

std::vector<std::string> dividirComando(const std::string& comando) {
    std::vector<std::string> partes;
    std::stringstream ss(comando);
    std::string parte;

    while (ss >> parte) {
        partes.push_back(parte);
    }

    return partes;
}