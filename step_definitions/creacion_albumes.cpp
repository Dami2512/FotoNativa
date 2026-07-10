#include <cassert>
#include <string>
#include <vector>
#include <cucumber-cpp/defs.hpp>

using namespace cucumber;

struct ContextoAlbum {
    bool sesionIniciada = false;
    bool enSeccionAlbumes = false;
    bool albumCreado = false;
    bool albumVisible = false;
    bool tieneFotografias = false;
    bool fotosAgrupadas = false;
};


GIVEN("^que el usuario inició sesión en FotoNativa$") {
    ScenarioScope<ContextoAlbum> contexto;

    contexto->sesionIniciada = true;
}

GIVEN("^se encuentra en la sección de álbumes$") {
    ScenarioScope<ContextoAlbum> contexto;

    contexto->enSeccionAlbumes = true;
}

WHEN("^crea un nuevo álbum con nombre y descripción$") {
    ScenarioScope<ContextoAlbum> contexto;

    if (contexto->sesionIniciada && contexto->enSeccionAlbumes) {
        contexto->albumCreado = true;
        contexto->albumVisible = true;
    }
}

THEN("^el sistema registra el álbum correctamente$") {
    ScenarioScope<ContextoAlbum> contexto;

    assert(contexto->albumCreado == true);
}

THEN("^el álbum queda disponible en su portafolio$") {
    ScenarioScope<ContextoAlbum> contexto;

    assert(contexto->albumVisible == true);
}


GIVEN("^que el usuario tiene fotografías cargadas$") {
    ScenarioScope<ContextoAlbum> contexto;

    contexto->tieneFotografias = true;
}

GIVEN("^tiene un álbum creado$") {
    ScenarioScope<ContextoAlbum> contexto;

    contexto->albumCreado = true;
}

WHEN("^selecciona fotografías para agregarlas al álbum$") {
    ScenarioScope<ContextoAlbum> contexto;

    if (contexto->tieneFotografias && contexto->albumCreado) {
        contexto->fotosAgrupadas = true;
    }
}

THEN("^el sistema agrupa las fotografías correctamente$") {
    ScenarioScope<ContextoAlbum> contexto;

    assert(contexto->fotosAgrupadas == true);
}

THEN("^las muestra dentro del álbum seleccionado$") {
    ScenarioScope<ContextoAlbum> contexto;

    assert(contexto->fotosAgrupadas == true);
}
