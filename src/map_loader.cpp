#include "object_manager.h"


void object_manager::load_map(std::string name) {
	
	std::string line; 
	
	std::ifstream mapfile;
	int tmp_id;

	mapfile.open(name);
	if (!mapfile) {
		std::cout << "map load failed; check path" << std::endl;
	}
	//get map name
	getline(mapfile, map_name);
	//get map size
	mapfile >> w >> h;
	//resize map vector
	map_tiles.resize(w);
	for (int i = 0; i < w; ++i)
		map_tiles[i].resize(h);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			//read id to file

			if (!(mapfile >> tmp_id)) {
				std::cout << "save file corrupted. error in reading of map tiles; \n";
				exit(1);
			}
			map_tiles[i][j].id=tmp_id;
			map_tiles[i][j].set_pos(coords(i, j));
		}
	}
	//check for magical string - test if entities not corrupted
	std::string tmp;
	if (!(mapfile >> tmp) || tmp != "0x01") {
		std::cout << "save file corrupted. error in file structure; \n";
		exit(1);
	}

	std::vector <int> params; //parametres for instantiation
	int count = 0;
	int temp_i = 0;
	while (!(mapfile.eof())) {
		count = 0;
		params.clear();
		while (temp_i != -1) {
			mapfile >> temp_i;
			if (temp_i == -2 || temp_i == EOF) { break; }
			count++;
			params.push_back(temp_i);
		}
		switch (count)
		{
		case 3:
			create_unit(params[0], coords(params[1], params[2])); //fire
			break;
		case 5:
			create_unit(params[0],params[1],coords(params[2],params[3]),params[4]); //player
			break;
		case 4:
			if (params[0] != 102) {
				create_unit(params[0], params[1], coords(params[2], params[3])); //exit
			}
			else {
				create_unit(params[0], coords(params[1], params[2]), params[3]); //goblin
			}
			break;
		default:
			std::cout << "save file corrupted. error in entity parametres structure; \n";
			exit(1);
			break;
		}
		if (temp_i == EOF)break;

	}
}