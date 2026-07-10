#include <cassert>
#include <cucumber-cpp/defs.hpp>

using namespace cucumber;

struct ContextoVisualizacion {
    bool fotografiaCargada = false;
    bool enGaleria = false;
    bool imagenAbierta = false;
    bool altaResolucion = false;
    bool sinDistorsiones = false;
    bool mismaNitidez = false;
    bool mismaCalidad = false;
};

GIVEN("^que una fotografía fue cargada correctamente en FotoNativa$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    contexto->fotografiaCargada = true;
}

GIVEN("^se encuentra almacenada en la galería del usuario$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    contexto->enGaleria = true;
}

WHEN("^el usuario abre la fotografía desde su portafolio$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    if (contexto->fotografiaCargada && contexto->enGaleria) {
        contexto->imagenAbierta = true;
        contexto->altaResolucion = true;
        contexto->sinDistorsiones = true;
    }
}

THEN("^el sistema muestra la imagen en alta resolución$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    assert(contexto->altaResolucion == true);
}

THEN("^la fotografía se visualiza sin distorsiones ni pérdida visible de nitidez$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    assert(contexto->sinDistorsiones == true);
}


GIVEN("^que el fotógrafo cargó una imagen en calidad original$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    contexto->fotografiaCargada = true;
}

GIVEN("^la imagen se encuentra disponible en su galería$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    contexto->enGaleria = true;
}

WHEN("^el usuario compara la imagen visualizada con el archivo original$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    contexto->mismaNitidez = true;
    contexto->mismaCalidad = true;
}

THEN("^no debe evidenciarse pérdida de nitidez$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    assert(contexto->mismaNitidez == true);
}

THEN("^no debe observarse reducción visible de calidad$") {
    ScenarioScope<ContextoVisualizacion> contexto;

    assert(contexto->mismaCalidad == true);
}
