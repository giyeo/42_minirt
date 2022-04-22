• If any misconfiguration of any kind is encountered in the file the program must exit
properly and return "Error\n" followed by an explicit error message of your choice.
• For the defense, it would be ideal for you to have a whole set of scenes with the
focus on what is functional, to facilitate the control of the elements to create

Your program must take as a first argument a scene description file with the .rt
extension.
◦ Each type of element can be separated by one or more line break(s).
◦ Each type of information from an element can be separated by one or more
space(s).
◦ Each type of element can be set in any order in the file.
◦ Elements which are defined by a capital letter can only be declared once in
the scene

Each element first’s information is the type identifier (composed by one or two
character(s)), followed by all specific information for each object in a strict
order such as:

∗ identifier: cy
∗ x,y,z coordinates: 50.0,0.0,20.6
∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ the cylinder diameter: 14.2
∗ the cylinder height: 21.42
∗ R,G,B colors in range [0,255]: 10, 0, 255


∗ identifier: pl
∗ x,y,z coordinates: 0.0,0.0,-10.0
∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ R,G,B colors in range [0-255]: 0, 0, 255


∗ identifier: sp
∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
∗ the sphere diameter: 12.6
∗ R,G,B colors in range [0-255]: 10, 0, 255

∗ identifier: L
∗ x,y,z coordinates of the light point: 0.0,0.0,20.6
∗ the light brightness ratio in range [0.0,1.0]: 0.6
∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255

∗ identifier: C
∗ x,y,z coordinates of the view point: 0.0,0.0,20.6
∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ FOV : Horizontal field of view in degrees in range [0,180]

∗ identifier: A
∗ ambient lighting ratio in range [0.0,1.0]: 0.2
∗ R,G,B colors in range [0-255]: 255, 255, 255
