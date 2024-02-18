## The first graphical project I've done. The aim of this project is to read the map in fdf format and display it in 3D format.

![Screenshot from 2023-06-09 12-14-50](https://github.com/AshParker19/42_FdF/assets/117525743/74c5b98c-bb93-434d-92dd-30cb1cc1dc0b)

---

_So far, this project was my biggest struggle of the course._
The gap between rank01 and this project is gigantic, and I had to learn a lot of new things to complete it.
One of the reasons probably was that this was the first project of rank02 I did, but it was worth it, I did enjoy it a lot.

I've learned how to use the minilibx library, how to work with 2D and 3D graphics, how to use the Bresenham's and DDA drawing algorithms, how to use the 2D transformations, and a lot more. I improwed my Linked list skills and discovered structures in a completely new way.

---
![42-ezgif com-video-to-gif-converter](https://github.com/AshParker19/42_FdF/assets/117525743/a868aa2e-f3f9-451b-8e2a-28e62900895c)

![world-ezgif com-video-to-gif-converter](https://github.com/AshParker19/42_FdF/assets/117525743/1f7c1f73-bd4e-4f3e-9226-b19f66697dee)

![himalaya-ezgif com-video-to-gif-converter](https://github.com/AshParker19/42_FdF/assets/117525743/4b5dbbe7-ef80-4997-8b7b-3372b3e88a8c)


## `The flow of the program:`

### `Data structure I used:`
I use a linked list to store the map. I read the provided `.fdf` files and store these values:
```
`x` - x coordinate of the point(width)
`y` - y coordinate of the point(height)
`z` - z coordinate of the point(altitude)
```
Thus, when the whole map is read, I have a linked list of points, which I can use to draw the map.
But before that, in order to draw the grid, I need to connect the points with lines, this is not a problem for horizontal lines
because in the linked list I always have pointer to the `next`, but the problem was how to connect them vertically, this why I have 
`down` in my linked list, which is a pointer to the point below the current one.

In order connect all the horizontal lines vertically, I came up with this algorithm:
```
    1.I have a pointer to the head of the linked list, and the number of nodes in the list.
    2.I also have the maximum number of nodes in a column.
    3.Loop through the list, and for each node I connect it with the node below it, I use some pointer arithmetic to do this.
    4.I can always find the needed node from the row below by going max number of nodes in a column forward.
    5.Repeat this until I reach the last possible node, which is the number of nodes minus the maximum number of nodes in a column.
```

### `Drawing the map:`
Now, when my linked list is ready, all the points are connected vertically and horizontally, I can start drawing the map.
I tried different drawing algorithms, none of them was working perfectly with the purpose of  this project, so I used modified version of DDAs algorithm, which I found on the internet.

```
    First I draw all the horizontal lines, then I draw all the vertical lines.
    I use the same algorithm for both of them, but with some modifications.
    
    In order to draw a complete line I need to know the coordinates of the start and the end of the line.
    I also need to know the color of the start and the end of the line.
    I use the function to draw the lines, it takes the image, the line, and the coordinates as arguments. I need all of this info.
    To draw a line, I put pixel by pixel trough the line, starting at the start coordinate and each time recalculating the new position, getting closer and closer to the end coordinate.
    First I find the absolute difference between the start and the end coordinates, and then I find the maximum of them, this is the number of pixels in the line.
    Then I loop through the line, and each time I put a pixel, the current coorinate `x` and `y` values are incremented so we are moving closer to the end coordinate,
    The calculation is done by the formula: 
    `x += dx / coor.y_coor`, 
    `y += dy / coor.y_coor`, 
```

---

## Sources:

Bresenham's drawing algorithm - https://youtu.be/RGB-wlatStc

DDA drawing algorithm - https://youtu.be/W5P8GlaEOSI

2D transformations - https://youtu.be/EKN7dTJ4ep8
