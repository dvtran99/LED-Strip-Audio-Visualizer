# LED-Strip-Audio-Visualizer
Source code and schematic for LED Strip Audio Visualizer.

Converts an audio jack's line level to a readable ADC input. Uses ADC input to update state of LED strip. LED strip consists of 300 LEDs that is sectioned into 30 groups of LEDs and is updated every 50ms, resulting in the LED strip storing 1.5s of memory. Relative mapping of line level strength to LED color is as follows:

- No color
- Red
- Orange
- Yellow
- Green
- Blue
- Purple
- Pink

Demo of LED Strip here: [https://www.youtube.com/watch?v=_n9ZDiK8l8U](https://www.youtube.com/watch?v=_n9ZDiK8l8U)