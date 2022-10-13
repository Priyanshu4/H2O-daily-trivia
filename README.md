# H2O-daily-trivia
In the hallways of the building I live in at the University of Connecticut, each dorm room door has a small bulletin board next to it.
Students decorate the bulletin board outside their room.
I took the decorations to the next level with an interactive screen that displays a new trivia question each day. 
Each day at midnight, it automatically puts up a new trivia question and background image from its internal questions list.
Throughout the day, people walking by can test their knowledge and answer the question by pushing one of the 4 buttons on the display.
When someone presses a button to answer the question, it tells them if they are correct and shows them the answer statistics from the other people who answered.
Since over 100 people live on my floor, tens of people answer the trivia question each day.
My floor is the Honors 2 Opportunities (H2O) floor, which is why the project is called H2O Daily Trivia.

To make this project, I used a Raspberry Pi Pico, Raspberry Pi's microcontroller chip with 256 kB of RAM and 2 MB flash memory.
For the display, I used the Pimoroni Pico Display Pack 2.0. It's a 2 inch LCD screen with 320 by 240 resolution.
It also has four built-in buttons, which is perfect for multiple choice trivia questions with 4 answer choices.
The software for the Pico was developed in C++ and uses the CMake build system.
The case for the microcontroller and display was 3D printed.
The microcontroller and screen are powered with a portable power bank.
