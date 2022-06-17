4 type of parses with error check

ambient		= double, color
light		= coordinate, double, color
sphere		= coordinate, double, color
camera		= coordinate, coordinate, int
plane		= coordinate, coordinate, color
cylinder	= coordinate, coordinate, double, double, color

coordinate + color done;
double + int;

parse_double;

∗	the light brightness ratio in range [0.0,1.0]: 0.6
*	the sphere diameter: 12.6
∗	the cylinder diameter: 14.2
∗	the cylinder height: 21.42
∗	ambient lighting ratio in range [0.0,1.0]: 0.2
∗	ambient lighting ratio in range [0.0,1.0]: 0.2

parse_int;

∗	FOV : Horizontal field of view in degrees in range [0,180]

parse_color / parse_three_ints;

∗	R,G,B colors in range [0-255]: 255, 255, 255

parse_coordinates / parse_three_double

∗	x,y,z coordinates of the view point: 0.0,0.0,20.6
∗	3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0