
#include "object_manager.h"
#include <iostream>
#include "stdlib.h"

/// <summary>
/// Main game cycle. Create object manager object, that manages all objects and game state.
/// </summary>
int main(int argc, char* argv[])
{
    object_manager object;
    ///load map from example or by path in agrs list
    if (argc == 1) {
        object.load_map("maps/1.txt");
    }
    else {
        std::string arg1(argv[1]);
        object.load_map(arg1);
    }
    ///generate keys on map for final quest
    object.generate_keys(object.exits_point[0]->get_sp_points());

    ///main game loop
    while (true) {
        object.Render();
        object.input_handler();
        object.check_hp();
    }
   
   
}
