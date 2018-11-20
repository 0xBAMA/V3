#include "../voraldo/V3.h"

using std::cout;
using std::endl;

/*

Conditional Operator (inline if statment)
-----------------------------------------

x ? y : z

works like

if(x) y else z



Just a note, this:
------------------

a = x ? : y;

is the same as:

a = x ? x : y;

*/

Voraldo::Voraldo()
{
	RGB black = {0,0,0};
	name_to_RGB_map["black"] = black;

	RGB dark_grey = {24,24,24};
	name_to_RGB_map["dark_grey"] = dark_grey;

	RGB medium_grey = {128,128,128};
	name_to_RGB_map["medium_grey"] = medium_grey;

	RGB light_grey = {240,240,240};
	name_to_RGB_map["light_grey"] = light_grey;

	RGB white = {255,255,255};
	name_to_RGB_map["white"] = white;

	RGB bright_red = {255,0,0};
	name_to_RGB_map["bright_red"] = bright_red;

	RGB bright_green = {0,255,0};
	name_to_RGB_map["bright_green"] = bright_green;

	RGB bright_blue = {0,0,255};
	name_to_RGB_map["bright_blue"] = bright_blue;

	RGB bright_cyan = {0,255,255};
	name_to_RGB_map["bright_cyan"] = bright_cyan;

	RGB bright_magenta = {255,0,255};
	name_to_RGB_map["bright_magenta"] = bright_magenta;

	RGB bright_yellow = {255,255,0};
	name_to_RGB_map["bright_yellow"] = bright_yellow;

	RGB maroon = {128,0,0};
	name_to_RGB_map["maroon"] = maroon;

	RGB olive = {128,128,0};	
	name_to_RGB_map["olive"] = olive;

	RGB green = {0,128,0};
	name_to_RGB_map["green"] = green;

	RGB purple = {128,0,128};
	name_to_RGB_map["purple"] = purple;

	RGB teal = {0,128,128};
	name_to_RGB_map["teal"] = teal;

	RGB navy = {0,0,128};
	name_to_RGB_map["navy"] = navy;

	RGB coral = {255,127,80};
	name_to_RGB_map["coral"] = coral;

	RGB tomato = {255,99,71};
	name_to_RGB_map["tomato"] = tomato;

	RGB salmon = {250,128,114};
	name_to_RGB_map["salmon"] = salmon;

	RGB orange = {255,165,0};
	name_to_RGB_map["orange"] = orange;

	RGB dark_orange = {135,66,0};
	name_to_RGB_map["dark_orange"] = dark_orange;

	RGB gold = {255,215,0};
	name_to_RGB_map["gold"] = gold;

//Dawnbringer 16 color palette
	//http://pixeljoint.com/forum/forum_posts.asp?TID=12795

	RGB Dawnbringer00 = {20, 12, 28};
	name_to_RGB_map["Dawnbringer00"] = Dawnbringer00;
	RGB Dawnbringer01 = {68, 36, 52};
	name_to_RGB_map["Dawnbringer01"] = Dawnbringer01;
	RGB Dawnbringer02 = {48, 52, 109};
	name_to_RGB_map["Dawnbringer02"] = Dawnbringer02;
	RGB Dawnbringer03 = {78, 74, 78};
	name_to_RGB_map["Dawnbringer03"] = Dawnbringer03;
	RGB Dawnbringer04 = {133, 76, 48};
	name_to_RGB_map["Dawnbringer04"] = Dawnbringer04;
	RGB Dawnbringer05 = {52, 101, 36};
	name_to_RGB_map["Dawnbringer05"] = Dawnbringer05;
	RGB Dawnbringer06 = {208, 70, 72};
	name_to_RGB_map["Dawnbringer06"] = Dawnbringer06;
	RGB Dawnbringer07 = {117, 113, 97};
	name_to_RGB_map["Dawnbringer07"] = Dawnbringer07;
	RGB Dawnbringer08 = {89, 125, 206};
	name_to_RGB_map["Dawnbringer08"] = Dawnbringer08;
	RGB Dawnbringer09 = {210, 125, 44};
	name_to_RGB_map["Dawnbringer09"] = Dawnbringer09;
	RGB Dawnbringer10 = {133, 149, 161};
	name_to_RGB_map["Dawnbringer10"] = Dawnbringer10;
	RGB Dawnbringer11 = {109, 170, 44};
	name_to_RGB_map["Dawnbringer11"] = Dawnbringer11;
	RGB Dawnbringer12 = {210, 170, 153};
	name_to_RGB_map["Dawnbringer12"] = Dawnbringer12;
	RGB Dawnbringer13 = {109, 194, 202};
	name_to_RGB_map["Dawnbringer13"] = Dawnbringer13;
	RGB Dawnbringer14 = {218, 212, 94};
	name_to_RGB_map["Dawnbringer14"] = Dawnbringer14;
	RGB Dawnbringer15 = {222, 238, 214};
	name_to_RGB_map["Dawnbringer15"] = Dawnbringer15;



//Voxel types begin here

	//states - limited number for now

	//	0 - empty - black
	//	1 - armor - dark grey
	//	2 - frame - dark orange
	//	3 - hull - olive
	//	4 - electrical - gold
	//	5 - red light - bright red
	//	6 - space gas

	Vox empty;
	empty.mask = false;
	empty.color = name_to_RGB_map.at("black");
	empty.alpha = 0.0;
	empty.size = 0;
	empty.state = 0;

	name_to_Vox_map["empty"] = empty;

	Vox armor_0;
	armor_0.mask = false;
	armor_0.color = name_to_RGB_map.at("dark_grey");
	armor_0.alpha = 1.0;
	armor_0.size = 1;
	armor_0.state = 1;

	name_to_Vox_map["armor_0"] = armor_0;

	Vox armor_1;
	armor_1.mask = false;
	armor_1.color = name_to_RGB_map.at("medium_grey");
	armor_1.alpha = 1.0;
	armor_1.size = 1;
	armor_1.state = 1;

	name_to_Vox_map["armor_1"] = armor_1;

	Vox frame;
	frame.mask = false;
	frame.color = name_to_RGB_map.at("dark_orange");
	frame.alpha = 1.0;
	frame.size = 2;
	frame.state = 2;

	name_to_Vox_map["frame"] = frame;

	Vox hull;
	hull.mask = false;
	hull.color = name_to_RGB_map.at("olive");
	hull.alpha = 1.0;
	hull.size = 2;
	hull.state = 3;

	name_to_Vox_map["hull"] = hull;

	Vox electrical;
	electrical.mask = false;
	electrical.color = name_to_RGB_map.at("gold");
	electrical.alpha = 0.87;
	electrical.size = 2;
	electrical.state = 4;

	name_to_Vox_map["electrical"] = electrical;

	Vox red_light;
	red_light.mask = false;
	red_light.color = name_to_RGB_map.at("bright_red");
	red_light.alpha = 0.9;
	red_light.size = 2;
	red_light.state = 5;

	name_to_Vox_map["red_light"] = red_light;


	Vox space_gas_0;
	space_gas_0.mask = false;
	space_gas_0.color = name_to_RGB_map.at("dark_grey");
	space_gas_0.alpha = 0.3;
	space_gas_0.size = 1;
	space_gas_0.state = 6;

	name_to_Vox_map["space_gas_0"] = space_gas_0;

	Vox space_gas_1;
	space_gas_1.mask = false;
	space_gas_1.color = name_to_RGB_map.at("medium_grey");
	space_gas_1.alpha = 0.3;
	space_gas_1.size = 1;
	space_gas_1.state = 6;

	name_to_Vox_map["space_gas_1"] = space_gas_1;	

	Vox space_gas_2;
	space_gas_2.mask = false;
	space_gas_2.color = name_to_RGB_map.at("light_grey");
	space_gas_2.alpha = 0.3;
	space_gas_2.size = 1;
	space_gas_2.state = 6;

	name_to_Vox_map["space_gas_2"] = space_gas_2;	

	Vox space_gas_3;
	space_gas_3.mask = false;
	space_gas_3.color = name_to_RGB_map.at("dark_grey");
	space_gas_3.alpha = 0.3;
	space_gas_3.size = 2;
	space_gas_3.state = 6;

	name_to_Vox_map["space_gas_3"] = space_gas_3;	

	Vox space_gas_4;
	space_gas_4.mask = false;
	space_gas_4.color = name_to_RGB_map.at("medium_grey");
	space_gas_4.alpha = 0.3;
	space_gas_4.size = 2;
	space_gas_4.state = 6;

	name_to_Vox_map["space_gas_4"] = space_gas_4;	

	Vox space_gas_5;
	space_gas_5.mask = false;
	space_gas_5.color = name_to_RGB_map.at("gold");
	space_gas_5.alpha = 0.3;
	space_gas_5.size = 2;
	space_gas_5.state = 6;

	name_to_Vox_map["space_gas_5"] = space_gas_5;	



	data = NULL;  //declare with an empty block
//call Block::init(int x, int y, int z) to populate it
}

