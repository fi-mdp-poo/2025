# menuCalculadorGenerico

## Descripción
Este proyecto es un sistema de facturación genérico desarrollado en C++. Permite gestionar facturas, calcular impuestos y emitir recibos de pago para diferentes categorías de contribuyentes. El sistema está diseñado con orientación a objetos y utiliza un menú interactivo para facilitar la operación.

## Estructura principal
- **CalculadorImpositivo**: Clase principal que gestiona las facturas y realiza el cálculo de impuestos.
- **Factura**: Representa una factura con número, detalle y monto.
- **ReciboDePago**: Genera el recibo de pago con los montos calculados.
- **Categoria**: Clase base abstracta para diferentes tipos de categorías de contribuyentes (Limitada, Completa, Extendida).
- **Menu**: Permite la interacción con el usuario mediante opciones.
- **MenuItem**: Representa una opción del menú. Hay varios tipos, como agregar factura, calcular impuesto, mostrar facturas, etc.

## ¿Cómo funciona?
1. El usuario interactúa con el menú principal.
2. Puede agregar facturas, calcular impuestos, modificar el monto fijo, y ver el historial de facturas.
3. El cálculo de impuestos depende de la categoría seleccionada y de los montos de las facturas.

## Compilación y ejecución

### Requisitos
- Compilador C++ (g++, clang++, MSVC, etc.)
- Makefile incluido para facilitar la compilación en sistemas compatibles.

## Ejecucion
Utilizando ctrl + shift + B sobre el main.cpp deberia compilar y ejecutar el codigo en la consola.

## Archivos importantes
- `src/` : Código fuente principal.
- `include/` : Archivos de cabecera (clases y métodos).
- `Makefile` : Script de compilación.
- `diagram.puml` : Diagrama de clases UML del sistema.
