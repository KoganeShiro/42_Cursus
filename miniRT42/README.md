# miniRT

## Notes

Use interface and TDD method to implement the parsing


Notes from reading the miniRT "tuto"

argument of the program, .rt file exemple
```
A 0.2 255,255,255
C 0,0,0 0,0,1 60
L 0,0,0 0.7 255,255,255
sp 0,0,50 20 255,0,0
```

**parsing and reading input files**

**graphic management** (windows, hooks, etc.). **with the minilibx**

A little more mathematical and concerns **intersections and ray tracing**

Then the **management of light, shadows and colors**


#### **Position the camera**
Define a fixed setup, specifying the position, orientation of the camera, and the size of the viewport.

#### **casting rays**
1. Shoot a ray from the camera towards each pixel of the viewport,
2. Find the nearest object hit by the ray in the scene,
3. If hit then find color at surface of the object.

#### **Ray Equation**
parametric equation
[What is a ray ?](https://link.springer.com/content/pdf/10.1007/978-1-4842-4427-2_2)
[A Minimal Ray-Tracer](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection.html)

#### **Objects equation**
[Raycasting algo, how to calculate intersection of a circle/sphere with a ray](https://www.youtube.com/watch?v=ebzlMOw79Yw)

- For spheres, it requires solving quadratic equations to find the points where the ray and the sphere's surface meet.
- Planes involve straightforward geometric calculations to determine where the ray intersects the plane.
- Cylinders require a bit more complexity, involving calculations to find where the ray crosses the cylindrical surface.

1. A function capable of converting x, y coordinates from the canvas to the viewport.
2. A function that calculates the intersection of the ray with every sphere, providing the color of the sphere at the nearest intersection within the specified range of t.
3. A function that solves the quadratic equation for each shape, focusing on spheres for now.
4. A function that places a pixel in an image with the given color at the specified coordinates.

#### **[Diffuse Shading](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/diffuse-lambertian-shading.html) Model**
###### **Ambient Light**
Light from reflected surfaces (similar to bouncing light)
This is called scattered light, it will hit other objects, some of it will be absorbed, and some will scatter again. This process keeps going until all the original light energy is absorbed by the surfaces in the scene.
We have an indirect light that is always present in the environment.
Each pixel of our scene will be multiplied by the given brightness ratio, aka ambient ratio
##### **Diffuse Shading**
When a ray of light hits a _matte_ object, the ray is scattered back into the scene equally in every direction, a process called _diffuse reflection_; this is what makes matte objects look matte. *Check to blender to see how it looks*
##### **[Lambert Shading](https://en.wikipedia.org/wiki/Lambertian_reflectance) model**
It calculates the intensity of light on a surface. The brightness of the surface is proportional to the cosine of the angle between the _surface normal_ (a perpendicular line to the surface) and _the light direction_.
The more directly the light hits the surface, the brighter it appears
1. Find the light direction.
2. Calculate the cosine of the angle between the light ray and the surface normal.
3. Multiply the cosine angle by the brightness ratio of the light.
4. Add the result to the color of the intersection point.
5. Finally, add this value to the ambient color.

##### **Shadows and Diffuse Lighting**
We need to calculate the direction from the *point of intersection* to the light source and check if there is any object blocking (excluding the object in question of course) the light. If there is an obstruction, the point is in shadow, except if they is ambient lighting.
If the point is not in shadow, we apply diffuse shading to that point.


#### Tips:
Ensure to work with a freely positionable camera as early as possible.
- Crazy colors? It's quite likely you're not adding/scaling you're colors correctly.
- Interesting distortions of any kind? Check whether you've normalized all the vectors that should be.
Do every calculation on the [stack](https://orkhanhuseyn.medium.com/what-are-stack-based-calculators-cf2dbe249264). It's just so much faster.
In case you're field of view is rotated in any way: That's probably just your camera.

---

## Ressources

[miniRT playlist russe ?](https://youtu.be/E6e_hQ5LQDE?feature=shared)

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