Voraldo::~Voraldo()
{
	cout << "deleting block" << endl;
	delete[] data;
}

void Voraldo::init_block(int x, int y, int z, bool noise_fill)
{
	if(data != NULL)
	{
		delete[] data;
	}

	x_res = x;
	y_res = y;
	z_res = z;

	num_cells = x_res * y_res * z_res;

	data = new Vox[num_cells];

	for(int i = 0; i < num_cells; i++)
	{ //initialize array

		if(!noise)
		{
			data[i] = name_to_Vox_map.at("empty");
		}
		else
		{
			//this makes nice noise, it's inspired by something from the first iteration.
			int randcheck = std::rand()%696;
			if(randcheck == 69)
			{

				int s = rand()%256;
				switch(s)
				{
					case 0:
						data[i] = name_to_Vox_map.at("space_gas_0");
						break;
					case 1:
						data[i] = name_to_Vox_map.at("space_gas_1");
						break;
					case 2:
						data[i] = name_to_Vox_map.at("space_gas_2");
						break;
					case 3:
						data[i] = name_to_Vox_map.at("space_gas_3");
						break;
					case 4:
						data[i] = name_to_Vox_map.at("space_gas_4");
						break;
					case 5:
						data[i] = name_to_Vox_map.at("space_gas_5");
						break;
					default:
						break;
				}
			}
		}
	}
}

