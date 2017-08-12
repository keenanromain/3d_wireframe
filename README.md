# 3d_wireframe

This project, nicknamed FDF for the French phrase fil de fer, is a 3-d wireframe renderer that allows the user to move an image in three dimensional space. The external tools used include hook functions for user-determined keyboard events and display functions for calculating output pixel by pixel.

<img width="1993" alt="screen shot 2017-08-09 at 2 23 59 pm" src="https://user-images.githubusercontent.com/13093517/29144927-b6f57e14-7d0f-11e7-830a-e9dd8447a9b1.png">

## Key Details

3d_wireframe works by reading in the contents of a file ending in '.fdf' and then checking for it's validity. The validity testing is done in many ways and the function below demonstrates two such ways; checking the vertical and horizontal bounds of a given file's input and comparing the length of each line in the file to it's primary one. When given a valid file, *parse_in* performs as it's name implies by reading and parsing the input into the environment data structure.

<img width="580" alt="screen shot 2017-08-09 at 2 43 29 pm" src="https://user-images.githubusercontent.com/13093517/29146488-3f2dbda4-7d16-11e7-893a-39ed39c337a4.png">

This is done primarily through the *get_next_line* function as it reads the file's content line by line and stores the data inside the string 'line'. This string is then converted into a 2-d array of integers (a valid file can only contain characters of numbers) and the result is then stored inside the grid member of the environment struct. In line 55, the code compares each 1-d line within the 2-d grid against the original 1d-array to check for proper width. For each successful run of the while loop, the contents of the 'line' variable are freed in order for the variable to be reused. The height is then incremented as the loop moves down to the next line in the file.


The next key detail is the *image_loop* function where the coordinates successfully read and parsed into the environment struct are staged before being plotted as pixels in the *run_bresenham* function. In order to stage all of the coordinates, two loops based on height and width are nested within each other. This allows the entirety of the grid's dimensions to be ran through. Each point is then passed to the *set_bresenham* function which performs the needed calculations for each set of coordinates. Note that the inner loops variable 'j' on line 85 begins at an index of 0 rather than -1 despite the prefix incrementation of the inner loop. This is because the 0th position of the width in the environment struct holds the number of elements in the line, rather than raw input data from the file.

<img width="513" alt="screen shot 2017-08-09 at 2 45 13 pm" src="https://user-images.githubusercontent.com/13093517/29147211-8b1a6c90-7d1a-11e7-950c-486312d886bf.png">

The last major detail is the *run_bresenham* function which performs the final calculations for line drawing before the coordinates are sent to the mlx library and are outputted onto the window. This function contains a generic Bresenham Line Drawing Algorithm with a few minor changes for different colored output. This is achieved first through a comparison of absolute values within the environment struct. The comparison's truthfulness is stored as 'env.z' and is responsible the red vectors. If 'env.z' proves false and the top-most priority grid point is greater than zero, the condition of 'env.top' on line 30 is met and a blue line is drawn. If the two prior conditions are false, a yellow line is drawn. 

<img width="571" alt="screen shot 2017-08-09 at 2 46 06 pm" src="https://user-images.githubusercontent.com/13093517/29147617-071e9e04-7d1d-11e7-8bd0-986ad72c4bec.png">

A very simple demonstration of these properties is shown below in the **Implementation** section with the '42' graphic displaying all three colors based on the conditions above. For more on the Bresenham Line Drawing Algorithm and my favorite resource for this project, please explore the link below:

http://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/

## Implementation

To run this project, clone this repo into your terminal and generate the executable via the make command.
```
git clone https://github.com/keenanromain/3d_wireframe.git
cd 3d_wireframe
make
```
A successful make command will output that an executable called 'fdf' has been created. In the test-maps directory, there are a number of valid maps that will display the functionality of this project. From the root directory of the cloned repo, a command like...
```
./fdf test-maps/42.fdf
```
...will generate the following:

<img width="1993" alt="screen shot 2017-08-09 at 2 23 11 pm" src="https://user-images.githubusercontent.com/13093517/29146164-b572dece-7d14-11e7-9478-07bda5905f13.png">

## Acknowledgement

3d_wireframe was developed at École 42 USA in Fremont, California. 
