# 🔐 Sistema Anti-Furto com Sensor PIR - Arduino

Sistema de segurança que detecta intrusos e ativa alarmes sonoro e visual.

## Componentes Necessários
- Arduino Uno
- Sensor PIR (detector de movimento)
- Buzzer ativo (alarme sonoro)
- 1 LED vermelho (alarme visual)
- Resistor 220Ω (para o LED)
- Fios e protoboard

## Como Funciona
1. O sensor PIR monitora movimentos continuamente
2. Quando detecta presença:
   - Acende o LED vermelho
   - Ativa o buzzer (1900Hz)
   - Mantém o alarme por 1 segundo
3. Após 1 segundo:
   - Desliga o buzzer
   - Apaga o LED
   - Volta ao modo de monitoramento

## Conexões
| Arduino | Componente | Detalhes |
|---------|------------|----------|
| A0      | PIR (Sinal) | Fio amarelo/verde |
| D6      | LED Vermelho | Com resistor 220Ω |
| D7      | Buzzer     | Terminal positivo |
| 5V      | PIR (VCC)  | Fio vermelho |
| GND     | Todos GND  | PIR, LED e Buzzer |

## Como Usar
1. Baixe o arquivo `.ino`
2. Abra na IDE Arduino
3. Monte o circuito como na tabela acima
4. Carregue o código para o Arduino
5. Ajuste os potenciômetros do PIR conforme necessário

## Personalização
Você pode alterar no código:
- Duração do alarme (1 segundo)
- Frequência do buzzer (1900Hz)
- Intervalo do LED piscante (500ms)
- Sensibilidade (ajuste nos potenciômetros do PIR)

✉️ **Contato**: matheushollifer@gmail.com
