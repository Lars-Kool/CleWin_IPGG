# C scripts behind the symbols in basic_shapes.cif
In this folder you can find the scripts that are used to generate all symbols in the "../Basic_shapes.cif" file. These scripts are written in C, although they contain certain functions, like `rectangle()` and `snapnode()` that are CleWin specific, and will thus not run outside the CleWin script editor. Feel free to use (parts) of these scripts to program your own symbols. Below you can find a small guide on how to add a script to CleWin.

## How to add scripts to CleWin
1. Create a new symbol ("Arrange->Create empty symbol").
2. Enter the newly created symbol by clicking on it in the Symbol hierarchical overview.
3. Enter the properties mode of the symbol and go to the parameters tab ("Right-Click->Properties" on the symbol in the hierarchical overview)
4. Add all the required parameters to the symbol (the required parameters are listed in the [manual](../doc/Manual.md).
5. Select the script object tool (White "S" with black outline in the toolbar on the left).
6. Add a script object to the design.
7. Center the object around (0, 0).
8. Copy-paste the script into the script editor.
