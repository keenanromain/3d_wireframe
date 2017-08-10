# 3d_wireframe

This project, nicknamed FDF for the French phrase fil de fer, is a 3-d wireframe renderer that allows the user to move the image in three dimensional space. The tools used to accomplish this include key hook functions for events provided by the user and pixel display functions for the calculated output.

<img width="1993" alt="screen shot 2017-08-09 at 2 23 59 pm" src="https://user-images.githubusercontent.com/13093517/29144927-b6f57e14-7d0f-11e7-830a-e9dd8447a9b1.png">

## Key Details

3d_wireframe works by first reading in the contents of a file ending in '.fdf' and checking it's validity. This is done in various ways, including setting vertical and horizontal bounds and checking the length of each line successfully parsed into the environment struct. The reading and parsing is performed in the 'parse_in' function, mainly between lines 52 to 58.

<img width="580" alt="screen shot 2017-08-09 at 2 43 29 pm" src="https://user-images.githubusercontent.com/13093517/29146488-3f2dbda4-7d16-11e7-893a-39ed39c337a4.png">

The 'get_next_line' function reads the content of each line in the file to the string 'line'. This string is then converted into a  2-d array of integers and promptly stores this data inside the grid member of the environment struct. In line 55, the code compares each 1-d array inside the 2-d grid against the original 1d-array to check for proper width. For each successful run of the loop, the contents of the 'line' variable are freed in order for the variable to be recycled and the height is incremented before the code reads the next line.

<<<<<<< HEAD
=======
The next key function is the 'image_loop' function where the coordinates successfully read and parsed in the 'parse_in' function are staged before being plotted as pixels in the 'run_bresenham' function. In order to stage every coordinate, two loops are nested within each other with a call to the 'set_bresenham' function to perform the needed calculations for each set of coordinates. Note that the inner loops variable 'j' on line 85 begins at an index of 0 rather than -1 despite the prefix incrementation of the inner loop. This is because the 0th position of the width stores the entire length of the width, rather than input data from the file.

<img width="513" alt="screen shot 2017-08-09 at 2 45 13 pm" src="https://user-images.githubusercontent.com/13093517/29147211-8b1a6c90-7d1a-11e7-950c-486312d886bf.png">

The last key function is the 'run_bresenham' function which performs any final calculations before the coordinates are outputted onto the graphics window. This function is the generic Bresenham Line Drawing Algorithm plus a few minor changes in order to display different colored output. This is achieved first through checking absolute value comparisons between members within the environment struct and this comparison is stored as 'env.z'. If it is true, a red vector connecting coordinates is drawn. Otherwise, if the most current value of the grid variable is positive, the condition of 'env.top' on line 30 is met and a blue line is drawn. If neither of the previous conditions are true, a yellow line is then drawn. 

<img width="571" alt="screen shot 2017-08-09 at 2 46 06 pm" src="https://user-images.githubusercontent.com/13093517/29147617-071e9e04-7d1d-11e7-8bd0-986ad72c4bec.png">

A very visual demonstration of these properties is shown in the **Implementation** section with the '42' graphic displaying all three colors in appropriate fashion. For more on the Bresenham Line Drawing Algorithm and my favorite resource for this project, please explore the link below:

http://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/

>>>>>>> 41fbfa3bb3d0be587390ffa749a3a48b4c195dfa
## Implementation

To run this project, clone this repo into your command-line and generate the executable via the make command.
```
git clone https://github.com/keenanromain/3d_wireframe.git
cd 3d_wireframe
make
```
A successful make command will output that an executable called 'fdf' has been created. In the test-maps directory, there are a number of valid maps that will display the functionality of this project. From the root directory of the cloned repo, a command like:
```
./fdf test-maps/42.fdf
```
will generate the following:

<img width="1993" alt="screen shot 2017-08-09 at 2 23 11 pm" src="https://user-images.githubusercontent.com/13093517/29146164-b572dece-7d14-11e7-9478-07bda5905f13.png">

## Acknowledgement

3d_wireframe was developed at École 42 USA in Fremont, California. 
