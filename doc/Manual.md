# Manual for basic shapes in CleWin
By Lars Kool, Plateforme Technologique d'Institut Pierre-Gilles de Gennes

## Table of Contents

- Purpose of this repository
- Installation and updates
- Adding and modifying symbols to CleWin design
- Advanced methods
- Symbol descriptions

## Purpose of this repository

CleWin is a layout editor for lithography masks developed and maintained by WieWeb software (in collaboration with the MESA+ Institute at the University of Twente). CleWin is hierarchical, i.e. each layer/design consists of objects/patterns (called "symbols") that can themselves consist of different symbols. Changes made to symbols low in the hierarchy are propagated to the upper layers, so making small changes is easier.

With CleWin you can place centimeter sized object with nanometric accuracy. But with this power comes great responsibility. It is the designers responsability to make sure that all symbols are properly aligned, and there are no gaps (any gap could, depending on the resolution of your fabrication method, end up in your mask). To help with this, CleWin has a scripting interface that allows users to program the layout of a symbol in C, Matlab, MaskEngineer, Lua or Python. While this is incredibly powerful, it does bring a high barrier to entry. Moreover, CleWin only supports lines, polygons, circles, and circular arcs. Any other shape has to be aproximated by a polygon using the scripting interface. Furthermore, CleWin allows you to place snapping nodes (including normal vector) in your symbols to ensure perfect alignment, but only using the scripting interface.

This repository (i.e. GitHub folder) aims to bridge the gap between the use of only natively supported shapes, and full on scripting your entire design, by providing a library of parametric symbols (i.e. symbols that can be changed by changing the input parameters) commonly found in microfluidics. This is far from an exhaustive list. If you think a commonly used symbol/shape is missing, feel free to open a request [here]https://github.com/Lars-Kool/CleWin_IPGG/issues).

## Installation and updates

### Installation

"Installation" of this library is very simple, here we will guide you through the process.
1. First download the repository either by clicking the the green **Code** button, followed by "Download ZIP", and then unzipping the folder, or by cloning the repository `git clone https://github.com/Lars-Kool/CleWin_IPGG` in a folder of your choosing (need to have [**Git**](https://www.git-scm.com/) installed).
2. Next add the library to CleWin by clicking "**File->Open Library**", and selecting the "Basic_shapes.cif" file in the folder you just downloaded. **Add image of file-open library**

### Updates

CleWin reloads the library file on startup, meaning that replacing the "Basic_shapes.cif" file with 'update' the library. The method of replacing the library depends on the method of installing the original library. If you manually downloaded and unzipped the library, you need to do this again, and replace the old folder with the new folder.
Updating the library using Git is much simpler, just run `git pull`, and the library will be updated automatically!

## Adding and modifying symbols in CleWin

Added libraries can be found at the right side of the screen **ADD SCREENSHOT**. We would recommend pinning the library interface **ZOOM OF PIN**, since we expect you to use it frequently. Adding a symbol from the library is as simple as dragging the label of the symbol into your design. Note the semi-circles with a line through them at the edge of the symbols **ADD SNAPNODES**. These are snap-nodes (with the direction indicated by the line). Dragging two symbols with lines snap-nodes close to to each other will cause the symbol to snap to the already present symbol and automatically rotate in the correct orientation. This will prevent any misalignment of the components.

Most likely the default size of the symbol does not match your desired size. You can change the parameters (which are detailed per shape below) two ways. You can change the parameters of a specific symbol instance by selecting it followed by 'right-click' and selecting properties (or by pressing 'Alt'+'Enter' after selecting it). **ADD SNIPPET OF POPUP MENU**
You can also change the default parameters of that symbol in your design using 'right-click'->'Properties'in the symbols menu **ADD SNIPPET OF SYMBOLS MENU**. This automatically changes the parameters of all instances which have the default parameters.

The location of the snap-nodes is calculated automatically upon changing the parameters, ensuring the design is always properly aligned. Should you find a case where the snap-node is not properly aligned, please open a ticket [here]https://github.com/Lars-Kool/CleWin_IPGG/issues).

It is very likely that you will use a specific combination of basic symbols multiple times in your design. The hierarchical nature of CleWin allows you to create a new symbol ('Arrange'->'Create Emtpy Symbol'). You can then place this more complex symbol in your design, without having to place and align all the sub-symbols.

# Advanced methods

There might be a time where you would like to do more advanced things, like have a channel follow a non-linear/circular path, add parameters to your complex symbol and have them propagated to the sub-symbols, or add a matrix of labels to your mask, for example. Sadly, you have reached the limit of this library, and you will have to venture in the world of scripting. The CleWin UserGuide (which can be found in the install folder of CleWin) has all the necessary documentation. Furthermore, feel free to have a look at the scripts in the 'src' folder to see you we created certain objects. **MAKE SURE THAT YOU SAVE YOUR SYMBOLS TO A DIFFERENT FILE!!!** Whenever you update this library, the file will be overwritten, and you will lose all your symbols. There is basically no way to get them back!

A couple tips on scripting (in C) that were not immediately obvious to me:
- When creating a polygon, you need an array of nodes. The expected format is double nodes[] = {x1, y1, x2, y2, ..., xn, yn}.
- If you want to modify a TransformationMatrix (TM), the operations need to be done in the following ISRT:
    1. Identity (unityTM)
    2. Scale (scaleTM)
    3. Rotate (rotateTM)
    4. Translate (translateTM)
- If you want to transform a symbol, you need to perform all the transformations **before** adding the object.
- The functions `snapnode` and `rotateTM` require the angle in degrees, whereas all the math functions require the angle in radians.

# Symbol descriptions

## Straight
![Test](./rsc/snap_node.png)
