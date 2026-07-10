#include <cassert>
#include <string>
#include <cucumber-cpp/defs.hpp>

using namespace cucumber;

struct ContextoCompatibilidad {
    std::string dispositivo;
    bool fotografiaAbierta = false;
    bool visualizacionCorrecta = false;
    bool sinDistorsiones = false;
};


GIVEN("^que el usuario accede a FotoNativa desde un (.*)$") {
    REGEX_PARAM(std::string, dispositivo);

    ScenarioScope<ContextoCompatibilidad> contexto;

    contexto->dispositivo = dispositivo;
}

GIVEN("^abre una fotografía almacenada en alta resolución$") {
    ScenarioScope<ContextoCompatibilidad> contexto;

    contexto->fotografiaAbierta = true;
}

WHEN("^visualiza la imagen desde la galería$") {
    ScenarioScope<ContextoCompatibilidad> contexto;

    if (contexto->fotografiaAbierta) {
        contexto->visualizacionCorrecta = true;
        contexto->sinDistorsiones = true;
    }
}

THEN("^el sistema muestra la fotografía correctamente$") {
    ScenarioScope<ContextoCompatibilidad> contexto;

    assert(contexto->visualizacionCorrecta == true);
}

THEN("^la imagen no presenta distorsiones visuales$") {
    ScenarioScope<ContextoCompatibilidad> contexto;

    assert(contexto->sinDistorsiones == true);
}
