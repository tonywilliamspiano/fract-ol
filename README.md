# fract-ol
## Rendering simple fractals in C using the minilibx from 42 Wolfsburg

This was the first graphics project in the 42 curriculum, in which the task was to render fractals using the minilibx, a small graphics library. These fractals are created by iterating over a certain function and defining colors of the pixels based on behavior of the numbers. 

If, after a certain number of iterations, the numbers 'escape' towards infinity, the color of the pixel becomes a certain shade. Otherwise, the color of the pixel stays black. This creates crazy, repeating patterns. Check out explanations of the Mandelbrot and Julia fractals on YouTube or Wikipedia for a deeper dive into the math!

## Implementation

My code is based around a structure named "t_fractal" which contains all important information pertaining to the fractal. The program creates one of these structures and passes a pointer to it around to the other functions. This way, I only have to create one "t_fractal" in memory and all parts of the program easily have access to its parameters. 

Then, a graphics window is created, the fractals are displayed, and instructions pop up in the terminal. A few interesting points and how I implemented them: 

- Zooming in and out of the fractal uses interpolation on the X-axis and Y-axis. Basically, this changes where the program 'sees' the sides of the window, so that the user has a smooth zooming experience and it feels like you're zooming toward where the mouse is positioned. 

- My Julia Set incorporates movement by changing the fractal's constant by small increments. The minilibx works by creating an infinite loop which refreshes until the window is closed. I added the fractal's constant value this loop, and by incrementing or decrementing them I give the appearance of movement and shifting fractals. I did the same thing with the color shifters. 

- To increase the efficiency of the program, I made a few adjustments. First, I compile using the Ofast flag, putting a premium on quick execution at the cost of quick compilation. Second, I made sure to use functions as little as possible. If I could set a variable outside of a loop, I did that instead of calculating it every time. I could get faster with a multi-threaded approach, but this was beyond the scope of the project and the fractal responds well as long as the screen is not too big.

- The colors go in a smooth gradient from one to another. I achieved this by splitting each color into its red-green-blue values and passing the function a number to tell it where on the spectrum between the colors it should be. If color 1 is 0,0,0 and color 2 is 100,50,50 and I pass the function the number 50, it will give back 50,25,25. This enables flexibility with the color, allowing user input as well as color shifting in the program. 

This was just a very broad overview: If you want any in-depth explanations of parts of the code, feel free to contact me. 

## Compilation

I've included files for the 'libft.a', a library with basic 42 functions, and the 'libmlx.a', the library for the minilibx, in the repository because further installations are often required to compile the minilibx correctly. 

To use the program, you should just have to download a graphics program (I used XQuartz for Mac). To test if you've installed X11 correctly, you can type the command "xeyes" into your terminal for a simple Hello World. 

Try it out yourself! Just clone the repository, go into the folder and run the command "make", and everything should
compile as planned. If you have any problems, just let me know. 

