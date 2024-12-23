# miniRT42
### Table of content
- [Features](#features)
- [Scene Description](#scene-description)
- [Installation](#installation)
- [Usage](#usage)
  - [Possible output](#possible-output)
- [Ressources](#ressources)

## The project
miniRT42 is a mini raytracer developed in C, using the minilibX library.

The principle is to simulate the behavior of light by casting virtual rays to determine the color of each pixel in the rendered image.

![image](https://github.com/user-attachments/assets/e451036e-c45b-41d8-9cb8-3261a9a671da)

## Features

The raytracer can represent three types of objects:

-  Sphere: Defined by its color, position, and radius.  
-  Infinite Plane: Defined by its color, position, and normal vector.
-  Hollow Cylinder: Defined by its color, position, radius, and height.

## Scene Description

The 3D scene description is stored in a .rt file, which is parsed to obtain the necessary information for each object, such as its color, position, and dimensions.

## Installation

  Clone the repository:
```
git clone https://github.com/KoganeShiro/42_Cursus.git
cd 42_Cursus/miniRT42
```

Compile the project:

```
make
```

## Usage

To run the raytracer, use the following command:
```
./miniRT42 [scene_file.rt]
```

### Possible output
![image](https://github.com/user-attachments/assets/6df9cc9b-9c9d-4a0f-a660-65e3512fc59c)
![image](https://github.com/user-attachments/assets/2fc79a5d-1a66-495f-b023-c9e604a2ee33)
![image](https://github.com/user-attachments/assets/afbb985c-15f5-4cd9-8346-aebf5293dbec)
![image](https://github.com/user-attachments/assets/1c7872aa-e493-450e-b1e7-c979aad3dd22)
![image](https://github.com/user-attachments/assets/ae50be91-bc8b-4282-acff-4a7d4c9bd7d4)
![image](https://github.com/user-attachments/assets/23d948a5-7414-42bd-ba3e-dab65469b76a)
![image](https://github.com/user-attachments/assets/562fea3e-765c-4f9e-9cac-0c1399ae6f23)


## Ressources
(We didn't use all of these)

[An Introduction to Ray Tracing In C](https://www.jakobmaier.at/posts/raytracing/#top)

[ray tracing wikipedia](https://en.wikipedia.org/wiki/Ray_tracing_(graphics))

[Minimal raytracer](https://medium.com/swlh/a-minimal-raytracer-for-you-to-mess-with-and-learn-from-4502115519cc)


[Article on miniRT part 1](https://medium.com/@iremoztimur07/building-a-minirt-42-project-part-1-ae7a00aebdb9)

[Article on miniRT part 2](https://medium.com/@iremoztimur07/minirt-shading-algorithms-part-2-6c46e6d81fbd)

[Guide on miniRT](https://42-cursus.gitbook.io/guide/rank-04/minirt)

[MiniRT article](https://haglobah.github.io/Mastering-42/holy_graph/miniRT.html)


https://github.com/tdameros/42-miniRT#-resources

https://github.com/favreau/awesome-ray-tracing


[RayTracingInOneWeekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

[scratchapixel](https://www.scratchapixel.com/index.html)

[Some Mathematics for Advanced Graphics](https://www.cl.cam.ac.uk/teaching/1999/AGraphHCI/SMAG/node1.html)

[The cherno playlist](https://www.youtube.com/watch?v=FiYDkMZCSF4&list=PLlrATfBNZ98edc5GshdBtREv5asFW3yXl&index=11)
[QuantitativeBytes yt](https://www.youtube.com/@QuantitativeBytes)

[Quaternions et rotation 3D, 3Blue1Brown yt](https://www.youtube.com/watch?v=zjMuIxRvygQ)

[3Blue1Brown article on quaternions](https://eater.net/quaternions)

[Linear algebra yt playlist](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)


[Normal mapping article on learnopengl.com](https://learnopengl.com/Advanced-Lighting/Normal-Mapping)

[ligth explaination on learnopengl.com](https://learnopengl.com/Lighting/Basic-Lighting)

[Article on raytracing shape](https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm)

[Line cylinder intersection wikipedia](https://en.m.wikipedia.org/wiki/Line-cylinder_intersection)


[Raytracing paper](https://www.doc.ic.ac.uk/~dfg/graphics/graphics2008/GraphicsLecture09.pdf)


[Ray Tracing Essentials NVIDIA yt playlist](https://www.youtube.com/watch?v=gBPNO6ruevk&list=PL5B692fm6--sgm8Uiava0IIvUojjFOCSR)


[Ray Tracing walkthrough in cpp yt playlist](https://www.youtube.com/watch?v=lXlXqUEEJ94&list=PLlrATfBNZ98edc5GshdBtREv5asFW3yXl&index=7)


[Book by NVIDIA](https://www.realtimerendering.com/raytracinggems/)

Mathematics for 3D Game Programming and Computer Graphics, Third Edition

[3D Math Primer for Graphics and Game Development BOOK](https://gamemath.com/book/intro.html)

[Computer Graphics from Scratch BOOK](https://www.gabrielgambetta.com/computer-graphics-from-scratch/)

[infographie lumiere](http://nicolas.janey.free.fr/Physique/Physique.htm)

[rendering algo](https://www.aortiz.me/2018/12/21/CG.html)
