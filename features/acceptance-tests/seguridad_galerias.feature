Feature: Seguridad en galerías privadas  
  Como fotógrafo  
  quiero que mis galerías privadas estén protegidas mediante enlaces únicos 	y control de acceso  
  para evitar visualizaciones no autorizadas.  
  
  Scenario: Bloqueo de acceso a usuario no autorizado  
    Given que una galería fue configurada como privada  
    And un usuario no autorizado intenta ingresar  
    When intenta acceder mediante un enlace inválido o sin contraseña  
    Then el sistema bloquea la visualización de la galería  
    And muestra un mensaje indicando que no tiene permisos de acceso  
  
  Scenario: Acceso permitido mediante enlace válido  
    Given que el cliente recibe un enlace privado de galería  
    And el enlace se encuentra activo  
    When el cliente abre el enlace correctamente  
    Then el sistema permite visualizar la galería compartida  
    And mantiene el contenido protegido frente a usuarios no autorizados 
