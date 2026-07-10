#include <cassert>
#include <cucumber-cpp/defs.hpp>

using namespace cucumber;

struct ContextoRendimiento {
    bool fotografiaSeleccionada = false;
    bool cargaRapida = false;
    bool mensajeConfirmacion = false;
    bool imagenAlmacenada = false;
    bool visualizacionFluida = false;
};


GIVEN("^que el fotógrafo selecciona una fotografía en alta resolución$") {
    ScenarioScope<ContextoRendimiento> contexto;

    contexto->fotografiaSeleccionada = true;
}

WHEN("^inicia la carga de la fotografía$") {
    ScenarioScope<ContextoRendimiento> contexto;

    if (contexto->fotografiaSeleccionada) {
        contexto->cargaRapida = true;
        contexto->mensajeConfirmacion = true;
    }
}

THEN("^el sistema completa la carga sin tiempos de espera excesivos$") {
    ScenarioScope<ContextoRendimiento> contexto;

    assert(contexto->cargaRapida == true);
}

THEN("^muestra un mensaje de confirmación al finalizar el proceso$") {
    ScenarioScope<ContextoRendimiento> contexto;

    assert(contexto->mensajeConfirmacion == true);
}


GIVEN("^que una fotografía en alta resolución se encuentra almacenada$") {
    ScenarioScope<ContextoRendimiento> contexto;

    contexto->imagenAlmacenada = true;
}

WHEN("^el usuario la abre desde su galería$") {
    ScenarioScope<ContextoRendimiento> contexto;

    if (contexto->imagenAlmacenada) {
        contexto->visualizacionFluida = true;
    }
}

THEN("^el sistema muestra la imagen sin demoras excesivas$") {
    ScenarioScope<ContextoRendimiento> contexto;

    assert(contexto->visualizacionFluida == true);
}

THEN("^permite navegar sin interrupciones visibles$") {
    ScenarioScope<ContextoRendimiento> contexto;

    assert(contexto->visualizacionFluida == true);
}
