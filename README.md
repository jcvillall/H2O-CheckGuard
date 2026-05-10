# H2O CheckGuard

Sistema inteligente para monitoreo y optimización del consumo 
de agua en entornos domésticos.

## Descripción del prototipo

Prototipo funcional desarrollado en Wokwi con Arduino Uno que 
simula un sistema de detección de fugas y monitoreo de caudal 
con tres niveles de alerta.

## Estados del sistema

| Estado | Condición | Respuesta |
|--------|-----------|-----------|
| Normal | Flujo bajo | LED verde activo |
| Consumo Alto | Flujo elevado | LED amarillo + monitoreo |
| Fuga detectada | Flujo crítico | LED rojo + buzzer + válvula cierra |

## Componentes simulados

- Arduino Uno (microcontrolador)
- Potenciómetro (simula sensor de flujo)
- LCD 16x2 I2C (visualización local)
- LEDs verde, amarillo y rojo (indicadores de estado)
- Buzzer (alerta sonora)
- Servo motor (simula válvula de corte automático)

## Simulación

Desarrollado en [Wokwi](https://wokwi.com/projects/463518116298479617) — simulador IoT online.

## Nivel TRL

**TRL 5** — Validación tecnológica en entorno relevante simulado.

## Tecnologías

- Arduino IDE / C++
- LiquidCrystal I2C
- Servo

## Autores

- [Nombre estudiante 1]
- [Nombre estudiante 2]

## Institución

Universidad Nacional Abierta y a Distancia — UNAD
Alexis Zorrilla Ruiz 
Juan Camilo Villalobos Ramírez 
202016907 - Proyecto de grado 
Tutor: Rubén Darío Ordóñez M. 
