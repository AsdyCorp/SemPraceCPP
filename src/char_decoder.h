#pragma once
inline

///Decode id of methode to char for cout
char get_char_icon(int id) {
	switch (id)
	{
	//water
	case 0:
		return '~';
		break;
	//free land
	case 1:
		return ' ';
		break;
	//player
	case 100:
		return 'P';
		break;
	//goblins
	case 101:
		return 'G';
		break;
	//exit
	case 102:
		return '#';
		break;
	//fire
	case 103:
		return 'F';
		break;
	//key
	case 99:
		return 'K';
		break;
	//error char
	default:
		return '!';
		break;
	}
}