//draw at point
void Voraldo::draw_point(vec point, Vox set)
{

}

//draw along 3 dimensional line segment
void Voraldo::draw_line_segment(vec point1, vec point2, Vox set)
{

}

//draw 3 dimensional triangle, with verticies point 0, point 1, point 2
void Voraldo::draw_triangle(vec point0, vec point1, vec point2, Vox set)
{

}

//draw sphere - centered at center_point, of radius radius
void Voraldo::draw_sphere(vec center_point, double radius, Vox set)
{

}

//draw ellipsoid - centered at center_point, radii in radii
void Voraldo::draw_ellipsoid(vec center_point, vec radii, Vox set)
{

}

//draw cylinder - bvec and tvec establish the endpoints, by center, and radius is the radius
void Voraldo::draw_cylinder(vec bvec, vec tvec, double radius, Vox set)
{

}

//draw tube - just like a cylinder, but with an inner radius that will establish thickness
void Voraldo::draw_tube(vec bvec, vec tvec, double inner_radius, double outer_radius, Vox set)
{

}

//draw blockoid - draw all voxels within the axis-aligned block defined by mindex and maxdex
void Voraldo::draw_blockoid(vec mindex, vec maxdex, Vox set)
{

}

//draw quadrilateral hexahedron - fill the space defined by 8 points - refer to docs
void Voraldo::draw_quadrilateral_hexahedron(vec a, vec b, vec c, vec d, vec e, vec f, vec g, vec h, Vox set)
{

}

//...


//array access functions

void Voraldo::set_data_by_3D_index(int x, int y, int z, Vox set)
{
	//validate the input - make sure you are in the block
	bool x_valid = x < x_res && x >= 0;
	bool y_valid = y < y_res && y >= 0;
	bool z_valid = z < z_res && z >= 0;

	bool masked = data[get_array_index_by_xyz(x,y,z)].mask;

	//all dimensions valid, do as the user asks
	if(x_valid && y_valid && z_valid && !masked)
	{
		if(set.color.red <= 255&&set.color.green <= 255&&set.color.blue <= 255)
		{
			data[get_array_index_by_xyz(x,y,z)] = set;
		}
		else
		{
			data[get_array_index_by_xyz(x,y,z)] = name_to_Vox_map;
		}
	}
	else
	{
		if(!masked)
		{
			std::cout << std::endl << "Invalid index for set_data_by_index()" << std::endl;

			std::cout << "you used " << std::to_string(x) << " for x which should be between 0 and ";
			std::cout << std::to_string(x_res) << std::endl;

			std::cout << "you used " << std::to_string(y) << " for y which should be between 0 and ";
			std::cout << std::to_string(y_res) << std::endl;

			std::cout << "you used " << std::to_string(z) << " for z which should be between 0 and ";
			std::cout << std::to_string(z_res) << std::endl;
		}
		else
		{
			std::cout << "Cell " 
				<< std::to_string(x) << " " 
				<< std::to_string(y) << " " 
				<< std::to_string(z) << " is masked";
		}
	}

	return;
}

int Voraldo::get_array_index_for_3D_index(int x, int y, int z)
{

}

//mask functions

void Voraldo::unmask_all()
{//sets all mask values to false

}

void Voraldo::invert_mask()
{//inverts every cell's mask value

}

//display

void Voraldo::display()
{

}

bool Voraldo::planetest()
{

}