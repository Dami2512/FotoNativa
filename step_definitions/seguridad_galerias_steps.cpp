#include <cassert>
#include <cucumber-cpp/defs.hpp>

using namespace cucumber;

struct ContextoSeguridad {
    bool galeriaPrivada = false;
    bool usuarioAutorizado = false;
    bool enlaceValido = false;
    bool accesoPermitido = false;
    bool accesoBloqueado = false;
    bool mensajeError = false;
};


GIVEN("^que una galería fue configurada como privada$") {
    ScenarioScope<ContextoSeguridad> contexto;

    contexto->galeriaPrivada = true;
}

GIVEN("^un usuario no autorizado intenta ingresar$") {
    ScenarioScope<ContextoSeguridad> contexto;

    contexto->usuarioAutorizado = false;
}

WHEN("^intenta acceder mediante un enlace inválido o sin contraseña$") {
    ScenarioScope<ContextoSeguridad> contexto;

    if (contexto->galeriaPrivada && !contexto->usuarioAutorizado) {
        contexto->accesoBloqueado = true;
        contexto->mensajeError = true;
    }
}

THEN("^el sistema bloquea la visualización de la galería$") {
    ScenarioScope<ContextoSeguridad> contexto;

    assert(contexto->accesoBloqueado == true);
}

THEN("^muestra un mensaje indicando que no tiene permisos de acceso$") {
    ScenarioScope<ContextoSeguridad> contexto;

    assert(contexto->mensajeError == true);
}


GIVEN("^que el cliente recibe un enlace privado de galería$") {
    ScenarioScope<ContextoSeguridad> contexto;

    contexto->usuarioAutorizado = true;
}

GIVEN("^el enlace se encuentra activo$") {
    ScenarioScope<ContextoSeguridad> contexto;

    contexto->enlaceValido = true;
}

WHEN("^el cliente abre el enlace correctamente$") {
    ScenarioScope<ContextoSeguridad> contexto;

    if (contexto->usuarioAutorizado && contexto->enlaceValido) {
        contexto->accesoPermitido = true;
    }
}

THEN("^el sistema permite visualizar la galería compartida$") {
    ScenarioScope<ContextoSeguridad> contexto;

    assert(contexto->accesoPermitido == true);
}

THEN("^mantiene el contenido protegido frente a usuarios no autorizados$") {
    ScenarioScope<ContextoSeguridad> contexto;

    assert(contexto->galeriaPrivada == true);
}
