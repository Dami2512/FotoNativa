#include <cassert>
#include <string>
#include <cucumber-cpp/defs.hpp>

using namespace cucumber;

struct ContextoCarga {
    bool pantallaCarga = false;
    bool formatoPermitido = false;
    bool imagenCargada = false;
    bool sinCompresion = false;
    bool archivoRechazado = false;
    bool mensajeError = false;
};


GIVEN("^que el fotógrafo se encuentra en la pantalla de carga de imágenes$") {
    ScenarioScope<ContextoCarga> contexto;

    contexto->pantallaCarga = true;
}

GIVEN("^selecciona una fotografía en formato permitido$") {
    ScenarioScope<ContextoCarga> contexto;

    contexto->formatoPermitido = true;
}

WHEN("^presiona el botón \"Subir fotografía\"$") {
    ScenarioScope<ContextoCarga> contexto;

    if (contexto->pantallaCarga && contexto->formatoPermitido) {
        contexto->imagenCargada = true;
        contexto->sinCompresion = true;
    }
}

THEN("^el sistema carga la imagen correctamente$") {
    ScenarioScope<ContextoCarga> contexto;

    assert(contexto->imagenCargada == true);
}

THEN("^conserva la resolución original sin aplicar compresión$") {
    ScenarioScope<ContextoCarga> contexto;

    assert(contexto->sinCompresion == true);
}

GIVEN("^selecciona un archivo con formato no permitido$") {
    ScenarioScope<ContextoCarga> contexto;

    contexto->formatoPermitido = false;
}

WHEN("^intenta subir el archivo a la plataforma$") {
    ScenarioScope<ContextoCarga> contexto;

    if (!contexto->formatoPermitido) {
        contexto->archivoRechazado = true;
        contexto->mensajeError = true;
    }
}

THEN("^el sistema rechaza la carga$") {
    ScenarioScope<ContextoCarga> contexto;

    assert(contexto->archivoRechazado == true);
}

THEN("^muestra un mensaje indicando los formatos aceptados$") {
    ScenarioScope<ContextoCarga> contexto;

    assert(contexto->mensajeError == true);
}
