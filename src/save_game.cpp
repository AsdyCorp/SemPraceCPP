#include "object_manager.h"

void object_manager::save_game() {

	
	std::string name;
	long long nsecs = std::time(0);
	name.append("save_file");
	name.append(std::to_string(nsecs)); //get epoch time
	
	std::ofstream save_file(name); //create file

	save_file <<map_name<<std::endl; //map name
	save_file << w << " " << h << std::endl; //map size
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			save_file << map_tiles[i][j].id<<" "; //tiles
		}
		save_file << std::endl;
	}
	
	save_file << "0x01"<<std::endl; //magic string

	if ((int)all_objects.size() > 0) { //entities
		for (int i = 0; i < (int)all_objects.size() - 1; i++) {
			save_file << all_objects[i]->save_data() << " -2" << std::endl;
		}
		save_file << all_objects[(int)all_objects.size() - 1]->save_data() << " -2";
	}
	save_file.close();

}