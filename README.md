# 3d_wireframe

This project, nicknamed FDF for the French phrase fil de fer, is a 3-d wireframe renderer that allows the user to move the image in three dimensional space. The tools used to accomplish this include key hook functions for events provided by the user and pixel display functions for the calculated output.

<img width="1993" alt="screen shot 2017-08-09 at 2 23 59 pm" src="https://user-images.githubusercontent.com/13093517/29144927-b6f57e14-7d0f-11e7-830a-e9dd8447a9b1.png">

## Key Details


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
