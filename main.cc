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

int init_x = 513;
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

	vec RRhub = vec(128,128,208);
	vec RRinner = vec(128,128,200);
	vec RRouter = vec(128,128,216);

	vec LRhub = vec(128,128,48);
	vec LRinner = vec(128,128,56);
	vec LRouter = vec(128,128,40);

	vec RFhub = vec(384,128,208);
	vec RFinner = vec(384,128,200);
	vec RFouter = vec(384,128,216);

	vec LFhub = vec(384,128,48);
	vec LFinner = vec(384,128,56);
	vec LFouter = vec(384,128,40);

	vec Rdiff = vec(128,128,128);
	vec Fdiff = vec(384,128,128);

	vec Rdiff_Roffset = vec(128,128,100);
	vec Rdiff_Loffset = vec(128,128,156);

	vec Rdiff_Foffset = vec(164,128,128);


	//Draw driveline/axles
	main_block->draw_cylinder(Rdiff,Fdiff,4.5,main_block->name_to_Vox_map.at("blue_light"));

	main_block->draw_cylinder(LRhub,RRhub,4.5,main_block->name_to_Vox_map.at("blue_light"));
	main_block->draw_cylinder(LFhub,RFhub,4.5,main_block->name_to_Vox_map.at("blue_light"));

	main_block->mask_all_nonzero();

	//Draw hubs
	main_block->draw_cylinder(LFhub,LFinner,7,main_block->name_to_Vox_map.at("red_light"));
	main_block->draw_cylinder(RFhub,RFinner,7,main_block->name_to_Vox_map.at("red_light"));
	main_block->draw_cylinder(LRhub,LRinner,7,main_block->name_to_Vox_map.at("red_light"));
	main_block->draw_cylinder(RRhub,RRinner,7,main_block->name_to_Vox_map.at("red_light"));

	main_block->mask_all_nonzero();

	//Draw diff
	main_block->draw_sphere(Rdiff,14, main_block->name_to_Vox_map.at("electrical"));
	main_block->draw_cylinder(Rdiff,Rdiff_Roffset,7.5,main_block->name_to_Vox_map.at("electrical"));
	main_block->draw_cylinder(Rdiff,Rdiff_Loffset,7.5,main_block->name_to_Vox_map.at("electrical"));

	main_block->draw_cylinder(Rdiff,Rdiff_Foffset,7.5,main_block->name_to_Vox_map.at("electrical"));

	//Draw wheels and tires
	main_block->draw_cylinder(LFinner,LFouter,16,main_block->name_to_Vox_map.at("space_gas_5"));
	main_block->draw_cylinder(RFinner,RFouter,16,main_block->name_to_Vox_map.at("space_gas_5"));
	main_block->draw_cylinder(LRinner,LRouter,16,main_block->name_to_Vox_map.at("space_gas_5"));
	main_block->draw_cylinder(RRinner,RRouter,16,main_block->name_to_Vox_map.at("space_gas_5"));

	main_block->draw_tube(LFinner,LFouter,19,26,main_block->name_to_Vox_map.at("solid_black"));
	main_block->draw_tube(RFinner,RFouter,19,26,main_block->name_to_Vox_map.at("solid_black"));
	main_block->draw_tube(LRinner,LRouter,19,26,main_block->name_to_Vox_map.at("solid_black"));
	main_block->draw_tube(RRinner,RRouter,19,26,main_block->name_to_Vox_map.at("solid_black"));

	main_block->draw_tube(LFinner,LFouter,25,27,main_block->name_to_Vox_map.at("space_gas_solid"));
	main_block->draw_tube(RFinner,RFouter,25,27,main_block->name_to_Vox_map.at("space_gas_solid"));
	main_block->draw_tube(LRinner,LRouter,25,27,main_block->name_to_Vox_map.at("space_gas_solid"));
	main_block->draw_tube(RRinner,RRouter,25,27,main_block->name_to_Vox_map.at("space_gas_solid"));

	//end of drawing functions

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