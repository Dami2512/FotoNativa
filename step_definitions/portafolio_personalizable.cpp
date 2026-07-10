#include <cassert>
#include <cucumber-cpp/defs.hpp>

using namespace cucumber;

struct ContextoPortafolio {
    bool enConstructor = false;
    bool tieneFotografias = false;
    bool plantillaSeleccionada = false;
    bool portafolioGenerado = false;
    bool vistaPrevia = false;
    bool ordenModificado = false;
    bool cambiosGuardados = false;
};


GIVEN("^que el usuario accede al constructor de portafolio$") {
    ScenarioScope<ContextoPortafolio> contexto;

    contexto->enConstructor = true;
}

GIVEN("^tiene fotografías cargadas en su cuenta$") {
    ScenarioScope<ContextoPortafolio> contexto;

    contexto->tieneFotografias = true;
}

WHEN("^selecciona fotografías y una plantilla visual$") {
    ScenarioScope<ContextoPortafolio> contexto;

    if (contexto->enConstructor && contexto->tieneFotografias) {
        contexto->plantillaSeleccionada = true;
        contexto->portafolioGenerado = true;
        contexto->vistaPrevia = true;
    }
}

THEN("^el sistema genera un portafolio personalizado$") {
    ScenarioScope<ContextoPortafolio> contexto;

    assert(contexto->portafolioGenerado == true);
}

THEN("^muestra una vista previa del resultado final$") {
    ScenarioScope<ContextoPortafolio> contexto;

    assert(contexto->vistaPrevia == true);
}


GIVEN("^que el fotógrafo tiene un portafolio creado$") {
    ScenarioScope<ContextoPortafolio> contexto;

    contexto->portafolioGenerado = true;
}

GIVEN("^desea cambiar el orden de sus fotografías$") {
    ScenarioScope<ContextoPortafolio> contexto;

    contexto->ordenModificado = true;
}

WHEN("^reorganiza las imágenes y guarda los cambios$") {
    ScenarioScope<ContextoPortafolio> contexto;

    if (contexto->portafolioGenerado && contexto->ordenModificado) {
        contexto->cambiosGuardados = true;
    }
}

THEN("^el sistema actualiza el portafolio$") {
    ScenarioScope<ContextoPortafolio> contexto;

    assert(contexto->cambiosGuardados == true);
}

THEN("^muestra las fotografías en el orden seleccionado$") {
    ScenarioScope<ContextoPortafolio> contexto;

    assert(contexto->ordenModificado == true);
}
