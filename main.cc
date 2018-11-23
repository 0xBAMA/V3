#include <iostream>
#include <string>
#include <chrono>
#include "includes/voraldo/V3.h"

//stream class aliases
using std::cout;
using std::endl;
using std::cin;

//Chrono class aliases 
using Clock=std::chrono::high_resolution_clock;
using milliseconds=std::chrono::milliseconds;

//menu functions
void menu(); //present options and prompt to user
char user(); //get user input

void exit(); //responsible for deallocating memory 

Voraldo *main_block = NULL;

int init_x = 257;
int init_y = 257;
int init_z = 257;

int main(){
	char input = 0; //holds menu response

	auto tick = Clock::now(); //start of the timekeeping

	int num_bytes = init_x * init_y * init_z * sizeof(Vox);

	main_block = new Voraldo;
	main_block->init_block(init_x, init_y, init_z, true);

	auto tock = Clock::now(); //end of timekeeping
	cout<< "-----------------" << endl;
	cout<< "Dynamic memory allocation for " 
		<< init_x * init_y * init_z << " voxels took " 
		<< std::chrono::duration_cast<milliseconds>(tock-tick).count() 
		<< " milliseconds" << endl;

	cout<< "using " << std::setw(4) << float(num_bytes)/(1024.0*1024.0) 
		<< " megabytes" << endl;
	cout<< "-----------------" << endl;

	menu();

	input = user();

	tick = Clock::now();

	//drawing functions


	vec triangle1pt1 = vec(20,30,45);
	vec triangle1pt2 = vec(18,45,45);
	vec triangle1pt3 = vec(14,22,18);

	vec triangle2pt1 = vec(183,40,21);
	vec triangle2pt2 = vec(126,140,81);
	vec triangle2pt3 = vec(180,160,121);

	vec centerpoint = vec(
		(triangle1pt1[0]+triangle1pt2[0]+triangle1pt3[0]+triangle2pt1[0]+triangle2pt2[0]+triangle2pt3[0])/6,
		(triangle1pt1[1]+triangle1pt2[1]+triangle1pt3[1]+triangle2pt1[1]+triangle2pt2[1]+triangle2pt3[1])/6,
		(triangle1pt1[2]+triangle1pt2[2]+triangle1pt3[2]+triangle2pt1[2]+triangle2pt2[2]+triangle2pt3[2])/6);

	main_block->draw_sphere(centerpoint,36.0,main_block->name_to_Vox_map.at("clear_blue_glass"));
	main_block->draw_sphere(centerpoint,25.0,main_block->name_to_Vox_map.at("empty"));

	vec radii = vec(12,3,3);
	main_block->draw_ellipsoid(centerpoint,radii,main_block->name_to_Vox_map.at("red_light_clear"));
	radii[0] = 3;
	radii[1] = 12;
	main_block->draw_ellipsoid(centerpoint,radii,main_block->name_to_Vox_map.at("green_light_clear"));
	radii[1] = 3;
	radii[2] = 12;
	main_block->draw_ellipsoid(centerpoint,radii,main_block->name_to_Vox_map.at("blue_light_clear"));

	vec xlinept1 = vec(centerpoint[0]+15,centerpoint[1],centerpoint[2]);
	vec xlinept2 = vec(centerpoint[0]-15,centerpoint[1],centerpoint[2]);

	vec ylinept1 = vec(centerpoint[0],centerpoint[1]+15,centerpoint[2]);
	vec ylinept2 = vec(centerpoint[0],centerpoint[1]-15,centerpoint[2]);

	vec zlinept1 = vec(centerpoint[0],centerpoint[1],centerpoint[2]+15);
	vec zlinept2 = vec(centerpoint[0],centerpoint[1],centerpoint[2]-15);

	main_block->draw_line_segment(xlinept1,xlinept2, main_block->name_to_Vox_map.at("solid_black"));
	main_block->draw_line_segment(ylinept1,ylinept2, main_block->name_to_Vox_map.at("solid_black"));
	main_block->draw_line_segment(zlinept1,zlinept2, main_block->name_to_Vox_map.at("solid_black"));

	vec linept1 = triangle1pt1;
	vec linept2 = triangle2pt1;

	main_block->draw_line_segment(linept1,linept2, main_block->name_to_Vox_map.at("hull"));

	linept1 = triangle1pt2;
	linept2 = triangle2pt2;

	main_block->draw_cylinder(linept1,linept2, 6.0, main_block->name_to_Vox_map.at("frame"));

	linept1 = triangle1pt3;
	linept2 = triangle2pt3;

	main_block->draw_tube(linept1,linept2, 4.0,6.0, main_block->name_to_Vox_map.at("red_light"));

	main_block->draw_triangle(triangle1pt1,triangle1pt2,triangle1pt3,main_block->name_to_Vox_map.at("electrical"));
	main_block->draw_triangle(triangle2pt1,triangle2pt2,triangle2pt3,main_block->name_to_Vox_map.at("electrical"));

	vec blockoid_max = vec(10,10,10);
	vec blockoid_min = vec(5,5,5);

	main_block->draw_blockoid(blockoid_min,blockoid_max,main_block->name_to_Vox_map.at("red_light"));

	vec a = vec(60,40,100);
	vec b = vec(60,15,100);
	vec c = vec(140,40,100);
	vec d = vec(140,15,100);

	vec e = vec(60,85,30);
	vec f = vec(60,60,30);
	vec g = vec(140,85,30);
	vec h = vec(140,60,30);

	main_block->draw_quadrilateral_hexahedron(a,b,c,d,e,f,g,h,main_block->name_to_Vox_map.at("blue_light"));

	tock = Clock::now();

	cout<< "-----------------" << endl;
	cout<< "all drawing took " 
	<< std::chrono::duration_cast<milliseconds>(tock-tick).count() 
	<< " milliseconds" << endl;
	cout<< "-----------------" << endl << endl;



	tick = Clock::now();

	main_block->display();

	tock = Clock::now();

	cout<< "-----------------" << endl;
	cout<< "Displaying the block of  " 
	<< init_x * init_y * init_z << " voxels took " 
	<< std::chrono::duration_cast<milliseconds>(tock-tick).count() 
	<< " milliseconds" << endl;
	cout<< "-----------------" << endl << endl;



	
	exit();

	return 0;

}

void menu(){
	cout << endl << endl
		<< "Hit any letter, followed by enter, to exit." 
		<< endl << endl;

	cout << "Enter a letter." << endl;
	cout << ">";
}

char user(){
	char temp;
	cin >> temp;
	return temp;
}

void exit(){ //this deletes all allocated dynamic memory
	auto tick = Clock::now(); //start of the timekeeping
	delete main_block;
	auto tock = Clock::now(); //end of timekeeping

	int num_bytes = init_x * init_y * init_z * sizeof(Vox);

	cout<< "-----------------" << endl;
	cout<< "Dynamic memory deallocation took " 
		<< std::chrono::duration_cast<milliseconds>(tock-tick).count() 
		<< " milliseconds" << endl;

	cout<< "freeing " << std::setw(4) << float(num_bytes)/(1024.0*1024.0)
		<< " megabytes" << endl;
	cout<< "-----------------" << endl;

}