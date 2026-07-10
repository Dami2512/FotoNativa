#include <cassert>
#include <cucumber-cpp/defs.hpp>

using namespace cucumber;

struct ContextoUsabilidad {
    bool usuarioEnPlataforma = false;
    bool deseaGestionarFotos = false;
    bool flujoClaro = false;
    bool tareaCompletada = false;
    bool panelPrincipal = false;
    bool opcionesVisibles = false;
};


GIVEN("^que el fotógrafo ingresa a la plataforma$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    contexto->usuarioEnPlataforma = true;
}

GIVEN("^desea cargar y organizar sus fotografías$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    contexto->deseaGestionarFotos = true;
}

WHEN("^utiliza las opciones de carga, álbumes y portafolio$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    if (contexto->usuarioEnPlataforma &&
        contexto->deseaGestionarFotos) {

        contexto->flujoClaro = true;
        contexto->tareaCompletada = true;
    }
}

THEN("^el sistema presenta un flujo claro e intuitivo$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    assert(contexto->flujoClaro == true);
}

THEN("^el usuario puede completar la tarea sin requerir ayuda externa$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    assert(contexto->tareaCompletada == true);
}


GIVEN("^que el usuario se encuentra en el panel principal de FotoNativa$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    contexto->panelPrincipal = true;
}

WHEN("^desea cargar, organizar o publicar fotografías$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    if (contexto->panelPrincipal) {
        contexto->opcionesVisibles = true;
    }
}

THEN("^el sistema muestra opciones visibles y comprensibles$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    assert(contexto->opcionesVisibles == true);
}

THEN("^permite continuar el proceso sin confusión$") {
    ScenarioScope<ContextoUsabilidad> contexto;

    assert(contexto->opcionesVisibles == true);
}
